int maxProfit(int* prices, int pricesSize){
    int min = prices[0];
    int max_diff = 0;

    for (int i = 1; i < pricesSize; i++){
        if (prices[i] < min){
            min = prices[i];
            continue;
        }

        if (prices[i] - min > max_diff)
            max_diff = prices[i] - min;
        
    }
    return max_diff;
}  