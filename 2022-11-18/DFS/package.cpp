#include <iostream>
using namespace std;
#define MAXN 100

int n = 4;                                  //  物品数量 ：4
int W = 6;                                  //  背包最大容量（重量）：6
int w[] = {0, 5, 3, 2, 1};                  //  存放4个物品重量,不用下标0元素
int v[] = {0, 4, 4, 3, 1};                  //  存放4个物品价值,不用下标0元素

int x[MAXN];                                //  存放最终解
int maxv;                                   //  存放最优解的总价值

int bound(int i, int tw, int tv){           //上界函数，用于剪枝
    i++;                                    //从i+1开始
    while (i <= n && tw + w[i] <= W){       //若序号为i的物品可以整个放入
        tw += w[i];
        tv += v[i];
        i++;
    }
    if (i <= n)
        return tv + (W - tw) * v[i];        //序号为i的物品不能整个放入
    else
        return tv;
}

void dfs(int i, int tw, int tv, int op[]){  //求解0/1背包问题
    if (i > n){                             //找到一个叶子结点
        maxv = tv;                          //存放更优解
        for (int j = 1; j <= n; j++)
            x[j] = op[j];
    }
    else{                                   //尚未找完所有物品
        if (tw + w[i] <= W){                //左孩子结点剪枝
            op[i] = 1;                      //选取序号为i的物品
            dfs(i + 1, tw + w[i], tv + v[i], op);
        }
        if (bound(i, tw, tv) > maxv){       //右孩子结点剪枝
            op[i] = 0;                      //不选取序号为i的物品,回溯
            dfs(i + 1, tw, tv, op);
        }
    }
}

int main(){

    dfs(1, 0, 0, x);

    for (int i = 1; i < 5; i++){
        if (x[i] == 1){
            cout << "物品 : " << i << "被选中" << endl;
        }
    }
    cout << endl << "最大价值为：" << maxv << endl;

    system("pause");

    return 0;
}
