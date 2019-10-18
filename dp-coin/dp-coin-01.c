#include <stdio.h>

#define M 100
#define N 10
#define min(a, b) ((a) < (b) ? (a) : (b))

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
	amount[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= m; j++) {
			amount[j] = min(amount[j], amount[j - coins[i]]) + 1;
		}
	}
	printf("%d\n", amount[m]);
}
