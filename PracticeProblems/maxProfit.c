


int maxProfit(int* prices, int pricesSize){


    // find max and its index
    int start_idx = 1;
    int max_profit = 0;


    int buy_val = prices[0];


     for (int i=start_idx; i<pricesSize; i++)
     {
        if (prices[i]-buy_val>=0)
        {
            if (prices[i]-buy_val>max_profit)
            {
                max_profit = prices[i]-buy_val;
            }
        }
        else
        {
            buy_val = prices[i];
        }
     }
    return max_profit;
}


