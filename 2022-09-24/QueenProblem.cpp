//Put the queens into the chest
//Only ONE queen in the same row and same colum
//Diagnoal is forbidden
//Use the recursive algorithm

#include <iostream>
#include <string.h>
#define N 100 //Max count of queen;
using namespace std;

int q[N] = {0};//queen's position, use arr flag and it's value to show.
int num = 0;//count the times of calls。

/// @brief out put the solution of queen
/// @param n 
void dispasolution(int n){
    cout<< "第"<<++num <<"次运行找到一个解："<<endl;
    for (int i = 1; i <= n; i++){
        cout << "("<<i <<"," << q[i]<<")";
    }
    cout << endl;
}


/// @brief Testing whether the position of the queen is suitable
/// @param i The num of the last rolls 
/// @param j The collumn of queen;
/// @return 
bool place(int i, int j){
    if(i==1)//The very first position is always true;
        return true;
    
    int k=1;
    while(k<i){  //k∈[1,i-1], where has already have queens
        if( (q[k]==j) || (abs(q[k]-j)==abs(i-k)) ){//To judge is the same roll and collumn or in the diagonal;
            return false;
        }

        k++;
    }
    return true;
}


void queen (int i, int n){
    if(i>n){    
        dispasolution(n);
    }
    else{
        for(int j = 1; j <= n; j++){
            if (place(i,j)){
                q[i]=j;
                queen(i+1,n);
            }
        }
    }
}

int main(){
    int n;//The num of queen will be put;
    cin >> n;
    memset(q,0,sizeof(q));
    queen(1,n);
    cout <<"可解个数："<<num;
    return 0;
}