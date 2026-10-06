---
obsidianUIMode: preview
note_type: latihan
latihan: Subset Sum dengan Bitmasking
sumber: chatgpt.com
tags:
  - bits
  - bitwise
---
---
# Subset Sum dengan Bitmasking

Diberikan:

- Sebuah array `a` yang berisi `N` bilangan bulat (`1 ≤ N ≤ 20`)
    
- Sebuah bilangan target `S`
    

Tentukan apakah **ada subset dari array tersebut** yang jumlah elemennya sama dengan `S`.

## 🧾 Contoh Input/Output:

**Contoh 1:**

```
Input:
N = 4, S = 6
a = [1, 2, 3, 4]

Output:
YES

Penjelasan:
Subset {2, 4} jumlahnya 6.
```

**Contoh 2:**

```
Input:
N = 3, S = 10
a = [1, 2, 3]

Output:
NO
```

---

## 🔍 Ide Penyelesaian (Dengan Bitmasking)

Kita bisa **meng-encode setiap subset** dengan sebuah bilangan bulat dari $0$ sampai $2^N - 1$, di mana bit `i` menyatakan:

- `1` → Elemen ke-i diambil ke subset
    
- `0` → Elemen ke-i tidak diambil
    

Misalnya, untuk N=3, angka `5 = 101₂` berarti ambil elemen ke-0 dan ke-2.

---

## 🧪 Implementasi C++

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int>& a, int S) {
    int N = a.size();
    for (int mask = 0; mask < (1 << N); ++mask) {
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                sum += a[i]; // Ambil elemen ke-i jika bit i menyala
            }
        }
        if (sum == S) return true; // Ketemu subset yang jumlahnya S
    }
    return false;
}

int main() {
    int N, S;
    cout << "Masukkan jumlah elemen N dan target S: ";
    cin >> N >> S;
    
    vector<int> a(N);
    cout << "Masukkan " << N << " elemen:\n";
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    if (subsetSum(a, S))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
```

---

## 📘 Penjelasan Baris demi Baris

| Kode              | Penjelasan                                            |
| ----------------- | ----------------------------------------------------- |
| `(1 << N)`        | Banyaknya subset yang mungkin = 2ⁿ                    |
| `mask & (1 << i)` | Cek apakah elemen ke-`i` diambil dalam subset         |
| `sum += a[i]`     | Tambahkan elemen ke dalam total sum subset            |
| `if (sum == S)`   | Jika total sama dengan target `S`, maka return `true` |
## FAQ
> Loh, berarti soal ini tanpa bitwise juga bisa dong? nyari $x$ ditambah $y$ dari array yang hasilnya $z$, gitu kan?


Yup, **benar banget!** 👏

### ✅ Jawaban singkatnya:

**Iya, soal ini bisa diselesaikan tanpa bitwise**, misalnya dengan **rekursi biasa**, **backtracking**, atau bahkan dengan **nested loop** kalau `N` kecil.

Tapi... 🤔

---

### ❗Kenapa tetap kita pakai _bitmasking_?

Karena:

#### 1. Efisiensi untuk `N ≤ 20`

- Kalau kamu pakai 2 _nested loop_, hanya bisa cek 2 elemen sekaligus.
    
- Tapi **bitmasking bisa mengecek semua kemungkinan subset** (termasuk 3, 4, atau semua elemen diambil), hanya dengan satu loop dari `0` sampai `2ⁿ - 1`.
    

#### 2. Bitmasking = Strategi Serbaguna di Competitive Programming

- Banyak soal yang **butuh semua kemungkinan kombinasi**, dan dengan bitmasking itu **lebih cepat dan bersih**, apalagi saat pakai `if (mask & (1 << i))`.
    
- Misalnya: **Travelling Salesman Problem**, **DP dengan status subset**, **pembagian tim**, dll.
    

#### 3. Latihan Bitwise Penting

- Ini latihan awal yang bagus untuk:
    
    - Mengerti representasi subset dalam bentuk biner
        
    - Mengerti operasi `&`, `<<`, dan kontrol bit dengan `mask`
        

---

### 🔁 Versi Non-Bitwise (rekursi/backtracking)

Ini juga bisa:

```cpp
bool solve(int i, int sum) {
    if (i == N) return sum == S;
    return solve(i+1, sum) || solve(i+1, sum + a[i]);
}
```

---

### 📘 Kesimpulan untuk Dicatat:

|Metode|Cocok untuk|Catatan|
|---|---|---|
|Bitmasking|N ≤ 20|Elegan, cepat, dan melatih konsep bit|
|Rekursi DFS|N ≤ 20|Sama cepatnya, tapi struktur berbeda|
|Brute-force loop|N kecil (≤5)|Tidak fleksibel dan cepat membengkak|
