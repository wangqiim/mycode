#include<cstdio>
//������������1-n�ĸ�����ͬ����Ȼ���������ص� 
//ת����һ�������е������������O(nlogn)
//���ҵ�����2(Ԫ�ر��������һ�е�λ��) ����������� 
const int maxn = 100005;
int nums1[maxn],nums2[maxn];
int loc[maxn],f[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&nums1[i]);
		loc[nums1[i]] = i;	// nums1[i]�����ڵ�i��λ�� 
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&nums2[i]);
	int len=0;//f[i]�ĳ���
	f[0] = 0; 
	for(int i=1;i<=n;i++){
		if(loc[nums2[i]]>f[len])
			f[++len] = loc[nums2[i]];
		else{
			int l=1,r=len;
			int mid;	//�ҵ���һ������loc[nums2[i]]������
			while(l<r){	//�����ܳ�����ͬ��λ�� 
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

/* //ֱ��DP��ʱO(n^2) 
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
