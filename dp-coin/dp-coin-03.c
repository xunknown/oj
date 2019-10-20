/*
 * 题目：
 * 给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。
 * 假设每一种面额的硬币有k个。
 */

#include <stdio.h>
#define M 100
#define N 10

static int amount[M];
static int coins[N];
static int counts[N];

int main (void)
{
	int m, n;
	if (scanf("%d %d", &m, &n) != 2) return 0;
	if (m < 1 || m > M || n < 1 || n > N) return 0;
	printf("%d %d\n", m, n);
	for (int i = 0; i < n; i++) {
		if (scanf("%d %d", &coins[i], &counts[i]) != 2) break;
	}
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", coins[i], counts[i]);
	}
	amount[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = m; j >= coins[i]; j--) {
			for (int k = 1; k <= counts[i]; k++) {
				if (j < k * coins[i])
					break;
				amount[j] = amount[j] + amount[j - k * coins[i]];
			}
		}
	}
	printf("%d\n", amount[m]);
}
