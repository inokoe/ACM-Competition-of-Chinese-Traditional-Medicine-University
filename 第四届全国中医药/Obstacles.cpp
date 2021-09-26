/*
题目描述
There are n * m cells on the grid, the left-top cell is at (1,1) while the right-bottom cell is at (n,m).


Alice is standing at (1,1), her goal is to reach (n,m). When she is at cell (x,y), she can next move to (x-1,y), (x+1,y), (x,y-1) or (x,y+1). She can't move outside the grid, and she can't move to any cell with obstacles.


Bob wants to prevent Alice from reaching (n,m). He is now at a shop selling obstacles. There are k types of obstacles. For the i-th type, he can pay w_i dollars to make all the cells (x,y) that xl_i <= x <= xr_i and yl_i <= y <= yr_i filled with obstacles.


Bob doesn't know how to choose these obstacles. Please write a program to help him find the cheapest way that Alice can't reach (n,m) from (1,1), or determine it is impossible.
输入
The first line of the input contains an integer T(1 <= T <= 10), denoting the number of test cases.


In each test case, there are three integers n,m,k(2 <= n,m <= 10^9, 1 <= k <= 2000) in the first line, denoting the size of the grid and the number of types.


For the next k lines, each line contains five integers xl_i,xr_i,yl_i,yr_i,w_i (1 <= xl_i <= xr_i <= n, 1 <= yl_i <= yr_i <= m, 1 <= w_i <= 10^9), denoting a type. It is guaranteed that no obstacle will cover (1,1) or (n,m).
输出
For each test case, print a single line containing an integer, denoting the minimum number of dollars that Bob needs to pay for. If there is no solution, please print -1 instead.
样例输入 Copy
2
5 6 4
2 5 1 2 7
1 4 4 6 8
2 2 3 3 6
3 3 3 3 5
10000 10000 1
100 100 100 100 1
样例输出 Copy
20
-1
*/

//http://202.196.1.136/problem.php?id=2145