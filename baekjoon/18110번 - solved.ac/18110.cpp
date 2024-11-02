#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

double truncated_mean(vector<double>& data, double trim_ratio) {
    int n = data.size();
    int trim_count = static_cast<int>(round(n * trim_ratio)); // 절사할 개수를 반올림하여 계산

    // 데이터 정렬
    sort(data.begin(), data.end());

    // 절사평균 계산
    double sum = accumulate(data.begin() + trim_count, data.end() - trim_count, 0.0);
    int remaining_count = n - 2 * trim_count;

    // 반올림된 절사평균 반환
    return remaining_count > 0 ? round(sum / remaining_count) : 0.0;
}

int main() {
    int n;
    double x;
    vector<double> data;
    double trim_ratio = 0.15; // 상위와 하위 15% 절단

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        data.push_back(x);
    }

    double result = truncated_mean(data, trim_ratio);
    cout << result << endl;

    return 0;
}