#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, a;
  cin >> n >> a;

  int sum = a;

  rep(i, n) {
    int b;
    string op;
    cin >> op >> b;

    if (op == "+") {
      sum += b;
    } else if (op == "-") {
      sum -= b;
    } else if (op == "*") {
      sum *= b;
    } else if (op == "/") {
      if (b == 0) {
        cout << "error" << endl;
        break;
      }
      sum /= b;
    }
    cout << i + 1 << ":" << sum << endl;
  }
}
