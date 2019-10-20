/*
 * 题目：
 * 如图一个数塔，从顶部出发在每一个节点可以选择向左或者向右走，一直走到最底层，找出一条路径，使得路径上的数字之和最大.
 *		7
 *	      3   8
 *	    8   1   0
 *	  2   7   4   4
 *	4   5   2   6   5
 * https://blog.csdn.net/sinat_38052999/article/details/68938618
 * https://blog.csdn.net/theonegis/article/details/45801201
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
