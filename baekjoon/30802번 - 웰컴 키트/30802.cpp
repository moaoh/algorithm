#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n, t, p;
  int tNum = 0;
  vector<int> v(6);

  cin >> n;
  for (int i = 0; i < 6; i++) {
      cin >> v[i];
  }
  cin >> t >> p;

  for (int i = 0; i < 6; i++) {
      tNum += v[i] / t;
      if (v[i] % t != 0) tNum++;
  }
  cout << tNum << endl;
  cout << n / p << " " << n % p;

  return 0;
}