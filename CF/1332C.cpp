#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int hashmap[200];
int main(){
	int T;
	cin>>T;
	string s;
	while(T--){
		int res=0;
		int n,k;
		cin>>n>>k;
		cin>>s;
		s = "0" + s;
		if(k%2==0){	//kÊÇÅ¼Êý 
			for(int i=1; i<=k/2; i++){
				int cnt = 0;
				int maxn = 0;
				memset(hashmap,0,sizeof(hashmap));
				for(int j=i;j<=n;j+=k){
					hashmap[s[j]]++;
					maxn = max(maxn,hashmap[s[j]]);
					hashmap[s[j+(k-2*i+1)]]++;
					maxn = max(maxn,hashmap[s[j+(k-2*i+1)]]);
					cnt=cnt+2;
				}
				res += cnt-maxn;
			}
			printf("%d\n",res);
		}else{
			int cnt;
			int maxn;
			for(int i=1; i<=k/2; i++){
				cnt = 0;
				maxn = 0;
				memset(hashmap,0,sizeof(hashmap));
				for(int j=i;j<=n;j+=k){
					hashmap[s[j]]++;
					maxn = max(maxn,hashmap[s[j]]);
					hashmap[s[j+(k-2*i+1)]]++;
					maxn = max(maxn,hashmap[s[j+(k-2*i+1)]]);
					cnt=cnt+2;
				}
				res += cnt-maxn;
			}
			cnt = 0;
			maxn = 0;
			memset(hashmap,0,sizeof(hashmap));
			for(int i=k/2+1;i<=n;i+=k){
				hashmap[s[i]]++;
				maxn = max(maxn,hashmap[s[i]]);
				cnt++;
			}
			res += cnt - maxn;
			printf("%d\n",res);
		}
	}
}
