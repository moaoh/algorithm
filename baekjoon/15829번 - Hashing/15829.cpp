#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    long long sum = 0;
    long long M = 1234567891;
    long long r = 1;

    string l;
    cin >> n >> l;

    for (int i = 0; i < l.size(); i++) {
        int a = (l[i] - 'a' + 1);
        sum = (sum + (a * r) % M) % M;
        r = (r * 31) % M;
    }

    cout << sum << endl;
    return 0;
}