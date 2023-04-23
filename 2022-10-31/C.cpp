#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct node{
    int value;
    int weight;
}good[200];

bool cmp_value(node a, node b){
    if(a.value == b.value)
        return a.value < b.value;
    return a.value > b.value;
}

bool cmp_weight(node a, node b){
    if(a.weight == b.weight)
        return a.weight > b.weight;
    return a.weight < b.weight;
}

bool cmp_unit(node a, node b){
    if((a.value / a.weight) == (b.value / b.weight))
        return a.weight < b.weight;
    return (a.value / a.weight) > (b.value / b.weight);
}

int cnt_value(int n, int c){
    int value = 0;
    for (int i = 0; i < n; i++){
        if(c >= good[i].weight){
            c -= good[i].weight;
            value += good[i].value;
        }
    }
    return value;
}

int main(){
    int n = 0, c = 0;

    while(cin >> n >> c){
        int ans_w = 0, ans_v = 0, ans_u = 0;

        for(int i = 0; i < n; i++){
            cin >> good[i].value;
        }
        for(int i = 0; i < n; i++){
            cin >> good[i].weight;
        }

        sort(good, good + n, cmp_weight);
        ans_w = cnt_value(n,c);

        sort(good, good + n, cmp_value);
        ans_v = cnt_value(n,c);

        sort(good, good + n, cmp_unit);
        ans_u = cnt_value(n, c);

        int result = ans_v  >ans_w? ans_v>ans_u? ans_v:ans_u : ans_w>ans_u? ans_w:ans_u;

        cout << result << endl;

        memset(good, 0, sizeof(good));

    }
    
    return 0;
}