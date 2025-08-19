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
bool q_pop(DQueue *q, int* x){
    if(q_empty(q)) return false;
    *x = q->buf[q->head] ;
       
    return true;
}