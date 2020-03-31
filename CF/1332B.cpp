#include<cstdio>
#include<vector>
using namespace std;

const int maxn = 1003;
vector<int> nums[35];	//´æË÷Òý
int color[maxn]; 

int main(){
	int T;
	int n;
	int a;
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<35;i++) nums[i].clear();
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			for(int j=2;j<35;j++)
				if(a%j==0){
					nums[j].push_back(i);
					break;
				}
		}
		int cnt = 0;
		for(int i=2;i<35;i++){
			if(nums[i].size()>0){
				cnt++;
				for(int j=0;j<nums[i].size();j++){
					color[nums[i][j]] = cnt;
				}
			}
		}
		printf("%d\n",cnt);
		for(int i=0;i<n;i++)
			printf("%d ",color[i]);
		putchar('\n');
	}
	return 0;
}

