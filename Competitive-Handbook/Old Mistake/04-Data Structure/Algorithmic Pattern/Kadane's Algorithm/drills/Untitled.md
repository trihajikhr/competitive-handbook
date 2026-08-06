


Kadane tapi mencari rentang ssubarray, bukan jumlah:

```cpp
#include <iostream>
#include <vector>
using namespace std;

auto kadane(const vector<int>& vec) -> pair<int, int> {
    int current_max = vec.front();
    int global_max = vec.front();

    int start = 0, end = 0;
    int temp_start = 0;
    for (int i = 1; i < (int)vec.size(); i++) {
        if (vec[i] > current_max + vec[i]) {
            current_max = vec[i];
            temp_start = i;
        } else {
            current_max += vec[i];
        }

        if (current_max > global_max) {
            global_max = current_max;
            start = temp_start;
            end = i;
        }
    }

    return {start, end};
}

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    pair<int, int> rest = kadane(vec);
    cout << "Start: " << rest.first << "\n";
    cout << "End  : " << rest.second << "\n";

    return 0;
}

```