class Solution {
public:
    int myAtoi(string str) {
        int len=str.length();
        int i=0;
        int max=INT_MAX/10;
        bool sign=true;
        bool f=false;
        for(i=0;i<len;i++)
        {
            if(str[i]!=' '){f=true;break;}
        }
        if(!f) return 0;
        if(str[i]=='-'){sign=false;i++;}
        else if(str[i]=='+'){i++;}
        if(str[i]<'0'||str[i]>'9') return 0;
        int ans=0;
        while(i<len&&str[i]>='0'&&str[i]<='9')
        {
            if(ans>max)
            {
                if(sign) return INT_MAX;
                else return INT_MIN;
            }
            else if(ans==max)
            {
                if(str[i]-'0'>7)
                {
                    if(sign) return INT_MAX;
                    else return INT_MIN;
                }
            }
            ans=10*ans+str[i]-'0';
            i++;
        }
        if(sign) return ans;
        else return -ans;
    }
};
