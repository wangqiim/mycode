#include<cstdio>
#include<stack>
using namespace std;

const int maxn = 1001;
 
int main(){
	char str[maxn];
	scanf("%s",str);
	stack<int> s;
	int tmp;
	for(int i=0;str[i]!='@';i++){
		if('0'<=str[i]&&str[i]<='9'){
			tmp = str[i]-'0';
			while(str[++i]!='.'){
				tmp = tmp*10+str[i]-'0';
			}
			s.push(tmp);
		}
		else{			
			int b = s.top(); s.pop();
			int a = s.top(); s.pop();
			if(str[i]=='+')
				a+=b;
			else if(str[i]=='-')
				a-=b;
			else if(str[i]=='*')
				a*=b;
			else	//'/'
				a/=b;
			s.push(a); 	
		}
	}
	printf("%d",s.top());
	return 0;
}
