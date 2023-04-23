#include <iostream>
#include <string.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX 1000

int Map[MAX][MAX];
int Cost[MAX][MAX];
int Minium[MAX];
int Distance[MAX];
int Visit[MAX];
int Vertex, Edge;
int s, t;

void Init();
void GetMap();
void Dijkstra();

int main(){

    while(cin >> Vertex >> Edge){
        Init();
        GetMap();

        cin >> s >> t;

        Dijkstra();
        int res = Distance[t]-Distance[s];
        if(res == INF){
            cout << -1 << endl;
        }
        else{
            cout << res <<endl;
        }

        Map[MAX][MAX] = { 0 } ;
        Cost[MAX][MAX] = { 0 } ;
        Minium[MAX] = { 0 } ;
        Distance[MAX] = { 0 } ;
        Visit[MAX] = { 0 } ;
    }

    return 0;
}

void Init(){
    memset(Map,INF,sizeof(Map));
    memset(Cost,INF,sizeof(Cost));
    for(int i = 1;i <= Vertex; i++){
    	Map[i][i]=0;
    	Cost[i][i]=0;
	}
}

void  GetMap(){
    while (Edge--){
        int X,Y,Weigth;
        cin >> X >> Y >>Weigth;

        if(Map[X][Y] > Weigth){
            Map[X][Y] = Map[Y][X] = Weigth;
            Cost[X][Y] = Cost[Y][X] = Weigth;
        }
    }

}

void Dijkstra(){
    memset(Visit,0,sizeof(Visit));
    for(int i = 1;i <= Vertex;i++){
    	Distance[i]=Map[s][i];
    	Minium[i]=Cost[s][i];
	}
    Visit[s]=1;
    int u;
    for(int k = 1; k < Vertex; k++){
      int minium=INF;
        for(int i = 1; i <= Vertex; i++){
            if(!Visit[i] && Distance[i] < minium)
               {
                   minium = Distance[i];
                   u=i;
               }  
        }
        Visit[u]=1;
        for(int i = 1;i <= Vertex; i++){
    		if(Distance[i]==Distance[u]+Map[u][i]){
        	    if(Minium[i] > Minium[u] + Cost[u][i] )
        	        Minium[i] = Minium[u] + Cost[u][i];
		    }
	        else if(Distance[i]>Distance[u]+Map[u][i]){
			    Distance[i] = Distance[u] + Map[u][i];
        	    Minium[i] = Minium[u] + Cost[u][i];
		    }
    	   
       }
    }
}