/*
* Dijkstra���·����
* ����ͳ��ͼ(G)��"����vs"������������������·����
*
* ����˵����
*        G -- ͼ
*       vs -- ��ʼ����(start vertex)��������"����vs"��������������·����
*     prev -- ǰ���������顣����prev[i]��ֵ��"����vs"��"����i"�����·����������ȫ�������У�λ��"����i"֮ǰ���Ǹ����㡣
*     dist -- �������顣����dist[i]��"����vs"��"����i"�����·���ĳ��ȡ�
*/
//#include <stdio.h>
//void main(Graph G, int vs, int prev[], int dist[])
//{
//	int i, j, k;
//	int min;
//	int tmp;
//	int flag[MAX];      // flag[i]=1��ʾ"����vs"��"����i"�����·���ѳɹ���ȡ��
//
//	// ��ʼ��
//	for (i = 0; i < G.vexnum; i++)
//	{
//		flag[i] = 0;              // ����i�����·����û��ȡ����
//		prev[i] = 0;              // ����i��ǰ������Ϊ0��
//		dist[i] = G.matrix[vs][i];// ����i�����·��Ϊ"����vs"��"����i"��Ȩ��
//	}
//
//	// ��"����vs"������г�ʼ��
//	flag[vs] = 1;
//	dist[vs] = 0;
//
//	// ����G.vexnum-1�Σ�ÿ���ҳ�һ����������·����
//	for (i = 1; i < G.vexnum; i++)
//	{
//		// Ѱ�ҵ�ǰ��С��·����
//		// ������δ��ȡ���·���Ķ����У��ҵ���vs����Ķ���(k)��
//		min = INF;
//		for (j = 0; j < G.vexnum; j++)
//		{
//			if (flag[j] == 0 && dist[j]<min)
//			{
//				min = dist[j];
//				k = j;
//			}
//		}
//		// ���"����k"Ϊ�Ѿ���ȡ�����·��
//		flag[k] = 1;
//
//		// ������ǰ���·����ǰ������
//		// �������Ѿ�"����k�����·��"֮�󣬸���"δ��ȡ���·���Ķ�������·����ǰ������"��
//		for (j = 0; j < G.vexnum; j++)
//		{
//			tmp = (G.matrix[k][j] == INF ? INF : (min + G.matrix[k][j])); // ��ֹ���
//			if (flag[j] == 0 && (tmp  < dist[j]))
//			{
//				dist[j] = tmp;
//				prev[j] = k;
//			}
//		}
//	}
//
//	// ��ӡdijkstra���·���Ľ��
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