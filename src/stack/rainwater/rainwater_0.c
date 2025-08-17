#include <stdio.h>
#include <stdbool.h>

#define MAX 200000+1

int s[MAX];
int top = -1;

void push(int in){
    s[++top] = in;
}
void pop(){
    top--;
}
bool empty(){
    return top <0 ? true : false;
}

int main(void){

    int N;
    int h[MAX];
    int ans = 0;

    scanf("%d", &N);
    for(int i = 0; i<N ; i++)
    scanf("%d", &h[i]);

    h[N] = 0;

    push(0);
    for(int i =1; i<N +1 ; i++){

        while ( !empty() &&  h[s[top]] <=h[i])
        {
            int minValue = s[top];
            pop();
            if (empty()) break;   
            int left = s[top];
            
            int height = h[left] < h[i] ? h[left] : h[i];
            height -= h[minValue];        // 유효 물 높이
            if (height > 0) {
                int width = i - left - 1;
                ans += (long long)height * width;
            }

            // if(h[s[top]] > minValue && h[s[top]] > 0 )
            //     ans += right - left ;
            // printf("i = %d top = %d temp = %d ans =%d \n", right, left, (right-left), ans);
            // printf("minValue = %d h[s[top]] = %d \n", right, left, (right-left));
        }
        push(i);


    }

    printf("ans = %d", ans);



    return 0;
}