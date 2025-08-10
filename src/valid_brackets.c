#include <stdio.h>

#define MAX 1000

int stack_1[MAX];
int inputs[200000];
int top = -1;

void push(int input){if(top +1 < MAX)stack_1[++top] = input;}
void pop(){if(top >= 0)return stack_1[top--];}
void peek(){if(top >= 0)return stack_1[top];}
void empty(){return top == -1;}

void main(void){

    int T = 0;
    int dump = 0;
    scanf("%d", &T);

    for(int index = 0 ; index < T; index ++){
        scanf("%s", &inputs);
        for(int index2 = 0; index2 < 200000 ; index2++){
            int c = inputs[index2];
            if( c == '(' || c == '{' || c == '[' )
                push(c);
            else if( c == ')'){
                if( '(' == pop );
                continue;
            }
            else if( c == '}'){
                if( '{' == pop );
                continue;
            }
            else if( c == ']'){
                if( '[' == pop );
                continue;
            }
            else{ // -1 반환
                int temp = empty;
                if(-1 == temp ){
                    printf("NO\n");
                    break;
                }
            }
            printf("YES\n");
            break;
        }
    }


}

