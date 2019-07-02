class Solution {
private:
    void flood(vector<vector<int>>& image, int sr,int sc, int& newColor,int& oriColor)
    {
        image[sr][sc]=newColor;
        if(sr-1>=0&&image[sr-1][sc]==oriColor) flood(image,sr-1,sc,newColor,oriColor);
        if(sr+1<image.size()&&image[sr+1][sc]==oriColor) flood(image,sr+1,sc,newColor,oriColor);
        if(sc-1>=0&&image[sr][sc-1]==oriColor) flood(image,sr,sc-1,newColor,oriColor);
        if(sc+1<image[0].size()&&image[sr][sc+1]==oriColor) flood(image,sr,sc+1,newColor,oriColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oriColor=image[sr][sc];
        if(oriColor==newColor) return image;
        flood(image,sr,sc,newColor,oriColor);
        return image;
    }
};
