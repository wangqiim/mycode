#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

namespace Manacher{
    vector<int> ans, str, lef;
    int build(const string &s){
        // 初始化
        int n = s.length(), m = (n + 1) << 1, ret = 0;
        str.resize(m + 1); ans.resize(m + 1); lef.resize(m + 1);
        // $ - 串开始标记， @ - 串结束标记，# - 将字母间隔开。注意这里的字符必须是字符串内不存在的
        str[0] = '$'; str[m] = '@'; str[1] = '#'; ans[1] = 1;
        for (int i = 1; i <= n; i++) 
            str[i << 1] = s[i - 1], str[i << 1 | 1] = '#';
        // Manacher 操作。r, p 分别维护当前最靠右最长回文串的右边界与中心
        ans[1] = 1;
        for (int r = 0, p = 0, i = 2; i < m; ++i){
            if (r > i) ans[i] = min(r - i, ans[p * 2 - i]); else ans[i] = 1; // Manacher 核心操作
            while(str[i - ans[i]] == str[i + ans[i]]) ++ans[i]; // 暴力向外扩展
            if (i + ans[i] > r) r = i + ans[i], p = i; // 尝试更新 r, p
            ret = max(ret, ans[i] - 1); // 更新答案
        }
        // 计算维护以每个位置为起点的最长回文串
        for (int i = 0; i <= m; i++) lef[i] = 0;
        for (int i = 2; i < m; i++) if (lef[i - ans[i] + 1] < i + 1) lef[i - ans[i] + 1] = i + 1;
        for (int i = 1; i <= m; i++) if (lef[i] < lef[i - 1]) lef[i] = lef[i - 1];
        return ret;
    }
    int mid(int x, bool odd){
        if (odd) return ans[(x + 1) << 1] - 1;
        return ans[(x + 1) << 1 | 1] - 1;
    }
    int left(int x){ return lef[(x + 1) << 1] - ((x+1) << 1); }
}

string s;

string solve(){
	int res = 0;
	int n = s.size();
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
	if(left>=right) return s;
	Manacher::build(s.substr(left,right-left+1));
	int len1 = Manacher::left(0);
	string s1 = s.substr(0,left+Manacher::left(0))+s.substr(right+1);
	
	reverse(s.begin(),s.end());
	Manacher::build(s.substr(left,right-left+1));
	int len2 = Manacher::left(0);
	string s2 = s.substr(0,left+Manacher::left(0))+s.substr(right+1);
	
	if(len1>=len2)
		return s1;
	else
		return s2;
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
