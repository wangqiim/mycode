#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 200001;

bool isvis[maxn]={false};	//δ�����Ľ��
int nums[maxn];
int n,res=0x7fffffff;
int dfsnums[maxn];	//��¼ÿ�β����е�һ�γ��ֵ�λ�� 

void dfs(int begin,int now){
	if(isvis[begin]==true) return;
	if(dfsnums[begin]!=0){	//����������,���ֻ��� 
		res = min(res,now-dfsnums[begin]);
	}else{
		dfsnums[begin] = now;
		dfs(nums[begin],now+1);
		isvis[begin] = true;
	}
	return;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&nums[i]);
	}
	for(int i=1,j;i<=n;i++){
		dfs(i,1);
	}
	printf("%d",res);
	return 0;
}


/*	//ֱ�ӱ����ᳬʱ 
#include<cstdio>

const int maxn = 200001;
int trans[maxn]; //trans[i]��ʾiÿ�λ����Ϣ���ݸ�trans[i] 
int nums[maxn];	//nums[i]��ʾ i ����Ϣ����nums[i]�� 

int main(){
	int n,res=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&trans[i]);
		nums[i] = i;
	}
	bool flag=true;
	while(flag){
		res++;
		for(int i=1;i<=n;i++){
			nums[i] = trans[nums[i]];
			if(nums[i]==i){
				flag = false;
				break;	
			}
		}
	}
	printf("%d",res);
	return 0;
}
*/
