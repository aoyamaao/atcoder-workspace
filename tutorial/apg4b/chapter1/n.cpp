#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> data(N);
  int sum = 0;

  for (int i = 0; i < data.size(); i++) {
    cin >> data.at(i);
    sum += data.at(i);
  }

  int ave = sum / N;
  vector<int> res(N);

  for (int i = 0; i < data.size(); i++) {
    int temp = data.at(i) - ave;
    if (temp < 0) {
      temp *= -1;
    }
    cout << temp << endl;
  }
}
