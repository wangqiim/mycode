#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

/*�������������ĿӰ�������������;������߷֣������ֲ�����߷�Ҳ��¼�ʼ�ﵽ��λ��= =*/
const int maxn = 1003;
string name[maxn];
int score[maxn];
unordered_map<string,int> hashmap;	//ÿ�������ķ���
unordered_map<string,int> hashmap2;	//��ģ��һ�μӷֹ��� 

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>name[i]>>score[i];
		hashmap[name[i]] = hashmap[name[i]] + score[i];
	}
	int maxsco = 0;
	for(auto it=hashmap.begin();it!=hashmap.end();it++)
		maxsco = max(maxsco,it->second);
	string res;
	for(int i=0;i<n;i++){	//��ģ��һ��ӷֹ��� 
		hashmap2[name[i]] = hashmap2[name[i]] + score[i];
		if(hashmap2[name[i]]>=maxsco && hashmap[name[i]]==maxsco){
			//�����Ѿ��ﵽ���֣��������ս�������֣�˵��name[i]�ǵ�һ���ﵽ�� 
			res = name[i];
			break;
		}
	}
	cout<<res<<endl;
	return 0;
}

