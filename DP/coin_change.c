// Solution using hashmap.
// Implement hashmap
struct node {
    int key;
    int value;
    struct node *next;
};

struct Map{
    uint8_t num_bins;
    struct node ** arr;
};

// funciton to initialize map
void init_map(struct Map * dp, uint8_t bin_size)
{
    dp->num_bins = bin_size; // set the num_bins
    dp->arr = (struct node **)malloc(sizeof(struct node**)*bin_size); // generate an array to hold the List Node
    for (int ii = 0; ii < bin_size; ii++)
    { // set all array point to null;
        *((dp->arr)+ii) = NULL;
    }
}

// hash funciton.
int calc_hash(int key, int num_bins)
{
    return key%num_bins;
}

// funciton for inserting key
uint8_t add_value(struct Map * dp, int key, int value)
{
    int hash_val = calc_hash(key, dp->num_bins);
    struct node * temp = *((dp->arr) + hash_val);
    if (temp == NULL)
    {// in this bin, this key value pair is the fist one to be inserted
        temp = (struct node * ) malloc(sizeof(struct node));
        if (temp==NULL) return 0; // malloc failed
        temp->key = key;
        temp->value = value;
        temp->next = NULL;
        *((dp->arr) + hash_val) = temp;
    }
    else
    {// in this bin, the key already exist
        struct node * prev = NULL;
        while (temp!=NULL)
        {
            if (temp->key == key) // the key already exist
                return 0; // no new key was added.
            prev = temp;
            temp = temp->next;
        }
        // to reach here, the linked list must end.
        temp = (struct node * ) malloc(sizeof(struct node));
        if (temp==NULL) return 0; // malloc failed
        prev->next = temp;
        temp->key = key;
        temp->value = value;
        temp->next = NULL;
    }
    return 1;
}

// funcion to get value
uint8_t get_value(struct Map * dp, int key, int * value)
{
    int hash_val = calc_hash(key, dp->num_bins);
    struct node * temp = *((dp->arr) + hash_val);
    if (temp == NULL) return 0;

    while(temp!=NULL)
    {
        if (temp->key == key)
        {// key match with the current one
            *value = temp->value;
            return 1;
        }
        temp = temp->next;
    }
    // to reach here, there was no node matching the key
    return 0;
}

int count_coin(int amount, int* coins, int coinSize, struct Map * dp)
{
    if (amount == 0) return 0;
    if (amount < 0) return -1;
    int value;
    if (get_value(dp, amount, &value))
    {//
        //printf("Map used: amount=%d, value=%d", amount, value);
        return value;
    }
    int min_step = INT_MAX;
    uint8_t valid = 0;
    for (int ii=0; ii<coinSize; ii++)
    {
        int temp = count_coin(amount-coins[ii], coins, coinSize, dp);
        if (temp<min_step && temp>=0){
          min_step = temp;
          if (!valid) valid = 1;
        }
    }
    if (valid) // at least one result was valid;
    {
        add_value(dp, amount, min_step + 1);
        return min_step + 1;
    }
    else
    {
        add_value(dp, amount, -1);
        return -1;
    }
}

int coinChange(int* coins, int coinsSize, int amount){
    if (coinsSize<=0) return -1;

    // initialize Map
    struct Map dp;
    if (coins[coinsSize-1]>11)
        init_map(&dp, coins[coinsSize-1]);
    else
        init_map(&dp, 11);
    int min_coins = count_coin(amount, coins, coinsSize, &dp);
    return min_coins;
}
