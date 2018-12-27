class Solution {
public:
    string countAndSay(int n) {
        string a="1";
        int ge=1;
        while(ge<n)
        {
            string b="";
            int len=a.length();
            for(int i=0;i<len;++i)
            {
                int count=1;
                while(i<len-1&&a[i]==a[i+1])
                {
                    ++count;
                    ++i;
                }
                b=b+to_string(count)+a[i];
            }
            a=b;
            ++ge;
        }
        return a;
    }
};
