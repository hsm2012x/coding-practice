#include <stdio.h>
#include <stdbool.h>
#define MAX 200000

int s[MAX];
int top = -1;

void pop(){
    top--;
}

void push(int in){
    s[++top] = in;
}

bool empty(){
    if (top ==-1)
        return true;

    return false;
}

int main(void){

    int N;
    int h[MAX +1];

    scanf("%d", &N);

    for(int i = 0; i<N ;i++){
        scanf("%d", &h[i]);
    }

    h[N] = 0;

    // 2 1 0 1 2 3 
    int ans = 0;
    push(0);
    for(int i = 1; i <= N ; i++){

        while(!empty() && h[s[top]] < h[i]){
            // top = 2, h[s[top]] = 0
            // i = 3, h[i] = 1
            int bottom = h[s[top]];
            pop();
            int right_b = i;
            int left_b = s[top];

            if( !empty()&&h[s[top]] != 0 &&h[s[top]] > bottom ){
                int height = (h[s[top]] > h[i]) ? h[i] : h[s[top]];
                int v = ((height -bottom) * (right_b - left_b - 1));
                printf("h %d  v %d i %d top %d\n", height, v, i, top);
                // ans = (v > ans) ? v : ans;
                ans += v;
            }
        }
        push(i);
    }

    printf("%d", ans);
    
}