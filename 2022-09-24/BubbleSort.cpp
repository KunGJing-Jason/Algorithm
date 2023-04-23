#include <iostream>
using namespace std;

void BubbleSort(int a[],int n,int i);

int main(){
    int a[8]={22, 95, 31, 69, 68, 45, 98, 78};  //Initial the array;
    BubbleSort(a,8,0);                          //Start the recursion fuction;
    for (int i = 0; i < 8; i++)                 //Using loop to output the elements of the array;
    {
        cout<<a[i]<<",";
    }
    cout<<endl;
    
    return 0;
    
}

void BubbleSort(int a[], int n, int i){
    int j;
    bool exchange;                          //Define a flag in order to find whether the element has change;
    if(i == n-1)
        return;                             //The end of the recursion;
    else{
        exchange = false;                   //Initial the flag;
        for(j=n-1;j>i;j--){
            if(a[j]<a[j-1]){                //Start to sort;
                swap(a[j],a[j-1]);          //change the element and let the bigger one in the end of the array;
                exchange = true;            //Flag
            }
            if(exchange == false){
                return;                     //Flag is not false means the elements still need to be sorted;
            }
            else
                BubbleSort(a,n,i+1);        //Start the recursion;
        }
    }
}