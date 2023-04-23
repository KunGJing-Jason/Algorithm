#include <stdio.h>

//函数声明
int EuclideanCommonDivisor(int max, int min);
int EnmuCommonDividor(int max, int min);
int BruteForceCommonDividor(int max, int min);

//主函数
int main(){
    double num1,num2;
    printf("Please Input the number A and number B, seperated by blankspace:\n");
    scanf("%lf %lf",&num1,&num2);

    int max=(int)num1;
    int min=(int)num2;

    if(max<0&&min>0 || min<0&&max>0){
        printf("There is no greatest common divisor between positive and negtive!");
        return 0;
    }

    printf("%d & %d greatest common divisor is:%d\n",max,min,EuclideanCommonDivisor(max,min));//欧几里得
    printf("%d & %d greatest common divisor is:%d\n",max,min,EnmuCommonDividor(max,min));//枚举
    printf("%d & %d greatest common divisor is:%d\n",max,min,BruteForceCommonDividor(max,min));//蛮力
    return 0;
}

//欧几里得
int  EuclideanCommonDivisor(int max,int min){
    
    int temp=max>min?max:min;//对temp赋值，将大数赋值给中间变量，进行计算
    
    while(temp!=0){//若temp为0，则两数没有最小公因数
        temp=max%min;//将余数赋值给temp，当余数为0时，此时max中的数据就是最大公因数，将max返回；
        max=min;
        min=temp;
    }
    return max;
    
}

//枚举
int EnmuCommonDividor(int max,int min){
    int temp = max>min?min:max;//三元判断大小，将小数赋值给temp；若temp能同时将二者整除，则为最小公因数
    while(max%temp!=0 || min%temp!=0){//只要其中一个数字余数不为0，则将继续执行；
        temp--;
    }
    return temp;
}


//蛮力法
int BruteForceCommonDividor(int max,int min){
    int temp=1;//对temp1 赋值，防止后续相乘结果为0
    for(int i=2;i<=max&&i<=min;i++)//当i小于m和n时（或出现37 17），程序继续执行，i<2时，程序无意义
    {
        while(max%i==0 && min%i==0){//当m、n除以i余数为0的时候，i为最小公因数，将最小公因数累乘，结果为最大公因数。
            temp*=i;
            max /=i;
            min /=i;
        }
    }
    return temp;
}