/*
Description
在平面上有n个边平行坐标轴的正方形，编号依次为1,2,...,n，每个正方形都占据了若干个格子。第i个正方形的中心位于格子(x_i,y_i)，其半径为r_i，即它的左下角为格子(x_i-r_i,y_i-r_i)，右上角为格子(x_i+r_i,y_i+r_i)，共占据(2r_i+1)^2个格子。


定义正方形i和正方形j的距离为：从正方形i占据的格子中选择一个格子(x_1,y_1)，从正方形j占据的格子中选择一个格子(x_2,y_2)，使得这两个格子的曼哈顿距离|x_1-x_2|+|y_1-y_2|最小，此时这两个代表格子之间的曼哈顿距离被视为这两个正方形的距离。


请写一个程序，快速支持m次操作，操作有以下两种：
1 i x y r 将第i个正方形的中心改为(x,y)，半径改为r。
2 u v 询问如果在编号在[u,v]之间的所有正方形之中挑选两个编号不同的正方形，那么它们的距离的最小值是多少。
Input
第一行包含一个正整数T(1 <= T <= 3)，表示测试数据的组数。


每组测试数据第一行包含两个正整数n,m(2 <= n,m <= 100000)，分别表示正方形的数量以及操作的数量。


接下来n行，每行三个正整数x_i,y_i,r_i(1 <= x_i,y_i,r_i <= 10)，依次描述每个正方形。


接下来m行，每行描述一个操作，其中1 <= i <= n, 1 <= x,y,r <= 10, 1 <= u<v <= n。
Output
对于每个询问，输出一行一个整数，即距离的最小值。
Sample Input
1
5 5
9 3 1
2 9 1
1 2 1
8 7 1
3 7 1
2 4 5
1 2 5 6 1
2 2 4
1 3 9 5 1
2 2 4
Sample Output
3
1
0
*/

//https://acm.zcmu.edu.cn/JudgeOnline/problem.php?id=5073