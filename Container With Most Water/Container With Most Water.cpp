class Solution {
public:

    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int s;
        int max=0;
        while(i!=j)
        {
            if(height[i]<height[j])
            {
                int area=height[i]*(j-i);
                max=(area>max)?area:max;
                i++;
            }
            else
            {
                int area=height[j]*(j-i);
                max=(area>max)?area:max;
                j--;
            }
        }
        return max;
        
    }
};
