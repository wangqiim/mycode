#include<cstdio>

const int maxn  = 100005;	//������
struct{
	int val;
	int ff;//�����
	int ch[2];	//ch[0]����,ch[1]�Һ���
	int cnt;	//����,��ǰ����ֵ�ظ��Ĵ��� 
	int size;	//��С,��ǰ����Լ��������ӵ�size�� 
}t[maxn];
int root = 0;
int tot = 0;

void pushup(int x){
	t[x].size = t[t[x].ch[0]].size + t[x].cnt + t[t[x].ch[1]].size;
	return;
}

void rotate(int x){	//x������תһ�� 
	int y = t[x].ff;	//y��x�ĸ��� 
	int z = t[y].ff;	//z��y��үү 
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

void find(int x){	//����x��λ�ã���������ת�����ڵ㡣
	int u = root;
	if(!u) return;	//����
	while(t[u].ch[x>t[u].val]&&x!=t[u].val)	//�����ڶ��ӣ��Ҳ��� 
		u = t[u].ch[x>t[u].val];	
	splay(u,0);	//�ѵ�ǰλ����ת�����ڵ� 
}

void insert(int x){	//����x
	int u=root,ff=0;
	while(u&&t[u].val!=x){//��u���ڲ���û���ƶ�����ǰ��ֵ
		ff = u;
		u = t[u].ch[x>t[u].val];//���ڵ�ǰλ���������ң�����������
	}
	if(u){
		t[u].cnt++;
	}else{	//�����������Ľ�㣬�򴴽�һ�������ȥ 
		u = ++tot;	//�½��
		if(ff)	//��������Ǹ��ڵ� 
			t[ff].ch[x>t[ff].val] = u;
		t[u].ch[0] = t[u].ch[1] = 0;
		t[tot].ff = ff;
		t[tot].val = x;
		t[tot].cnt = 1;
		t[tot].size = 1;
	}
	splay(u,0);	//������ƶ����������ֽṹ��ƽ�⡣ 
}


int Next(int x,int f){	//f=0:����x��ǰ����f=1:����x�ĺ�� 
	find(x);//��x��ת�����ڵ� 
	int u = root;
	if(t[u].val>x&&f) return u;//�����ǰ����ֵ����x������Ҫ���ҵ��Ǻ��
	if(t[u].val<x&&!f) return u;	//�����ǰ����ֵС��x,����Ҫ�ҵ���ǰ��
	u = t[u].ch[f];
	while(t[u].ch[f^1]) 	//������ת 
		u = t[u].ch[f^1];
	return u;
}
//ע�⣺�˴���splay�ˣ���Ϊfind��ʱ���Ѿ�splay���ˡ� 
//Ϊ�˷�ֹ��ת�ǵ�һ��ǰ�����ڿ�ʼʱ�����һ��-INF ��INFͦ�õġ� 

void Delete(int x){	//Ĭ����Ҫɾ���Ľ��һ�����ڡ� 
    int last=Next(x,0);	//����x��ǰ��
    int next=Next(x,1);	//����x�ĺ��
    splay(last,0);
	splay(next,last);
    //��ǰ����ת�����ڵ㣬�����ת�����ڵ�����
    //�����ԣ���ʱ�����ǰ�����Ҷ��ӣ�x�Ǻ�̵�����ӣ�����x��Ҷ�ӽڵ�
    int del=t[next].ch[0];//��̵������
    if(t[del].cnt>1){
        t[del].cnt--;//ֱ�Ӽ���һ��
        splay(del,0);//��ת
    }
    else
        t[next].ch[0]=0;//����ڵ�ֱ��ɾȥ
    splay(next,0);	//ͨ��splay�̶�Ҳ������size 
    return;
}//ע�⣺��ʱ�����Ȼ��ɾȥ�ˣ������Ǹ��ռ�û�б��ͷŵ�����ռ���������е�λ�� 

int kth(int x){	//�������е�k���� 
    int u=root;
    if(t[u].size<x)//�����ǰ����û����ô����
        return 0;//������
    while(1){
        int y=t[u].ch[0];//�����
        if(x>t[y].size+t[u].cnt){
        //�������������ӵĴ�С�͵�ǰ�ڵ������Ҫ��
            x-=t[y].size+t[u].cnt;//��������
            u=t[u].ch[1];//��ô��ǰ��������һ�����Ҷ�������
        }
        else//����Ļ��ڵ�ǰ�ڵ����������ϲ���
            if(t[y].size>=x)//����ӵĽڵ����㹻
                u=y;//��������ϼ�����
            else//��������ڵ�ǰ���ڵ���
                return t[u].val;
    }
}

int rank(int x){	//��ѯx��������(�����ӵ�)
	find(x);
	return t[t[root].ch[0]].size;	//���ǵ��Ѿ�������һ��-INF����+1 
}

int main(){
	insert(0x7fffffff);		//û��������Ļ� 
	insert(-0x80000000);	//����Ľ��x,goal���ܻ�delete����splay������ѭ��!
	int n;
	scanf("%d",&n);
	int opt,x;
	for(int i=0;i<n;i++){
		scanf("%d%d",&opt,&x);
		if(opt==1){
			insert(x);
		}else if(opt==2){
			Delete(x);
		}else if(opt==3){
			printf("%d\n",rank(x));
		}else if(opt==4){
			printf("%d\n",kth(x+1));
		}else if(opt==5){
			printf("%d\n",t[Next(x,0)].val);
		}else{
			printf("%d\n",t[Next(x,1)].val);
		}
	}
	return 0;
}

