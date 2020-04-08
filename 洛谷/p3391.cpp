#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn  = 100005;	//结点个数
struct{
	int val;
	int ff;//父结点
	int ch[2];	//ch[0]左孩子,ch[1]右孩子
	int size;	//大小,当前结点以及两个孩子的size和
	int mark;	//懒标记大法好啊 
}t[maxn];
int root = 0;
int tot = 0;
int n,m;

void pushup(int x){
	t[x].size = t[t[x].ch[0]].size + 1 + t[t[x].ch[1]].size;
	return;
}

void pushdown(int x){	//把懒标记推到孩子上 
	if(t[x].mark){
        t[t[x].ch[0]].mark^=1;
        t[t[x].ch[1]].mark^=1;
        t[x].mark=0;
        swap(t[x].ch[0],t[x].ch[1]);
	}
	return;
}

void rotate(int x){	//x向上旋转一步 
	int y = t[x].ff;	//y是x的父亲 
	int z = t[y].ff;	//z是y的爷爷 
	pushdown(y);
	pushdown(x);
	int k = t[y].ch[1]==x; //k=0,x是左孩子，k=1,x是右孩子
	t[z].ch[t[z].ch[1]==y] = x;//y的位置会变成x 技巧:t[z].ch[1]==y的值表示了y是左右孩子
	t[x].ff = z;	//x的父亲变成z
	t[y].ch[k] = t[x].ch[k^1];	//如果k是0,则y获得了x的右孩子，如果k是1,y获得了x的左孩子
	t[t[x].ch[k^1]].ff = y;	//更新从x->y的那个孩子的父亲
	t[x].ch[k^1] = y;	//更新y为x的孩子 
	t[y].ff=x;	//更新y的父亲
	pushup(y);
	//pushup(x); x在splay操作后更新一次就够了 
	return;
}
//上述代码使用了很多小技巧，可以解决所有情况（如下六种情况 ）
//需要更新的结点总结:z.ch;x.ff ;y.ch ;x.ch;x.ch.ff;y.ff； 
/*  rotate(x) 函数可以解决下列6种情况,使得x向上旋转一步。
		z    z  z  z       
 	   /    /   \  \ 
      y    y     y  y     y  y
     /     \    /   \    /   \
    x       x  x     x  x     x 
*/
void splay(int x,int goal){		//错误的结点x,goal可能会引发死循环!
	//将x旋转为是goal的孩子,如果goal为0,则旋转到根。 
	while(t[x].ff!=goal){
		int y = t[x].ff;
		int z = t[y].ff;
		if(z!=goal){	//y不是根节点 
			(t[z].ch[0]==y)^(t[y].ch[0]==x)?rotate(x):rotate(y);
			//如果xy同左或者同右，则先旋转y，（定义）
			//在转y的时候会把x也向上代了一层。所以要判断 z!=goal
		}
		rotate(x);	//把x上旋一个结点 
	}
	pushup(x);
	if(goal==0) root = x;
	return;
}

void insert(int x){	//插入x
	int u=root,ff=0;
	while(u&&t[u].val!=x){//当u存在并且没有移动到当前的值
		ff = u;
		u = t[u].ch[x>t[u].val];//大于当前位置则向右找，否则向左找
	}
	//不存在这样的结点，则创建一个结点插进去 
	u = ++tot;	//新结点
	if(ff)	//如果父结点非根节点 
		t[ff].ch[x>t[ff].val] = u;
	t[u].ch[0] = t[u].ch[1] = 0;
	t[tot].ff = ff;
	t[tot].val = x;
	t[tot].size = 1;
	splay(u,0);	//根结点移动到根，保持结构的平衡。 
}

int kth(int x){	//查找树中第k个数 
    int u=root;
    while(1){
    	pushdown(u);
        int y=t[u].ch[0];//左儿子
        if(x>t[y].size+1){
        //如果排名比左儿子的大小和当前节点的数量要大
            x-=t[y].size+1;//数量减少
            u=t[u].ch[1];//那么当前排名的数一定在右儿子上找
        }
        else//否则的话在当前节点或者左儿子上查找
            if(t[y].size>=x)//左儿子的节点数足够
                u=y;//在左儿子上继续找
            else//否则就是在当前根节点上
                return u;	//注意，这里是获得当前结点!!!!!!!!!!!!!!!!!!!!!!!!! 
    }
}

void Work(int l,int r){
    l=kth(l);
    r=kth(r+2);
    splay(l,0);
    splay(r,l);
    t[t[t[root].ch[1]].ch[0]].mark^=1;	//打上标记
	return; 
}

void write(int u){	//中序遍历输出
	pushdown(u);
	if(t[u].ch[0]) write(t[u].ch[0]);
    if(t[u].val>=1&&t[u].val<=n) printf("%d ",t[u].val);
    if(t[u].ch[1])write(t[u].ch[1]);
	return ;
}

int main(){
	insert(0x7fffffff);		//没有这两句的话 
	insert(-0x80000000);	//错误的结点x,goal可能会delete调用splay引发死循环!
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

