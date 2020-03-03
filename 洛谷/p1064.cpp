#include<cstdio>
#include<algorithm>
using namespace std;
/*����ÿ���ö�ٿ���ʹ��01ǡ�ñ������https://www.luogu.com.cn/problemnew/solution/P1064*/
/*�ù��������ܷ���ܶ�*/
const int maxn = 32001;	//���Ǯ��
const int maxm = 61;	//�������Ʒ����

int v[maxm],p[maxm],q[maxm];
//�۸�,		��Ҫ��,q=0����,�����ʾ�������  
int group[maxm][3];	//��i���������������������,��1��ʼ 
int c[maxm][5];//c[i][j] ��i���j�ַ����ļ۸� 
int w[maxm][5];//w[i][j] ��i���j�ַ����ļ۸�����Ҫ�ȳ˻� 
int hashmap[maxm];	//ԭ�����ӳ�䵽group��ı�� 

int dp[maxm][maxn];
//���ȣ�����������ϵ�Ķ��ֵ�һ�飬����K�� 
//dp[k][j] = ��ǰk����ѡ��ֵ������j�����ܵõ����������
//������Ŀÿ�����ֻ��3������������5�����.1:����ѡ.2:ѡ����.3:ѡ������1.4ѡ������2.5ȫѡ
//ת�Ʒ��� dp[k][j] = max(dp[k-1][j],dp[k-1][j-c[i]]+w[i](c[i],w[i]��k��һ�ַ�����Ӧ�ļ۸�ͼ�ֵ��Ҫ�Ȼ�)}

int main(){
	int n,m;	//n��Ǯ��,mϣ���������Ʒ�� 
	scanf("%d %d",&n,&m);
	int n_group = 0; 
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&v[i],&p[i],&q[i]);
		if(q[i]==0){
			group[++n_group][0]=i;	//��¼ÿ�������,�Ȳ���¼����(���������ܻ�δ����) 
			hashmap[i] = n_group;
		} 
	}
	for(int i=1;i<=m;i++)	//��¼���� 
		if(q[i]!=0)
			for(int j=1;j<=2;j++)	//���븽�� 
				if(group[hashmap[q[i]]][j]==0){
					group[hashmap[q[i]]][j]=i;
					break;
				}
	for(int i=1;i<=n_group;i++){	//����ÿ������� 
		int a1=group[i][0],a2=group[i][1],a3=group[i][2];	//������ÿ����Ʒ�ı�� 
		c[i][1] = v[a1]; 		
		w[i][1] = v[a1]*p[a1];					//ֻѡ��
		if(a2!=0){
			c[i][2] = v[a1]+v[a2];	
			w[i][2] = v[a1]*p[a1]+v[a2]*p[a2];		//��,��1
		}		
		if(a3!=0){
			c[i][3] = v[a1]+v[a3];	
			w[i][3] = v[a1]*p[a1]+v[a3]*p[a3];			//��,��2
			c[i][4]=v[a1]+v[a2]+v[a3];
			w[i][4]=v[a1]*p[a1]+v[a2]*p[a2]+v[a3]*p[a3];	//ȫѡ 
		}
	}
	for(int i=1;i<=n_group;i++){
		for(int j=1;j<=n;j++){
			dp[i][j] = dp[i-1][j];	//����ʲô����ѡ 
			for(int k=1;k<=4&&c[i][k]!=0;k++){	//����ÿ��ķ���
				if(c[i][k]<=j)
					dp[i][j] = max(dp[i][j],dp[i-1][j-c[i][k]]+w[i][k]);
			}
		}
	}
	printf("%d",dp[n_group][n]);
	return 0;
}
