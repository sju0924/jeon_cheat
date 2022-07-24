using namespace std;

//INF값
const int INF = 100000001;
//배열 크기 최댓값
const int MAX = 100;
int d[MAX+1][MAX+1];


int N,M;
/*
    플로이드-워셜 알고리즘
    모든 노드에서 모든 노드까지 거리를 구할 때 사용됨.
    시간 복잡도 O(n^3)

    @input: -
    @output: 모든 노드에서 모든 노드까지의 최단 거리 d
    @required: d 배열이 초기화되어 있어야 함. 없는 간선은 INF값
*/
void floyd_warshall() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++) {
                //cout << d[i][k] << " " << d[i][j] << " " << d[j][k] << "\n";
                if (k == j) {
                    d[j][k] = 0;
                    continue;
                }
                if (d[j][k] > d[j][i] + d[i][k])
                    d[j][k] = d[j][i] + d[i][k];
            }
}
