#include<cstdio>
/*���õĽ�����������������Ȧ��һ��0��������������(����Ժ�ı߽�)DFSһ�ξͿ���*/
const int maxn = 30;
int nums[maxn][maxn];
int n;
int nowc=0;	
int c=0;	//�ݹ麯��dfs������ڵ�nowk��ɫˢ��K��ɫ 
bool isround;	//����Χ

void dfs(int i,int j){	//(i,j)��0,ˢ��k��ɫ��true��ʾ�Ǳպ�ȦΧ������ 
	nums[i][j] = c;
	//����Ⱦɫ��������
	if(i==0) isround = false; //�� 
	else if(nums[i-1][j]==nowc)
		dfs(i-1,j);
	if(j==n-1) isround = false; //�� 
	else if(nums[i][j+1]==nowc)
		dfs(i,j+1);
	if(i==n-1) isround = false; //�� 
	else if(nums[i+1][j]==nowc)
		dfs(i+1,j);
	if(j==0) isround = false; //��
	else if(nums[i][j-1]==nowc)
		dfs(i,j-1); 
	return;
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&nums[i][j]);
	//�ҵ�һ��0ʱ,���԰�������ͨ��0ȫˢ��3,��������߽�,�򲻷��ϡ����ˢ�궼û�����߽磬��˵����1��Χ,ȫ��ˢ��2 
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(nums[i][j]==0){
				isround = true;
				nowc=0;
				c=3;
				dfs(i,j);
				if(isround){
					nowc=3;
					c=2;
					dfs(i,j);//����������Ⱦ��2
				}
			}

	for(int i=0;i<n;i++){//������� 
		for(int j=0;j<n;j++){
			if(nums[i][j]==3)
				printf("%d",0);
			else
				printf("%d",nums[i][j]);
			if(j!=n-1)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}
