class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign=true;
        int i=0;
        if(dividend<0) {dividend=-dividend;sign=false;}
        if(divisor<0) {divisor=-divisor;sign=!sign;}
        if(dividend==INT_MIN) 
        {
            if(divisor==1&&sign) return INT_MAX;
            dividend=dividend+abs(divisor); i++;
            if(dividend<0) dividend=-dividend;
        }
        if(divisor==INT_MIN)
        {
            if(!sign) i=-i;
            return i;
        }
        int j,temp;
        int max=INT_MAX>>1;
        while(dividend>=divisor)
        {
            j=0;
            temp=divisor;
            while(temp<=max&&temp<=dividend)
            {
                temp=temp<<1;
                j++;
            }
            if(temp>dividend)
            {
                temp=temp>>1;
                dividend-=temp;
                i+=1<<(j-1);
            }
            else
            {
                dividend-=temp;
                i+=1<<j;
            }

        }
        if(!sign) i=-i;
        return i;
        
    }
};
