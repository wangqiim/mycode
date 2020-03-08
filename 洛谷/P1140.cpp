#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 101;
char nums1[maxn];
char nums2[maxn];
int G[300][300];
int dp[maxn][maxn];
//dp[i][j] 表示基因1前i项,基因2前j项匹配上时的最大相似度

int main(){
	G['A']['A'] = 5; G['A']['C'] = -1; G['A']['G'] = -2; G['A']['T'] = -1; G['A']['-'] = -3;
	G['C']['A'] = -1; G['C']['C'] = 5; G['C']['G'] = -3; G['C']['T'] = -2; G['C']['-'] = -4;
	G['G']['A'] = -2; G['G']['C'] = -3; G['G']['G'] = 5; G['G']['T'] = -2; G['G']['-'] = -2;
	G['T']['A'] = -1; G['T']['C'] = -2; G['T']['G'] = -2; G['T']['T'] = 5; G['T']['-'] = -1;
	G['-']['A'] = -3; G['-']['C'] = -4; G['-']['G'] = -2; G['-']['T'] = -1;
	int n1,n2;
	scanf("%d",&n1);
	for(int i=1;i<=n1;i++){
		scanf(" %c",&nums1[i]);
	}
	scanf("%d",&n2);
	for(int i=1;i<=n2;i++){
		scanf(" %c",&nums2[i]);
	}
	for(int i=1;i<=n1;i++)	//边界处理 
		dp[i][0] = dp[i-1][0]+G[nums1[i]]['-']; 
	for(int j=1;j<=n2;j++)	//边界处理 
		dp[0][j] = dp[0][j-1]+G['-'][nums2[j]];
	for(int i=1;i<=n1;i++)
		for(int j=1;j<=n2;j++)
			dp[i][j] = max(dp[i-1][j-1]+G[nums1[i]][nums2[j]],max(dp[i-1][j]+G[nums1[i]]['-'],dp[i][j-1]+G['-'][nums2[j]]));
	printf("%d",dp[n1][n2]);
	return 0;
}
