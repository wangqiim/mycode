#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn  = 100005;	//������
struct{
	int val;
	int ff;//�����
	int ch[2];	//ch[0]����,ch[1]�Һ���
	int size;	//��С,��ǰ����Լ��������ӵ�size��
	int mark;	//����Ǵ󷨺ð� 
}t[maxn];
int root = 0;
int tot = 0;
int n,m;

void pushup(int x){
	t[x].size = t[t[x].ch[0]].size + 1 + t[t[x].ch[1]].size;
	return;
}

void pushdown(int x){	//��������Ƶ������� 
	if(t[x].mark){
        t[t[x].ch[0]].mark^=1;
        t[t[x].ch[1]].mark^=1;
        t[x].mark=0;
        swap(t[x].ch[0],t[x].ch[1]);
	}
	return;
}

void rotate(int x){	//x������תһ�� 
	int y = t[x].ff;	//y��x�ĸ��� 
	int z = t[y].ff;	//z��y��үү 
	pushdown(y);
	pushdown(x);
	int k = t[y].ch[1]==x; //k=0,x�����ӣ�k=1,x���Һ���
	t[z].ch[t[z].ch[1]==y] = x;//y��λ�û���x ����:t[z].ch[1]==y��ֵ��ʾ��y�����Һ���
	t[x].ff = z;	//x�ĸ��ױ��z
	t[y].ch[k] = t[x].ch[k^1];	//���k��0,��y�����x���Һ��ӣ����k��1,y�����x������
	t[t[x].ch[k^1]].ff = y;	//���´�x->y���Ǹ����ӵĸ���
	t[x].ch[k^1] = y;	//����yΪx�ĺ��� 
	t[y].ff=x;	//����y�ĸ���
	pushup(y);
	//pushup(x); x��splay���������һ�ξ͹��� 
	return;
}
//��������ʹ���˺ܶ�С���ɣ����Խ���������������������� ��
//��Ҫ���µĽ���ܽ�:z.ch;x.ff ;y.ch ;x.ch;x.ch.ff;y.ff�� 
/*  rotate(x) �������Խ������6�����,ʹ��x������תһ����
		z    z  z  z       
 	   /    /   \  \ 
      y    y     y  y     y  y
     /     \    /   \    /   \
    x       x  x     x  x     x 
*/
void splay(int x,int goal){		//����Ľ��x,goal���ܻ�������ѭ��!
	//��x��תΪ��goal�ĺ���,���goalΪ0,����ת������ 
	while(t[x].ff!=goal){
		int y = t[x].ff;
		int z = t[y].ff;
		if(z!=goal){	//y���Ǹ��ڵ� 
			(t[z].ch[0]==y)^(t[y].ch[0]==x)?rotate(x):rotate(y);
			//���xyͬ�����ͬ�ң�������תy�������壩
			//��תy��ʱ����xҲ���ϴ���һ�㡣����Ҫ�ж� z!=goal
		}
		rotate(x);	//��x����һ����� 
	}
	pushup(x);
	if(goal==0) root = x;
	return;
}

void insert(int x){	//����x
	int u=root,ff=0;
	while(u&&t[u].val!=x){//��u���ڲ���û���ƶ�����ǰ��ֵ
		ff = u;
		u = t[u].ch[x>t[u].val];//���ڵ�ǰλ���������ң�����������
	}
	//�����������Ľ�㣬�򴴽�һ�������ȥ 
	u = ++tot;	//�½��
	if(ff)	//��������Ǹ��ڵ� 
		t[ff].ch[x>t[ff].val] = u;
	t[u].ch[0] = t[u].ch[1] = 0;
	t[tot].ff = ff;
	t[tot].val = x;
	t[tot].size = 1;
	splay(u,0);	//������ƶ����������ֽṹ��ƽ�⡣ 
}

int kth(int x){	//�������е�k���� 
    int u=root;
    while(1){
    	pushdown(u);
        int y=t[u].ch[0];//�����
        if(x>t[y].size+1){
        //�������������ӵĴ�С�͵�ǰ�ڵ������Ҫ��
            x-=t[y].size+1;//��������
            u=t[u].ch[1];//��ô��ǰ��������һ�����Ҷ�������
        }
        else//����Ļ��ڵ�ǰ�ڵ����������ϲ���
            if(t[y].size>=x)//����ӵĽڵ����㹻
                u=y;//��������ϼ�����
            else//��������ڵ�ǰ���ڵ���
                return u;	//ע�⣬�����ǻ�õ�ǰ���!!!!!!!!!!!!!!!!!!!!!!!!! 
    }
}

void Work(int l,int r){
    l=kth(l);
    r=kth(r+2);
    splay(l,0);
    splay(r,l);
    t[t[t[root].ch[1]].ch[0]].mark^=1;	//���ϱ��
	return; 
}

void write(int u){	//����������
	pushdown(u);
	if(t[u].ch[0]) write(t[u].ch[0]);
    if(t[u].val>=1&&t[u].val<=n) printf("%d ",t[u].val);
    if(t[u].ch[1])write(t[u].ch[1]);
	return ;
}

int main(){
	insert(0x7fffffff);		//û��������Ļ� 
	insert(-0x80000000);	//����Ľ��x,goal���ܻ�delete����splay������ѭ��!
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) insert(i);
	int l,r;
	while(m--){
		scanf("%d%d",&l,&r);
		Work(l,r);
	}
	write(root);
	putchar('\n');
	return 0;
}

