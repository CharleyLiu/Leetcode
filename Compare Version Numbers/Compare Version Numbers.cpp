class Solution {
public:
    int compareVersion(string version1, string version2) {
        int beg1,beg2,end1,end2;
        beg1=beg2=0;
        end1=version1.find(".",beg1);
        end2=version2.find(".",beg2);
        int num1,num2;
        while(end1!=string::npos&&end2!=string::npos)
        {
            num1=atoi(version1.substr(beg1,end1-beg1).c_str());
            num2=atoi(version2.substr(beg2,end2-beg2).c_str());
            if(num1>num2) return 1;
            if(num1<num2) return -1;
            beg1=end1+1;
            beg2=end2+1;
            end1=version1.find(".",beg1);
            end2=version2.find(".",beg2);
        }
        num1=atoi(version1.substr(beg1,end1-beg1).c_str());
        num2=atoi(version2.substr(beg2,end2-beg2).c_str());
        if(num1>num2) return 1;
        if(num1<num2) return -1;
        if(end1==string::npos&&end2==string::npos) return 0;
        if(end1==string::npos)
        {
            while(end2!=string::npos)
            {
                beg2=end2+1;
                end2=version2.find(".",beg2);
                if(atoi(version2.substr(beg2,end2-beg2).c_str())!=0) return -1;
            }
            return 0;

        }
        while(end1!=string::npos)
        {
            beg1=end1+1;
            end1=version1.find(".",beg1);
            if(atoi(version1.substr(beg1,end1-beg1).c_str())!=0) return 1;
        }
        return 0;

    }
};
