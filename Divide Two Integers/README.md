Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.

https://leetcode.com/problems/divide-two-integers/

Divide Two Integers:Runtime: 12 ms, faster than 98.84% of C++ online submissions for Divide Two Integers.


Faster: Most of time consumption is for the IO, so the runtime for this question actually a little bit meaningless. I run two algrithoms in VS with 100000 runs for each, and the time cost of "Faster" is around 2/3 of "Divide Two Integers".
