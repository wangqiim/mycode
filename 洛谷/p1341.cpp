#include<iostream>
#include<string>
using namespace std;


const int maxn = 256;// ASCII 'z','Z'��С��256

int G[maxn][maxn];
int depth[maxn];	//��Ķ�
int fa[maxn];	//���鼯����� 
int n,cnt=0,start=0;	//cnt��Ϊ�����ĵ�,start�ݹ鿪ʼ�Ľ�� 
char res[1000]={};
int left;
int t;

int find_fa(int x){
	if(fa[x] != x) fa[x]=find_fa(fa[x]);
	return fa[x];
}

void dfs(int now){
	for(int i=0;i<maxn;i++)
		if(G[now][i]==1){
			G[now][i]=G[i][now]=0;
			dfs(i);
		}
	res[n--]=(char)now;	//�� 
	return;
}

int main(){
	for(int i=0;i<maxn;i++) fa[i]=i;	//���鼯��ʼ�� 
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		G[s[0]][s[1]]=G[s[1]][s[0]] = 1;
		fa[find_fa(s[0])] = find_fa(s[1]);	//�ϲ�
		depth[s[0]]++;
		depth[s[1]]++; 
	}
	
	int root = find_fa(s[0]); //�ж��Ƿ���һ����ͨͼ 
	for(int i=0;i<maxn;i++)
		if(find_fa(i)!=i&&find_fa(i)!=root){
			cout<<"No Solution";
			return 0;
		}
		
	for(int i=0;i<maxn;i++)	//���������Ƚ��ĸ��� 
		if(depth[i]&1){
			cnt++;
			if(start==0)
				start = i;
		}

	if(cnt==0)	//��ŷ����·,�ҵ�һ����С�Ŀ�ʼ��� 
		for(int i=0;i<maxn;i++)
			if(depth[i]){
				start = i;
				break;
			}
			
	if(cnt!=0&&cnt!=2){//��Ϊ�����ĵ㲻��0����2�� 
		cout<<"No Solution";
		return 0;
	}
	dfs(start);
	cout<<res;
	return 0;
}
