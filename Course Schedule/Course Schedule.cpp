class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0) return true;
        vector<vector<int>> mapper(numCourses);
        vector<int> indeg(numCourses,0);
        for(vector<int>& pair:prerequisites)
        {
            mapper[pair[1]].push_back(pair[0]);
            ++indeg[pair[0]];
        }
        queue<int> q;
        int course=-1;
        int count=0;
        for(int i=0;i<numCourses;++i)
        {
            if(indeg[i]==0)
            {
                q.push(i);
                ++count;
            }
        }
        if(q.size()==0) return false;
        while(!q.empty())
        {
            course=q.front();
            q.pop();
            for(int& next:mapper[course])
            {
                if(indeg[next]==1)
                {
                    q.push(next);
                    ++count;
                    indeg[next]=0;
                }
                else --indeg[next];
            }
        }
        if(count==numCourses) return true;
        else return false;
    }
};
