#include<cstdio>
#include<map>
using namespace std;

map<long long,int> hashmap;

int main(){
	int n;
	scanf("%d",&n);
	long long a;
	long long acc=0;
	hashmap[0] = 0;	//hashmap[i]= j ,i在j位置第一次出现 
	long long res = 0;
	int bound = 0;	//bound为最后一个不能包含的元素 
	for(int i=1;i<=n;i++){
		scanf("%lld",&a);
		acc+=a;
		if((hashmap.count(acc)==0)||hashmap[acc]<bound){
			res += i-bound;
		}else{
			res += i - hashmap[acc]-1;
			bound = hashmap[acc]+1;
		}
		hashmap[acc] = i;
	}
	printf("%lld\n",res);
	return 0;
} 
