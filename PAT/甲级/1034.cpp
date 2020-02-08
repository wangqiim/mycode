#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

const int maxn = 2001;
const int inf = 1000000000;

map<string,int> name2no;
map<int,string> no2name;
map<string,int> res;

int G[maxn][maxn] = {0};
int weight[maxn] = {0};
int n,k;
int sum_num;
int head;
int totalvalue;
bool vis[maxn] = {false};
int numperson = 0;
int gang = 0;


void dfs(int nowvisit,int &head,int &sum_num,int &totalvalue){	//nowvisit��ǰ���ʵı��,	 
	vis[nowvisit] = true;
	sum_num++;
	if(weight[nowvisit]>weight[head]){
		head = nowvisit;
	}
	for(int i = 0;i<numperson;i++){
		if(G[nowvisit][i]>0){
			totalvalue += G[nowvisit][i];
			G[i][nowvisit] = 0;
			if(vis[i]==false){
				dfs(i,head,sum_num,totalvalue);
			}
		}
	}
}

void dfstra(){
	for(int i = 0;i<n;i++){
		if(vis[i]==false){
			head = i;
			totalvalue = 0;
			sum_num = 0;
			dfs(head,head,sum_num,totalvalue);
			if(totalvalue>k&&sum_num>2){
				res[no2name[head]] = sum_num;
				gang++;
			}
		}
	}
}

int change(string str){
	if(name2no.find(str) != name2no.end()){
		return name2no[str];
	}
	else{
		name2no[str] = numperson;
		no2name[numperson] = str;
		return numperson++;
	}
}

int main(){
	cin>>n>>k;	//������������ֵ 
	string name1,name2;	//��Ա1����Ա2 
	int time;	//��Ա1��2��ͨ��ʱ�� 
	for(int i = 0 ;i<n;i++){
		cin>>name1>>name2>>time;
		int id1 = change(name1);
		int id2 = change(name2);
		weight[id1] += time;	//ͬʱ����ÿ�����Ȩ�� 
		weight[id2] += time;
		G[id1][id2] += time;
		G[id2][id1] += time;
	}
	dfstra();
	map<string,int>::iterator it;	//it.first
	cout<<gang<<endl;
	for(it = res.begin();it!=res.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0; 
}
