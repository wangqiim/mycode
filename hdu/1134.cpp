#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXN 9999	//�����ĵ�ÿһλa���Դ�0000-9999(ֻ��0~9�Ļ�MAXNΪ9)
#define DLEN 4		//��Ӧ��MAXN,������ÿλ(a)�洢ԭ�����ֵ�4λ
#define MAXSIZE 1010	//ͨ��cin>>����bigNumʱ����ʱ����cin���ַ�������Ϊ1010*4(DLEN)�� 
class  BigNum{
	private:
		int a[500];	//�ɿ��ƴ�����λ�� 	a[1]���λ��a[0]�� 
		int len;	//����a�ĳ��� 
	public:
		BigNum(){len=1;memset(a,0,sizeof(a));}	//���캯��
		BigNum(const int);	//��һ��int����ת���ɴ�����
		BigNum(const char*);	//��һ���ַ������͵ı���ת����һ��������
		BigNum(const BigNum &);	//���ƹ��캯��
		BigNum &operator=(const BigNum &); //���ظ�ֵ�����������֮����и�ֵ����
		friend istream& operator>>(istream&,BigNum&); //�������������,ʹ����Ԫ������������������д���������Կ�������������Ҳ������� 
		friend ostream& operator<<(ostream&,BigNum&); //������������

		BigNum operator+(const BigNum &)const; //���ؼӷ����������������֮����������, 
		BigNum operator-(const BigNum &)const; //���ؼ������������������֮����������
		BigNum operator*(const BigNum &)const; //���س˷����������������֮����������
		BigNum operator/(const int &)const; //���س����������������һ�����������������
		//ʹ�ú����Ͳ�����const����ֹ��Ϊ������,ȴ��Ա���޸�
		BigNum operator^(const int &)const; //������n�η�����
		int operator%(const int &)const; //������һ��int���͵ı�������ȡģ����
		bool operator>(const BigNum &T)const; //��������һ�������Ĵ�С�Ƚ�
		bool operator>(const int &t)const; //������һ��int���͵ı����Ĵ�С�Ƚ�
		void print(); //�������	 
};

BigNum::BigNum(const int b){	//��һ��int���͵ı���ת��Ϊ����
	int c,d=b;
	len=0;
	memset(a,0,sizeof(a));
	while(d>MAXN){
		c=d-(d/(MAXN+1))*(MAXN+1);	//�൱��d%(MAXN+1) 
		d=d/(MAXN+1);
		a[len++]=c;
	}
	a[len++]=d;
} 

BigNum::BigNum(const char *s){ //��һ���ַ������͵ı���ת��Ϊ����
	int t,k,index,L,i;
	memset(a,0,sizeof(a));
	L=strlen(s);
	len=L/DLEN;		//DLEN:������ÿλ(a)�洢ԭ�����ֵ�DLENλ
	if(L%DLEN) len++;	//����ȡ��
	index=0;
	for(i=L-1;i>=0;i-=DLEN){	//�ӵ�λ��ʼ�����ַ���s 
		t=0;
		k=i-DLEN+1;	//��һ��ѭ��ʱ��kָ��������λ 
		if(k<0) k=0;	//����ַ�������DLENλ 
		for(int j=k;j<=i;j++)	//��k~i�⼸λ�浽a��ȥ 
			t=t*10+s[j]-'0';
		a[index++]=t;
	} 
}

BigNum::BigNum(const BigNum &T):len(T.len){ //�������캯��
	int i;
	memset(a,0,sizeof(a));
	for(i=0;i<len;i++)
		a[i]=T.a[i];
}

BigNum & BigNum::operator=(const BigNum &n){ //���ظ�ֵ�����������֮�丳ֵ����
	int i;
	len=n.len;
	memset(a,0,sizeof(a));
	for(i=0;i<len;i++)
		a[i]=n.a[i];
	return *this; 
}

istream& operator>>(istream &in,BigNum &b){	//�ú����е�4Ӧ����DLEN�滻�� 
	char ch[MAXSIZE*4];	//��ʱ�ַ��� 
	in>>ch;
	int L=strlen(ch);
	int count=0,sum=0;
	int i;
	for(i=L-1;i>=0;){	//��ch�ĵ�λ��ʼ�� 
		sum=0;
		int t=1;
		for(int j=0;j<4&&i>=0;j++,i--,t*=10){	//��4λ�浽a������ 
			sum+=(ch[i]-'0')*t;
		}
		b.a[count++]=sum;
	}
	b.len=count++;
	return in;
}

ostream& operator<<(ostream& out,BigNum& b){ //������������ //�ú����е�4Ӧ����DLEN�滻��
	int i;
	cout<<b.a[b.len-1];	//��������λ�����֣����������Ҫ���ǰ��0����4λ 
	for(i=b.len-2;i>=0;i--){
		printf("%04d",b.a[i]);
	}
	return out;
}

BigNum BigNum::operator+(const BigNum &T)const{ //��������֮����������
	BigNum t(*this);	//����return; 
	int i,big;
	big = T.len>len?T.len:len;
	for(i=0;i<big;i++){
		t.a[i] += T.a[i];
		if(t.a[i]>MAXN){	//�н�λ 
			t.a[i+1]++;
			t.a[i]-=MAXN+1;
		}
	}
	if(t.a[big]!=0)	//���λ�����˽�λ 
		t.len=big+1;
	else t.len=big;
	return t;
}

BigNum BigNum::operator-(const BigNum &T)const{ //��������֮����������
	int i,j,big;
	bool flag;	//0��ʾ���������ڼ����֣�t1 = ������ 
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
	for(i=0;i<big;i++){	//�����λ��ʼ�� 
		if(t1.a[i]<t2.a[i]){	//��λ������ 
			j=i+1;
			while(t1.a[j]==0)	//һֱ�ҵ����Խ�λ��j 
				j++;
			t1.a[j--]--;
			while(j>i)
				t1.a[j--]+=MAXN;
			t1.a[i]+=MAXN+1-t2.a[i];	//MAXN+1Ϊ�Ӹ�λ�������� 
		}else 
			t1.a[i]-=t2.a[i];
	}
	t1.len=big;
	while(t1.a[len-1]==0 && t1.len>1){
		t1.len--;
		big--;
	}
	if(flag)	//������<=�������ı����λ�ķ��� 
		t1.a[big-1]=0-t1.a[big-1];
	return t1;
}

BigNum BigNum::operator*(const BigNum &T)const{ //��������֮������
	BigNum ret;
	int i,j,up;
	int temp,temp1;
	for(i=0;i<len;i++){
		up=0;	//up�ǽ�λ 
		for(j=0;j<T.len;j++){
			temp=a[i]*T.a[j]+ret.a[i+j]+up;
			if(temp>MAXN){
				temp1=temp-temp/(MAXN+1)*(MAXN+1);	//���� 
				up=temp/(MAXN+1);	//��λ�� 
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
	while(ret.a[ret.len-1]==0 && ret.len>1)	//�޷��γ�i+jλ������10*10(2*2-1=3λ) 50*50(2*2=4λ) 
		ret.len--;
	return ret;
}

bool BigNum::operator>(const BigNum &T)const{ //��������һ�������Ĵ�С�Ƚ�
	int ln;
	if(len>T.len) return true;
	else if(len==T.len){	//�������
		ln=len-1;
		while(a[ln]==T.a[ln]&&ln>=0)	//��λ��ȣ��жϵ�λ 
			ln--;
		if(ln>=0 && a[ln]>T.a[ln])
			return true;
		else
			return false;
	}else	//����С 
		return false; 
}

BigNum BigNum::operator/(const int &b)const{ //������һ�����������������
	BigNum ret;
	int i,down=0;
	for(i=len-1;i>=0;i--){
		ret.a[i]=(a[i]+down*(MAXN+1))/b;	
		down=a[i]+down*(MAXN+1)-ret.a[i]*b;	//downΪ��λ������ 
	}
	ret.len=len;
	while(ret.a[ret.len-1]==0 && ret.len>1)
		ret.len--;
	return ret;
}

int BigNum::operator%(const int &b)const{ //������һ�� int���͵ı�������ȡģ
	int i,d=0;
	for(i=len-1;i>=0;i--)	//����������(a*b)%c = (a%c)*b%c 
		d=((d*(MAXN+1))%b+a[i])%b;
	return d;
}

BigNum BigNum::operator^(const int &n)const{ //������n�η�����
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

bool BigNum::operator>(const int &t)const{ //������һ��int���͵ı����Ĵ�С�Ƚ�
	BigNum b(t);
	return *this>b;
}

void BigNum::print(){ //�������
	int i;
	printf("%d",a[len-1]);
	for(i=len-2;i>=0;i--)
		printf("%04d",a[i]);
	printf("\n");
}

BigNum f[110];	//�������� 
int main(){
    f[0]=1;
    for(int i=1;i<=100;i++)
        f[i]=f[i-1]*(4*i-2)/(i+1);//������������ʽ
    int n;
    while(scanf("%d",&n)==1){
        if(n==-1)
            break;
        f[n].print();
    }
    return 0;
}
