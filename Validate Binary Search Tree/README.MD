Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
   
   
   https://leetcode.com/problems/recover-binary-search-tree/


My algorithm is correct but the implementation based on C++ is a little bit hard.
Because in C++, infinite number is represented by INT_MAX, so if there exist INT_MAX or INT_MIN in the BST, this implementation
can't get the correct answer.
Adding some bool flag to indicate whether we have met INT_MAX & INT_MIN before will remedy that.
