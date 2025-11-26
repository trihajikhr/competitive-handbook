---
obsidianUIMode: preview
note_type: latihan
latihan: Apakah Stack Kosong
sumber: Google.com, AI
tags:
  - stack
  - data-structure
date_learned: 2025-06-15T21:47:00
---
---
# Apakah Stack Kosong
Mantap! Kita langsung lanjut ke soal ke-4 yang akan melatih kamu menggunakan **`empty()`** dan **`size()`**:

---

## 🧠 Soal Stack 3 – Apakah Stack Kosong?

**Deskripsi:**

Kamu akan diberikan `n` perintah yang terdiri dari `"PUSH x"` untuk memasukkan bilangan ke stack dan `"POP"` untuk menghapus elemen paling atas dari stack. Setelah setiap perintah, cetak ukuran stack saat ini, dan apakah stack kosong atau tidak.

**Format Input:**

- Baris pertama: sebuah bilangan bulat `n` (1 ≤ n ≤ 100)
    
- Diikuti `n` baris, masing-masing berisi perintah:
    
    - `"PUSH x"` (x adalah bilangan bulat)
        
    - atau `"POP"`
        

**Format Output:**  
Untuk setiap perintah, cetak dalam format berikut:

```
Size = <ukuran_stack>, Empty = <YES/NO>
```

**Contoh Input:**

```
5
PUSH 10
PUSH 20
POP
POP
POP
```

**Contoh Output:**

```
Size = 1, Empty = NO
Size = 2, Empty = NO
Size = 1, Empty = NO
Size = 0, Empty = YES
Size = 0, Empty = YES
```

**Catatan:**

- POP terhadap stack kosong tidak menyebabkan error, hanya abaikan.
    

**Petunjuk:**

- Gunakan `.empty()` untuk mengecek apakah stack kosong.
    
- Gunakan `.size()` untuk mendapatkan jumlah elemen saat ini.
    

---

Kalau udah selesai, bilang aja mau lanjut ke soal ke-5, nanti aku buatkan dengan fungsi stack yang belum kamu pakai. Semangat! 💪

## Jawabanku
Berikut adalah jawabanku, yang ternyata masih bisa diperbaiki lagi:

```cpp
#include<iostream>
#include<stack>
#include<sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> val;
    int n; cin >> n;

    while(n--){
        string s;
        getline(cin >> ws, s);

        stringstream ss(s);
        string cmd;
        ss >> cmd;

        if(cmd=="PUSH"){
            int num;
            ss >> num;
            val.push(num);
            cout << "Size = " << val.size() << ", Empty = NO\n"; 
        } else if (cmd=="POP"){
            if(!val.empty()) val.pop();
            bool zero = (val.empty()? true:false);
            cout << "Size = " << val.size() << ", Empty = " << (zero? "YES":"NO") << "\n";
        }
    }
    return 0;
}
```

# Editorial
✅ Kodenya sudah **benar dan rapi**! Kamu sudah:

- Gunakan `getline(cin >> ws, s)` dengan tepat untuk menangani input baris campuran (`PUSH x` dan `POP`).
    
- Pakai `stringstream` untuk parsing kata per kata.
    
- Gunakan `val.push(num)`, `val.pop()`, `val.size()`, dan `val.empty()` dengan akurat.
    
- Menangani kasus `POP` saat stack kosong (tidak memanggil `pop()` sembarangan).
    

👍 Output juga sudah persis sesuai yang diminta.

---

### 🔍 Sedikit saran (optional, bukan kesalahan):

Baris ini:

```cpp
bool zero = (val.empty()? true:false);
```

bisa disingkat langsung menjadi:

```cpp
bool zero = val.empty();
```

karena `val.empty()` sudah menghasilkan `true` atau `false`.

Jadi bisa disingkat:

```cpp
cout << "Size = " << val.size() << ", Empty = " << (val.empty() ? "YES" : "NO") << "\n";
```

