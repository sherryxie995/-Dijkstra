// Dijkstra.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 100
#define INFINITY INT_MAX
typedef struct {
	int weight = INFINITY;//初始化为无穷
}Arc[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct MGraph {
	int vex[MAX_VERTEX_NUM];
	Arc matrix;
	int vexnum,arcnum;
};
void InsertArc(MGraph*G,int v,int u,int w) {
	G->matrix[v][u].weight = w;
}
MGraph CreateGraph(MGraph*G) {
	//int n, m;
	//int n1, n2, w;
	//printf("请输入顶点数:\n");
	//printf("请输入弧数:\n");
	//printf("请输入每条弧的弧尾,弧头,权重:\n");
	InsertArc(G, 0, 1, 25);
	InsertArc(G, 0, 2, 30);
	InsertArc(G, 1, 2, 8);
	InsertArc(G, 1, 3, 40);
	InsertArc(G, 1, 4, 35);
	InsertArc(G, 2, 3, 15);
	InsertArc(G, 2, 4, 20);
	InsertArc(G, 3, 4, 10);
	G->vexnum = 5;
	G->arcnum = 8;
	for (int i = 0; i < G->vexnum; i++) {
		G->vex[i] = i;
	}
	return *G;
}
void print(MGraph*G,int*p,int*d) {
	int i, j;
	for (i = G->vexnum-1; i >0 ; i--) {
		printf("源点0到顶点%d的路径为:", i);
		j = i;
		printf("%d->", j);
		while (p[j] > 0) {
			printf("%d->",p[j]);
			j = p[j];
		}
		printf("0\t");
		printf("路径成本为:%d\n", d[i]);
	}
}
void Dijkstra(MGraph*G) {
	int* p,*d,*find;
	d = (int*)malloc(sizeof(int) * G->vexnum);
	p = (int*)malloc(sizeof(int) * G->vexnum);
	find = (int*)malloc(sizeof(int) * G->vexnum);
	int i,j,k,min;
	for (i = 0; i < G->vexnum; i++) {
		G->matrix[i][i].weight = 0;//对角线上的数值设为0
		d[i] = G->matrix[0][i].weight;
		find[i] = false;
		if(d[i]!=INFINITY)p[i] = 0;
		else {
			p[i] = -2;
		}
	}
	p[0] = -1;
	find[0] = true;
	for (i = 1; i < G->vexnum; i++) {
		min = INFINITY;
		if (!(find[i])) {
			if (d[i] < min) {
				min = d[i];
				k = i;
			}
		}
		find[k] = true;//找到当前离源点最近的点加入集合
		for (j = 0; j < G->vexnum; j++) {
			if (!(find[j])&&G->matrix[i][j].weight + d[i] < d[j]) {
				d[j] = G->matrix[i][j].weight + d[i];
				p[j] = i;
			}
		}
	}
	print(G,p,d);
}
int main()
{
    MGraph G;
	G = CreateGraph(&G);
	Dijkstra(&G);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
