#include<iostream>
#include<string>
using namespace std;


string preod="",inod,postod;	//����������� 

void get_preod(int l_in,int r_in,int l_post,int r_post){ //����ͺ�������Ҷ˵�
	if(l_post>r_post) return;
	if(l_post==r_post){
		preod+=postod[l_post];
		return;	
	} 
	preod+=postod[r_post];	//���� 
	int mid;
	for(mid=l_in;mid<=r_in;mid++)
		if(inod[mid]==postod[r_post])
			break;	
	get_preod(l_in  , mid-1 ,l_post ,mid-1-l_in+l_post);	//������ 
	get_preod(mid+1 , r_in  ,mid+r_post-r_in,r_post-1);	//������
	return;
}

int main(){
	cin>>inod>>postod;
	int n = inod.size();
	get_preod(0,n-1,0,n-1);
	cout<<preod;
	return 0;
} 
