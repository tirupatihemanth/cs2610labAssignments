#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int findMin(int* num, int start, int end) {
    if(end < start) {
        return num[0];
    }
    if(start == end) return num[start];
    int mid = start + (end - start)/2;
    if(mid > start && num[mid] < num[mid-1]) {
        return num[mid];
    }
    if(mid < end && num[mid+1] < num[mid]) {
        return num[mid+1];
    }
    if(num[end] > num[mid]) {
        return findMin(num, start, mid-1);
    }
    return findMin(num, mid+1, end);
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int N;
    scanf("%d", &N);
    int* arr = (int *)malloc(N*sizeof(int));
    int i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int min = findMin(arr, 0, N-1);
    printf("%d", min);
    return 0;
}

