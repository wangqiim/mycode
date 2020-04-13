#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXN 9999	//大数的的每一位a可以存0000-9999(只存0~9的话MAXN为9)
#define DLEN 4		//对应于MAXN,大数的每位(a)存储原来数字的4位
#define MAXSIZE 1010	//通过cin>>读入bigNum时，临时保存cin的字符串长度为1010*4(DLEN)。 
class  BigNum{
	private:
		int a[500];	//可控制大数的位数 	a[1]存的位比a[0]高 
		int len;	//数组a的长度 
	public:
		BigNum(){len=1;memset(a,0,sizeof(a));}	//构造函数
		BigNum(const int);	//将一个int类型转换成大整数
		BigNum(const char*);	//将一个字符串类型的变量转换成一个大整数
		BigNum(const BigNum &);	//复制构造函数
		BigNum &operator=(const BigNum &); //重载赋值运算符，大数之间进行赋值运算
		friend istream& operator>>(istream&,BigNum&); //重载输入运算符,使用有元函数把两个操作数都写出来（可以控制左操作数和右操作数） 
		friend ostream& operator<<(ostream&,BigNum&); //重载输出运算符

		BigNum operator+(const BigNum &)const; //重载加法运算符，两个大数之间的相加运算, 
		BigNum operator-(const BigNum &)const; //重载减法运算符，两个大数之间的相减运算
		BigNum operator*(const BigNum &)const; //重载乘法运算符，两个大数之间的相乘运算
		BigNum operator/(const int &)const; //重载除法运算符，大数对一个整数进行相除运算
		//使用函数和参数加const。防止作为操作数,却成员被修改
		BigNum operator^(const int &)const; //大数的n次方运算
		int operator%(const int &)const; //大数对一个int类型的变量进行取模运算
		bool operator>(const BigNum &T)const; //大数和另一个大数的大小比较
		bool operator>(const int &t)const; //大数和一个int类型的变量的大小比较
		void print(); //输出大数	 
};

BigNum::BigNum(const int b){	//将一个int类型的变量转化为大数
	int c,d=b;
	len=0;
	memset(a,0,sizeof(a));
	while(d>MAXN){
		c=d-(d/(MAXN+1))*(MAXN+1);	//相当于d%(MAXN+1) 
		d=d/(MAXN+1);
		a[len++]=c;
	}
	a[len++]=d;
} 

BigNum::BigNum(const char *s){ //将一个字符串类型的变量转化为大数
	int t,k,index,L,i;
	memset(a,0,sizeof(a));
	L=strlen(s);
	len=L/DLEN;		//DLEN:大数的每位(a)存储原来数字的DLEN位
	if(L%DLEN) len++;	//向上取整
	index=0;
	for(i=L-1;i>=0;i-=DLEN){	//从低位开始遍历字符串s 
		t=0;
		k=i-DLEN+1;	//第一次循环时是k指向倒数第四位 
		if(k<0) k=0;	//如果字符串不足DLEN位 
		for(int j=k;j<=i;j++)	//把k~i这几位存到a中去 
			t=t*10+s[j]-'0';
		a[index++]=t;
	} 
}

BigNum::BigNum(const BigNum &T):len(T.len){ //拷贝构造函数
	int i;
	memset(a,0,sizeof(a));
	for(i=0;i<len;i++)
		a[i]=T.a[i];
}

BigNum & BigNum::operator=(const BigNum &n){ //重载赋值运算符，大数之间赋值运算
	int i;
	len=n.len;
	memset(a,0,sizeof(a));
	for(i=0;i<len;i++)
		a[i]=n.a[i];
	return *this; 
}

istream& operator>>(istream &in,BigNum &b){	//该函数中的4应该用DLEN替换？ 
	char ch[MAXSIZE*4];	//临时字符串 
	in>>ch;
	int L=strlen(ch);
	int count=0,sum=0;
	int i;
	for(i=L-1;i>=0;){	//从ch的低位开始存 
		sum=0;
		int t=1;
		for(int j=0;j<4&&i>=0;j++,i--,t*=10){	//读4位存到a数字里 
			sum+=(ch[i]-'0')*t;
		}
		b.a[count++]=sum;
	}
	b.len=count++;
	return in;
}

ostream& operator<<(ostream& out,BigNum& b){ //重载输出运算符 //该函数中的4应该用DLEN替换？
	int i;
	cout<<b.a[b.len-1];	//先输出最高位的数字，其后的输出都要添加前置0补齐4位 
	for(i=b.len-2;i>=0;i--){
		printf("%04d",b.a[i]);
	}
	return out;
}

BigNum BigNum::operator+(const BigNum &T)const{ //两个大数之间的相加运算
	BigNum t(*this);	//用来return; 
	int i,big;
	big = T.len>len?T.len:len;
	for(i=0;i<big;i++){
		t.a[i] += T.a[i];
		if(t.a[i]>MAXN){	//有进位 
			t.a[i+1]++;
			t.a[i]-=MAXN+1;
		}
	}
	if(t.a[big]!=0)	//最高位产生了进位 
		t.len=big+1;
	else t.len=big;
	return t;
}

BigNum BigNum::operator-(const BigNum &T)const{ //两个大数之间的相减运算
	int i,j,big;
	bool flag;	//0表示被减数大于减数字，t1 = 被减数 
	BigNum t1,t2;
	if(*this>T){	//t1>t2
		t1=*this;
		t2=T;
		flag=0;
	}else{
		t1=T;
		t2=*this;
		flag=1;
	}
	big=t1.len;
	for(i=0;i<big;i++){	//从最低位开始减 
		if(t1.a[i]<t2.a[i]){	//该位不够减 
			j=i+1;
			while(t1.a[j]==0)	//一直找到可以借位的j 
				j++;
			t1.a[j--]--;
			while(j>i)
				t1.a[j--]+=MAXN;
			t1.a[i]+=MAXN+1-t2.a[i];	//MAXN+1为从高位借来的数 
		}else 
			t1.a[i]-=t2.a[i];
	}
	t1.len=big;
	while(t1.a[len-1]==0 && t1.len>1){
		t1.len--;
		big--;
	}
	if(flag)	//被减数<=减数，改变最高位的符号 
		t1.a[big-1]=0-t1.a[big-1];
	return t1;
}

BigNum BigNum::operator*(const BigNum &T)const{ //两个大数之间的相乘
	BigNum ret;
	int i,j,up;
	int temp,temp1;
	for(i=0;i<len;i++){
		up=0;	//up是进位 
		for(j=0;j<T.len;j++){
			temp=a[i]*T.a[j]+ret.a[i+j]+up;
			if(temp>MAXN){
				temp1=temp-temp/(MAXN+1)*(MAXN+1);	//余数 
				up=temp/(MAXN+1);	//进位数 
				ret.a[i+j]=temp1;
			}else{
				up=0;
				ret.a[i+j]=temp;
			}
		}
		if(up!=0)
			ret.a[i+j]=up;
	}
	ret.len=i+j; 
	while(ret.a[ret.len-1]==0 && ret.len>1)	//无法形成i+j位举例：10*10(2*2-1=3位) 50*50(2*2=4位) 
		ret.len--;
	return ret;
}

bool BigNum::operator>(const BigNum &T)const{ //大数和另一个大数的大小比较
	int ln;
	if(len>T.len) return true;
	else if(len==T.len){	//长度相等
		ln=len-1;
		while(a[ln]==T.a[ln]&&ln>=0)	//该位相等，判断低位 
			ln--;
		if(ln>=0 && a[ln]>T.a[ln])
			return true;
		else
			return false;
	}else	//长度小 
		return false; 
}

BigNum BigNum::operator/(const int &b)const{ //大数对一个整数进行相除运算
	BigNum ret;
	int i,down=0;
	for(i=len-1;i>=0;i--){
		ret.a[i]=(a[i]+down*(MAXN+1))/b;	
		down=a[i]+down*(MAXN+1)-ret.a[i]*b;	//down为高位的余数 
	}
	ret.len=len;
	while(ret.a[ret.len-1]==0 && ret.len>1)
		ret.len--;
	return ret;
}

int BigNum::operator%(const int &b)const{ //大数对一个 int类型的变量进行取模
	int i,d=0;
	for(i=len-1;i>=0;i--)	//利用了性质(a*b)%c = (a%c)*b%c 
		d=((d*(MAXN+1))%b+a[i])%b;
	return d;
}

BigNum BigNum::operator^(const int &n)const{ //大数的n次方运算
	BigNum t,ret(1);
	int i;
	if(n<0)	exit(-1);
	if(n==0) return 1;
	if(n==1) return *this;
	int m=n;
	while(m>1){
		t=*this;
		for(i=1;(i<<1)<=m;i<<=1)
			t=t*t;
		m-=i;
		ret=ret*t;
		if(m==1) ret=ret*(*this);
	}
	return ret;
}

bool BigNum::operator>(const int &t)const{ //大数和一个int类型的变量的大小比较
	BigNum b(t);
	return *this>b;
}

void BigNum::print(){ //输出大数
	int i;
	printf("%d",a[len-1]);
	for(i=len-2;i>=0;i--)
		printf("%04d",a[i]);
	printf("\n");
}

BigNum f[110];	//卡特兰数 
int main(){
    f[0]=1;
    for(int i=1;i<=100;i++)
        f[i]=f[i-1]*(4*i-2)/(i+1);//卡特兰数递推式
    int n;
    while(scanf("%d",&n)==1){
        if(n==-1)
            break;
        f[n].print();
    }
    return 0;
}
