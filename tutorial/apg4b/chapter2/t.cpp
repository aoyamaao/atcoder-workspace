#include <bits/stdc++.h>

#include <cstddef>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
  }

  // ここにプログラムを追記
  // (ここで"試合結果の表"の2次元配列を宣言)
  vector<vector<char>> results(N);

  for (int i = 0; i < N; i++) {
    int id = i + 1;
    vector<char> user(N);

    for (int j = 0; j < N; j++) {
      if (i == j) {
        user.at(j) = '-';
        continue;
      }

      int targetId = j + 1;
      char result = '-';
      for (int k = 0; k < M; k++) {
        if (A.at(k) != targetId && B.at(k) != targetId) {
          continue;
        }
        if (A.at(k) == id || B.at(k) == id) {
          if (A.at(k) == id) {
            result = 'o';
          } else if (B.at(k) == id) {
            result = 'x';
          }
          break;
        }
      }
      user.at(j) = result;
    }
    results.at(i) = user;
  }

  for (vector<char> vc : results) {
    for (size_t i = 0; i < vc.size(); i++) {
      cout << vc.at(i);
      if (i != vc.size() - 1) {
        cout << ' ';
      }
    }
    cout << endl;
  }
}
