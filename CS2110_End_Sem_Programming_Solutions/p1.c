#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if(b == 0) return a;
    if(a < b) return gcd(b,a);
    return gcd(b, a%b);
}
int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, G = 0;
        scanf("%d", &N);
        int n = N;
        while(N--) {
            int temp;
            scanf("%d", &temp);
            G = gcd(temp, G);
        }
        if(G == 1) {
            printf("%d\n", n);
        }
        else {
            printf("-1\n");
        }
    }
    return 0;
}
