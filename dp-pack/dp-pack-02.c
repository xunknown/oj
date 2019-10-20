/*
 * 一、0/1背包问题
 * 问题描述：
 * 有n件物品和容量为m的背包 给出i件物品的重量以及价值 求解让装入背包的物品重量不超过背包容量 且价值最大 。
 * 特点:这是最简单的背包问题，特点是每个物品只有一件供你选择放还是不放。
 * https://www.jianshu.com/p/50af9094a2ac
 */
#include <stdio.h>

#define N 100
#define M 100
#define max(a,b) ((a) > (b) ? (a) : (b))

struct item_s {
	int w;
	int v;
};

static struct item_s items[N];
static int values[N + 1][M + 1];

int main (void)
{
	int m, n;
	if (scanf("%d %d", &m, &n) != 2) return 0;
	if (m > M || n > N) return 0;
	printf("%d %d\n", m, n);

	for (int i = 0; i < n; i++) {
		if (scanf("%d %d", &items[i].w, &items[i].v) != 2) break;
	}
	for (int i = 0; i < n; i++) {
		printf("%d: %d %d\n", i, items[i].w, items[i].v);
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		if (items[i].w <= m) {
			values[1][items[i].w] = max(values[1][items[i].w], items[i].v);
		}
		printf("%d:%d %d\n", 1, items[i].w, values[1][items[i].w]);
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		for (int j = m; j > 0; j--) {
			if (items[i - 1].w <= j) {
				values[i][j] = max(values[i - 1][j], values[i - 1][j - items[i - 1].w] + items[i - 1].v);
			} else {
				values[i][j] = values[i - 1][j];
			}
			printf("%d:%d %d\n", i, j, values[i][j]);
		}
	}
	printf("\n");
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			printf("%d:%d %d\n", i, j, values[i][j]);
		}
	}

	printf("\n");
	printf("%d\n", values[n][m]);
	return 0;
}
