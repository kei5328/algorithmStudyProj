
struct heap
{
    uint32_t num_of_elems; // current number of elements
    uint32_t max_size; // max size(same as the size of harr)
    int * harr; // array to keep the elements
};

// initializes a heap
struct heap * init_heap(uint32_t max_size)
{
    struct heap * p_heap =(struct heap *)malloc(sizeof(struct heap));
    p_heap->num_of_elems = 0;
    p_heap->max_size = max_size;
    p_heap->harr = (int*)malloc(sizeof(int)*max_size);
    return p_heap;
}

// frees a heap structure
void free_heap(struct heap * p_heap)
{
    free(p_heap->harr);
    free(p_heap);
}


// returns the parent index
int parent(int index)
{
    int temp;
    temp = (index-1)/2;
    if ((index-1)>=0)
        return temp;
    else
        return -1;
}
// returns the left index.
int left(int index, int max_num)
{
    int temp;
    temp = (index*2+1);
    if (temp<max_num)
        return temp;
    else
        return -1;
}
// returns the right index
int right(int index, int max_num)
{
    int temp;
    temp = (index*2+2);
    if (temp<max_num)
        return temp;
    else
        return -1;
}

// swap function for integer.
void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// to heapify a min heap structure
void min_heapify(struct heap * p_heap, int index)
{
    int smallest = index;
    int l = left(index, p_heap->num_of_elems);
    int r = right(index, p_heap->num_of_elems);
    if (l>0 && p_heap->harr[l] < p_heap->harr[smallest])
        smallest = l;
    if (r>0 && p_heap->harr[r] < p_heap->harr[smallest])
        smallest = r;
    if (smallest!=index)
    {
        swap(&p_heap->harr[smallest], &p_heap->harr[index]);
        min_heapify(p_heap, smallest);
    }
}

// handles the insersion of the numbers to a heap.
void insert_key(struct heap * p_heap, int value)
{
    if (p_heap->max_size <= p_heap->num_of_elems)
    {// heap is already full
        if (*(p_heap->harr) < value)
        {// when the incoming value is larger than the current minimum.
            *(p_heap->harr) = value; // change the minimum
            min_heapify(p_heap, 0); // call min_heapify to place the incoming number to the correct location in the heap.
        }
    }
    else
    {// heap is not full yet
        *(p_heap->harr + p_heap->num_of_elems) = value; // add to the next available element in the heap array.
        int curr = p_heap->num_of_elems; // get the curernt index;
        p_heap->num_of_elems++;
        int pa = parent(curr); // get the parent index.
        while (pa>=0 && p_heap->harr[pa] > p_heap->harr[curr])
        {// there is a parent, and the parent value is larger than the current value.
            swap(&p_heap->harr[pa], &p_heap->harr[curr]); // swap the number.
            curr = pa; // traverse to the parent
            pa = parent(pa);
        }
    }
}

int findKthLargest(int* nums, int numsSize, int k){
    struct heap * p_heap = init_heap(k); // init with the heap size of k; this allows the heap to have the kth largest element as the minimum item in the heap.
    for (int ii = 0; ii < numsSize; ii++) // insert the values in the heap.
    {
        insert_key(p_heap, *(nums+ii));
    }
    int res = *(p_heap->harr);
    free_heap(p_heap);
    return res;
}
