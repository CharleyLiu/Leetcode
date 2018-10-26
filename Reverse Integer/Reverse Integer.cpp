class Solution {
public:
    int reverse(int x) {//2^31=2187483648
        int a[32]={0};
        int min=-pow(2,31);
        int max=pow(2,31)-1;
        max=max/10;
        int ans=0;
        if(x==min) return 0;
        int temp;
        bool f=false;
        if(x<0) {f=true;x=-x;}
        a[0]=x%10;
        int i=1;
        int r=x/pow(10,i);
        while(r!=0)//i:number of digits.
        {
            a[i++]=r%10;
            r=x/pow(10,i);
        }
        for(int j=0;j<i;j++)
        {
            if(ans>max) return 0;
            else if(ans==max){if (a[j]>7) return 0;}
            temp=ans*10+a[j];
            ans=temp;
        }
        if(f) ans=-ans;
        return ans;
    }
};
