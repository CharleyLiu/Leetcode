class Solution {
public:
    bool isPalindrome(string s) {
        int front=0;
        int end=s.length()-1;
        while(front<end)
        {
            while(front<end&&!isalnum(s[front])) ++front;
            while(front<end&&!isalnum(s[end])) --end;
            if(tolower(s[front])==tolower(s[end]))
            {
                ++front;
                --end;
            }
            else return false;
        }
        return true;
        
    }
};
