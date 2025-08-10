#include <stdio.h>

#define MAX 110
typedef struct { int y, x; } Node;

int N, M;
int grid[MAX][MAX];
int dist_[MAX][MAX];

Node q[MAX*MAX];
int front = 0, rear = 0;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

static inline void push(Node v){ q[rear++] = v; }
static inline Node pop(){ return q[front++]; }
static inline int empty(){ return front==rear; }

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) scanf("%d",&grid[i][j]);

    // blocked=1, free=0 가정
    if(grid[0][0]==1){ puts("-1"); return 0; }

    dist_[0][0] = 1;
    push((Node){0,0});

    while(!empty()){
        Node cur = pop();
        for(int k=0;k<4;k++){
            int ny = cur.y + dy[k];
            int nx = cur.x + dx[k];
            if(ny<0||nx<0||ny>=N||nx>=M) continue;
            if(grid[ny][nx]==0 && dist_[ny][nx]==0){
                dist_[ny][nx] = dist_[cur.y][cur.x] + 1;
                push((Node){ny,nx});
            }
        }
    }
    int ans = dist_[N-1][M-1];
    printf("%d\n", ans==0?-1:ans);
    return 0;
}
