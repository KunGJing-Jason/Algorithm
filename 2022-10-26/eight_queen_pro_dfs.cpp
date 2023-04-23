#include <iostream>
#include <math.h>
using namespace std;
#define n 8
int q[n] = {-1};						//第i行上的皇后在第几列

int cnt = 0;							//计数器，多少种解

void print();							//输出方法
bool check(int j);						//位置是否合法
void queen();							//皇后放置
	
int main(){
	queen();
	cout << "共有"<< cnt << "种布局。" << endl;
	return 0;
}

void print(){							//输出方法
	int i,j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(q[i] == j)
				cout << " Q ";
			else
				cout << " □ ";
		}
		cout<<endl;
	}
	cout<<endl;
}

bool check(int j){						//位置是否合法
	int i=0;
	while(i<j){
		if(q[i] == q[j] || abs(q[i]-q[j]) == abs(i-j))
			return false;
		i++;
	}
	return true;
}

void queen(){							//皇后放置
	int i = 0;
	while(i >= 0){						//直到回溯到第一行也找不到可以放置皇后的位置，函数结束
		q[i]++;

		while(!check(i) && q[i]<n)
			q[i]++;						//找到这一行能够放置皇后的列数

		if(q[i] < n){
			if(i == n-1){				//最后一行也成功放置皇后，找到一个解
				cnt++;
				print();
			}
			else
				i++;
		}
		else{
			q[i] = -1;					//第i行到最后也没有找到合适的位置，初始化本行的列数
			i--;						//回到上一行，从下一列开始寻找
		}
	}
}