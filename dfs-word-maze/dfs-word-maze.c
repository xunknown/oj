/**
 * 在一个字符矩阵中找到出指定的字符串，只能上下左右查找。
 * @author      : alpha (alpha@mascot)
 * @created     : Tuesday Oct 22, 2019 00:07:08 HKT
 */

#include <stdio.h>
#include <string.h>

#define MAX_N 21
#define MAX_M 21
#define MAX_W 100

static char word[MAX_W + 1] = { 0  };
static char maze[MAX_N][MAX_M + 1] = { 0 };
static int  flag[MAX_N][MAX_M] = { 0 };

static int real_w = 0;
static int real_n = 0;
static int real_m = 0;

/*
 * 从指定位置i,j开始查找指定第k个字符
 * 找到返回1，否则返回0
 */
int dfs(int i, int j, int k)
{
	/* 超出范围 */
	if (i < 0 || i >= real_n || j < 0 || j >= real_m){
		return 0;
	}

	/* 已经完成 */
	if (k >= real_w) {
		return 1;
	}

	/* 查找左边 */
	if ((j > 0) && (flag[i][j - 1] == 0) && (maze[i][j - 1] == word[k])) {
		flag[i][j - 1] = 1;
		if (dfs(i, j - 1, k + 1)) {
			return 1;
		}
		flag[i][j - 1] = 0;
	}
	/* 查找右边 */
	if ((j < real_m - 1) && (flag[i][j + 1] == 0) && (maze[i][j + 1] == word[k])) {
		flag[i][j + 1] = 1;
		if (dfs(i, j + 1, k + 1)) {
			return 1;
		}
		flag[i][j + 1] = 0;
	}
	/* 查找上边 */
	if ((i > 0) && (flag[i - 1][j] == 0) && (maze[i - 1][j] == word[k])) {
		flag[i - 1][j] = 1;
		if (dfs(i - 1, j, k + 1)) {
			return 1;
		}
		flag[i - 1][j] = 0;
	}
	/* 查找下边 */
	if ((i < real_n - 1) && (flag[i + 1][j] == 0) && (maze[i + 1][j] == word[k])) {
		flag[i + 1][j] = 1;
		if (dfs(i + 1, j, k + 1)) {
			return 1;
		}
		flag[i + 1][j] = 0;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	if (scanf("%d %d\n", &real_n, &real_m) != 2) {
		printf("NO\n");
		return 0;
	}
	printf("%d %d\n", real_n, real_m);

	if (fgets(word, MAX_W, stdin) == NULL) {
		printf("NO\n");
		return 0;
	}
	printf("%s", word);
	size_t wl = strlen(word);
	if ((wl > 0) && (word[wl - 1] == '\n')) {
		wl--;
	}
	real_w = wl;

	for (int i = 0; i < real_n; i++) {
		if (fgets(maze[i], MAX_M, stdin) == NULL) {
			printf("NO\n");
			return 0;
		}
		if (strlen(maze[i]) < (size_t)real_m) {
			printf("NO\n");
			return 0;
		}
	}
	for (int i = 0; i < real_n; i++) printf("%s", maze[i]);

	for (int i = 0; i < real_n; i++) {
		for (int j = 0; j < real_m; j++) {
			if ((flag[i][j] == 0) && (maze[i][j] == word[0])) {
				flag[i][j] = 1;
				if (dfs(i, j, 1)) {
					printf("YES:%d,%d\n", i, j);
					return 1;
				}
				flag[i][j] = 0;
			}
		}
	}

	printf("NO\n");
	return 0;
}
