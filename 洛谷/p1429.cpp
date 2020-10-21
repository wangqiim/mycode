
#include<bits/stdc++.h>
using namespace std;
int const p1=92083,p2=69061;
int n,m;
int a[2005][2005];
long long tot;
typedef unsigned long long ull;
unsigned long long hash1[2005][2005],hash2[2005][2005],hash3[2005][2005];
unsigned long long P1[100005],P2[100005];
long long read()
{
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
//三种不同hash求矩阵(i,j)~(ii,y)的哈希值 
ull sum1(int i,int j,int x,int y,int k){
	return hash1[x][y]-hash1[i-1][y]*P2[k]-hash1[x][j-1]*P1[k]+hash1[i-1][j-1]*P1[k]*P2[k];
}
ull sum2(int i,int j,int x,int y,int k)
{
	return hash2[x][j]-hash2[i-1][j]*P2[k]-hash2[x][y+1]*P1[k]+hash2[i-1][y+1]*P1[k]*P2[k];
}
ull sum3(int i,int j,int x,int y,int k)
{
	return hash3[i][y]-hash3[x+1][y]*P2[k]-hash3[i][j-1]*P1[k]+hash3[x+1][j-1]*P1[k]*P2[k];
}
//判断函数 
bool check(int i,int j,int x,int y,int mid)
{
	return sum1(i,j,x,y,mid)==sum2(i,j,x,y,mid)&&sum1(i,j,x,y,mid)==sum3(i,j,x,y,mid);
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	a[i][j]=read();
	//预处理P1,P2数组 
	P1[0]=1;for(int i=1;i<=100000;i++)P1[i]=P1[i-1]*p1;
	P2[0]=1;for(int i=1;i<=100000;i++)P2[i]=P2[i-1]*p2;
	//三种不同hash预处理 
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	hash1[i][j]=hash1[i][j-1]*p1+a[i][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	hash1[i][j]+=hash1[i-1][j]*p2;
	for(int i=1;i<=n;i++)
	for(int j=m;j>=1;j--)
	hash2[i][j]=hash2[i][j+1]*p1+a[i][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	hash2[i][j]+=hash2[i-1][j]*p2;
	for(int i=n;i>=1;i--)
	for(int j=1;j<=m;j++)
	hash3[i][j]=hash3[i+1][j]*p2+a[i][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	hash3[i][j]+=hash3[i][j-1]*p1;
	//处理边长为奇数的 
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		int l=1,r=min(min(i,j),min(n-i+1,m-j+1)),ans=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(i-mid+1,j-mid+1,i+mid-1,j+mid-1,2*mid-1))
			{
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		tot+=ans;
	}
	//偶数特处理 
	for(int i=1;i<n;i++)
	for(int j=1;j<m;j++)//偶数枚举(i,j)~(i+1,j+1)为中心 
	{
		int l=1,r=min(min(i,j),min(n-(i+1)+1,m-(j+1)+1)),ans=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(i-mid+1,j-mid+1,(i+1)+mid-1,(j+1)+mid-1,2*mid))
			{
				ans=mid;
				l=mid+1;
			}
			else 
			r=mid-1;
		}
		tot+=ans;
	}
	cout<<tot<<endl;
}

