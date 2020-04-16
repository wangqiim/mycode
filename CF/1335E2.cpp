#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 200005;
int acc[201][maxn]={};	//acc[i][j] ǰj��Ԫ����i�ĸ��� 

int main(){
	int t,n,a;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		vector<vector<int> > nums(201);	//nums[i][j]:i��ɫ��j�γ����ڵ�λ��
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
			nums[a].push_back(i);
			for(int c=1;c<=200;c++)
				acc[c][i] = acc[c][i-1];
			acc[a][i]++;
		}
		int res = 0;
		for(int c=1;c<=200;c++){	//ö��a����ɫ
			int cnt = nums[c].size();	//a�ĸ���
			for(int i=0;i<=cnt/2;i++){	//ö��a�ĸ���
				int cntb = 0;	//b�������� 
				if(i==0){
					for(int k=1;k<=200;k++) cntb = max(cntb,acc[k][n]);
					res = max(res,cntb);
				}else{
					int left = nums[c][i-1];
					int right = nums[c][cnt-i];
					for(int k=1;k<=200;k++) cntb = max(cntb,acc[k][right-1]-acc[k][left]);
					res = max(res,2*i+cntb);
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
