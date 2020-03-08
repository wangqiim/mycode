#include<cstdio>
#include<stack>
using namespace std;

const int maxn = 3000006;
stack<int> s;
int nums[maxn];
int res[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&nums[i]);
	for(int i=n-1;i>=0;i--){
		while(!s.empty()&&nums[s.top()]<=nums[i]){
			s.pop();
		}
		res[i] = (s.empty()?0:s.top()+1);
		s.push(i);
	}
	for(int i=0;i<n;i++){
		printf("%d ",res[i]);
	}
	return 0;
}

/*// not good!
#include<cstdio>

const int maxn = 3000006;
int nums[maxn];
int res[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&nums[i]);
	nums[0] = 0x7fffffff;
	res[n] = 0;
	for(int i=n-1;i>=1;i--){
		int t = i+1;
		while(nums[t]<=nums[i]) t=res[t];
		res[i] = t;
	}
	for(int i=1;i<=n;i++){
		printf("%d ",res[i]);
	}
	return 0;
}*/
