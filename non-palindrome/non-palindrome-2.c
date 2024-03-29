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

/*
 * 算法要点：
 * 回文判断：当前字符与前两个字符任一个相同，则构成回文，即s[i] == s[i-1] 或者 s[i] == s[i - 2]
 * 第1步：从最后一个字符开始逆序找出第一个小于上限的字符：即从最后一个字符往前搜索，找出第一个s[i] - 'a' + 1 < p的字符。
 * 第2步：该字符从当前值(不是从'a')开始依次加1，直至上限。注：每个位置的字符变化的范围都是从‘a’到‘a’ + p - 1，含上下限；
 * 第3步：该字符每修改一次，就与前两个字符比较，检查是否构成回文，构成回文则继续修改（不保存修改值），
 * 不构成回文则结束修改，并将当前位置的字符改为修改后的字符（找到合适的字符）。
 * 第4步：如果当前位置不能找到合适的字符，则当前位置字符不变，并前移一个位置，重复1~3步骤。
 * 如果直到第2个位置的字符，都无法找到合适的字符，则不存在符合要求的非回文子串，查找结束。
 * 第5步：如果第3步找到合适的字符，如果该位置已经是字符串的最后一个位置，则当前字符串就是满足要求的非回文子串。
 * 第6步：如果第3步的字符的位置不是字符串最一个位置，则从该位置的下一个位置开始直至字符串最后一个位置，
 * 从前往后，每个位置的字符从'a'（不是从'当前值'开始）到'a' + p -1逐步修改，修改之后检查是否构成回文。
 * 如果构成回文则不保存该字符并继续查找，一旦找到一个不构成回文的字符则保存并结束当前位置查找，下一个位置继续这一过程。
 * 第6步结束之后，当前字符串即是满足要求的字符串（第6步可能没有修改字符串）。
 * 这里隐含一个非常重要的规律：
 * 以第3步确定的位置i为分界，如果字符串前一部分（从0～i）不包含回文，
 * 则后一部分（从i + 1～n）一定可以找到一个不含回文的子串，因此第6步只需关心后一部分的变化。
 */
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
