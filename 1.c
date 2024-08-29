#include <stdio.h>
#include <string.h>
#define OK 1
#define ERROR 0
#define MaxInt 32767
#define MVNum 100

typedef int Status;
typedef char VerTexType[20];  // 顶点类型改为字符串，长度根据需要调整
typedef int ArcType;

int visited[MVNum];

typedef struct {
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
} AMGraph;

int LocateVex(AMGraph G, char v[]) {
    int i;
    for (i = 0; i < G.vexnum; i++) {
        if (strcmp(G.vexs[i], v) == 0) {
            return i;
        }
    }
    return -1;  // 如果顶点不存在，返回 -1
}

Status CreateUDN(AMGraph *G) {
    int i, j, ii, jj, k, w;
    char v1[20], v2[20];
    printf("请输入顶点数和边数：");
    scanf("%d%d", &((*G).vexnum), &((*G).arcnum));
    printf("请输入%d个顶点值：", (*G).vexnum);
    for (i = 0; i < (*G).vexnum; i++) {
        scanf("%s", (*G).vexs[i]);
    }
    for (i = 0; i < (*G).vexnum; i++) {
        for (j = 0; j < (*G).vexnum; j++) {
            (*G).arcs[i][j] = MaxInt;
        }
    }
    for (k = 0; k < (*G).arcnum; k++) {
        printf("请输入两点及其之间权值：");
        scanf("%s %s %d", v1, v2, &w);
        ii = LocateVex(*G, v1);
        jj = LocateVex(*G, v2);
        (*G).arcs[ii][jj] = w;
        (*G).arcs[jj][ii] = w;
    }
    return OK;
}

int FirstAdjVex(AMGraph G, int v) {
    int i;
    for (i = 0; i < G.vexnum; i++) {
        if (G.arcs[v][i] != MaxInt) {
            return i;
        }
    }
    return -1;
}

int NextAdjVex(AMGraph G, int v, int w) {
    int i;
    for (i = w + 1; i < G.vexnum; i++) {
        if (G.arcs[v][i] != MaxInt) {
            return i;
        }
    }
    return -1;
}

void DFS(AMGraph G, int v) {
    int w;
    printf("%s ", G.vexs[v]);
    visited[v] = 1;
    for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
}

void DFS_AM(AMGraph G, int v) {
    int i, w;
    for (i = 0; i < G.vexnum; i++) {
        visited[i] = 0;
    }
    printf("%s ", G.vexs[v]);
    visited[v] = 1;
    for (w = 0; w < G.vexnum; w++) {
        if ((G.arcs[v][w] != MaxInt) && (!visited[w])) {
            DFS(G, w);
        }
    }
}

int main() {
    int i, j;
    AMGraph G;
    CreateUDN(&G);
    printf("\n邻接矩阵表示图：\n");
    for (i = 0; i < G.vexnum; i++) {
        for (j = 0; j < G.vexnum; j++) {
            if (G.arcs[i][j] == MaxInt) {
                printf("%10s", "MaxInt");
            } else {
                printf("%10d", G.arcs[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n邻接矩阵表示图深度优先遍历结果：");
    DFS_AM(G, 2);
    return 0;
}
