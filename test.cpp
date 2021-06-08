/*
* Dijkstra最短路径。
* 即，统计图(G)中"顶点vs"到其它各个顶点的最短路径。
*
* 参数说明：
*        G -- 图
*       vs -- 起始顶点(start vertex)。即计算"顶点vs"到其它顶点的最短路径。
*     prev -- 前驱顶点数组。即，prev[i]的值是"顶点vs"到"顶点i"的最短路径所经历的全部顶点中，位于"顶点i"之前的那个顶点。
*     dist -- 长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度。
*/
//#include <stdio.h>
//void main(Graph G, int vs, int prev[], int dist[])
//{
//	int i, j, k;
//	int min;
//	int tmp;
//	int flag[MAX];      // flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取。
//
//	// 初始化
//	for (i = 0; i < G.vexnum; i++)
//	{
//		flag[i] = 0;              // 顶点i的最短路径还没获取到。
//		prev[i] = 0;              // 顶点i的前驱顶点为0。
//		dist[i] = G.matrix[vs][i];// 顶点i的最短路径为"顶点vs"到"顶点i"的权。
//	}
//
//	// 对"顶点vs"自身进行初始化
//	flag[vs] = 1;
//	dist[vs] = 0;
//
//	// 遍历G.vexnum-1次；每次找出一个顶点的最短路径。
//	for (i = 1; i < G.vexnum; i++)
//	{
//		// 寻找当前最小的路径；
//		// 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
//		min = INF;
//		for (j = 0; j < G.vexnum; j++)
//		{
//			if (flag[j] == 0 && dist[j]<min)
//			{
//				min = dist[j];
//				k = j;
//			}
//		}
//		// 标记"顶点k"为已经获取到最短路径
//		flag[k] = 1;
//
//		// 修正当前最短路径和前驱顶点
//		// 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
//		for (j = 0; j < G.vexnum; j++)
//		{
//			tmp = (G.matrix[k][j] == INF ? INF : (min + G.matrix[k][j])); // 防止溢出
//			if (flag[j] == 0 && (tmp  < dist[j]))
//			{
//				dist[j] = tmp;
//				prev[j] = k;
//			}
//		}
//	}
//
//	// 打印dijkstra最短路径的结果
//	printf("dijkstra(%c): \n", G.vexs[vs]);
//	for (i = 0; i < G.vexnum; i++)
//		printf("  shortest(%c, %c)=%d\n", G.vexs[vs], G.vexs[i], dist[i]);
//}

#include<stdio.h>
#include<stdlib.h>
#define max 11000000000
int a[1000][1000];
int d[1000];
int p[1000];
int i, j, k;
int m;
int n;
int main()
{
	scanf_s("%d%d", &n, &m);
	int min1;
	int max1=0;
	int x, y, z;
	for (i = 1; i <= m; i++)
	{
		scanf_s("%d%d%d", &x, &y, &z);
		a[x][y] = z;
		a[y][x] = z;
	}
	for (i = 1; i <= n; i++)
		d[i] = max1;
	d[1] = 0;
	for (i = 1; i <= n; i++)
	{
		min1 = max1;
		for (j = 1; j <= n; j++)
		if (!p[j] && d[j]<min1)
		{
			min1 = d[j];
			k = j;
		}
		p[k] = j;
		for (j = 1; j <= n; j++)
		if (a[k][j] != 0 && !p[j] && d[j]>d[k] + a[k][j])
			d[j] = d[k] + a[k][j];
	}
	for (i = 1; i<n; i++)
		printf("%d->", p[i]);
	printf("%d\n", p[n]);
	return 0;
}