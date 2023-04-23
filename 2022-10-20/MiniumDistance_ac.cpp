#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<climits>

using namespace std;

const int MAXN = 200;
const int INF = INT_MAX;

struct Edge {
    int to;
    int length;
    Edge(int t, int l) :to(t), length(l) {}
};

struct Point {
    int number;
    int distance;
    Point(int n, int d) :number(n), distance(d) {}
    bool operator<(const Point& p) const {
        return distance > p.distance;
    }
};

vector<Edge> graph[MAXN];
int dis[MAXN];

void Dijkstra(int s) {
    priority_queue<Point> myPriorityQueue;
    dis[s] = 0;
    myPriorityQueue.push(Point(s, dis[s]));
    while (!myPriorityQueue.empty()) {
        int u = myPriorityQueue.top().number;
        myPriorityQueue.pop();
        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].to;
            int d = graph[u][i].length;
            if (dis[v] > dis[u] + d) {
                dis[v] = dis[u] + d;
                myPriorityQueue.push(Point(v, dis[v]));
            }
        }
    }
    return;
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        memset(graph, 0, sizeof(graph));
        fill(dis, dis + n, INF);
        while (m--) {
            int from, to, length;
            scanf("%d%d%d", &from, &to, &length);
            graph[from].push_back(Edge(to, length));
            graph[to].push_back(Edge(from, length));
        }
        int s, t;
        scanf("%d%d", &s, &t);
        Dijkstra(s);
        if (dis[t] == INF) {
            dis[t] = -1;
        }
        printf("%d\n", dis[t]);
    }
    return 0;
}