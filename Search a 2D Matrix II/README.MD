Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

https://leetcode.com/problems/search-a-2d-matrix-ii/

Binary search.cpp(lg(n!)) Runtime: 196 ms, faster than 15.33% of C++ online submissions for Search a 2D Matrix II.
Memory Usage: 12.9 MB, less than 86.67% of C++ online submissions for Search a 2D Matrix II.

IteratePrune(O(m+n)): Runtime: 64 ms, faster than 84.67% of C++ online submissions for Search a 2D Matrix II.
Memory Usage: 12.8 MB, less than 100.00% of C++ online submissions for Search a 2D Matrix II.
