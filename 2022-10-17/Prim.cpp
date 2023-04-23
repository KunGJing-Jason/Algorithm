#include <iostream>
using namespace std;

const int MAXV = 10;    //MAX point 
const int INF = 0x3f3f3f3f;    //Sign of unreachable point


typedef struct 
{
    int edges[MAXV][MAXV];  //Matrix;
    int n, e;               //mount point and edges

}MatGraph;


void CreatMat(MatGraph &g, int A[MAXV][MAXV], int n, int e);
void DispMat(MatGraph g);
void Prim(MatGraph g, int v);

int main(){
    MatGraph g;

    int A[MAXV][MAXV] = {               //making the martix
        {0,  1,  3,  4,  7},            //Point 0;
        {1,  0,  2,  INF,  INF},        //Point 1;
        {3,  2,  0,  5,  8},            //Point 2;
        {4,  INF, 5,  0,  6},           //Point 3;
        {7,  INF, 8,  6,  0}            //Point 4;
    };  

    int n = 5, e = 8;                   //Points and Edges;

    CreatMat(g,A,n,e);
    cout << "The GUI of Martix is:" << endl;
    DispMat(g);

    cout << "The Ans of Prim is :" << endl;
    Prim(g,0);


    return 0;
}


void CreatMat(MatGraph &g, int A[MAXV][MAXV], int n, int e){
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
    cout << endl << endl;

}

void Prim(MatGraph g, int v){
    int lowcost[MAXV];
    int closest[MAXV];

    int min = 0, i = 0, j = 0, k = 0;

    for(i = 0; i < g.n; i++){
        lowcost[i] = g.edges[v][i];
        closest[i] = v;
    }

    for ( i = 1; i < g.n; i++){
        min = INF;

        for ( j = 0; j < g.n; j++){
            if( (lowcost[j] != 0) && (lowcost[j] < min)){
                min = lowcost[j];
                k = j;
            }
        }

        cout <<"Egde : ("<< closest[k] <<" "<< k <<"), Weight is :" << min <<endl;

        lowcost[k] = 0;

        for ( j = 0; j < g.n; j++){
            if(lowcost[j] != 0 && g.edges[k][j] < lowcost[j]){
                lowcost[j] = g.edges[k][j];
                closest[j] = k;
            }
        }
        
    }
    
}