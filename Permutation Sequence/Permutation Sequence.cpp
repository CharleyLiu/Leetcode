class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        int* m=new int[n];
        bool f[10]={false};
        m[0]=1;
        int t;
        for(int i=1;i<n;++i) m[i]=i*m[i-1];
        for(int i=n-1;i>=0;--i)
        {
            int temp=k%m[i];
            if(k==0) t=i+1;
            else if(temp==0) t=max(k/m[i],1);
            else t=k/m[i]+1;
            int count=0;
            
            for(int j=1;j<=9;++j)
            {
                if(f[j]) continue;
                ++count;
                if(count==t){count=j;break;}
            }
            f[count]=true;
            ans=ans+to_string(count);
            k=temp;
        }
        return ans;
        
    }
};
