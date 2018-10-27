class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0;
        int j=0;
        int slen=s.length();
        int plen=p.length();
        while(i<slen&&j<plen)
        {
            if(p[j]>='a'&&p[j]<='z')
            {
                if(j+1<plen&&p[j+1]=='*')
                {
                    if(j+2>=plen)
                    {
                        while(s[i]==p[j])
                        {
                            i++;
                        }
                        j=j+2;
                    }
                    else
                    {
                        int k=0;
                        while(i+k<slen)
                        {
                            if(isMatch(s.substr(i+k,slen-i-k),p.substr(j+2,plen-j-2)))
                            {
                                bool ff=true;
                                for(int z=i;z<i+k;z++)
                                {
                                   if(s[z]!=p[j]){ff=false;break;}
                                }
                                if(ff) return true;
                            }
                            k++;
                        }
                        if(i+k==slen)
                        {
                            if (isMatch("",p.substr(j+2,plen-j-2)))
                            {
                                bool ff=true;
                                for(int z=i;z<i+k;z++)
                                {
                                   if(s[z]!=p[j]){ff=false;break;}
                                }
                                if(ff) return true;
                            }
                        }
                        return false;
                    }       

                }
                else
                {                
                    if(s[i]==p[j])
                    {
                        i++;
                        j++;
                    }
                    else return false;
                }        
            }
            else if(p[j]=='.')
            {
                if(j+1<plen&&p[j+1]=='*')
                {
                    int k=0;
                    while(i+k<slen)
                    {
                        if(isMatch(s.substr(i+k,slen-i-k),p.substr(j+2,plen-j-2))) return true;
                        k++;
                    }
                    if(i+k==slen)
                    {
                        if (isMatch("",p.substr(j+2,plen-j-2))) return true;
                    }
                    return false;
                }
                else{i++;j++;}
            }
        }
        if(i!=slen) return false;
        else if(j!=plen)
        {
            while(j<plen)
            {
                if(p[j]!='*')
                   {
                        if (j+1>=plen||p[j+1]!='*') return false;
                        else j=j+2;
                   }
                else j++;
            }
        }
        return true;
    }
};
