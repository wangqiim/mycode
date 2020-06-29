#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<set> 
using namespace std;
 
int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--) {
    	cin >> n;
    	cin >> s;
    	bool flag = 0;	//ÓÐ0±äÎª1
    	int index_1 = -1;
    	int index_0 = -1;
    	for (int i = 0; i < n; i++) if (s[i] == '1') {
    		index_1 = i;
    		break;
		} 
    	for (int i = n - 1; i >=0; i--) if (s[i] == '0') {
    		index_0 = i;
    		break;
		}
    	for (int i = n - 1; i >= 0; i--) {
    		if (s[i] == '0') 	
    			flag = '1';
    		else if (s[i] == '1' && flag == 1){
    			s[i] = '0';
			}
		}	
		if (index_1 != -1 && index_0 != -1 && index_0 > index_1)
			cout << s.substr(index_0 - index_1) << endl;
		else 
			cout << s << endl;
	}
    return 0;
}
