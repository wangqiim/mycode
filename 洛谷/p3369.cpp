#include<cstdio>

const int maxn  = 100005;	//结点个数
struct{
	int val;
	int ff;//父结点
	int ch[2];	//ch[0]左孩子,ch[1]右孩子
	int cnt;	//数量,当前结点的值重复的次数 
	int size;	//大小,当前结点以及两个孩子的size和 
}t[maxn];
int root = 0;
int tot = 0;

void pushup(int x){
	t[x].size = t[t[x].ch[0]].size + t[x].cnt + t[t[x].ch[1]].size;
	return;
}

void rotate(int x){	//x向上旋转一步 
	int y = t[x].ff;	//y是x的父亲 
	int z = t[y].ff;	//z是y的爷爷 
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

void find(int x){	//查找x的位置，并将其旋转到根节点。
	int u = root;
	if(!u) return;	//树空
	while(t[u].ch[x>t[u].val]&&x!=t[u].val)	//当存在儿子，且不等 
		u = t[u].ch[x>t[u].val];	
	splay(u,0);	//把当前位置旋转到根节点 
}

void insert(int x){	//插入x
	int u=root,ff=0;
	while(u&&t[u].val!=x){//当u存在并且没有移动到当前的值
		ff = u;
		u = t[u].ch[x>t[u].val];//大于当前位置则向右找，否则向左找
	}
	if(u){
		t[u].cnt++;
	}else{	//不存在这样的结点，则创建一个结点插进去 
		u = ++tot;	//新结点
		if(ff)	//如果父结点非根节点 
			t[ff].ch[x>t[ff].val] = u;
		t[u].ch[0] = t[u].ch[1] = 0;
		t[tot].ff = ff;
		t[tot].val = x;
		t[tot].cnt = 1;
		t[tot].size = 1;
	}
	splay(u,0);	//根结点移动到根，保持结构的平衡。 
}


int Next(int x,int f){	//f=0:查找x的前驱，f=1:查找x的后继 
	find(x);//把x旋转到根节点 
	int u = root;
	if(t[u].val>x&&f) return u;//如果当前结点的值大于x，并且要查找的是后继
	if(t[u].val<x&&!f) return u;	//如果当前结点的值小于x,并且要找的是前驱
	u = t[u].ch[f];
	while(t[u].ch[f^1]) 	//反着跳转 
		u = t[u].ch[f^1];
	return u;
}
//注意：此处不splay了，因为find的时候已经splay过了。 
//为了防止跳转是第一个前驱，在开始时候插入一个-INF 和INF挺好的。 

void Delete(int x){	//默认需要删除的结点一定存在。 
    int last=Next(x,0);	//查找x的前驱
    int next=Next(x,1);	//查找x的后继
    splay(last,0);
	splay(next,last);
    //将前驱旋转到根节点，后继旋转到根节点下面
    //很明显，此时后继是前驱的右儿子，x是后继的左儿子，并且x是叶子节点
    int del=t[next].ch[0];//后继的左儿子
    if(t[del].cnt>1){
        t[del].cnt--;//直接减少一个
        splay(del,0);//旋转
    }
    else
        t[next].ch[0]=0;//这个节点直接删去
    splay(next,0);	//通过splay继而也更新了size 
    return;
}//注意：此时结点虽然被删去了，但是那个空间没有被释放掉。还占据着数组中的位置 

int kth(int x){	//查找树中第k个数 
    int u=root;
    if(t[u].size<x)//如果当前树上没有这么多数
        return 0;//不存在
    while(1){
        int y=t[u].ch[0];//左儿子
        if(x>t[y].size+t[u].cnt){
        //如果排名比左儿子的大小和当前节点的数量要大
            x-=t[y].size+t[u].cnt;//数量减少
            u=t[u].ch[1];//那么当前排名的数一定在右儿子上找
        }
        else//否则的话在当前节点或者左儿子上查找
            if(t[y].size>=x)//左儿子的节点数足够
                u=y;//在左儿子上继续找
            else//否则就是在当前根节点上
                return t[u].val;
    }
}

int rank(int x){	//查询x数的排名(后来加的)
	find(x);
	return t[t[root].ch[0]].size;	//考虑到已经插入了一个-INF抵消+1 
}

int main(){
	insert(0x7fffffff);		//没有这两句的话 
	insert(-0x80000000);	//错误的结点x,goal可能会delete调用splay引发死循环!
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

