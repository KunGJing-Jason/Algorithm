#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 51
int n = 3;
                                    // num  time    deadline    produce
int t[] = {0,1,4,1};                //  1     1        5           2
int d[] = {0,5,4,5};                //  2     4        4           8
int p[] = {0,2,8,6};                //  3     1        5           6

int bestp = 0;                                      

struct Action{  
    int time;                                          
    int deadline;                                          
    int produce;                                          
    bool operator < (const Action t) const{
	return produce > t.produce;                                   
   }
};

Action A[MAXN];                                     

void solve();                                       

int main(){
    for (int i = 1; i <= n; i++){                   
	    A[i].time = t[i];
	    A[i].deadline = d[i];
	    A[i].produce = p[i];
    }

    solve();
    cout<<"最优解："<< bestp << endl;
}

/// @brief 主要判定就是当前的任务的deadline 是否 >= sum + 当前任务时间；
/// @brief 例子，当前deadline 为 5，sum = 4; 而完成的当前任务时间为8，那么 4 + 8 > 5 ， 不合符条件
void solve(){                                       
    sort(A+1, A+n+1);                               
    int sum = 0;                                    
    for (int i = 1; i <= n; i++){
        if (A[i].deadline >= sum + A[i].time){                 //若sum + A[i].time超过了限制，则不能计入
            bestp += A[i].produce;                        
            sum += A[i].time;                          
        }
   }
}
