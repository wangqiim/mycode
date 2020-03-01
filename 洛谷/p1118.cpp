#include<cstdio>

const int maxn = 13;

int yhsj[12][12];
bool isused[maxn];	//�ݹ�ʱ�жϸ�������û�б�ʹ��
int nums[maxn];	//���ʱʹ�� 
int n;
int flag=false; //ֻ���һ����С������ 

void dfs(int now,int sum){	//��ǰ��Ҫ�ݹ鴦����ǵ�nowλ��,sumΪĿ��ֵ��ȥ֮ǰ���е�ʣ��� 
	if(now==n){
		if(sum==0){
			for(int i=0;i<n;i++)
				if(i==n-1) printf("%d\n",nums[i]);
				else printf("%d ",nums[i]);
			flag = true;
		}
		return;
	}
	for(int i=1;i<=n;i++){	//i�ܷ�ʹ�� 1~n
		if(flag) break;	//�Ѿ��������С��,�˴�����֦Ҳ�޷�ȫ��AC 
		if(isused[i]==false&&(sum-i*yhsj[n-1][now])>=0){
			isused[i] = true;
			nums[now] = i;
			dfs(now+1,sum-i*yhsj[n-1][now]);
			isused[i] = false;
		}
	}
	return;
}

int main(){
	int s;
	scanf("%d %d",&n,&s);
	for(int i=0;i<n;i++){//����������� 
		for(int j=0;j<=i;j++){
			if(j==0||i==j){
				yhsj[i][j]=1;
				continue;
			}else{
				yhsj[i][j]=yhsj[i-1][j-1]+yhsj[i-1][j];	//���ֻ�������һά��ϵ��Ҳ�������ù������鹹�� 
			}
		}
	}
	dfs(0,s);
	return 0;
}
