#include<cstdio>
using namespace std;
 
int main() {
    int t, x, y, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &x, &y, &n);
        printf("%d\n", n - (n % x - y + x) % x );
    }
    return 0;
}
