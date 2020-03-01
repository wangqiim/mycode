#include<iostream>
#include<string>
using namespace std;

//一个数字有7笔,从上到下,从左到右依次 
int nums[11][7]={{1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{1,0,1,1,1,0,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,0},{1,1,0,1,0,1,1},{1,1,0,1,1,1,1},{1,0,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};

int main(){
	int k;
	string s;
	string res;
	cin>>k>>s;
	int size = s.size();
	//每个数字分成五行.
	res = "";
	for(int i=0;i<size;i++){	//第一行 
		if(i!=0) res+=" ";//除了第一个数字,其他的都要添加空格
		int number = s[i]-'0';	//字符转int 
		int n=k;	 
		res+=" ";
		if(nums[number][0]==1)
			for(int j=0;j<k;j++) res+="-";//每一笔画要重复k次
		else
			for(int j=0;j<k;j++) res+=" ";//每一笔画要重复k次	
		res+=" ";
	}
	cout<<res<<endl;//第一行结束
	res = "";
	for(int i=0;i<size;i++){
		if(i!=0) res+=" ";
		int number = s[i]-'0';
		if(nums[number][1]==1)
			res+="|";
		else
			res+=" ";
		for(int j=0;j<k;j++) res+=" ";
		if(nums[number][2]==1)
			res+="|";
		else
			res+=" ";
	}
	for(int i=0;i<k;i++){	//第二行要重复输出k次 
		cout<<res<<endl;
	}//第二行结束
	res = "";
	for(int i=0;i<size;i++){
		if(i!=0) res+=" ";//除了第一个数字,其他的都要添加空格
		int number = s[i]-'0';	//字符转int 
		int n=k;	 
		res+=" ";
		if(nums[number][3]==1)
			for(int j=0;j<k;j++) res+="-";//每一笔画要重复k次
		else
			for(int j=0;j<k;j++) res+=" ";//每一笔画要重复k次	
		res+=" ";
	}
	cout<<res<<endl;
	//第三行结束
	res = "";
	for(int i=0;i<size;i++){
		if(i!=0) res+=" ";
		int number = s[i]-'0';
		if(nums[number][4]==1)
			res+="|";
		else
			res+=" ";
		for(int j=0;j<k;j++) res+=" ";
		if(nums[number][5]==1)
			res+="|";
		else
			res+=" ";
	}
	for(int i=0;i<k;i++){	//第二行要重复输出k次 
		cout<<res<<endl;
	}//第四行结束
	res = "";
	for(int i=0;i<size;i++){
		if(i!=0) res+=" ";//除了第一个数字,其他的都要添加空格
		int number = s[i]-'0';	//字符转int 
		int n=k;	 
		res+=" ";
		if(nums[number][6]==1)
			for(int j=0;j<k;j++) res+="-";//每一笔画要重复k次
		else
			for(int j=0;j<k;j++) res+=" ";//每一笔画要重复k次	
		res+=" ";
	}
	cout<<res<<endl;
	//第五行结束 
	return 0;
}
