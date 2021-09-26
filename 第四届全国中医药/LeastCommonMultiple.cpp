/*
Description
In arithmetic and number theory, the least common multiple of two integers a and b, usually denoted by LCM(a, b), is the smallest positive integer that is divisible by both a and b.


The LCM of more than two integers is also well-defined: it is the smallest positive integer that is divisible by each of them.


You are given $n$ positive integers a_1,a_2,...,a_n, please find the LCM of them.
Input
The first line of the input contains an integer T(1 ≤ T ≤ 10), denoting the number of test cases.

In each test case, there is one integer n(2 ≤ n ≤ 15) in the first line.

In the second line, there are n integers a_1,a_2,...,a_n(1 ≤ a_i ≤ 10^18).
Output
For each test case, print a single line containing an integer, denoting the LCM. Since the answer can
be extremely large, please print it modulo 10^9 + 7 instead.
Sample Input
3
2
4 6
3
7 8 9
2
1000000009 1000000009

Sample Output
12
504
2
*/

//https://acm.zcmu.edu.cn/JudgeOnline/problem.php?id=5071