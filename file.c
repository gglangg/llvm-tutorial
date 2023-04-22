#include <stdio.h>

int callee(const int* X){
    return *X+1;
}

void test(int** outer,int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            outer[i][j] = i*j;
        }
    }
    for(int i=0;i<N;i++){
        outer[i][i]=1;
    }
}

int main(void) {
    int T=4;
    return callee(&T);    
}