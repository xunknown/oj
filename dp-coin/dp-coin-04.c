/*
 * 题目：
 * 给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。
 * 假设每一种面额的硬币数量无限制。
 * https://leetcode-cn.com/problems/coin-change-2/
 */

#include <stdio.h>
#define M 100
#define N 10

static int amount[M];
static int coins[N];

int main (void)
{
	int m, n;
	if (scanf("%d %d", &m, &n) != 2) return 0;
	if (m < 1 || m > M || n < 1 || n > N) return 0;
	printf("%d %d\n", m, n);
	for (int i = 0; i < n; i++) {
		if (scanf("%d", &coins[i]) != 1) break;
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", coins[i]);
	}
	amount[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= m; j++) {
			amount[j] = amount[j] + amount[j - coins[i]];
		}
	}
	printf("%d\n", amount[m]);
}
