/*
 * 三、多重背包问题
 * 问题描述：
 * 有n件物品和容量为m的背包 给出i件物品的重量以及价值 还有数量 求解让装入背包的物品重量不超过背包容量 且价值最大 。
 * 特点 ：它与完全背包有类似点 特点是每个物品都有了一定的数量。
 * https://www.jianshu.com/p/50af9094a2ac
 */
#include <stdio.h>

#define N 100
#define M 100
#define max(a,b) ((a) > (b) ? (a) : (b))

struct item_s {
	int w;
	int v;
	int c;
};

static struct item_s items[N];
static int values[M + 1];

int main (void)
{
	int m, n;
	if (scanf("%d %d", &m, &n) != 2) return 0;
	if (m > M || n > N) return 0;
	printf("%d %d\n", m, n);

	for (int i = 0; i < n; i++) {
		if (scanf("%d %d %d", &items[i].w, &items[i].v, &items[i].c) != 3) break;
	}
	for (int i = 0; i < n; i++) {
		printf("%d: %d %d %d\n", i, items[i].w, items[i].v, items[i].c);
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		for (int j = m; j >= items[i].w; j--) {
			for (int k = 0; k <= items[i].c; k++) {
				int w = k * items[i].w;
				if (j < w) break;
				int v = k * items[i].v;
				values[j] = max(values[j], values[j - w] + v);
				printf("%d: %d\n", j, values[j]);
			}
		}
	}
	printf("\n");

	printf("%d\n", values[m]);
	return 0;
}
