#include <iostream>
#include <string>
using namespace std;

void sortmerge(string* mass, int l, int mid, int r, int pos) {
    int chast1 = 0;
    int chast2 = 0;
    string result[r - l];

    while (l + chast1 < mid && mid + chast2 < r) {
        char char1 = (pos < mass[l + chast1].size()) ? mass[l + chast1][pos] : '\0';
        char char2 = (pos < mass[mid + chast2].size()) ? mass[mid + chast2][pos] : '\0';

        if (char1 <= char2) {
            result[chast1 + chast2] = mass[l + chast1];
            chast1 += 1;
        } else {
            result[chast1 + chast2] = mass[mid + chast2];
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

    for (int i = 0; i < chast1 + chast2; i++) {
        mass[l + i] = result[i];
    }
}

void Recursivemerge(string* massiv, int lef, int rig, int pos) {
    if (lef + 1 >= rig) {
        return;
    }
    int mid = (lef + rig) / 2;
    Recursivemerge(massiv, lef, mid, pos);
    Recursivemerge(massiv, mid, rig, pos);
    sortmerge(massiv, lef, mid, rig, pos);
}

int main() {
    int countline, length, countword;
    cin >> countline >> length >> countword;
    string str[countline];

    for (int i = 0; i < countline; i++) {
        cin >> str[i];
    }

    for (int wor = length - 1; wor >= length - countword; wor--) {
        Recursivemerge(str, 0, countline, wor);
    }
    for (int i = 0; i < countline; i++) {
        cout << str[i] << endl;
    }

    return 0;
}
