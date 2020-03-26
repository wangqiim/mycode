#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 1000006;
char str[maxn];	//Æ¥Åä´® 
char pat[maxn];		//Ä£Ê½´® 
int  next[maxn]={0};

int main(){
	scanf("%s",str);
	scanf("%s",pat);
	int m = strlen(str);
	int n = strlen(pat);
	for(int i=1,j=0;i<n;i++){
		while(pat[i]!=pat[j] && j!=0)
			j = next[j];
		if(pat[i] == pat[j])
			next[i+1] = ++j;
	}
	for(int i=0,j=0;i<m;i++){
		while(str[i]!=pat[j] && j!=0)
			j = next[j];
		if(str[i]==pat[j])
			j++;
		if(j==n){
			printf("%d\n",i-n+2);
			j = next[j];
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",next[i]);
	return 0;
}
