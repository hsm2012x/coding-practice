#include <stdio.h>
#include <stdbool.h>

#define MAX 50000
typedef struct{
    
    int buf[MAX];
    int cap;
    int head; // 읽을 위치
    int tail; // 쓸 위치
    int size;

}DQueue;

void q_init(DQueue* q){
   q->cap = q->head = q->tail = q->size = 0;
}
bool q_empty(DQueue *q) {return q->size ==0;} 
bool q_full (DQueue *q){return q->size ==MAX;}

bool q_push(DQueue *q, int x){
    if(q_full(q)) return false;
    q->buf[q->tail] = x;
    q->tail = (q->tail + 1) % MAX;
    q->size++;
    return true;
}

bool q_pop(DQueue *q, int* x){
    if(q_empty(q)) return false;
    *x = q->buf[q->head] ;
    q->head = (q->head + 1) % MAX;
    q->size--;
    return true;
}
bool q_front(DQueue *q, int* x){
    if(q_empty(q)) return false;
    *x = q->buf[q->head] ;
       
    return true;
}
void q_print(DQueue *q) {
    printf("Queue (size %d): [ ", q->size);
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->buf[(q->head + i) % MAX]);
    }
    printf("]\n");
}

int main(void) {
    int N;
    DQueue q;

    scanf("%d", &N);
    q_init(&q);

    for (int i = 1; i <= N; i++) {
        q_push(&q, i);
    }

    int temp; // 값을 잠시 담아둘 변수

    // 1. 카드가 1장 남을 때까지 반복
    while (q.size > 1) {
        // 2. 맨 앞 카드를 버린다.
        q_pop(&q, &temp);

        // 3. 그다음 맨 앞 카드를 꺼내서
        q_pop(&q, &temp);
        
        // 4. 맨 뒤로 옮긴다.
        q_push(&q, temp);
    }

    // 마지막으로 남은 카드를 꺼내서 출력
    q_pop(&q, &temp);
    printf("%d\n", temp);

    return 0;
}