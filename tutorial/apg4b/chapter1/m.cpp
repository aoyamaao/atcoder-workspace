#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  // ここにプログラムを追記
  int num = 1;

  for (int i = 0; i < S.size(); i++) {
    if (S.at(i) == '+') {
      num++;
    } else if (S.at(i) == '-') {
      num--;
    }
  }
  cout << num << endl;
}
