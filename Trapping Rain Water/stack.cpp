class Solution {
public:
    int trap(vector<int>& height) {
        int len=height.size();
        int* st=new int[len];
        int i=0;
        int area=0;
        for(int j=0;j<len;++j)
        {
            if(i==0) st[i++]=j;
            else if(height[j]<=height[st[i-1]]) st[i++]=j;
            else
            {
                while(i>0&&height[st[i-1]]<height[j])
                {
                     int hi=st[i-1];
                    --i;
                    if(i==0) break;
                    int distance=j-st[i-1]-1;
                    int thi=min(height[st[i-1]],height[j]);
                    area+=distance*(thi-height[hi]);
                    
                }
                st[i++]=j;
            }
        }
        return area;
        
    }
};
