#include<cstdio>
#include<vector>
using namespace std;

const int maxn = 200005;
int a[maxn];
int hashmap[maxn];
int t,n,maxnum,index,left;
bool flag;
vector<int> res;

int main(){
	scanf("%d",&t);
	while(t--){
		res.clear();
		maxnum = 0;index = 0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>maxnum){
				index = i;
				maxnum = a[i];	
			}
		}
		
		left = maxnum;flag = 1;
		for(int i=1;i<=left;i++) hashmap[i] = 0;
		for(int i=1;i<=left;i++){
			if(++hashmap[a[i]]>1 || a[i]>left){
				flag = false;
				break;
			}
		}
		for(int i=1;i<=n-left;i++) hashmap[i] = 0;
		for(int i=left+1;i<=n;i++){
			if(++hashmap[a[i]]>1 || a[i]>(n-left)){
				flag = false;
				break;
			}
		}
		if(flag){
			res.push_back(left);
			res.push_back(n-left);	
		} 
		
		left = n-maxnum;flag = 1;
		for(int i=1;i<=left;i++) hashmap[i] = 0;
		for(int i=1;i<=left;i++){
			if(++hashmap[a[i]]>1 || a[i]>left){
				flag = false;
				break;
			}
		}
		for(int i=1;i<=n-left;i++) hashmap[i] = 0;
		for(int i=left+1;i<=n;i++){
			if(++hashmap[a[i]]>1 || a[i]>(n-left)){
				flag = false;
				break;
			}
		}
		if(flag){
			res.push_back(left);
			res.push_back(n-left);
		}
		if(res.size()==0) printf("0\n");
		else if(res.size()==2 || (res.size()==4&&maxnum*2==n)) printf("1\n%d %d\n",res[0],res[1]);
		else printf("2\n%d %d\n%d %d\n",res[0],res[1],res[2],res[3]);
	}
	return 0;
} 
