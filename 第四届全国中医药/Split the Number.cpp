/*
Description
There is an infinite integer sequence f_1,f_2,f_3,..., where f_1=1,f_2=2,f_i=f_{i-1}+f_{i-2}(i >= 3).


You are given two positive integers n and k, your task is to check whether n can be split into k integers a_1,a_2,...,a_k, where a_1,a_2,...,a_k∈f and a_1+a_2+...+a_k=n. Note that you can split n into same integers, for example, 10=5+5=f_4+f_4.
Input
The first line of the input contains an integer T(1 <= T <= 100000), denoting the number of test cases.


In each test case, there is one integer n(1 <= n,k <= 10^{18}) in the first line.
Output
For each test case, print a single line. If it is possible to split n into k integers, print Yes, otherwise print No.
Sample Input
4
10 1
10 2
5 1
12 2
Sample Output
No
Yes
Yes
No
*/

//https://acm.zcmu.edu.cn/JudgeOnline/problem.php?id=5074