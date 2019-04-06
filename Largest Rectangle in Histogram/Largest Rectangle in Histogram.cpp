class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0) return 0;
        int len=heights.size();
        int* stack=new int[len];
        int i=0;
        int j=1;
        int area=0;
        stack[0]=0;
        while(j<len){
        while(i>=0&&heights[stack[i]]>heights[j])
            {
                int h=heights[stack[i--]];
                int w=i>=0?j-stack[i]-1:j;
                area=max(area,w*h);
            }
            stack[++i]=j++;
        }
        while(i>=0)
        {
            int h=heights[stack[i--]];
            int w=i>=0?j-stack[i]-1:j;
            area=max(area,w*h);
        }
        return area;
    }
};
