#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct student{
	string name;
	int fgrade;		//期末平均成绩 
	int cgrade;		//班级评议成绩
	char isgood;	//是否是学生干部Y表示是,N表示不是 
	char iswest;	//是否是西部学生
	int pnum;	//发表的论文数
	int money;
};

int get_money(student& a){	//返回学生a得到的奖金值 
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
	string name="";	//获得奖金最多的学生的姓名 
	int maxm=0;	//最多奖金 
	int s=0;		//总奖金 
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
