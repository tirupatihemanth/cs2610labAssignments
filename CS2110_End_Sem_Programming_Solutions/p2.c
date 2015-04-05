#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        long long int** arr = (long long int**) malloc((N+1)*sizeof(long long int *));
        int** blocked = (int**) malloc((N+1)*sizeof(int *));
        int i, j;
        
        for(i = 0; i <= N; i++) {
            arr[i] = (long long int *) malloc((N+1)*sizeof(long long int));
            blocked[i] = (int *) malloc((N+1)*sizeof(int));
        }
        
        for(i = 0; i <= N; i++) {
            for(j = 0; j <= N; j++) {
                arr[i][j] = 0;
                blocked[i][j] = 0;
            }        
        }
        
        while(M--) {
            int X, Y;
            scanf("%d %d", &X, &Y);
            blocked[X][Y] = 1;
        }
        
        if(blocked[1][1] == 0) {
            arr[1][1] = 1;
        }
        
        for(i = 1; i <= N; i++) {
            for(j = 1; j <= N; j++) {
                if(blocked[i][j] == 0) {
                    arr[i][j] += arr[i-1][j] + arr[i][j-1];
                }
            }
        }
        printf("%lld\n", arr[N][N]);
    }
    return 0;
}

