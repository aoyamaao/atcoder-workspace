#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> data(5);
  for (int i = 0; i < 5; i++) {
    cin >> data.at(i);
  }

  // dataの中で隣り合う等しい要素が存在するなら"YES"を出力し、そうでなければ"NO"を出力する
  // ここにプログラムを追記
  bool first = true;
  int prev = 0;
  bool isSame = false;

  for (int i : data) {
    if (first) {
      first = false;

    } else if (prev == i) {
      isSame = true;
    }
    prev = i;
  }

  string s;
  if (isSame) {
    s = "YES";
  } else {
    s = "NO";
  }
  cout << s << endl;
}
