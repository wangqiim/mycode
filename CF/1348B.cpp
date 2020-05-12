#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 102;
int cnt[maxn];
int nums[maxn];
int ans[10004];
int n,k;

int main(){
	int t,n,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		vector<int> temp;
		memset(cnt,0,sizeof(cnt));
		int a;
		int diff = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			if(cnt[a]==0){
				temp.push_back(a);
				diff++;
			}
			cnt[a]++;
		}
		if(diff > k)
			puts("-1");
		else{
			while(diff<k){
				temp.push_back(1);
				diff++;
			}
			int nn = temp.size();
			int index = 0;
			for(int i=0;i<n;i++)
				for(int j=0;j<nn;j++)
					ans[index++] = temp[j];
			printf("%d\n",nn*n);
			for(int i=0;i<nn*n;i++)
				printf("%d ",ans[i]);
			puts("");
		}
	}

	return 0;
}
