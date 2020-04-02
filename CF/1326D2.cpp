#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

namespace Manacher{
    vector<int> ans, str, lef;
    int build(const string &s){
        // ��ʼ��
        int n = s.length(), m = (n + 1) << 1, ret = 0;
        str.resize(m + 1); ans.resize(m + 1); lef.resize(m + 1);
        // $ - ����ʼ��ǣ� @ - ��������ǣ�# - ����ĸ�������ע��������ַ��������ַ����ڲ����ڵ�
        str[0] = '$'; str[m] = '@'; str[1] = '#'; ans[1] = 1;
        for (int i = 1; i <= n; i++) 
            str[i << 1] = s[i - 1], str[i << 1 | 1] = '#';
        // Manacher ������r, p �ֱ�ά����ǰ�������Ĵ����ұ߽�������
        ans[1] = 1;
        for (int r = 0, p = 0, i = 2; i < m; ++i){
            if (r > i) ans[i] = min(r - i, ans[p * 2 - i]); else ans[i] = 1; // Manacher ���Ĳ���
            while(str[i - ans[i]] == str[i + ans[i]]) ++ans[i]; // ����������չ
            if (i + ans[i] > r) r = i + ans[i], p = i; // ���Ը��� r, p
            ret = max(ret, ans[i] - 1); // ���´�
        }
        // ����ά����ÿ��λ��Ϊ��������Ĵ�
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
