
// let's define a simple hashmap. I'll use chaining.

// node for each hash map array
struct HashNode
{
    int val;
    struct HashNode * next;
};

// structure for hash map.
struct HashMap
{
    int arr_size; // size of an array.
    struct HashNode** arr; // array containing the pointer to the hash node.
};

// computes the index by simple modulo
int hash_function(int val, int len)
{
    if (len==0) return -1;
    return (int)abs(val%len);
}

// function to free malloced nodes.
void delete_node(struct HashNode* node)
{
    if (node==NULL) return;

    struct HashNode* curr_node = node;
    struct HashNode* prev_node = node;
    while(curr_node->next!=NULL)
    {
        prev_node = curr_node;
        curr_node = curr_node->next;
        free(prev_node);
    }
    free(curr_node);
}

// function to free malloced map. Calls dete_node inside.
void delete_map(struct HashMap* map)
{
    if (map==NULL) return;
    for (int ii = 0; ii<map->arr_size; ii++)
    {//
        delete_node(map->arr[ii]);
    }
    free(map);
}


// initialize a node with an input val.
struct HashNode* init_node(int val)
{
    struct HashNode * node = (struct HashNode*) malloc(sizeof(struct HashNode));
    if (node==NULL) return NULL;

    node->val = val;
    node->next = NULL;
    return node;
}

// initialize a hash map.
struct HashMap* init_map(int arr_size)
{
    // malloc the map.
    struct HashMap * map = (struct HashMap*)malloc(sizeof(struct HashMap));
    if (map!=NULL)
    {// malloc succeeded: assign array size and malloc the array,
        map->arr_size = arr_size;
        map->arr = (struct HashNode**)malloc(sizeof(struct HashNode*)*arr_size);
        if (map->arr==NULL) return NULL; // make sure the malloc has succeeded.
        for (int ii = 0; ii<arr_size; ii++)
        {// initialize as null.
            map->arr[ii] = NULL;
        }
    }
    return map;
}

// this function checks if the val is in the hash map.
bool is_member(struct HashMap* map, int val)
{

    bool result = false;
    if (map==NULL) return false;

    // get the index from the hash function.
    int idx = hash_function(val, map->arr_size);

    // check for out of indices
    if (idx>=map->arr_size || idx<0) return 0;
    struct HashNode * curr_node = map->arr[idx];
    while (curr_node!=NULL)
    {// search until the end.
        if (curr_node->val == val)
        {
            result = true;
            break;
        }
        curr_node = curr_node->next;
    }
    return result;
}

// adds a new value to the map. (returns 0 if the value already exists or cannot be added in).
bool add_to_map(struct HashMap* map, int val)
{
    if (map==NULL) return 0;
    if (is_member(map, val)) return 0; // check if it's a member or not.
    struct HashNode* add_node = init_node(val); // create a new node.
    if (add_node==NULL) return 0; // check for the null ptr
    int idx = hash_function(val, map->arr_size); // get the index from hash function.
    if (idx>=map->arr_size || idx<0) return 0; // check the validity of the result.
    // Add the newly created node to the list.
    struct HashNode * curr_node = map->arr[idx];

    if (curr_node==NULL)
    {// current index is empty.
        map->arr[idx] = add_node;
    }
    else
    {// current index already has a number.
        while (curr_node->next!=NULL)
        {// traverse until the last one(next is null).
            curr_node = curr_node->next;
        }
        curr_node->next = add_node; // add the newly generated node.
    }
    return true;
}

bool containsDuplicate(int* nums, int numsSize){

    if (numsSize<=1) return false;

    struct HashMap * map = init_map(10);

    for (int ii = 0; ii<numsSize; ii++)
    {
        int curr_val = (*(nums+ii));
        if (is_member(map, curr_val))
        {
            delete_map(map);
            return true;
        }
        else
        { // add values;
            add_to_map(map, curr_val);
        }
    }
    // to reach here, all the number in nums did not overlap.
    delete_map(map);
    return false;
}

// 2nd solution




bool swap(int * nums, int idx1, int idx2)
{
    if (nums==NULL) return false;
    int temp = *(nums+idx1);
    *(nums+idx1) = *(nums+idx2);
    *(nums+idx2) = temp;
    return true;
}
int partition(int * nums, int p, int q)
{
    if (nums==NULL) return -1;
    int i = p-1;
    int pivot = *(nums+q);
    for (int j = p; j<=q-1; j++)
    {
        if (*(nums+j)<=pivot)
        {
          i++;
          swap(nums, i, j);
        }
    }
    swap(nums, i+1, q);
    return i+1;
}
void quickSort(int * nums, int p, int q)
{

     if (p<q)
     {
        int r = partition(nums, p, q);
        if (r<0) return;
        quickSort(nums, p, r-1);
        quickSort(nums, r+1, q);
     }
    return;
}



bool containsDuplicate(int* nums, int numsSize){

    if (numsSize<=1) return false;

    quickSort(nums, 0, numsSize-1);

    int prev_val = *nums;
    for (int ii = 1; ii<numsSize; ii++)
    {
        int curr_val = *(nums+ii);
        if (curr_val==prev_val) return true;
    }
    return false;
}
