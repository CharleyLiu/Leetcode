Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
https://leetcode.com/problems/combinations/
Bad.cpp:Runtime: 1060 ms, faster than 5.33% of C++ online submissions for Combinations.
Memory Usage: 415.4 MB, less than 5.30% of C++ online submissions for Combinations.

Most of memory and runtime comsuption is for vector operation, it could be faster if use new int array.
This algorithm is a naive DP solution, with exponential complexity.

Naivebacktracking.cpp:
Runtime: 712 ms, faster than 5.33% of C++ online submissions for Combinations.
Memory Usage: 191.2 MB, less than 5.30% of C++ online submissions for Combinations.
This algorithm save some time on pass vector by value.

