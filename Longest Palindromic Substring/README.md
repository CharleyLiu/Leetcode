Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"

Output: "bb"

https://leetcode.com/problems/longest-palindromic-substring/

Normal Solution(O(n^2)): Runtime: 460 ms, faster than 9.20% of C++ online submissions for Longest Palindromic Substring.

Manacher's Algorithm(O(n)): Runtime: 4 ms, faster than 99.67% of C++ online submissions for Longest Palindromic Substring.

Generate from mid(O(n^2)time O(1)space): Runtime: 16 ms, faster than 84.92% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 8.6 MB, less than 97.93% of C++ online submissions for Longest Palindromic Substring.
