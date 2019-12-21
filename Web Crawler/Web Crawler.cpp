/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        int start=startUrl.find('/');
        int end=startUrl.find('/',start+2);
        string host=startUrl.substr(0,end);
        vector<string> ans={};
        unordered_set<string> visited={};
        visited.insert(startUrl);
        queue<string> q;
        q.push(startUrl);
        while(!q.empty())
        {
            string s=q.front();
            q.pop();
            start=s.find('/');
            end=s.find('/',start+2);
            string h=s.substr(0,end);
            if(h==host) 
            {
                ans.push_back(s);
                vector<string> craw=htmlParser.getUrls(s);
                for(string& link:craw){
                    if(visited.find(link)==visited.end()){
                        visited.insert(link);
                        q.push(link);
                    }
                }
            }
        }
        return ans;
    }
};
