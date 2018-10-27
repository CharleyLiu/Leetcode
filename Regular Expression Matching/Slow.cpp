class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        if (plen == 0) return slen == 0;
        bool first_match = (slen != 0) && (s[0] == p[0] || p[0] == '.');
        if (plen > 1 && p[1] == '*')
        {
            return (isMatch(s, p.substr(2, plen - 2)) || (first_match&&isMatch(s.substr(1, slen - 1), p)));
        }
        else
        {
            return first_match && isMatch(s.substr(1, slen - 1), p.substr(1, plen - 1));
        }
    }
};
