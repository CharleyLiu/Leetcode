Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:

As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
Example 2:

Input: S = "babgbag", T = "bag"
Output: 5
Explanation:

As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
    
https://leetcode.com/problems/distinct-subsequences/

Runtime: 8 ms, faster than 88.40% of C++ online submissions for Distinct Subsequences.
Memory Usage: 14.3 MB, less than 46.62% of C++ online submissions for Distinct Subsequences.

O1space.cpp:

Runtime: 8 ms, faster than 88.40% of C++ online submissions for Distinct Subsequences.
Memory Usage: 9 MB, less than 75.03% of C++ online submissions for Distinct Subsequences.
