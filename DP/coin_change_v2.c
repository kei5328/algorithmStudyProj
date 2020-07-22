
// solution using array for DP.
int count_coin(int amount, int* coins, int coinSize, int * dp)
{
    if (amount == 0) return 0;
    if (amount < 0) return -1;

    if (*(dp+amount) >= -1) return *(dp+amount);

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
        *(dp+amount) = min_step+1;
        return min_step + 1;
    }
    else
    {
        *(dp+amount) = -1;
        return -1;
    }
}

int coinChange(int* coins, int coinsSize, int amount){
    if (coinsSize<=0) return -1;

    // initialize Map
    int dp[amount+1];
    for (int ii = 0; ii<amount+1; ii++)
    {
        dp[ii] = -2;
    }
    int min_coins = count_coin(amount, coins, coinsSize, dp);
    return min_coins;
}
