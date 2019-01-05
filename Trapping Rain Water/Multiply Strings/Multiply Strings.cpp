class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        string ans="";
        if(num1.length()>num2.length())
        {
            string temp=num1;
            num1=num2;
            num2=temp;
        }
        int len1=num1.length();
        int len2=num2.length();
        int ahead=0;
        for(int i=0;i<len1+len2;++i)
        {
            int sum=ahead;
            bool flag=false;
	    for (int k = 0; k < len1; ++k)
		{
			if (len2 + len1 - k - i - 2 < 0||len1-k-i>=2) continue;
			sum += (num1[k] - '0')*(num2[len2 + len1 - k - i - 2] - '0');
            flag=true;
		}
        if(flag)
        {
            int digit=sum%10;
            ahead=(sum-digit)/10;
            ans=char(digit+'0')+ans;
        }

        }
        if(ahead!=0) ans=char(ahead+'0')+ans;
        return ans;
        
    }
};
