#include <iostream>
#include<vector>
#include <limits.h>
using namespace std;

//배열 크기 최댓값
const int MAX = 500;
//가중치 최대값
const int INF = INT_MAX;
int node, edge, start;

//underflow 날 수 있으니 자료형에 유의해야 함
vector<pair<long long int, int> > graph[MAX + 1];
long long int d[MAX + 1];
int N, E; //N: 노드개수, E: 엣지 개수
/*
    벨만 포드 알고리즘을 수행하는 함수
    음의 가중치가 있어 음의 사이클이 생길 수 있을 때 사용한다.
    @input: int start
    @output(result): start로부터 최단 거리 d[MAX+1]
    @require: 그래프를 나타내는 벡터 graph
*/
int bellman_ford(int start)
{
    fill(d, d + MAX + 1, INF);

    d[start] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < graph[j].size(); k++) {
                int start = j;
                int end = graph[j][k].second;

                if (d[start] < INF && d[start] + graph[j][k].first < d[end]) {
                    if (i == N - 1) return -1;
                    d[end] = d[start] + graph[j][k].first;
                }
            }          
        }
    }

    return 1;
}
