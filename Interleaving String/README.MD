Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false


https://leetcode.com/problems/interleaving-string/

Runtime: 4 ms, faster than 100.00% of C++ online submissions for Interleaving String.
Memory Usage: 8.6 MB, less than 62.03% of C++ online submissions for Interleaving String.

The above agrithom use a matrix to dynamic programming. Actually we only need two layers to handle this.
