#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  string op;
  cin >> a >> op >> b;
  bool error = false;

  if (op != "+" && op != "-" && op != "*" && op != "/") {
    error = true;
  } else if (op == "/" && b == 0) {
    error = true;
  }

  if (error) {
    cout << "error" << endl;
    return 0;
  }

  int out = 0;
  if (op == "+") {
    out = a + b;
  } else if (op == "-") {
    out = a - b;
  } else if (op == "*") {
    out = a * b;
  } else if (op == "/") {
    out = a / b;
  }
  cout << out << endl;
}
