#include<cstdio>
#include<cstring>

struct bign{	//存123时: d={3,2,1}llen =3; 
	int d[5000];
	int len;
	bign(){
		memset(d,0,sizeof(d));
		len = 0;}
};

bign change(char str[]){	//通过字符串读取大整数 
	//str[]={'1','2','3'} ->a.b={3,2,1}
	bign a;
	a.len = strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i] = str[a.len-1-i] - '0';
	}
	return a;
}

bign add(bign a,bign b){	//大整数之间进行加法 
	bign c;
	int carry = 0;	//进位
	for(int i=0;i<a.len||i<b.len;i++){
		int temp = a.d[i]+b.d[i] + carry;
		c.d[c.len++] = temp%10;
		carry = temp/10;
	} 
	if(carry!=0) c.d[c.len++] = carry;
	return c;
}

void print(bign a){	//输出大整数 
	for(int i=a.len-1;i>=0;i--)
		printf("%d",a.d[i]);
	return;
}

int main(){
	int n;
	scanf("%d",&n);
	bign pp;
	char s[2] = {'1','\0'};
	bign p = change(s);
	s[0] = '0';
	bign res = change(s);
	for(int i=1;i<=n;i++){
		res = add(pp, p);
		pp = p;
		p = res;
	}
	print(res);
	return 0;
} 
