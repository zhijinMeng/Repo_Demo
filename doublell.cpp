#include <iostream>
using namespace std;

const int N = 100010;

int idx, e[N], l[N], r[N];

void init(){
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

void insertAtK(int k, int x){
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx ++;
}

void deleteK(int k){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main(){
    int n;
    cin >> n;
    
    init();
    
    while(n--){
        string a;
        cin >> a;
        
        if(a == "L"){
            int x;
            scanf("%d", &x);
            insertAtK(0,x);
        }
        if(a == "R"){
            int x;
            scanf("%d", &x);
            insertAtK(l[1],x);

        }
        if(a == "D"){
            int x;
            scanf("%d", &x);
            deleteK(x + 1);
            
        }
        if(a == "IL"){
            int x;
            scanf("%d", &x);
            int y;
            scanf("%d", &y);
            insertAtK(l[x + 1], y);
            
        }
        if(a == "IR"){
            int x;
            scanf("%d", &x);
            int y;
            scanf("%d", &y);
            insertAtK(x + 1, y);
        }
    }
    
    for(int i = r[0]; i != 1; i = r[i]){
        printf("%d ", e[i]);
    }
    
}