/**
 * @author      : alpha (alpha@mascot)
 * @created     : Wednesday Oct 23, 2019 01:00:44 HKT
 * 一个字符串是非回文的，当且仅当，他只由前p个小写字母构成，而且他不包含长度大于等于2的回文子串。
 * 给出长度为n的非回文串s。请找出字典序比s大的，而且字典序要最小的长度为n的非回文。
 * https://blog.csdn.net/chenzhenyu123456/article/details/50131641
 * https://blog.csdn.net/qq_41289920/article/details/81047341
 */

#include <stdio.h>
#include <string.h>

#define MAX_N 1000
#define MAX_P 26

char *next(char str[], int len, int p)
{
	int i = len - 1;
	if (i < 0)
		return NULL;

	char nc = str[i] + 1;
	if (nc - 'a' < p) {
		str[i] = nc;
		return str;
	}
	if (nc - 'a' == p) {
		str[i] = 'a';
		return next(str, i, p);
	}
	return NULL;
}

int is_palindrome(char str[], int len)
{
	if (str[0] == str[1])
		return 1;
	for (int i = 2; i < len; i++) {
		if (str[i] == str[i - 1] || str[i] == str[i - 2])
			return 1;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int n, p;
	if (scanf("%d %d", &n, &p) != 2) {
		printf("NO\n");
		return 0;
	}
	printf("%d %d\n", n, p);

	if (n < 1 || n > MAX_N || p < 1 || p > MAX_P) {
		printf("NO\n");
		return 0;
	}

	char start[MAX_N + 1] = { 0 };
	if (scanf("%s", start) != 1) {
		printf("NO\n");
		return 0;
	}
	printf("%s\n\n", start);

	if (strlen(start) != n) {
		printf("NO\n");
		return 0;
	}

	while (next(start, n, p) != NULL) {
		printf("%s\n", start);
		if (!is_palindrome(start, n)) {
			printf("find: %s\n", start);
		}
	}

	printf("NO\n");
	return 0;
}
