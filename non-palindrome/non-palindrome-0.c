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

int len;
int n,p;
char s[1000+5],ss[1000+5];//s复制到ss，对s做修改
int bk[1000+5];
int ok() {
	if(s[0]==s[1]) return 0;
	for(int i = 2; i<len; i++) {
		if(s[i]==s[i-1]||s[i]==s[i-2]) return 0;
	}
	if(strcmp(ss,s)==0) return 0;
	return 1;
}
int dfs(int step) {
	if(step>n) return 0;
	if(step==n) {
		if(ok() ) {
			printf("%s\n",s);
			return 1;
		}
		return 0;
	}
	char i;
	bk[step]==1 ? (i='a') : (i=ss[step]);
	bk[step]=1;
	for(; i<=96+p; i++) {
		if(step>=2) {
			if(i==s[step-1]||i==s[step-2]) continue;
		}
		else if(step==1) if(i==s[step-1]) continue;
		s[step]=i;//还是直接放在for下面也无所谓？
		if(dfs(step+1) ) return 1;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&p);
	scanf("%s",s);
	strcpy(ss,s);
	len=strlen(s);
	if(!dfs(0) ) {
		printf("NO\n");
	}
	return 0 ;
}
