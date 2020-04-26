#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 200005;
int a[maxn];
int acc[maxn];	//1-i山峰的数量
int peak[maxn];	//i是否为山峰（不考虑边界） 
int main(){
	int t,n,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++){
			acc[i] = 0;
			peak[i] = 0;
		}
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<n-1;i++){
			if(a[i-1]<a[i]&&a[i]>a[i+1])
				peak[i] = 1;
			acc[i] = acc[i-1]+peak[i];
			//cout<<"i="<<i<<"acc="<<acc[i]<<endl;
		}
		acc[n-1] = acc[n-2];
		int index = 0;
		int res = 0;
		int cnt;
		for(int i=0;i<n-k+1;i++){
			if(i==0) cnt = acc[i+k-1];
			else cnt = acc[i+k-1] - acc[i-1];
			if(peak[i]==1) cnt--;
			if(peak[i+k-1]==1) cnt--;
			if(cnt>res){
				index = i;
				res = cnt;
			}
			//if(i==2) cout<<acc[6]<<acc[1]<<cnt<<endl;
		}
		printf("%d %d\n",res+1,index+1);
	}
	return 0;
}
