/*
Description
There are n holes and n-1 tunnels connecting them. The holes are labeled by 1,2,...,n. For all i>1, a hole number i is connected by a tunnel to the hole number ⌊i/2⌋. Tunnels are all bidirectional.


Initially, all the tunnels are available. There will be m events happened in the tunnel system. The i-th event will change the status of the tunnel between u_i and ⌊u_i/2⌋. If this tunnel is available, it will become unavailable, and if this tunnel is unavailable, it will become available.


Please write a program to support these events, and report the number of pairs i,j(1 <= i < j <= n) that holes i,j are still connected after each event.
Input
The first line of the input contains an integer T(1 <= T <= 5), denoting the number of test cases.


In each test case, there are two integers n,m(2 <= n,m <= 100000) in the first line, denoting the number of holes and the number of events.


For the next m lines, each line contains an integer u_i(2 <= u_i <= n), denoting an event.
Output
For each test case, print m lines. The i-th line contains an integer, denoting the number of connected pairs after the i-th event.
Sample Input
1
9 6
6
4
2
4
4
3
Sample Output
28
13
7
13
7
5
HINT
*/
//https://acm.zcmu.edu.cn/JudgeOnline/problem.php?id=5075

