#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXL 200000

static char s[MAXL + 5];
static char st[MAXL + 5];
static int top;

static inline void reset_stack(void){ top = -1; }
static inline bool push(char c){
    if (top + 1 >= MAXL + 5) return false; // (여유분 포함)
    st[++top] = c; 
    return true;
}
static inline bool pop_char(char *out){
    if (top < 0) return false;
    *out = st[top--];
    return true;
}
static inline bool match(char open, char close){
    return (open=='(' && close==')') || (open=='['&&close==']') || (open=='{'&&close=='}');
}

int main(void){
    int T; 
    if (scanf("%d", &T) != 1) return 0;

    while (T--){
        if (scanf("%200000s", s) != 1) return 0;

        reset_stack();
        bool ok = true;

        for (int i = 0; s[i]; ++i){
            char c = s[i];
            if (c=='(' || c=='[' || c=='{'){
                if (!push(c)){ ok = false; break; }          // 이론상 넘치지 않지만 습관화
            } else if (c==')' || c==']' || c=='}'){
                char t;
                if (!pop_char(&t) || !match(t, c)){ ok = false; break; }
            } else {
                ok = false; break;                            // 허용 외 문자는 실패로 처리
            }
        }

        puts(ok && top==-1 ? "YES" : "NO");
    }
    return 0;
}
