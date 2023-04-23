#include <iostream>
#include <math.h>
using namespace std;

#define MAX_N 100
int amount = 0;
int q[MAX_N];

int place(int i){                               
    int j = 1;
    if (i == 1)
        return 1;
    while (j < i){                             
        if ((q[j] == q[i]) || (abs(q[j] - q[i]) == abs(j - i)))
            return 0;                          
        j++;
    }
    return 1;
}

void Queens(int n){                     
    int i = 1;                          
    q[i] = 0;                           
    while (i >= 1)
    {                                   
        q[i]++;                         
        while (q[i] <= n && !place(i))  
            q[i]++;
        if (q[i] <= n){                 
            if (i == n){                
                ++amount;
            }

            else
            {                           
                i++;                    
                q[i] = 0;               
            }
        }
        else
            i--;                       
    }
}

int main()
{
    int n;
    while(cin >> n){
        Queens(n);
        cout << amount << endl;
        amount = 0;
    }
    return 0;
}
