#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100005;
char s[maxn];
long long cnt[26][26];	//cnt[0][1]	 bǰ��a�ĸ��� 
long long acc[26];	//acc[0] ��ǰǰ׺��'a'�ĸ��� 

int main(){
	scanf("%s",s);
	int len = strlen(s);
	for(int i=0;i<len;i++){
		int c = s[i]-'a';	//��iΪ�����ַ�c
		for(int j=0;j<26;j++)
			cnt[c][j] += acc[j];	//����cǰ������������ַ��ĸ��� 
		acc[c]++;	//����c��ǰ׺�������£� 
	}
	long long res = 0;
	for(int i=0;i<26;i++) //������ʱ 
		for(int j=0;j<26;j++)
			res = max(res,cnt[i][j]);
	for(int i=0;i<26;i++) //����һ����ʱ 
		res = max(res,acc[i]);
	printf("%lld\n",res);
	return 0;
}
