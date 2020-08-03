struct hash_node
{
    int key;    // value
    int value; // frequency of the value
    struct hash_node * next; // pointer to the next node
};
struct hash_map
{
    int num_of_bins;    // size of bins
    struct hash_node ** marr; // arrays to contain pointer to hash_nodes
};
struct min_heap
{
    int num_of_elems; // num of elems the heap currently possesses.
    int max_size; // max size of a heap. must be same as the size of harr
    struct hash_node ** harr; // array to manage heap structure
};
// initialize a hash map. returns a pointer to a malloced hash map
struct hash_map * init_map(int bin_size)
{
    struct hash_map* p_map = (struct hash_map*)malloc(sizeof(struct hash_map));
    p_map->num_of_bins = bin_size;
    p_map->marr = (struct hash_node **)malloc(sizeof(struct hash_node*)*bin_size);
    // initialize it as null;
    for (int ii = 0; ii<p_map->num_of_bins; ii++)
    {
        *(p_map->marr+ii) = NULL;
    }
    return p_map;
}

//frees a map structure
void free_map(struct hash_map * p_map)
{
    free(p_map->marr);
    free(p_map);
}


// initialize min heap. returns a pointer to a malloced min heap.
struct min_heap * init_heap(int max_size)
{
    struct min_heap * p_min_h = (struct min_heap *)malloc(sizeof(struct min_heap));
    p_min_h->num_of_elems = 0;
    p_min_h->max_size = max_size;
    p_min_h->harr = (struct hash_node **)malloc(sizeof(struct hash_node*)*max_size);
    return p_min_h;
}

void free_heap(struct min_heap * p_heap)
{
    free(p_heap->harr);
    free(p_heap);
}

// hash function(chaining is used so only one function is good enough)
int calc_hash(int key, int bins)
{
    return abs(key)%bins;
}

// this function returns 1 if the key exist in the hash map. 0 otherwise. p_node gets assigned to the existing point to the node.
uint8_t contains(int key, struct hash_map* p_map, struct hash_node ** p_node)
{
    struct hash_node * p_temp;
    int id = calc_hash(key, p_map->num_of_bins);
    p_temp = p_map->marr[id];
    while (p_temp!=NULL)
    {
        if (p_temp->key == key)
        {
            *p_node = p_temp;
            return 1;
        }
        p_temp = p_temp->next;
    }
    // to reach here, there was no node with matching key
    return 0;
}
// function to add a node to a hash map.
uint8_t add_node(struct hash_map* p_map, int key, int value)
{
    int id = calc_hash(key, p_map->num_of_bins);
    struct hash_node * temp;
    temp = p_map->marr[id];
    if (temp==NULL)
    {
        temp = (struct hash_node *)malloc(sizeof(struct hash_node));
        temp->key = key;
        temp->value = value;
        temp->next = NULL;
        p_map->marr[id] = temp;
    }
    else
    {
        while(temp->next!=NULL)
        {//
            temp = temp->next;
        }
        temp->next = (struct hash_node *)malloc(sizeof(struct hash_node));
        temp->next->key = key;
        temp->next->value = value;
        temp->next->next = NULL;
    }
    return 1;
}

// this function increases the number of value in the key
uint8_t add_value(struct hash_map* p_map, int key)
{
    struct hash_node * h_node;
    if (!contains(key, p_map, &h_node))
    {// the key does not exist in the hash map
        uint8_t success = add_node(p_map, key, 1);
        if (success)
            return 1;
        else
            return 0;
    }
    else
    {// the key already exist in the hash map
        // we simply need to increase the value of the h_node
        h_node->value++;
        return 1;
    }
}
// swap a pointer to the node.
void swap_node(struct hash_node ** p_nodeA, struct hash_node ** p_nodeB)
{
    struct hash_node * temp = *p_nodeA;
    *p_nodeA = *p_nodeB;
    *p_nodeB = temp;
}

int peek_min(struct min_heap * p_heap)
{
    return (p_heap->harr[0])->value;
}

int parent(int index)
{
    if (index>0)
        return (index-1)/2;
    else
        return -1;
}

int left(int index, int max_size)
{
    int temp = index*2+1;
    if (temp<max_size)
        return temp;
    else
        return -1;
}
int right(int index, int max_size)
{
    int temp = index*2+2;
    if (temp<max_size)
        return temp;
    else
        return -1;
}

void min_heapify(struct min_heap * p_heap, int index)
{
    int smallest = index;
    int l = left(index, p_heap->max_size);
    int r = right(index, p_heap->max_size);
    if (l>0 && p_heap->harr[l]->value < p_heap->harr[smallest]->value)
        smallest = l;
    if (r>0 && p_heap->harr[r]->value < p_heap->harr[smallest]->value)
        smallest = r;
    if (smallest!=index){
        swap_node( &(p_heap->harr[index]),  &(p_heap->harr[smallest]));
        min_heapify(p_heap, smallest);
    }
}

// adds a node into a heap structure
void insert_key(struct min_heap * p_heap, struct hash_node * p_node)
{
    if (p_heap->max_size <= p_heap->num_of_elems)
    {// already having the max
        // compare the minimum
        int min_val = peek_min(p_heap);
        if (min_val < p_node->value)
        {// in this case, we have to replace the current min and call min_heapify
            p_heap->harr[0] = p_node;
            min_heapify(p_heap, 0);
        }
    }
    else
    {// it's not full yet.
        p_heap->harr[p_heap->num_of_elems] = p_node;
        int pa = parent(p_heap->num_of_elems);
        int curr = p_heap->num_of_elems;
        p_heap->num_of_elems++;
        while (pa>=0 && p_heap->harr[pa]->value > p_node->value)
        {
            swap_node(&p_heap->harr[pa], &p_heap->harr[curr]);
            curr = pa;
            pa = parent(pa);
        }
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){

    if (numsSize==1){
        *returnSize = 1;
        int * p_result = (int *)malloc(sizeof(int)*k);
        *p_result = *nums;
        return p_result;
    }
    // initialize the map and heap
    struct hash_map * p_map = init_map(numsSize/2);
    struct min_heap * p_heap = init_heap(k);
    // add the frequency
    for (int ii = 0; ii<numsSize; ii++)
    {
        add_value(p_map, *(nums+ii));
    }
    // do things for a heap.
    for (int ii = 0; ii<p_map->num_of_bins; ii++)
    {
        if (p_map->marr[ii]!=NULL)
        {
            struct hash_node * p_temp;
            p_temp = p_map->marr[ii];
            while(p_temp!=NULL)
            {
                insert_key(p_heap, p_temp);
                p_temp = p_temp->next;
            }
        }
    }
    int * p_result = (int *)malloc(sizeof(int)*k);
    *returnSize=k;
    for (int ii = 0; ii<k; ii++)
    {
        *(p_result+ii) = (p_heap->harr[ii]->key);
    }
    free_map(p_map);
    free_heap(p_heap);
    return p_result;
}
