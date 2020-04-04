#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100005;
char s[maxn];
long long cnt[26][26];	//cnt[0][1]	 b前面a的个数 
long long acc[26];	//acc[0] 当前前缀中'a'的个数 

int main(){
	scanf("%s",s);
	int len = strlen(s);
	for(int i=0;i<len;i++){
		int c = s[i]-'a';	//第i为数是字符c
		for(int j=0;j<26;j++)
			cnt[c][j] += acc[j];	//更新c前面的所有其他字符的个数 
		acc[c]++;	//更新c的前缀（最后更新） 
	}
	long long res = 0;
	for(int i=0;i<26;i++) //两个数时 
		for(int j=0;j<26;j++)
			res = max(res,cnt[i][j]);
	for(int i=0;i<26;i++) //单独一个数时 
		res = max(res,acc[i]);
	printf("%lld\n",res);
	return 0;
}
