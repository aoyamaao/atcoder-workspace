#include <bits/stdc++.h>
using namespace std;

int main() {
  int num, price;
  cin >> num >> price;

  vector<int> apple(num);
  vector<int> pine(num);

  for (int i = 0; i < num; i++) {
    cin >> apple.at(i);
  }

  for (int i = 0; i < num; i++) {
    cin >> pine.at(i);
  }

  int count = 0;
  for (int a : apple) {
    for (int p : pine) {
      int total = a + p;
      if (total == price) {
        count++;
      }
    }
  }
  cout << count << endl;
}
