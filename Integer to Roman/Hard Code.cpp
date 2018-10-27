class Solution {
public:
    string intToRoman(int num) {
        string s="";
        int x=num;
        while(x>=1000)
        {
            s=s+'M';
            x-=1000;
        }
        if(x>=900)
        {
            s=s+"CM";
            x-=900;
        }
        if(x>=500)
        {
            s=s+'D';
            x-=500;
        }
        if(x>=400)
        {
            s=s+"CD";
            x-=400;
        }
        while(x>=100)
        {
            s=s+'C';
            x-=100;
        }
        if(x>=90)
        {
            s=s+"XC";
            x-=90;
        }
        if(x>=50)
        {
            s=s+'L';
            x-=50;
        }
        if(x>=40)
        {
            s=s+"XL";
            x-=40;
        }
        while(x>=10)
        {
            s=s+'X';
            x-=10;
        }
        if(x==9)
        {
            s=s+"IX";
            return s;
        }
        if(x>=5)
        {
            s=s+'V';
            x-=5;
        }
        if(x==4)
        {
            s=s+"IV";
            return s;
        }
        while(x>0)
        {
            s=s+'I';
            x--;
        }
        return s;
        
    }
};
