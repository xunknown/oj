/*
 * =====================================================================================
 *
 *       Filename:  pack-01.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Sunday, October 06, 2019 02:28:13 HKT
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
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
