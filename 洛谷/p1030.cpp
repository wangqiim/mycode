#include<iostream>
#include<string>
using namespace std;


string preod="",inod,postod;	//先序中序后序 

void get_preod(int l_in,int r_in,int l_post,int r_post){ //中序和后序的左右端点
	if(l_post>r_post) return;
	if(l_post==r_post){
		preod+=postod[l_post];
		return;	
	} 
	preod+=postod[r_post];	//根结 
	int mid;
	for(mid=l_in;mid<=r_in;mid++)
		if(inod[mid]==postod[r_post])
			break;	
	get_preod(l_in  , mid-1 ,l_post ,mid-1-l_in+l_post);	//左子树 
	get_preod(mid+1 , r_in  ,mid+r_post-r_in,r_post-1);	//右子树
	return;
}

int main(){
	cin>>inod>>postod;
	int n = inod.size();
	get_preod(0,n-1,0,n-1);
	cout<<preod;
	return 0;
} 
