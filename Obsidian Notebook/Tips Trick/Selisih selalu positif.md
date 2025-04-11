---
obsidianUIMode: preview
note_type: tips trick
tips_trick: selisih selalu positif
sumber: chatgpt.com
tags:
  - matematika
  - mutlak
---
#mutlak #matematika

---

# Selisih selalu positif
Jika kamu ingin mencari selisih antara dua angka tetapi tidak ingin hasilnya negatif, kamu bisa menggunakan fungsi `abs()` dari pustaka `<cmath>`.

## Contoh Penggunaan:

```cpp
#include <iostream>
#include <cmath>  // Untuk abs()
using namespace std;

int main() {
    int a = 5, b = 10;
    int selisih = abs(a - b);  // Selalu menghasilkan nilai positif
    cout << "Selisih: " << selisih << endl;
    return 0;
}
```

## Output:

```
Selisih: 5
```

Fungsi `abs()` akan memastikan bahwa hasil selisih selalu positif, sehingga **`abs(5 - 10) = abs(-5) = 5`**.