#include <iostream>
using namespace std;
long long total_count=0;
void sortmerge(int* mass, int l,int mid,int r){
    long long  chast1 = 0;
    long long  chast2 = 0;
    int result[r - l];
    while (l + chast1 < mid && mid + chast2 < r) {
        if (mass[l + chast1] <= mass[mid + chast2]) {
            result[chast1 + chast2] = mass[l + chast1];
            chast1 += 1;
        }
        else {
            result[chast1 + chast2] = mass[mid + chast2];
            total_count+=(mid-(l+chast1));
            chast2 += 1;
        }
    }
    while (l + chast1 < mid) {
        result[chast1 + chast2] = mass[l + chast1];
        chast1 += 1;
    }
    while (mid + chast2 < r) {
        result[chast1 + chast2] = mass[mid + chast2];
        chast2 += 1;
    }
    for (int i = 0; i<chast1+chast2;i++) {
        mass[l + i] = result[i];
    }

}
void Recursivemerge(int* massiv, int lef,int rig) {
    if (lef + 1 >= rig) {
        return;
    }
    int mid = (lef + rig) / 2;
    Recursivemerge(massiv, lef, mid);
    Recursivemerge(massiv, mid, rig);
    sortmerge(massiv, lef, mid, rig);
}
int main() {
    long long a,i;
    cin>>a;
    int mas[a];
    for (i=0;i<a;i++) {
        cin >> mas[i];
    }
    Recursivemerge(mas,0,a);
    cout<<total_count;
    return 0;
}
