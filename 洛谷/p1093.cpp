#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 300;
struct student{
	int no;
	int ch;
	int mt;
	int en;
	int s;
}st[maxn];

bool cmp(student a,student b){
	if(a.s!=b.s)
		return a.s>b.s;
	if(a.ch!=b.ch)
		return a.ch>b.ch;
	return a.no<b.no;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&st[i].ch,&st[i].mt,&st[i].en);
		st[i].no = i+1;
		st[i].s = st[i].ch+st[i].mt+st[i].en;
	}
	sort(st,st+n,cmp);
	for(int i=0;i<n&&i<5;i++)
		printf("%d %d\n",st[i].no,st[i].s);
	return 0;
}
