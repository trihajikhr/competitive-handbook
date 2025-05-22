---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Lucky Number
sumber: codeforces
tags:
  - matematika
---
#matematika 

---
# Algoritma membuat Lucky Number
```cpp
#include <iostream>
#include <vector>
using namespace std;

void generateLucky(int current, int n, vector<int>& lucky) {
    if (current > n) return;
    if (current != 0) lucky.push_back(current); // Hindari angka 0

    generateLucky(current * 10 + 4, n, lucky);
    generateLucky(current * 10 + 7, n, lucky);
    generateLucky(current * 10 + 9, n, lucky);
}

int main() {
    int n;
    cin >> n;

    vector<int> lucky;
    generateLucky(0, n, lucky);

    // Menampilkan semua lucky number <= n
    for (int x : lucky) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

```