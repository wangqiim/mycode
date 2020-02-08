#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
	int no;
	int l;
};

const int maxn = 1001;
int n,l,k;	//n人数,l层数,k发起人数 
int m[maxn];	//关注的人数 
vector<node> user_list[maxn];
bool isvis[maxn] = {false};
queue<node> q;
int res=-1;
vector<int> input;

void bfs(node nownum){	//nownum为发起者 
	q.push(nownum);
	isvis[nownum.no] = true;
	while(!q.empty()){
		node Node = q.front();
		q.pop();
		res++;
		node temp;
		for(int i=0;i<user_list[Node.no].size();i++){
			temp = user_list[Node.no][i];
			if(isvis[temp.no]==false){
				temp.l = Node.l+1;
				if(temp.l<=l){
					q.push(temp);
					isvis[temp.no]=true;
				} 
			}
		}
	}
}


int main(){
	cin>>n>>l;
	node Node;
	for(int i=1;i<=n;i++){
		cin>>m[i];
		int temp;
		for(int j = 0;j<m[i];j++){
			cin>>temp;
			Node.no = i;
			user_list[temp].push_back(Node);
		}
	}
	cin>>k;
	for(int i=0;i<k;i++){
		int kk;
		cin>>kk;
		input.push_back(kk);
	}
	node t;
	for(int i=0;i<k;i++){
		res = -1;
		t.no = input[i];
		t.l = 0;
		bfs(t);
		cout<<res;
		if(i!=k-1)
			cout<<endl;
		for(int j=0;j<maxn;j++)
			isvis[j] = false;
	}
	return 0;
}
	
