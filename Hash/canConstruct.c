

struct HashNode{
    char key;
    int val;
    struct HashNode * next;
};

typedef struct {
    int arr_size;
    struct HashNode ** arr;
}HashMap;


struct HashNode * init_node(char key, int val)
{
    struct HashNode * node  = (struct HashNode*)malloc(sizeof(struct HashNode));
    if (node)
    {
        node->key = key;
        node->val = val;
        node->next = NULL;
    }
    return node;
};


HashMap * init_map(int arr_size)
{
    HashMap * map = (HashMap*)malloc(sizeof(HashMap));
    if (map)
    {
        map->arr = (struct HashNode**)malloc(sizeof(struct HashNode*)*arr_size);
        map->arr_size = arr_size;
        if (map->arr)
        {
            for (int ii = 0; ii<arr_size; ii++)
            {
                map->arr[ii] = NULL;
            }
        }
    }
    return map;
}

// hash function (use key-'a') as we know it's lower english letters.
int hash_function(HashMap * map, char key)
{
    int num_key = (int)(key-'a');
    return (num_key%map->arr_size);
}



bool is_member(HashMap* map, char key)
{
    int idx = hash_function(map, key);
    if (idx<0 || idx>=map->arr_size)
    {
        return;
    }
    struct HashNode * curr_node = map->arr[idx];
    while (curr_node)
    {
        if (curr_node->key == key && curr_node->val>0)
        {// key exists and its value is more than 0.
            return true;
        }

        curr_node = curr_node->next;
    }
    return false;
}

void add_to_map(HashMap * map, char key)
{
    int idx = hash_function(map, key);
    if (idx<0 || idx>=map->arr_size)
    {
        return;
    }
    if (is_member(map, key))
    {
        if (map->arr[idx])
        {
            struct HashNode * curr_node =map->arr[idx];
            while (curr_node)
            {
                if (curr_node->key == key)
                {
                    curr_node->val += 1;
                    return;
                }

                curr_node = curr_node->next;
            }
        }
        else
            return;
    }
    else
    {

        struct HashNode * node = init_node(key, 1);
        if (map->arr[idx])
        {
            struct HashNode * curr_node =map->arr[idx];
            while (curr_node->next)
            {
                curr_node = curr_node->next;
            }
            curr_node->next = node;
        }
        else
        {
            map->arr[idx] = node;
        }
    }
    return;
}

bool pop_from_map(HashMap * map, char key)
{
    if (!is_member(map, key))
    {
        return false;
    }
    int idx = hash_function(map, key);
    if (idx<0 || idx>=map->arr_size)
    {
        return;
    }
    struct HashNode * curr_node = map->arr[idx];
    while(curr_node)
    {
        if (curr_node->key == key)
        {
            curr_node->val -= 1;
            return true;
        }

        curr_node = curr_node->next;
    }
    return false;
}

void delete_nodes(struct HashNode * node)
{
    struct HashNode * prev_node = node;
    while (node)
    {
        node = node->next;
        free(prev_node);
        prev_node = node;
    }

    return;
}

void delete_map(HashMap * map)
{

    for (int ii = 0; ii<map->arr_size; ii++)
    {
        delete_nodes(map->arr[ii]);
    }
    free(map);
}

bool canConstruct(char * ransomNote, char * magazine){

    int mag_len = strlen(magazine);
    int note_len = strlen(ransomNote);

    if (mag_len<=0) return false; // with empty magazine, no ransome note.

    HashMap * map = init_map(26);

    for (int ii = 0; ii<mag_len; ii++)
    {
        char key = magazine[ii];
        add_to_map(map, key);
    }

    for (int ii = 0; ii<note_len; ii++)
    {
        char key = ransomNote[ii];
        if (!pop_from_map(map, key))
            return false;
    }
    delete_map(map);
    return true;
}
