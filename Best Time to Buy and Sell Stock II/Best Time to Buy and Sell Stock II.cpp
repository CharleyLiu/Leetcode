class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int buyprice=0;
        if(prices.size()<=1) return 0;
        bool has=false;
        for(int i=0;i<prices.size()-1;++i)
        {
            if(prices[i+1]>prices[i]&&!has)
            {
               buyprice=prices[i];
               has=true;
            }
            if(prices[i+1]<prices[i]&&has)
            {
                profit+=prices[i]-buyprice;
                has=false;
            }
        }
        if (has&&prices[prices.size()-1]>buyprice)
            profit+=prices[prices.size()-1]-buyprice;
        return profit;
        
    }
};
