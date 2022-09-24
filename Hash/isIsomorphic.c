
struct Node
{
    int key;
    int val;

    struct Node * next;
};


struct HashMap
{
    int arr_size;
    struct node ** arr;
};
void free_list_node(struct Node* node)
{
    if (node==NULL) return;
    struct Node * curr_node = node->next;
    struct Node * prev_node = node;
    while (curr_node!=NULL)
    {
        free(prev_node);
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    free(prev_node);
}


void free_hash_map(struct HashMap* map)
{
    if (map==NULL) return;
    for (int ii = 0; ii<map->arr_size; ii++)
    {
        free_list_node(map->arr[ii]);
    }
    free(map);
}

// computes the index by simple modulo
int hash_function(int val, int len)
{
    if (len==0) return -1;
    return val%len;
}

struct Node * init_node(int key, int val)
{
    struct Node * new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node==NULL) return NULL;
    new_node->key = key;
    new_node->val = val;
    new_node->next = NULL;

    return new_node;
}

struct HashMap * init_map(int arr_size)
{
    struct HashMap * map = (struct HashMap*)malloc(sizeof(struct HashMap));
    if (map==NULL) return NULL;

    map->arr_size = arr_size;
    map->arr = (struct node**)malloc(sizeof(struct node*)*arr_size);
    if (map->arr==NULL)
    {
        free(map);
        return NULL;
    }

    // init as null
    for (int ii = 0; ii<arr_size; ii++)
    {
        map->arr[ii] = NULL;
    }

    return map;
}


bool is_member(struct HashMap * map, int key)
{
    if (map==NULL) return false;
    int idx = hash_function(key, map->arr_size);
    if (idx<0 || idx>=map->arr_size) return false;

    bool result = false;
    struct Node * curr_node = map->arr[idx];
    while (curr_node!=NULL)
    {
        if (curr_node->key == key)
        {
            result = true;
            break;
        }
        curr_node = curr_node->next;

    }
    return result;
}

bool get_val_from_map(struct HashMap* map, int key, int * val)
{
    if (map==NULL) return false;
    //if (!(is_member(map, key))) return false; // the key does not exist...

    int idx = hash_function(key, map->arr_size);
    if (idx<0 || idx>=map->arr_size) return false;
    bool result = false;
    struct Node * curr_node = map->arr[idx];
    while (curr_node!=NULL)
    {
        if (curr_node->key == key)
        {
            result = true;
            *val = curr_node->val;
            break;
        }
        curr_node = curr_node->next;
    }
    return result;
}


bool add_val_to_map(struct HashMap * map, int key, int val)
{
    if (map==NULL) return false;
    if (is_member(map, key)) return false; // already the member.


    struct Node * node = init_node(key, val);
    if (node==NULL) return false;

    int idx = hash_function(key, map->arr_size);
    if (idx<0 || idx>=map->arr_size) return false; // check for index.

    if (map->arr[idx]==NULL)
    {
        map->arr[idx] = node;
    }
    else
    {
        struct Node * curr_node =  map->arr[idx];
        while (curr_node->next!=NULL)
        {
            curr_node = curr_node->next;
        }
        curr_node->next = node;
    }
    return true;
}

bool isIsomorphic(char * s, char * t){

    // check if the lengths are the same
    //if (strlen(s)!=strlen(t)) return false;
    //if (strlen(s)==0 && strlen(t)==0) return true;
    bool result = true;
    uint16_t s_len = strlen(s);

    struct HashMap * map1 = init_map(16);
    struct HashMap * map2 = init_map(16);
    int s_val = 0;
    int t_val = 0;
    int map_val1 = 0;
    int map_val2 = 0;
    for (int ii = 0; ii<s_len; ii++)
    {
        s_val = (int) (*(s+ii));
        t_val = (int) (*(t+ii));
        // check if the s_val is in the hashmap as key
        //if (is_member(map, s_val))
        if (get_val_from_map(map1,s_val,&map_val1))
        {// s_val is already in the map as a key
         // get the value
            if (map_val1!=t_val)
            {
                result = false;
                break;
            }

        }
        else
        {// s_val is not in the map yet
            // add it in the map.
            bool success = add_val_to_map(map1, s_val, t_val);
            if (!success) return false;
        }

        if (get_val_from_map(map2,t_val,&map_val2))
        {// s_val is already in the map as a key
         // get the value
            if (map_val2!=s_val)
            {
                result = false;
                break;
            }
        }
        else
        {// s_val is not in the map yet
            // add it in the map.
            bool success = add_val_to_map(map2, t_val, s_val);
            if (!success) return false;
        }

    }
    free_hash_map(map1);
    free_hash_map(map2);
    return result;
}
