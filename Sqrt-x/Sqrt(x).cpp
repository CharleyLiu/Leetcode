class Solution {
public:
    int mySqrt(int x) {
        if (x==0) return 0;
        if(x==1) return 1;
        int begin=1;
        int end=x;
        while(begin<end)
        {
            int mid=begin+(end-begin)/2;
            if(mid==x/mid) return mid;
            else if(mid>x/mid)
            {
                end=mid-1;
            }
            else begin=mid+1;
        }
        if(begin>x/begin) return begin-1;
        else return begin;
        
    }
};
