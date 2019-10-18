/**
 * @author      : alpha (alpha@mascot)
 * @file        : dp-triangle-path
 * @created     : Wednesday Oct 16, 2019 01:31:39 HKT
 */

#include <stdio.h>

#define MAX_LEVEL 100
#define max(a, b) ((a) > (b) ? (a) : (b))

int main(int argc, char *argv[])
{
	int data[MAX_LEVEL][MAX_LEVEL] = { 0 };
	int level;
	if (scanf("%d", &level) != 1) {
		return 0;
	}
	if (level > MAX_LEVEL || level < 1) {
		return 0;
	}
	for (int i = 1; i <= level; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &data[i][j]);
		}
	}
	for (int i = level - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			data[i][j] += max(data[i + 1][j], data[i + 1][j + 1]);
		}
	}
	printf("%d\n", data[1][1]);
}
