#include <stdio.h>
#include <stdbool.h>
#define MAX_L 200000

static char s[MAX_L + 5];
static char stack_s[MAX_L + 5];
static int top = -1;
// pop, push, empty, reset

bool push(char ch){
    
    if(top + 1 > MAX_L){
        return 0;
    }
    stack_s[++top] = ch;

    return 1;
}

bool pop(char *ch){
    if(top < 0){
        return 0;
    }
    *ch = stack_s[top--];
    return 1;
}
bool empty(void){
    if (top ==-1)
        return 1;
    
    return 0;
}
bool match(char open, char close){
    return ( (open == '[' && close ==']') || (open == '(' && close ==')') ||  (open == '{' && close =='}') ) ;
}
void reset(void){
    top = -1;
}
int main(void){

    int T;
    if(scanf("%d", &T) != 1) return 0;

    while(T--){
        reset();
        bool ok = true;
        
        scanf("%s", s);
        for(int i = 0; s[i]; i++){
            char d1 = s[i];
            if(d1 == '[' || d1 == '{' || d1 == '('){
                if(!push(d1)){
                    ok = false;
                    break;
                }
            }
            else if(d1 == '}' || d1 == ']' || d1 == ')'){
                char d2;
                if(!pop(&d2) || !match(d2, d1)){
                    ok = false;
                    break;                 
                }
            }
            else{
                ok = false;
                break;
            }
        }
        puts(ok && empty() ? "YES" : "NO");


    }
    return 0;

}