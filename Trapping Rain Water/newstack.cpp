class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int water=0;
        for(int i=0;i<height.size();++i)
        {
            if(st.empty()||height[st.top()]>height[i]) st.push(i);
            else
            {
                while(!st.empty()&&height[st.top()]<=height[i])
                {
                    int index=st.top();
                    st.pop();
                    if(st.empty()) break;
                    water+=(min(height[st.top()],height[i])-height[index])*(i-st.top()-1);
                }
                st.push(i);
            }
            
        }
        return water;
    }
};
