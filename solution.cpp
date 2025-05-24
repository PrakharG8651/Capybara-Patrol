#include <bits/stdc++.h>
using namespace std;   

void operate(int x){
    if(x==0){
        cout<<1000;return;
    }
    bitset<30> b(x);
    bool start = false;
    for(int i=9;i>-1;i--){
        if(start or (b[i*3+2]+b[i*3+1]+b[i*3])){
            if(!start){
                cout<<1;
                start = true;
            }
            else{
                cout<<0;
            }
            cout<<b[i*3+2]<<b[i*3+1]<<b[i*3];
        }
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        x-=20;
        operate(x);
    }
}