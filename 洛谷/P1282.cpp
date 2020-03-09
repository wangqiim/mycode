#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int maxn = 1005;
//代码来自https://www.luogu.com.cn/problemnew/solution/P1282 
int a[maxn],b[maxn];
int dp[maxn][12001];	//dp[i][j]前i张牌,上-下差为j,最小翻转次数
const int N=5000;	//技巧:对第二维加5000防止上下差为负数 

int main(){
    int n,ans;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i],&b[i]);
    memset(dp,0x7F,sizeof(dp));	//用于区分可以和不可得到的上下差值 
    dp[0][0+N]=0;	//边界提交 
    for(int i=1;i<=n;i++)
        for(int j=-5000;j<=5000;j++){
            int dis=a[i]-b[i];
            dp[i][j+N]=min(dp[i-1][j-dis+N],dp[i-1][j+dis+N]+1); 
        }
    for(int i=0;i<=5000;i++){
        ans=min(dp[n][i+N],dp[n][-i+N]);
        if(ans<=1000){	//说明这个差值的情况下翻转次数是能得到的 
            printf("%d\n",ans);
            break;
        }
    }
    return 0;
}
