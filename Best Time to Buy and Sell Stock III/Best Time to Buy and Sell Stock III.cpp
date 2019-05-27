class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz=prices.size();
        if(sz<=1) return 0;
        int* first=new int[sz];
        int* second=new int[sz];
        first[0]=second[0]=0;
        int minprice=prices[0];
        for(int i=1;i<sz;++i)
        {
            first[i]=max(first[i-1],prices[i]-minprice);
            minprice=min(minprice,prices[i]);
        }
        int paid=first[0]-prices[0];
        for(int i=1;i<sz;++i)
        {

            second[i]=max(second[i-1],prices[i]+paid);
            paid=max(paid,first[i]-prices[i]);
        }
        return second[sz-1];
    }
};
