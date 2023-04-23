#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


struct node
{
    int step;                                       //当前步数
    int *x;                                         // x[i]:第i个皇后所在的列数
};

int n, num;

bool Palce(int i, int *x, int step){                //可行条件 : 第step+1个皇后有位置可去
    int j;
    for (j = 1; j <= step; j++){                    //与前面的j个皇后进行比较
        if (i == x[j] || abs(j - (step + 1)) == abs(x[j] - i))
            return false;                           //同列同对角线
    }
    return true;
}

void bfs(){ //搜索框架
    queue<node> q;                                  //创建队列
    node n0, n1, n2;                                //创建节点,n0 : 初始化   n1 : 最终结果   n2 : 存放队列信息
    int i, j;
    n0.step = 0;
    n0.x = new int[n1.step + 1];
    q.push(n0);                                     //初始化，进队列
    while (!q.empty())
    {
        n1 = q.front();                             //头结点出队列
        q.pop();
        if (n1.step == n){                          //出口
            for (i = 1; i <= n; i++)
                cout << "[" << i << ","<<n1.x[i] << "]"<< "  ";
            cout << endl;
            num++;
            continue;
        }
        for (i = 1; i <= n; i++){
            if (Palce(i, n1.x, n1.step)){
                n2.step = n1.step + 1;
                n2.x = new int[n2.step + 1];
                for (j = 1; j < n2.step; j++)
                    n2.x[j] = n1.x[j];
                n2.x[n2.step] = i;
                q.push(n2);
            } 
        }
    }
}

int main()
{
    cout << "请输入皇后个数n：" << endl;
    cin >> n;
    cout << "该皇后问题的解为：" << endl;
    bfs();
    cout << "共有" << num <<"种方法"<<endl;
    return 0;
}
