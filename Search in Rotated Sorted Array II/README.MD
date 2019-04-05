Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?

https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

Runtime: 8 ms, faster than 99.57% of C++ online submissions for Search in Rotated Sorted Array II.
Memory Usage: 8.7 MB, less than 44.66% of C++ online submissions for Search in Rotated Sorted Array II.

For this algorithm, the complexity is m+log(n-m+1), where m is the number of duplicates.
I have an brief idea that we could virtual copy the array append the original array. e.g. 2560012=>25600122560012
and maybe this will help.
