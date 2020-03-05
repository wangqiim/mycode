#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1000;

struct node{
	int no;
	int t;
}nums[maxn];

bool cmp(node a,node b){
	if(a.t!=b.t)
		return a.t<b.t;
	else return a.no<b.no;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&nums[i].t);
		nums[i].no = i+1;
	}
	sort(nums,nums+n,cmp);
	double res=0;
	for(int i=0;i<n;i++){
		res+=nums[i].t*(n-i-1);	//自己开始接水以后的打水时间不算等待时间 
		if(i!=n-1){
			printf("%d ",nums[i].no);
		}
		else
			printf("%d\n",nums[i].no);
	}
	printf("%.2f",res/n);
	return 0;
}
