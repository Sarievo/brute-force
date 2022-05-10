CF 718 A https://codeforces.com/contest/710/problem/A

>![chess board](https://espresso.codeforces.com/96da823b1b13b6cb4a868e77d380e136b9b34eb5.png)
>
>Image from Codeforces


Generator - A 2-character random string range from a1~h8

Brute-force solution - The brute-force solution for this problem is kinda funny, instead of directly calculate the available moves from the giving position, we may instead want to iterate them from a simulated board and count their available moves (still O(1) time but with an additional for-loop), and it may also pass the time limit because the input is limited. Nevertheless, if we have two or more answer of different complexity we can check them against each other.

Checker - No changes about the checker