class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int ans=0;
        while(x>ans)
        {
            ans=10*ans+x%10;
            x=x/10;
        }
        return (x==ans)||(x==ans/10);
    }
};
