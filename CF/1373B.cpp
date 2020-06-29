#include<iostream>
#include<string>
#include<stack>
using namespace std;
 
stack<char> st;

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
    	cin >> s;
    	while (!st.empty()) st.pop();
    	int n = s.size();
    	int cnt = 0;
    	for (int i = 0; i < n; i++) {
    		if (st.empty())
    			st.push(s[i]);
    		else {
    			if (st.top() == s[i]) {
    				st.push(s[i]);
				}
				else {
					st.pop();
					cnt++;
				}
			}
		}
		if (cnt % 2 == 0) 
    		puts("NET");
		else 
    		puts("DA");
	}	
    return 0;
}
