#include<iostream> 
#include<string>
using namespace std;

const int maxn = 100000;
struct people{
	int face;	//0��Ȧ�� 
	string job;	
};

people nums[maxn];

int main(){
	int n,m;//������ָ����
	int res = 0;	//�ӵ�һ�������С�˿�ʼ 
	int a,s;	//a=0����,a=1����.��s����. 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>nums[i].face>>nums[i].job;
	}
	for(int i=0;i<m;i++){
		cin>>a>>s;	//���뱣֤1<=s<=n 
		if(nums[res].face^a==1){//�������� ���߳������� 
			res = (res+s)%n;
		}
		else{
			res = (n+res-s)%n;
		} 
	}
	cout<<nums[res].job;
	return 0;
}
