#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, a, b;
  cin >> x >> a >> b;

  // 1.の出力
  x++;
  cout << x << endl;

  // ここにプログラムを追記
  int x2 = x *= (a + b);
  cout << x2 << endl;

  int x3 = x2 *= x2;
  cout << x3 << endl;

  int x4 = --x3;
  cout << x4 << endl;
}
