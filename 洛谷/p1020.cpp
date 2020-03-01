#include<cstdio>

const int maxn = 100001;
int nums[maxn];
int inc[maxn];	//����(�������)����	//���ȼ�Ϊϵͳ������,��֤�� 
int dec[maxn];	//������(���Ե���)���� 	//���ȼ�Ϊ������صĵ������� 
int len_inc=0,len_dec=0;

int first_lo(int l,int r,int k){	//ʹ�ö���,����dec����[l~r]��һ��С��k��λ��
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

int first_hi_eq(int l,int r,int k){	//ʹ�ö���,����inc����[l~r]��һ�����ڵ���k��λ��
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
	//������0��� 
	inc[0]=nums[0];dec[0]=nums[0];
	len_inc++;len_dec++;
	for(int i=1;i<n;i++){
		if(nums[i]<=dec[len_dec-1])
			dec[len_dec++] = nums[i];
		else{
			int j = first_lo(0,len_dec-1,nums[i]);
			//�ҵ�dec[]�е�һ��<nums[i]��Ԫ�ص��±�j
			dec[j] = nums[i]; 
			//printf("��i%d������Ҫ����j%dλ��\n",i,j);
		}
		if(nums[i]>inc[len_inc-1])
			inc[len_inc++] = nums[i];
		else{
			int j = first_hi_eq(0,len_inc-1,nums[i]);
			//�ҵ�inc[]�е�һ��>=nums[i]��Ԫ�ص��±�j
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
//dp,���Ӷ�O(n^2),ֻ�ܹ�һ������
const int maxn = 100001;
int nums[maxn];
int dp[maxn];//dp[i]:ǰi������,��i��һ������,���������Ŀ
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
	int all=0;	//�������е�����Ҫ��ϵͳ���� 
	for(int i=n-1;i>=0;i--){
		if(islj[i])//�Ѿ��������� 
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
