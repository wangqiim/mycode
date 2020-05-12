#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
	int t,n,k;
	string s;
	cin>>t;
	while(t--){
		cin>>n>>k;
		cin>>s;
		vector<string> ans(k);
		sort(s.begin(),s.end());
		string res="";
		int j = 0;
		int flag = 1;
		for(int i=0;i<n;i++){
			if(i>k){	//非第一层 
				if((j!=0 && s[i]!=s[i-1]) ||(j==0 && s[i]!=s[i-k])){
					flag = 0;
					break;
				}
			}else{
				if(i!=0 && i==k-1 && s[i]!=s[0]){	//第一层就有不一样的 
					res.push_back(s[i]);
					break;
				}
			}
			ans[j].push_back(s[i]);
			j = (j+1)%k;
		}
		if(flag){
			for(int i=0;i<k;i++)
				res = max(res,ans[i]);
			cout<<res<<endl;
		}else{
			if(res==""){
				res.push_back(s[0]);
				for(int i=k;i<n;i++)
					res.push_back(s[i]);
				cout<<res<<endl;
			}else{	//第一层出现不一样的了 
				cout<<res<<endl;
			}
		}
	}
	return 0;
}
