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

#define MAXN 1005

char str[MAXN];

int main() {
	int n, p;
	scanf("%d%d%s", &n, &p, str + 1);
	for (int i = n; i >= 1; i--) {
		int x = str[i] - 'a';
		if (x < p - 1) {
			int y = -1;
			for (int j = x + 1; j < p; j++) {
				char c = 'a' + j;
				if (i > 1 && c == str[i - 1]) continue;
				if (i > 2 && c == str[i - 2]) continue;
				y = j;
				break;
			}
			if (y == -1) continue;
			str[i] = 'a' + y;
			//printf("%d : %c\n", i, 'a' + y);
			if (i == n) {
				puts(str + 1);
				return 0;
			}
			for (int j = i + 1; j <= n; j++) {
				for (int k = 0; k < p; k++) {
					char c = 'a' + k;
					if (j > 1 && c == str[j - 1]) continue;
					if (j > 2 && c == str[j - 2]) continue;
					str[j] = c;
					break;
				}
			}
			puts(str + 1);
			return 0;
		}
	}
	puts("NO");
	return 0;
}
