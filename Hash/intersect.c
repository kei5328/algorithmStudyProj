


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct HashNode{
    int key;
    int val;
    struct HashNode * next;
};

typedef struct{
    struct HashNode ** arr;
    int size;
}HashMap;


HashMap * init_map(int size)
{
    HashMap * map = (HashMap*)malloc(sizeof(HashMap));
    if (map)
    {
        map->arr = (struct HashNode**) malloc(sizeof(struct HashNode*)*size);
        for (int ii = 0; ii<size; ii++)
        {
            map->arr[ii] = NULL;
        }
        map->size = size;
    }
    return map;
}
struct HashNode * init_node(int key)
{
    // reaching here means the key does not exist in the current hash// need to add in a new node.
    struct HashNode * node = (struct HashNode*)malloc(sizeof(struct HashNode));
    if (node)
    {
        node->key = key;
        node->val = 1;
        node->next = NULL;
    }
    return node;
};

int hash_function(HashMap * map, int num)
{
    return (num%map->size);
}


bool is_member(HashMap * map, int key)
{
    int idx = hash_function(map, key);
    if (idx<0 || idx>=map->size)
        return false;

    struct HashNode * curr_node = map->arr[idx];
    while(curr_node)
    {
        if (curr_node->key==key)
        {
            if (curr_node->val>0)
                return true;
            else
                return false;
        }

        curr_node = curr_node->next;
    }
    return false;
}

void add_key(HashMap * map, int key)
{
    int idx = hash_function(map, key);
    if (idx<0 || idx>=map->size)
        return;
    struct HashNode * curr_node = map->arr[idx];
    struct HashNode * prev_node = curr_node;
    while (curr_node)
    {
        if (curr_node->key == key)
        {
            curr_node->val++;
            return;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    if (prev_node)
        prev_node->next = init_node(key);
    else
        map->arr[idx] = init_node(key);
    return;
}

void pop_key_val(HashMap * map, int key)
{
    if (is_member(map, key))
    {
        int idx = hash_function(map, key);
        if (idx<0 || idx>=map->size)
            return;

        struct HashNode * curr_node = map->arr[idx];
        while(curr_node)
        {
            if (curr_node->key==key)
            {
                if (curr_node->val>0)
                {
                    curr_node->val -= 1;
                }
                break;
            }
            curr_node = curr_node->next;
        }
    }
    return;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){

    int* result = NULL;
    *returnSize = 0;
    HashMap* map = init_map(nums1Size);

    for (int ii = 0; ii<nums1Size; ii++)
    {
        add_key(map, nums1[ii]);
    }

    // first one, add to map with counting number
    // if the key does not exist, add key and set val as one
    // if the key already exists, increment the val by one
    // loop thru 2nd one
    // if the key-val pair exists and val >0,
    // realloc an array and input the
    for (int ii = 0; ii<nums2Size; ii++)
    {//
        int curr_num = nums2[ii];
        if (is_member(map, curr_num))
        {
            pop_key_val(map, curr_num);
            if (*returnSize==0)
            {
                result = (int *)malloc(sizeof(int)*1);
            }
            else
            {
                int * temp = realloc(result, sizeof(int)* ((*returnSize)+1));
                if (temp)
                {
                    result = temp;
                }

            }
            *(result+(*returnSize)) = curr_num;
            (*returnSize)=(*returnSize)+1;
        }
    }
    return result;
}
