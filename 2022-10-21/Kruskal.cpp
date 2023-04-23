#include <iostream>
using namespace std;

#define MAX 100
#define INF 0x3f3f3f3f

typedef struct{
    int u;
    int v;
    int w;
} Edge;


typedef struct 
{
    int edges[MAX][MAX];    //Matrix;
    int n, e;               //mount point and edges

}MatGraph;

void CreatMat(MatGraph &g, int A[MAX][MAX], int n, int e);
void DispMat(MatGraph g);
void SortEdge(Edge E[], int e);
void Kruskal(MatGraph g);


int main (){

    MatGraph g;

    int A[MAX][MAX] = {               //making the martix
        {0,  1,  3,  4,  7},            //Point 0;
        {1,  0,  2,  INF,  INF},        //Point 1;
        {3,  2,  0,  5,  8},            //Point 2;
        {4,  INF, 5,  0,  6},           //Point 3;
        {7,  INF, 8,  6,  0}            //Point 4;
    };  

    int n = 5, e = 8;

    CreatMat(g,A,n,e);
    cout << "The Graphics of Martix is:" << endl << endl;
    DispMat(g);
    cout << "The Ans of Kruskal is :" << endl << endl;
    Kruskal(g);
    cout << endl; 

    return 0;
}

void CreatMat(MatGraph &g, int A[MAX][MAX], int n, int e){
    g.e = e;
    g.n = n;

    for (int i = 0; i < g.n; i++){

        for (int j = 0; j < g.n; j++){
            g.edges[i][j] = A[i][j];
        }
        
    }
    
}


void DispMat(MatGraph g){
    for (int i = 0; i < g.n; i++){
        
        for (int j = 0; j < g.n; j++){
            if(g.edges[i][j] != INF){
                cout << g.edges[i][j]<<"   ";
            }
            else{
                cout << "∞" <<"   ";
            }
        }
        cout << endl;

    }
    cout << endl;

}



void SortEdge(Edge E[], int e){
    int i, j, k = 0;
    Edge temp;
    for (i = 1; i < e; i++){
        temp = E[i];
        j = i - 1;
        while (j >= 0 && temp.w < E[j].w){
            E[j + 1] = E[j];
            j--;
        }
        E[j + 1] = temp;
    }
}

void Kruskal(MatGraph g){
    int i, j, u1, v1, sn1, sn2, k;
    int vset[MAX];
    Edge E[MAX];
    k = 0;
    for (i = 0; i < g.n; i++)
        for (j = 0; j <= i; j++)
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF){
                E[k].u = i;
                E[k].v = j;
                E[k].w = g.edges[i][j];
                k++;
            }
    SortEdge(E, k);
    for (i = 0; i < g.n; i++)
        vset[i] = i;
    k = 1;
    j = 0;
    while (k < g.n){
        u1 = E[j].u;
        v1 = E[j].v;
        sn1 = vset[u1];
        sn2 = vset[v1];
        if (sn1 != sn2){
            cout << "Edge ："<< v1 << " to "<< u1 <<", Weight is :"<<E[j].w << endl;
            k++;
            for (i = 0; i < g.n; i++)
                if (vset[i] == sn2)
                    vset[i] = sn1;
        }
        j++;
    }
}
