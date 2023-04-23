#include <iostream>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXVEX 100
int dist[MAXVEX];                                           //建立dist数组
int path[MAXVEX];                                           //建立path数组
int S[MAXVEX];                                              //建立S数组

typedef char VertexType;

typedef struct graph{
    int n, e;
    VertexType vexs[MAXVEX];
    int edges[MAXVEX][MAXVEX];
} MGraph;

void CreateMGraph(MGraph &G, int n, int e){
    int value;
    char temp_i;
    char temp_j;

    G.n = n;
    G.e = e;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j)
                G.edges[i][j] = 0;
            else
                G.edges[i][j] = INF;
        }
    }

    for (int j = 0; j < G.n; j++){
        cin >> G.vexs[j];
    }

    int temp_number_i;
    int temp_number_j;

    for (int j = 0; j < e; j++){
        cin >> temp_i >> temp_j >> value;
        for (int i = 0; i < n; i++){
            if (G.vexs[i] == temp_i)
                temp_number_i = i;
            if (G.vexs[i] == temp_j)
                temp_number_j = i;
        }
        G.edges[temp_number_i][temp_number_j] = value;
    }
}

void DispMGraph(MGraph &G){

    cout << "顶点信息：" << endl;
    for (int i = 0; i < G.n; i++)
        cout << G.vexs[i];
    cout << "矩阵如下：" << endl;
    for (int i = 0; i < G.n; i++)
    {
        cout << endl << G.vexs[i];
        for (int j = 0; j < G.n; j++)
        {
            if (G.edges[i][j] == INF)
                cout << "   ∞";
            else
                cout << "   "<< G.edges[i][j];
        }
        cout << endl;
    }
}

void Dijkstra(MGraph g, int v){
    int mindis, i, j, u = 0;                        //求从v到其他顶点的最短路径
    for (i = 0; i < g.n; i++){
        dist[i] = g.edges[v][i];                    //距离初始化
        S[i] = 0;                                   // S[]置空
        if (g.edges[v][i] < INF)                    //路径初始化
            path[i] = v;                            // v→i有边时，置i前一顶点为v
        else                                        // v→i没边时，置i前一顶点为-1
            path[i] = -1;
    }
    S[v] = 1;                                      //源点编号v放入S中
    for (i = 0; i < g.n - 1; i++)                   //循环向S中添加n-1个顶点
    {
        mindis = INF;                               // mindis置最小长度初值
        for (j = 0; j < g.n; j++)                   //选取不在S中且有最小距离顶点u
            if (S[j] == 0 && dist[j] < mindis)
            {
                u = j;
                mindis = dist[j];
            }
        S[u] = 1;                                   //顶点u加入S中
        for (j = 0; j < g.n; j++)                   //修改不在s中的顶点的距离
            if (S[j] == 0)
                if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j])
                {
                    dist[j] = dist[u] + g.edges[u][j];
                    path[j] = u;
                }
    }
}

void Dispath(MGraph g, int v, int w)
{
    int i, j, k;
    int apath[MAXVEX], d;                               //存放一条最短路径(逆向)及其顶点个数

    
    for (i = 0; i < g.n; i++){                          //循环输出从顶点v到i的路径
        if (S[i] == 1 && i != v && i == w){

            cout << dist[i] << endl;
            d = 0;
            apath[d] = i;                               //添加路径上的终点
            k = path[i];
            if (k == -1)                                //没有路径的情况
                cout << "无路径" << endl;
            else{                                       //存在路径时输出该路径
                while (k != v){
                    d++;
                    apath[d] = k;
                    k = path[k];
                }
                d++;
                apath[d] = v;                           //添加路径上的起点
                cout << g.vexs[apath[d]];               //先输出起点
                for (j = d - 1; j >= 0; j--)            //再输出其余顶点
                    cout  << "->" << g.vexs[apath[j]];
                cout << endl;
            }
        }
    }
}

int main()
{
    MGraph G;
    int n, e;
    cin >> n >> e;                                      //输入顶点和边总数量

    if (n == 0 && n == 0){
        cout << "没有顶点和路径" << endl;
        return 0;
    }

    CreateMGraph(G, n, e);

    char a, b;
    cin >> a >> b;                                      //起点和终点

    int indexa, indexb;

    for (int i = 0; i < G.n; i++){
        if (a == G.vexs[i])
            indexa = i;
        if (b == G.vexs[i])
            indexb = i;
    }

    Dijkstra(G, indexa);
    DispMGraph(G);                                      //展示图
    cout << "从"<<a<<"到"<<b<<"的路径 总开销 和 完整路径 为 : " << endl;
    Dispath(G, indexa, indexb);
    system("pause");
    return 0;
}
