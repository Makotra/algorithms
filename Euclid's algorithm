#include <iostream>
using namespace std;
int main() {
    int a,b,minab,maxab,mid;
    cin>>a>>b;
    if (a>=b){
        maxab=a;
        minab=b;
    }
    else{
        maxab=b;
        minab=a;
    }
    for (;;){
        mid=maxab%minab;
        if (mid==0) {
            break;
        }
        maxab=minab;
        minab-=mid;
    }
    cout<<minab;
    return 0;
}
