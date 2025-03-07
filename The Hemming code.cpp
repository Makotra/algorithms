#include <iostream>
#include <string>
#include <vector>
using namespace std;

string hammingDecode(const string &encoded) {
  int n = encoded.size();
  vector<int> bits(n);

  for (int i = 0; i < n; i++) {
    bits[i] = encoded[i] - '0';
  }

  vector<int> controlPositions;
  for (int p = 1; p <= n; p *= 2) {
    controlPositions.push_back(p);
  }

  int errorPosition = 0;
  for (int p : controlPositions) {
    int checkSum = 0;
    for (int i = 1; i <= n; i++) {
      if (i & p) {
        checkSum ^= bits[i - 1];
      }
    }
    if (checkSum != 0) {
      errorPosition += p;
    }
  }

  if (errorPosition > 0 && errorPosition <= n) {
    bits[errorPosition - 1] ^= 1;
  }

  string decoded;
  for (int i = 1; i <= n; i++) {
    bool isControlPosition = false;
    for (int p : controlPositions) {
      if (p == i) {
        isControlPosition = true;
        break;
      }
    }
    if (!isControlPosition) {
      decoded += to_string(bits[i - 1]);
    }
  }

  return decoded;
}

int main() {
  int t;
  cin >> t;
  cin.ignore();

  vector<string> results;
  for (int i = 0; i < t; i++) {
    string encodedMessage;
    getline(cin, encodedMessage);
    results.push_back(hammingDecode(encodedMessage));
  }

  for (const string &result : results) {
    cout << result << endl;
  }

  return 0;
}
