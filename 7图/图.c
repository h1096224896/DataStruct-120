#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 图的基本类型定义
#define MAXV 100
typedef struct {
    int no; // 顶点编号
    char info; // 顶点其他信息
} VertexType;  // 顶点类型

typedef struct {
    int edges[MAXV][MAXV]; // 邻接矩阵
    int n, e; // 顶点数, 边数
    VertexType vexs[MAXV]; // 顶点信息
} MGraph;



int main()
{
    
    return 0;
}