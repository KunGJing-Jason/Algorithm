#include <iostream>
#include <math.h>
using namespace std;

#define MAX_N 100
int amount = 0;
int q[MAX_N];

int place(int i){                               //���Ե�i�е�q[i]�����ܷ�ڷŻʺ�
    int j = 1;
    if (i == 1)
        return 1;
    while (j < i){                             // j=1��i-1���ѷ����˻ʺ����
        if ((q[j] == q[i]) || (abs(q[j] - q[i]) == abs(j - i)))
            return 0;                          //�ûʺ��Ƿ�����ǰ�ʺ�ͬ�У�λ��(j,q[j])��(i,q[i])�Ƿ�ͬ�Խ���
        j++;
    }
    return 1;
}

void display(int n){                            //������
    int i = 1;
    for (i = 1; i <= n; i++){
        cout << "( "<<i + 1 <<" , "<< q[i] + 1<<")";
    }
    cout << endl;
}

void Queens(int n){                     //���n�ʺ�����
    int i = 1;                          // i��ʾ��ǰ��,Ҳ��ʾ���õ�i���ʺ�
    q[i] = 0;                           // q[i]�ǵ�ǰ��,ÿ���¿��ǵĻʺ��ʼλ����Ϊ0��
    while (i >= 1)
    {                                   //��δ���ݵ�ͷ��ѭ��
        q[i]++;                         //ԭλ�ú��ƶ�һ��
        while (q[i] <= n && !place(i))  //��̽һ��λ��(i,q[i])
            q[i]++;
        if (q[i] <= n){                 //Ϊ��i���ʺ��ҵ���һ������λ��(i,q[i])
            if (i == n){                //�����������лʺ�,���һ����
                cout << "��"<< ++amount << "��� : ";
                display(n);
            }

            else
            {                           //�ʺ�û�з�����
                i++;                    //ת����һ��,����ʼ��һ���»ʺ�ķ���
                q[i] = 0;               //ÿ���¿��ǵĻʺ��ʼλ����Ϊ0��
            }
        }
        else
            i--;                        //����i���ʺ��Ҳ������ʵ�λ��,����ݵ���һ���ʺ�
    }
}

int main()
{
    int n;
    cout << "������ʺ���� : ";
    cin >> n;
    Queens(n);
    cout << "�ʺ��ĸ���Ϊ : "<< amount << endl;
    system("pause");
    return 0;
}
