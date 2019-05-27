class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int sz=prices.size();
        if(sz<=1) return 0;
        int smallest=prices[0];
        for(int i=1;i<sz;++i)
        {
            if(prices[i]>smallest)
            {
                profit=max(profit,prices[i]-smallest);
            }
            else
            {
                smallest=prices[i];
            }
        }
        return profit;
        
    }
};
