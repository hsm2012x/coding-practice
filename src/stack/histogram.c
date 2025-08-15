#include <stdio.h>
#include <stdbool.h>

#define MAX 100000

// 입 출력
// 2단계 1. 낮은게 나올 때 까지 Push
// 2. 높은게 나오면 PoP

static int top = -1;
static int stack[MAX];
void pop(){
    if(top > -1)
        top--;
}
void push(int in){
    // if(in >0)
    stack[++top] = in;
}
bool empty(){
    if(top == -1)
    return 1;

    return 0;
}
int main(void){

    int N;
    int h[MAX];
    int ans = 0;
    scanf("%d", &N);
    for(int i=0; i<N;i++){
        scanf("%d", &h[i]);
    }
    h[N] = 0;
    for (int i = 0; i < N+1; i++) {
        while (!empty() && h[stack[top]] > h[i]) {
            int height = h[stack[top]];
            pop();
            int left = empty() ? 0 : stack[top] + 1;
            int width = i - left;
            int area = height * width;
            ans = ans > area ? ans : area;
            // printf("i=%d left=%d height=%d width=%d area=%d\n", i, left, height, width, area);
        }
        push(i);
    }

    printf("%d", ans);
}
