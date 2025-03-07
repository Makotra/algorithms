#include <iostream>
using namespace std;
int main() {
    int a,i,j,k;
    cin>>a;
    int mas[a];
    for (i=0;i<a;i++){
        cin>>mas[i];
    }
    for(i=1;i<a;i++){
        j=i;
        while (j){//пока не найдем элемента который меньше текущего - меняем местами текущий и с предыдущим индексом
            if (mas[j-1]<mas[j]){//если нашли что элемент с предедущим индексом меньше то текущий останавливается перед ним
                break;
            }
            k=mas[j-1];
            mas[j-1]=mas[j];
            mas[j]=k;
            j--;
        }
    }
    for (i=0;i<a;i++) {
        cout << mas[i] << " ";
    }
    return 0;
}
