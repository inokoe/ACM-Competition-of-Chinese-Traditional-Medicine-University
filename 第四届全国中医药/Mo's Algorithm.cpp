/*
Description
Mo's algorithm can solve some difficult data structure problems. Like this: You are given an array a_1,a_2,...,a_n and m queries. In each query, we want to get the mode number(the value that appears most often in a set of data) of subsequence a_l, a_{l + 1},...,a_r.


Maybe you want to solve it using segment tree or some other data structures. However, if you know the answer of [l, k] and [k + 1, r], you will find that it is very difficult to get the answer of [l, r].


Mo's algorithm is an offline algorithm that can solve this problem efficiently.


First, we need a data structure that can do these operations:
Insert a number.
Delete a number.
Get the mode number.
It can be solved easily by a binary heap or a balanced binary search tree. We call this data structure DS.


On the other hand, if we only keep a_l,a_{l+1},...,a_r in DS, we can transform to [l', r'] in |l-l'| + |r-r'| moves. So we need to find a good order to perform queries that the total number of moves is minimized.


It is very hard to find such excellent order. Mo's algorithm just gives an order that the total number of moves is O(m * sqrt{n}).


In this task, you are given the length of the sequence n and m queries q_1,q_2,...,q_m. Please write a program to rearrange these queries that cost(q_1,q_2)+cost(q_2,q_3)+...+cost(q_{m-1},q_m) is minimized, where cost([l,r],[l',r'])=|l-l'| + |r-r'|.
Input
The first line of the input contains an integer T(1 <= T <= 10), denoting the number of test cases.


In each test case, there are two integers n,m(1 <= n <= 100000, 2 <= m <= 10) in the first line, denoting the length of the sequence and the number of queries.


For the next m lines, each line contains two integers l_i and r_i (1 <= l_i <= r_i <= n), denoting a query.
Output
For each test case, print a single line containing an integer, denoting the minimum number of moves.
Sample Input
2
5 2
1 5
3 4
9 5
5 5
1 1
4 4
2 2
3 3
Sample Output
3
8
*/

//https://acm.zcmu.edu.cn/JudgeOnline/problem.php?id=5072