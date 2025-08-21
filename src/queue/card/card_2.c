#include <stdio.h>
#include <stdbool.h>

#define MAX 100000

int s[MAX];
int top = -1;

bool empty(){
    return top == -1;
}

void push(int in){

    s[++top] = in;
}

void pop(){
    top--;
}

int main(void){

    
    int N;
    int target = 1;
    int arr[MAX];
    scanf("%d", &N);

    for(int i = 1; i<=N; i++){
        scanf("%d", &arr[i-1]);
    }

    for(int i =0; i< N; i++){
        push(arr[i]);

        while(!empty() && target==s[top]){
            pop();
            target++;
        }
    }
    if(empty()){
        printf("ok");
    }
    else{
        printf("no");
    }
}

