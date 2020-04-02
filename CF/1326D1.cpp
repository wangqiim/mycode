#include<iostream>
#include<string>
#include<algorithm>
using namespace std; 

string s;

string solve(){
	int res = 0;
	int n = s.size();
	if(n==1) return s;
	int left = 0, right = n-1;
	while(left<right){
		if(s[left]==s[right]){
			left++;
			right--;
			res = res+2;
		}else{
			break;
		}
	}
	int pre_r=left-1;
	int res1 = 0;
	for(int i=right;i>=left;i--){
		bool flag = true;
		for(int j=left;j<=i;j++)
			if(s[j]!=s[i-(j-left)]){
				flag = false;
				break;
			}
		if(flag){
			pre_r = i;
			res1 = i-left+1;
			break;
		}
	}
	int suf_l=right+1;
	int res2 = 0;
	for(int i=left;i<=right;i++){
		bool flag = true;
		for(int j=right;j>=i;j--)
			if(s[j]!=s[i+right-j]){
				flag = false;
				break;
			}
		if(flag){
			suf_l = i;
			res2 = right-i+1;
			break;
		}
	}
	if(res1>=res2){
		return s.substr(0,pre_r+1)+s.substr(right+1);
	}else{
		return s.substr(0,left)+s.substr(suf_l);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		cin>>s;
		cout<<solve()<<endl;
	}
	return 0;
}
