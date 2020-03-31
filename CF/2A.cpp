#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

/*这题的题意是真的坑啊！！！就算中途掉下最高分，后来又补上最高分也记录最开始达到的位置= =*/
const int maxn = 1003;
string name[maxn];
int score[maxn];
unordered_map<string,int> hashmap;	//每个人最后的分数
unordered_map<string,int> hashmap2;	//再模拟一次加分过程 

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
	for(int i=0;i<n;i++){	//在模拟一遍加分过程 
		hashmap2[name[i]] = hashmap2[name[i]] + score[i];
		if(hashmap2[name[i]]>=maxsco && hashmap[name[i]]==maxsco){
			//该轮已经达到最大分，并且最终结果是最大分，说明name[i]是第一个达到的 
			res = name[i];
			break;
		}
	}
	cout<<res<<endl;
	return 0;
}

