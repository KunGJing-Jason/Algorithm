#include<iostream>
using namespace std;
int CompareLR(int arr[],int Left,int Right);

int main(){
    int t=0,NumSize;                    //t为几组数据，NumSize为每组数据的大小
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>NumSize;

        int *p = new int[NumSize];      //开辟动态数组空间

        for(int j=0;j<NumSize;j++){
            cin>>p[j];
        }

        if(CompareLR(p,0,NumSize-1)){   //调用递归
            cout<<"是回文数";
        }else{
            cout<<"不是回文数";
        }
    }
    return 0;
}
/// @brief 
/// @param arr   待判断数组 
/// @param Left  首元素
/// @param Right 尾元素
/// @return 
int CompareLR(int arr[],int Left,int Right){
 
    if(Left==Right)                             //若首尾下标相同，则直接输出是回文数，同时也是本递归的出口
        return 1;
    
    else{
        if(arr[Left]==arr[Right])               //若相同，则参与递归
            return CompareLR(arr,++Left,--Right);//对于首尾元素一定先自增，在运算；不然就会造成无法结束循环的情况；
        else
            return 0;
    }
    return 0;
}





