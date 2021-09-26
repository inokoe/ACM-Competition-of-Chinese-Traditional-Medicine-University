/*
Description
DongDong is playing a tower defense game. In this game, we have two kinds of resource: money and wood. At the beginning of the game, DongDong possesses G money and no wood. Before the first round DongDong can use this money, and he can get money only by defeating the monsters. There is only one monster in each round, and DongDong can get money when the monster is dead. Meanwhile, DongDong can use this money in the current round. DongDong will lose the game when his hardiness is lower than the monster’s attacking value, otherwise he will kill the monster. The money can increase the hardiness that one unit money can increase one unit hardiness. In addition, DongDong’s initial hardiness is 0. Furthermore, the money can also increase the efficiency of lumbering. The efficiency of lumbering means the number of wood that every worker can collect at each round. The initial efficiency of lumbering is W. If DongDong trains a worker in the current round, then the worker will start working in the following rounds. DongDong will pay F money to increase one unit efficiency of lumbering or train one worker. Also, DongDong have no workers in the initial time. Only workers can lumber. Because the wood is very precious, DongDong wants to know how much wood he can get at most after N rounds?

Input
The first line contains a positive integer T which means T test cases.

The first line of each test case contains 4 positive integers N, F, W, G(1<= N <= 1000, 1<= F, W <= 10000, 1<= G <= 1000000), which means N rounds, the cost of training a worker or increasing one unit efficiency of lumbering F, the initial efficiency of lumbering W, the initial money G, respectively. Then following N lines, each line contains two positive integers Ai, Gi, Ai means the attacking value of monsters, Gi means the money that DongDong can get after he kills the monster.

Output
For each case, if DongDong cannot finish N round game, please output “It's useless to collect wood.” (without quotes), otherwise print the most units of wood that DongDong can get.

Sample Input
3
5 1 1 1
1 1
1 1
1 1
1 1
1 1
4 10 7 100
1 1
2 2
3 3
100000 4
3 10 7 10
10 10
10 10
20 10
Sample Output
13
It's useless to collect wood.
14
*/