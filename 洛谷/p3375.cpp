#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 1000006;
char str[maxn];	//匹配串 
char pat[maxn];		//模式串 
int  next[maxn]={0};

/*
//https://wnjxyk.tech/416.html来自wnjxyk的kmp模版 
namespace KMP{
    vector<int> next;

    void build(const string &pattern){
        int n = pattern.length();
        next.resize(n + 1);
        for (int i = 0, j = next[0] = -1; i < n; next[++i] = ++j){
            while(~j && pattern[j] != pattern[i]) j = next[j];
        }
    }

    vector<int> match(const string &pattern, const string &text){
        vector<int> res;
        int n = pattern.length(), m = text.length();
        build(pattern);
        for (int i = 0, j = 0; i < m; ++i){
            while(j > 0 && text[i] != pattern[j]) j = next[j];
            if (text[i] == pattern[j]) ++j;
            if (j == n) res.push_back(i - n + 1), j = next[j];
        }
        return res;
    }
};
*/

int main(){
	scanf("%s",str);
	scanf("%s",pat);
	int m = strlen(str);
	int n = strlen(pat);
	
	next[0] = next[1] = 0;
	for(int i=1,j=0;i<n;i++){
		while(pat[i]!=pat[j] && j!=0)
			j = next[j];
		if(pat[i] == pat[j])
			++j;
		next[i+1] = j;
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
