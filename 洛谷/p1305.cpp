#include<cstdio>

const int maxn = 27;
char hashmap[maxn][2];	
//hashmap[0][0]��hashmap[0][1]�ֱ��ʾ'a'�����Ӻ��Һ��� 
char res[maxn]={};
int len_res=0;
int n;

void dfs(int root){
	res[len_res++] = root+'a';
	if(hashmap[root][0]!='*')
		dfs(hashmap[root][0]-'a');
	if(hashmap[root][1]!='*')
		dfs(hashmap[root][1]-'a');
	return;
}

int main(){
	scanf("%d",&n);
	int begin;
	char c;
	for(int i=0;i<n;i++){
		scanf("%c",&c);	//һ���س�Ҫ�������ַ����� 
		scanf("%c",&c);	//һ���س�Ҫ�������ַ�����
		scanf("%c",&c);
		if(i==0) begin = c-'a';
		scanf("%c %c",&hashmap[c-'a'][0],&hashmap[c-'a'][1]);
	}
	dfs(begin);
	printf("%s",res);
	return 0;	
}
