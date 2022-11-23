#include <stdio.h>

void turnArray(int *V, int N, int N1, int target, int *count);

int main() {
    int V[7] = {4,3,2,5,2,6,1};
    int N = 7, N1 = 3, target = 3;
    int count;

    turnArray(V, N, N1, target, &count);

    for (int i = 0; i < N; ++i) {
        printf("%d ", V[i]);
    }

    return 0;
}

void turnArray(int *V, int N, int N1, int target, int *count){
    int tmp;
    for (int i = 0; i < N1; ++i) {
        tmp = V[0];

        for (int j = 1; j < N; ++j) {
            if(V[j] == target){
                V[j-1] = 0;
                *count++;
            }else{
                V[j-1] = V[j];
            }

        }
        V[N -1] = tmp;
    }
}

