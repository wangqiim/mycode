#include<bits/stdc++.h>
using namespace std;
const int INF=1000000009;
const int maxn = 20;
int d[maxn][maxn],dp[maxn][(1<<maxn)];
//�����ֱ̫ţ���ˣ���Ȼͬһ���ߵ�Ȩֵ������ü��Σ�Ц�����˹�������
//Ҳ�͵��˼���Сʱ�������COPY��������ŸĲŷ��ִ���
int main(){
    int t,n,m,a,b,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
    	for(int i=1;i<=n;i++){	//��ʼ��G 
    		for(int j=1;j<=n;j++){
    			d[i][j] = INF;
			}
		} 
		
        for(int i=1;i<=n;i++){ 
        	for(int s=1;s<(1<<n);s++){
        		dp[i][s] = INF;
			}
		}
		
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            d[b][a] = d[a][b] = min(d[a][b],c);	//�������ܣ��� 
        }
        for(int i=1;i<=n;i++)
            d[i][i]=0;
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(d[i][k]<INF&&d[k][j]<INF)
                    d[i][j] = d[i][j]<(d[i][k]+d[k][j])?d[i][j]:(d[i][k]+d[k][j]);
                }
            }
		}
		
        dp[1][1]=0;
        for(int s=1;s<(1<<n);s++){
            for(int i=1;i<=n;i++){
            	if((s&(1<<(i-1))))
	                for(int j=1;j<=n;j++){
	                    if((s&(1<<(j-1)))==0)
	                    	dp[j][s|(1<<(j-1))]=min(dp[j][s|(1<<(j-1))],dp[i][s]+d[i][j]);
	                }
            }
        }
        int ans=INF;
        for(int i=1;i<=n;i++){
            ans=min(ans,dp[i][(1<<n)-1]+d[i][1]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
