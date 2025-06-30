#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;

  // ここにプログラムを追記
  int sum = A;
  for (int i = 0; i < N; i++) {
    string op;
    int B;
    cin >> op >> B;

    if (op == "+") {
      sum += B;
    } else if (op == "-") {
      sum -= B;
    } else if (op == "*") {
      sum *= B;
    } else if (op == "/") {
      if (B == 0) {
        cout << "error" << endl;
        break;
      }
      sum /= B;
    }
    cout << i + 1 << ":" << sum << endl;
  }
}
