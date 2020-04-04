#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int base=131;
int a[10010];
char s[10010];

int hashs(){
    int len=strlen(s);
    unsigned long long ans=0;
    for (int i=0;i<len;i++)
        ans=ans*base+s[i];
    return ans&0x7fffffff;	//直接抛弃溢出位 
}

int main(){
	int n;
	int res = 0;
    scanf("%d",&n);getchar();
    for (int i=0;i<n;i++){
        scanf("%s",s);
        a[i]=hashs();
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++)
        if(a[i]!=a[i-1])
            res++;
    printf("%d\n",res);
}
