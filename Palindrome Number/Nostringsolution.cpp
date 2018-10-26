class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int digit=1;
        int p=10;
        while(x/p!=0)
        {
            if(digit==9){digit=10;break;}
            p=p*10;
            digit++;
        }
        for(int i=0;i<digit/2;i++)
        {
            if(x/int(pow(10,digit-i-1))%10!=x/int(pow(10,i))%10) return false;
        }
        return true;
        
    }
};
