
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <chrono>
#include <memory>


using namespace std;


int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) { // считываем элементы массива и сохраняем их в векторе
    cin >> a[i];
  }

  while (k--) {
    int x;
    cin >> x;

    auto i = lower_bound(a.begin(), a.end(), x); // использует std::lower_bound для поиска итератора, указывающего на первый элемент отсортированного массива a, который не меньше x

    if (i == a.begin() || (*i - x) < (x - *(i-1))) {
      cout << *i << "\n";
    } else {
      cout << *(i-1) << "\n";
    }
  }

  return 0;
}
