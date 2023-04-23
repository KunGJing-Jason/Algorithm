#include <iostream>
using namespace std;
#define MAXN 100

int n = 4;                                  //  ��Ʒ���� ��4
int W = 6;                                  //  ���������������������6
int w[] = {0, 5, 3, 2, 1};                  //  ���4����Ʒ����,�����±�0Ԫ��
int v[] = {0, 4, 4, 3, 1};                  //  ���4����Ʒ��ֵ,�����±�0Ԫ��

int x[MAXN];                                //  ������ս�
int maxv;                                   //  ������Ž���ܼ�ֵ

int bound(int i, int tw, int tv){           //�Ͻ纯�������ڼ�֦
    i++;                                    //��i+1��ʼ
    while (i <= n && tw + w[i] <= W){       //�����Ϊi����Ʒ������������
        tw += w[i];
        tv += v[i];
        i++;
    }
    if (i <= n)
        return tv + (W - tw) * v[i];        //���Ϊi����Ʒ������������
    else
        return tv;
}

void dfs(int i, int tw, int tv, int op[]){  //���0/1��������
    if (i > n){                             //�ҵ�һ��Ҷ�ӽ��
        maxv = tv;                          //��Ÿ��Ž�
        for (int j = 1; j <= n; j++)
            x[j] = op[j];
    }
    else{                                   //��δ����������Ʒ
        if (tw + w[i] <= W){                //���ӽ���֦
            op[i] = 1;                      //ѡȡ���Ϊi����Ʒ
            dfs(i + 1, tw + w[i], tv + v[i], op);
        }
        if (bound(i, tw, tv) > maxv){       //�Һ��ӽ���֦
            op[i] = 0;                      //��ѡȡ���Ϊi����Ʒ,����
            dfs(i + 1, tw, tv, op);
        }
    }
}

int main(){

    dfs(1, 0, 0, x);

    for (int i = 1; i < 5; i++){
        if (x[i] == 1){
            cout << "��Ʒ : " << i << "��ѡ��" << endl;
        }
    }
    cout << endl << "����ֵΪ��" << maxv << endl;

    system("pause");

    return 0;
}
