#include<iostream>
#include<string>
using namespace std;

int main(){
	int T;
	cin >> T;
	string t;
	string ans;
	while(T--){
		ans = "";
		cin >> t;
		int n = t.size();
		int flag = 1;
		for(int i = 1; i < n; i++)
			if(t[i] != t[i-1]){
				flag = 0;
				break;
			}
		if(flag)
			ans = t;
		else
			for(int i = 0; i < n; i++){
				if(i == 0)
					ans.push_back(t[i]);
				else{
					if(t[i] == t[i-1])
						ans.push_back('0' + '1' - t[i]);
					ans.push_back(t[i]);
				}
			}
		cout << ans << endl;
	}
}
