#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct student{
	string name;
	int fgrade;		//��ĩƽ���ɼ� 
	int cgrade;		//�༶����ɼ�
	char isgood;	//�Ƿ���ѧ���ɲ�Y��ʾ��,N��ʾ���� 
	char iswest;	//�Ƿ�������ѧ��
	int pnum;	//�����������
	int money;
};

int get_money(student& a){	//����ѧ��a�õ��Ľ���ֵ 
	int res=0;
	if(a.fgrade>80&&a.pnum>=1)
		res+=8000;
	if(a.fgrade>85&&a.cgrade>80)
		res+=4000;
	if(a.fgrade>90)
		res+=2000;
	if(a.fgrade>85&&a.iswest=='Y')
		res+=1000;
	if(a.cgrade>80&&a.isgood=='Y')
		res+=850;
	return res;
}

int main(){
	int n;
	string name="";	//��ý�������ѧ�������� 
	int maxm=0;	//��ཱ�� 
	int s=0;		//�ܽ��� 
	cin>>n;
	vector<student> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i].name>>nums[i].fgrade>>nums[i].cgrade>>nums[i].isgood>>nums[i].iswest>>nums[i].pnum;
		nums[i].money = get_money(nums[i]);
		s+=nums[i].money;
		if(nums[i].money>maxm){
			name = nums[i].name;
			maxm = nums[i].money;
		}
	}
	cout<<name<<endl<<maxm<<endl<<s;
	return 0;
}
