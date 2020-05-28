#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int T;
	scanf("%d",&T);
    while (T--) {
        double h,c,t;
		scanf("%lf%lf%lf", &h, &c, &t);
        int ans = 1;
        double dh = h - t;
        double dc = t - c;
        if(dh == 0)
        	ans = 1;
        else if (dh >= dc){
            ans = 2;
        }else {
        	double temp;
            long long x = (long long)(dh / (dc - dh));
            ans = 2 * x + 1;
        	temp = fabs((x * ( h + c) + h) / (2 * x + 1) - t);
            x++;
            if(fabs((x * ( h + c) + h) / (2 * x + 1) - t) < temp){
                ans = 2 * x + 1;
                temp = fabs((x * ( h + c) + h) / (2 * x + 1) - t);
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
