#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int flag = 0; //0,1,2,3:����,С��,����,�ٷ���
	string nums;	//�����ַ��� 
	string res="";	//����ַ��� 
	int n=0,size;	//n���ŵ�λ�� 
	cin>>nums;
	
	size = nums.size();
	if(nums[size-1]=='%')	//�ж����������͵��� 
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
	
	if(flag==0){	//���� 
		reverse(nums.begin(),nums.end());
		for(int i=0;i<size;i++){
			if(nums[i]!='0'){
				res = nums.substr(i);
				break;
			}
			if(i == size-1)	//ֻ��һλ��Ϊ0
				res = "0"; 
		}
	}else if(flag==3){	//�ٷ��� 
		reverse(nums.begin(),nums.begin()+size-1);
		for(int i=0;i<size-1;i++){
			if(nums[i]!='0'){
				res = nums.substr(i);
				break;
			}
			if(i == size-2)
				res = "0%";
		}
	}else if(flag==1){	//С��
		reverse(nums.begin(),nums.begin()+n);
		reverse(nums.begin()+n+1,nums.end());
		for(int i=0;i<n;i++){	//�������� 
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
			if(i==n+1){	//С�������ȫ��0
				res += "0";
			}
		}

	}else{	//����
		reverse(nums.begin(),nums.begin()+n);
		reverse(nums.begin()+n+1,nums.end());
		for(int i=0;i<n;i++){	//���� 
			if(nums[i]!='0'){
				res = nums.substr(i,n-i);
				break;
			}
			if(i==n-1)
				res = "0";
		}
		res += '/';
		for(int i=n+1;i<size;i++){	//��ĸ 
			if(nums[i]!='0'){
				res += nums.substr(i,size-i);
				break;
			}
		}
	}
	cout<<res;
	return 0;
} 
