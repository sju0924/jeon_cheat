#include<iostream>
#include<vector>
#include<queue>
#include <limits.h>
using namespace std;

//배열 크기 최댓값
const int MAX = 100000;
//가중치 최대값
const int INF = INT_MAX;
int node, edge, start;

vector<pair<int, int> > graph[MAX+1]; 
int d[MAX+1]; 

/*
    다익스트라 알고리즘을 수행하는 함수
    @input: int start
    @output(result): start로부터 최단 거리 d[MAX+1]
    @require: 그래프를 나타내는 벡터 graph
*/
void dijkstra(int start)
{
    priority_queue<pair<int, int>,vector<pair<int,int>>, greater<>>pq;
    int cost;

    fill(d, d + MAX+1, INF);

    pq.push(make_pair(0,start));
    d[start] = 0;

    while (!pq.empty())
    {
        int dist = pq.top().first; 
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist)
            continue;

        for (int i = 0; i < graph[now].size(); i++)
        {
            cost = dist + graph[now][i].first;
            if (cost < d[graph[now][i].second])
            {
                d[graph[now][i].second] = cost;
                pq.push(make_pair(cost, graph[now][i].second));
            }
        }
    }
}