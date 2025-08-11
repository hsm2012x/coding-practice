#include <stdio.h>
#include <stdbool.h>

#define MAX_N 200000

int S[MAX_N+1];
int array[MAX_N];
int ans[MAX_N];
int top = -1;

bool push(int d){
    if(top > MAX_N +1){
        return false;
    }
    S[++top] = d;
    return true;
}

bool pop(){
    if(top < 0)
        return false;
    top--;
    // *d = S[top--];
    return true;
}
bool empty(){
    if(top == -1)
        return true;
    return false;
}

int main(void){


    // input N
    // input array
    // make ans
    // make stack
    // print ans
    int N;

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
        ans[i] = -1;
    }

    for(int i = 0; i < N-1; i++)
    {
        if(array[i] < array[i+1]){
            // 1 3 5
            ans[i] = array[i+1];
            while(!empty() && array[S[top]] < array[i+1])
            {
                ans[S[top]] = array[i+1];
                pop();
            }
        }
        else
        {
            push(i);
        }
        // printf("%d", array[i]);

    }
    for(int i = 0; i < N-1; i++)
        printf("%d ", ans[i]);
    
    printf("%d", -1);
    return 0;
}