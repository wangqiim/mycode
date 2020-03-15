#include<cstdio>
#include<queue> 
using namespace std;

const int maxn = 1000006;
int heap[maxn],len=0;
int n;	//操作的个数 

void heap_update(int x){	//调整x及其的所有子结点 
	while(x*2<=len){
		int i=2*x;
		if(i+1<=len&&heap[i+1]<heap[i])
			i = i+1;	//i表示两个结点中更小的那一个
		if(heap[i]<heap[x]){
			int t = heap[i];
			heap[i] = heap[x];
			heap[x] = t;
			x = i;	
		}
		else break;
	}
	return;
}

void heap_erase(){	//删除堆顶的元素 
	heap[1] = heap[len--];
	heap_update(1);
	return;
}

void head_insert(int v){	//插入数据v 
	heap[++len] = v;	//堆顶移动到最后 
	int x = len;	//更新他的父结点一直到堆顶 
	int fa = x/2;
	while(fa>=1){
		if(heap[fa]<=heap[x])
			break;
		else{
			int t = heap[fa];
			heap[fa] = heap[x];
			heap[x] = t;
			x = fa;
			fa /= 2;	
		}
	}
	return;
}

int main(){
	scanf("%d",&n);
	int o,x;
	for(int i=0; i<n; i++){
		scanf("%d",&o);
		if(o==1){
			scanf("%d",&x);
			head_insert(x);
		}else if(o==2) printf("%d\n",heap[1]);
		else heap_erase();
	}
	return 0;
}
