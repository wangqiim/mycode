#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 11000006;
char s[maxn];
int str[maxn*2],ans[maxn*2];
int n;

int build(){
    // 初始化
    int m = (n + 1) << 1, ret = 0;
    // $ - 串开始标记， @ - 串结束标记，# - 将字母间隔开。注意这里的字符必须是字符串内不存在的
    str[0] = '$'; str[m] = '@'; str[1] = '#'; ans[1] = 1;
    for (int i = 1; i <= n; i++) 
        str[i << 1] = s[i - 1], str[i << 1 | 1] = '#';
    // Manacher 操作。r, p 分别维护当前最靠右最长回文串的右边界与中心
    ans[1] = 1;
    for (int r = 0, p = 0, i = 2; i < m; ++i){
        if (r > i) ans[i] = min(r - i, ans[p * 2 - i]); else ans[i] = 1; // Manacher 核心操作
        while(str[i - ans[i]] == str[i + ans[i]]) ++ans[i]; // 暴力向外扩展
        if (i + ans[i] > r) r = i + ans[i], p = i; // 尝试更新 r, p
        ret = max(ret, ans[i] - 1); // 更新答案
    }
    return ret;
}

int main(){
	scanf("%s",s);
	n = strlen(s);
	printf("%d\n",build());
	return 0;
}
