#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int flag = 0; //0,1,2,3:整数,小数,分数,百分数
	string nums;	//输入字符串 
	string res="";	//结果字符串 
	int n=0,size;	//n符号的位置 
	cin>>nums;
	
	size = nums.size();
	if(nums[size-1]=='%')	//判断是哪种类型的数 
		flag = 3;
	else{
		for(int i=0;i<size;i++){
			if(nums[i]=='.'){
				n=i;
				flag = 1;
				break;
			}else if(nums[i]=='/'){
				n=i;
				flag = 2;
				break;
			}
		}		
	}
	
	if(flag==0){	//整数 
		reverse(nums.begin(),nums.end());
		for(int i=0;i<size;i++){
			if(nums[i]!='0'){
				res = nums.substr(i);
				break;
			}
			if(i == size-1)	//只有一位且为0
				res = "0"; 
		}
	}else if(flag==3){	//百分数 
		reverse(nums.begin(),nums.begin()+size-1);
		for(int i=0;i<size-1;i++){
			if(nums[i]!='0'){
				res = nums.substr(i);
				break;
			}
			if(i == size-2)
				res = "0%";
		}
	}else if(flag==1){	//小数
		reverse(nums.begin(),nums.begin()+n);
		reverse(nums.begin()+n+1,nums.end());
		for(int i=0;i<n;i++){	//整数部分 
			if(nums[i]!='0'){
				res = nums.substr(i,n-i);
				break;
			}
			if(i==n-1)
				res =  "0";
		}
		res += '.';
		for(int i=size-1;i>n;i--){
			if(nums[i]!='0'){
				res += nums.substr(n+1,i-n);
				break;
			}
			if(i==n+1){	//小数点后面全是0
				res += "0";
			}
		}

	}else{	//分数
		reverse(nums.begin(),nums.begin()+n);
		reverse(nums.begin()+n+1,nums.end());
		for(int i=0;i<n;i++){	//分子 
			if(nums[i]!='0'){
				res = nums.substr(i,n-i);
				break;
			}
			if(i==n-1)
				res = "0";
		}
		res += '/';
		for(int i=n+1;i<size;i++){	//分母 
			if(nums[i]!='0'){
				res += nums.substr(i,size-i);
				break;
			}
		}
	}
	cout<<res;
	return 0;
} 
