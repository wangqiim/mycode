#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 11000006;
char s[maxn];
int str[maxn*2],ans[maxn*2];
int n;

int build(){
    // ��ʼ��
    int m = (n + 1) << 1, ret = 0;
    // $ - ����ʼ��ǣ� @ - ��������ǣ�# - ����ĸ�������ע��������ַ��������ַ����ڲ����ڵ�
    str[0] = '$'; str[m] = '@'; str[1] = '#'; ans[1] = 1;
    for (int i = 1; i <= n; i++) 
        str[i << 1] = s[i - 1], str[i << 1 | 1] = '#';
    // Manacher ������r, p �ֱ�ά����ǰ�������Ĵ����ұ߽�������
    ans[1] = 1;
    for (int r = 0, p = 0, i = 2; i < m; ++i){
        if (r > i) ans[i] = min(r - i, ans[p * 2 - i]); else ans[i] = 1; // Manacher ���Ĳ���
        while(str[i - ans[i]] == str[i + ans[i]]) ++ans[i]; // ����������չ
        if (i + ans[i] > r) r = i + ans[i], p = i; // ���Ը��� r, p
        ret = max(ret, ans[i] - 1); // ���´�
    }
    return ret;
}

int main(){
	scanf("%s",s);
	n = strlen(s);
	printf("%d\n",build());
	return 0;
}
