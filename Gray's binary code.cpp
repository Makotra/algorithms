#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < (1 << n); i++) {
    int gray_code = i ^ (i >> 1);
    for (int j = n - 1; j >= 0; j--) {
      cout << ((gray_code >> j) & 1);
    }
    cout << endl;
  }
  return 0;
}
