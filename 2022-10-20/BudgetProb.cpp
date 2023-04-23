#include<iostream>
#define MAX 1005
#define INF 0x3f3f3f3f

using namespace std;

int map[MAX][MAX];
int num_Vertex, num_Edge;
int cost[MAX];
long ret_cost = 0;

int findMin();
int prim();


int main(){

    while (cin >> num_Vertex >> num_Edge){
        int X = 0, Y = 0, Weight = 0;
        for(int i = 1; i <= num_Vertex; i++){
            for (int j = 1; j <= num_Vertex; j++){
                if(i == j)
                    map[i][j] = 0; 
                else
                    map[i][j] = INF;           
            }
        }

        while (num_Edge--){
            cin >> X >> Y >>Weight;
            map[X][Y] = map[Y][X] = Weight;
        }
        
        cout << prim() <<endl;

        //clear all the data buffer;
        map[MAX][MAX] = { 0 };
        num_Vertex = num_Edge = 0;
        int cost[MAX] = { 0 };
        ret_cost = 0;

    }
    
    return 0;
}

int findMin(){
    int minCost = INF;
    int k = 0, j = 0;

    for (j = 1; j <= num_Vertex; j++){
        if(cost[j] != 0 && cost[j] < minCost){
            minCost = cost[j];
            k = j;
        }
    }
    return k;
}

int prim(){
    for(int i = 1; i <= num_Vertex; i++){
        cost[i] = map[1][i];
    }

    cost[1] = 0;

    for (int i = 1; i < num_Vertex; i++){
        int k = findMin();

        if(k != 0){
            ret_cost += cost[k];
            cost[k] = 0;

            for(int j = 0; j <= num_Vertex; j++){
                if(cost[j] && map[k][j] < cost[j]){
                    cost[j] = map[k][j];
                }
            }
        }else{
            return -1;
        }
    }
    return ret_cost;
}