#include<cstdio>
/*更好的解决方案是在最外层在圈上一层0，这样从最左上(添加以后的边界)DFS一次就可以*/
const int maxn = 30;
int nums[maxn][maxn];
int n;
int nowc=0;	
int c=0;	//递归函数dfs里把相邻的nowk颜色刷成K颜色 
bool isround;	//被包围

void dfs(int i,int j){	//(i,j)是0,刷成k颜色。true表示是闭合圈围起来的 
	nums[i][j] = c;
	//依次染色上右下左
	if(i==0) isround = false; //上 
	else if(nums[i-1][j]==nowc)
		dfs(i-1,j);
	if(j==n-1) isround = false; //右 
	else if(nums[i][j+1]==nowc)
		dfs(i,j+1);
	if(i==n-1) isround = false; //下 
	else if(nums[i+1][j]==nowc)
		dfs(i+1,j);
	if(j==0) isround = false; //左
	else if(nums[i][j-1]==nowc)
		dfs(i,j-1); 
	return;
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&nums[i][j]);
	//找到一个0时,尝试把他能连通的0全刷成3,如果碰到边界,则不符合。如果刷完都没碰到边界，则说明被1包围,全部刷成2 
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
					dfs(i,j);//被包裹，再染成2
				}
			}

	for(int i=0;i<n;i++){//输出矩阵 
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
