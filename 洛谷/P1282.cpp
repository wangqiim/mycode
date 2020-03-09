#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int maxn = 1005;
//��������https://www.luogu.com.cn/problemnew/solution/P1282 
int a[maxn],b[maxn];
int dp[maxn][12001];	//dp[i][j]ǰi����,��-�²�Ϊj,��С��ת����
const int N=5000;	//����:�Եڶ�ά��5000��ֹ���²�Ϊ���� 

int main(){
    int n,ans;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i],&b[i]);
    memset(dp,0x7F,sizeof(dp));	//�������ֿ��ԺͲ��ɵõ������²�ֵ 
    dp[0][0+N]=0;	//�߽��ύ 
    for(int i=1;i<=n;i++)
        for(int j=-5000;j<=5000;j++){
            int dis=a[i]-b[i];
            dp[i][j+N]=min(dp[i-1][j-dis+N],dp[i-1][j+dis+N]+1); 
        }
    for(int i=0;i<=5000;i++){
        ans=min(dp[n][i+N],dp[n][-i+N]);
        if(ans<=1000){	//˵�������ֵ������·�ת�������ܵõ��� 
            printf("%d\n",ans);
            break;
        }
    }
    return 0;
}
