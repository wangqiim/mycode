#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 10001;
int nums[maxn]={};

int main(){	//��������������ȶ���priority_queue�ƺ����� 
	int n,res=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&nums[i]);
	sort(nums,nums+n);
	for(int i=0;i<n-1;i++){	//ֻ��һ�ѵĻ�����������
		nums[i] += nums[i+1];
		res+=nums[i];
		int j=i+1;
		for(;j<n-1;j++)//��Ҫ��������,ֱ��һ�ֲ�������
			if(nums[j+1]<nums[i])
				nums[j] = nums[j+1];
			else break;
		nums[j] = nums[i];
	}
	printf("%d",res);
	return 0;
}
