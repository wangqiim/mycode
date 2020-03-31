#include<cstdio>
#include<unordered_map>
using namespace std;

unordered_map<int,int> hashmap;

int main(){
	int T;
	scanf("%d",&T);
	int n;
	int a;
	while(T--){
		hashmap.clear();
		scanf("%d",&n);
		int muln=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			if(++hashmap[a]>1)
				muln++;
		}
		printf("%d\n",n-muln);
	}
	return 0;
}
