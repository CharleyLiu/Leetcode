class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> comb(amount+1,0);
        comb[0]=1;
        for(int& coin:coins){
            for(int i=coin;i<=amount;++i){
                comb[i]+=comb[i-coin];
            }
        }
        return comb[amount];
    }
};
