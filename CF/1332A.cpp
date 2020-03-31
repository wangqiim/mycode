#include<cstdio>

int main(){
	int T;
	scanf("%d",&T);
	int a,b,c,d;
	int x,y,x1,y1,x2,y2;
	while(T--){
		bool res = true;
		scanf("%d %d %d %d",&a,&b,&c,&d);	//×ó£¬ÓÒ£¬ÏÂ£¬ÉÏ 
		scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);
		int left = x - x1;
		int right = x2 - x;
		int up = y - y1;
		int down = y2 - y;
		if(a>=b){
			if(a-b>left)
				res = false;
		}else{
			if(b-a>right)
				res = false;
		}
		if(c>=d){
			if(c-d>up)
				res = false;
		}else{
			if(d-c>down)
				res = false;
		}
		if(x1==x2&&(a!=0||b!=0))
			res = false;
		if(y1==y2&&(c!=0||d!=0))
			res = false;
		if(res)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
