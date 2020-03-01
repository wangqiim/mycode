#include<cstdio>

const int maxn = 100001;
int nums[maxn];
int inc[maxn];	//上升(必须大于)序列	//长度即为系统的数量,反证法 
int dec[maxn];	//非上升(可以等于)序列 	//长度即为最多拦截的导弹数量 
int len_inc=0,len_dec=0;

int first_lo(int l,int r,int k){	//使用二分,返回dec数组[l~r]第一个小于k的位置
	int m;
	while(l<r){
		m = l+(r-l)/2;
		if(dec[m]==k)
			l = m+1;
		else if(dec[m]<k)
			r = m;
		else
			l = m+1;
	}
	return l;
}

int first_hi_eq(int l,int r,int k){	//使用二分,返回inc数组[l~r]第一个大于等于k的位置
	int m;
	while(l<r){
		m = l+(r-l)/2;
		if(inc[m]==k)
			r = m;
		else if(inc[m]<k)
			l = m+1;
		else
			r = m;
	}
	return l;
}

int main(){
	/*int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&nums[i]);*/
	int n=0;
	while(~scanf("%d",&nums[n])) n++;
	//不考虑0输出 
	inc[0]=nums[0];dec[0]=nums[0];
	len_inc++;len_dec++;
	for(int i=1;i<n;i++){
		if(nums[i]<=dec[len_dec-1])
			dec[len_dec++] = nums[i];
		else{
			int j = first_lo(0,len_dec-1,nums[i]);
			//找到dec[]中第一个<nums[i]的元素的下标j
			dec[j] = nums[i]; 
			//printf("第i%d个数需要插入j%d位置\n",i,j);
		}
		if(nums[i]>inc[len_inc-1])
			inc[len_inc++] = nums[i];
		else{
			int j = first_hi_eq(0,len_inc-1,nums[i]);
			//找到inc[]中第一个>=nums[i]的元素的下标j
			inc[j]=nums[i]; 
		}
	}
	printf("%d\n%d",len_dec,len_inc);
	return 0;	
}

/*
#include<cstdio>	 
#include<algorithm>
using namespace std;
//dp,复杂度O(n^2),只能过一半数据
const int maxn = 100001;
int nums[maxn];
int dp[maxn];//dp[i]:前i发导弹,第i发一定拦截,最大拦截数目
bool islj[maxn]; 

int main(){	
	int n;
	int res = 0;
	//nums[0] = 90 ;nums[1] = 103 ;nums[2] = 99 ;nums[3] = 83;
	//nums[4] = 102 ;nums[5] = 70 ;nums[6] = 86 ;nums[7] = 70;
	//nums[8] = 99; nums[9] = 71;
	while(~scanf("%d",&nums[n])) n++;
	for(int i=0;i<n;i++){
		dp[i] = 1;
		for(int j=i-1;j>=0;j--){
			if(nums[j]>=nums[i])
				dp[i] =max(dp[i],dp[j] + 1);
		}
		if(dp[i]>res) res = dp[i];
	}
	int all=0;	//拦截所有导弹需要的系统数量 
	for(int i=n-1;i>=0;i--){
		if(islj[i])//已经被拦截了 
			continue;
		int t = nums[i];
		islj[i] = true;
		all++;
		for(int j=i-1;j>=0;j--){
			if(islj[j]==false&&nums[j]>=t){
				t =nums[j];
				islj[j] = true;	
			}
		} 
	}
	printf("%d\n%d",res,all);
	return 0;	
}
*/
