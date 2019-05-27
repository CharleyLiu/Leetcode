class Solution {
public:

    int numDistinct(string s, string t) {
        int slen=s.length();
        int tlen=t.length();
        double* olddp=new double[slen+1];
        for(int i=0;i<=slen;++i)
        {
            olddp[i]=1;
        }
        double* newdp=new double[slen+1];
        for(int i=1;i<=tlen;++i)
        {
            newdp[0]=0;
            for(int j=1;j<=slen;++j)
            {
                int tmp=0;
                if(s[j-1]==t[i-1]) tmp=olddp[j-1];
                newdp[j]=newdp[j-1]+tmp;
            }
            double* swp=olddp;
            olddp=newdp;
            newdp=swp;
        }
        return olddp[slen];
    }
};
