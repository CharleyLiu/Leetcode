class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool ac=false;
        int len=digits.size()-1;
        if(digits[len]==9)
        {
            digits[len]=0;
            ac=true;
        }
        else
        {
            digits[len]=digits[len]+1;
        }
        for(int i=len-1;i>=0;--i)
        {
            if(ac)
            {
                digits[i]=digits[i]+1;
                ac=false;
                if(digits[i]==10) 
                {
                    digits[i]=0;
                    ac=true;
                }                
            }
            if(!ac) break;
        }
        if(ac)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
