#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  vector<int> vec = {A, B, C};
  sort(vec.begin(), vec.end());

  int min = vec.at(0);
  int max = vec.at(vec.size() - 1);
  int diff = max - min;

  cout << diff << endl;
}
