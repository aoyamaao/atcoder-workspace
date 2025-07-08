#include <bits/stdc++.h>
using namespace std;

// nを受け取って、0〜nの総和を計算して返す
int sum(int n) {
  if (n == 0) {
    return 0;
  }
  int s = sum(n - 1);
  return s + n;
}

// aからbまでの総和を計算して返す (a ≤ b)
int sum_range(int a, int b) {
  if (a == b) {
    return a;
  }
  return sum_range(a, b - 1) + b;
}

int array_sum(vector<int> &data, int i = 0) {
  if (i == data.size()) {
    return 0;
  }
  return array_sum(data, i + 1) + data.at(i);
}

bool has_divisor(int n, int i) {
  if (n == i) {
    return false;
  }
  if (n % i == 0) {
    return true;
  }
  return has_divisor(n, i + 1);
}

// 素数を判定する
bool is_prime(int n) {
  if (n == 1) {
    // 1は素数ではない
    return false;
  } else if (n == 2) {
    // 2は素数
    return true;
  } else {
    return has_divisor(n, 2);
  }
}

vector<int> reverse_array_from_i(vector<int> &data, int i) {
  if (i == data.size()) {
    vector<int> empty_array(0);
    return empty_array;
  }
  vector<int> tmp = reverse_array_from_i(data, i + 1);
  tmp.push_back(data.at(i));
  return tmp;
}

vector<int> reverse_array(vector<int> &data) {
  return reverse_array_from_i(data, 0);
}

int main() {
  vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> b = reverse_array(a);
  for (int i = 0; i < b.size(); i++) {
    cout << b.at(i) << " ";
  }
  cout << endl;
}
