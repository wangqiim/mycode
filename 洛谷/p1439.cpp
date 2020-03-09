#include<cstdio>
//利用数组是用1-n的各不相同的自然数组成这个特点 
//转化成一个序列中的最长上升子序列O(nlogn)
//即找到数组2(元素变成在数组一中的位置) 最长的升序序列 
const int maxn = 100005;
int nums1[maxn],nums2[maxn];
int loc[maxn],f[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&nums1[i]);
		loc[nums1[i]] = i;	// nums1[i]出现在第i个位置 
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&nums2[i]);
	int len=0;//f[i]的长度
	f[0] = 0; 
	for(int i=1;i<=n;i++){
		if(loc[nums2[i]]>f[len])
			f[++len] = loc[nums2[i]];
		else{
			int l=1,r=len;
			int mid;	//找到第一个大于loc[nums2[i]]的数字
			while(l<r){	//不可能出现相同的位置 
				mid = (l+r)/2;
				if(loc[nums2[i]]<f[mid]){
					r = mid;
				}else{
					l = mid+1;
				}
			} 
			f[l] = loc[nums2[i]];
		}
	}
	printf("%d",len);
	return 0;
} 

/* //直接DP超时O(n^2) 
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100005;
int nums1[maxn],nums2[maxn];
int dp[maxn][maxn];	
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&nums1[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&nums2[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(nums1[i]==nums2[j]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
	printf("%d",dp[n][n]);
	return 0;
}*/
