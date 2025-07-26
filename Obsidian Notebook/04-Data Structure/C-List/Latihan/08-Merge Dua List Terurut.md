---
obsidianUIMode: preview
note_type: latihan
latihan: Merge Dua List Terurut
sumber: chatgpt.com
tags:
  - list
  - data-structure
date_learned: 2025-07-09T14:26:00
---
---
Mantap! 💪 Kita lanjut ke Soal 8: Merge Dua List Terurut  

Soal ini menguji pemahamanmu tentang manipulasi dua `std::list<int>` yang sudah terurut menaik, dan kamu diminta menggabungkannya jadi satu list terurut juga.

# Soal 8: Merge Dua List Terurut

### 📝 Deskripsi:

Diberikan dua list `A` dan `B` yang **sudah terurut secara menaik**, tugasmu adalah menggabungkannya menjadi satu list `C` yang juga terurut menaik, lalu mencetak isinya.
### 📥 Input:

Baris pertama: bilangan bulat `n` — banyaknya elemen di list A  
Baris kedua: `n` bilangan bulat — elemen list A  
Baris ketiga: bilangan bulat `m` — banyaknya elemen di list B  
Baris keempat: `m` bilangan bulat — elemen list B

### 📤 Output:

Cetak list hasil gabungan `C`, dalam satu baris, elemen dipisahkan spasi.  
Jika kosong, cetak `EMPTY`.
### ⚙️ Batasan:

- `0 <= n, m <= 10^4`
    
- Nilai bilangan: `-10^6 ≤ x ≤ 10^6`
    
- List A dan B **sudah terurut menaik**

### 💡 Contoh Input:

```
3
1 3 5
4
2 4 6 8
```

### 💬 Contoh Output:

```
1 2 3 4 5 6 8
```


### 💡 Petunjuk:

Kamu bisa gunakan fungsi STL `list::merge()` karena:

- Hanya bekerja jika **kedua list sudah urut**
    
- Akan otomatis menghasilkan list hasil gabungan yang juga urut
    

> Catatan: `merge()` akan **mengosongkan list kedua**, memindahkan datanya ke list pertama

# Jawabanku
Berikut adalah jawabanku untuk menjawab tantangan ini, yang perlu sedikit perbaikan, tepanya tidak perlunya menggunakan fungsi `sort()` setelah menggunakan fungsi `merge()`:

```cpp
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, x;
    list<int> A, B;

    cin >> n;
    while(n--){
        cin >> x;
        A.push_back(x);
    }

    cin >> m; 
    while(m--){
        cin >> x;
        B.push_back(x);
    }

    A.merge(B);
    A.sort();
    for(const auto&x: A) cout << x << " ";
    return 0;
}
```

# Editorial
🔥 Bagus banget! Kamu sudah menyelesaikan soal ini dengan benar, tapi ada sedikit kelebihan yang sebenarnya bisa dioptimalkan, terutama soal pemakaian `sort()` setelah `merge()`.

---

## ✅ Review Kode Per Bagian

### 🔹 Input dan Pengisian List

```cpp
cin >> n;
while(n--) {
    cin >> x;
    A.push_back(x);
}
```

✔️ Kamu membaca `n` angka untuk list `A`  
✔️ Begitu juga dengan `B` — sudah benar

---

### 🔹 Penggabungan List

```cpp
A.merge(B);
A.sort();
```

📌 **Ini akan bekerja, tapi tidak optimal**. Kenapa?

### ⚠️ Penjelasan:

`list::merge()` **hanya akan bekerja dengan benar dan efisien jika**:

- Kedua list **sudah terurut**
    
- Maka hasilnya akan **langsung urut juga**
    
- Jadi, **tidak perlu dipanggil `sort()` lagi**
    

📌 Tapi jika kamu panggil `A.sort()` setelah `merge()`, maka:

- Kamu **melakukan sorting ulang seluruh data**
    
- Ini **menghapus keuntungan dari `merge()`** yang sudah melakukan merge sort-style


### 🔧 Solusi Lebih Efisien

```cpp
A.merge(B); // Tidak perlu sort karena input A & B sudah urut
```

Simpan waktu dan performa!

### 🔹 Output

```cpp
for(const auto&x: A) cout << x << " ";
```

✅ Sudah bagus. Namun, jika `A` kosong (misalnya saat `n=0` dan `m=0`), output akan kosong.

📌 Soal minta: cetak `"EMPTY"` jika hasil gabungan kosong.

---

## 🧪 Tambahkan Pemeriksaan Kosong

```cpp
if(A.empty()) {
    cout << "EMPTY\n";
} else {
    for(const auto&x: A) cout << x << " ";
    cout << "\n";
}
```

---

## ✅ Versi Final yang Direkomendasikan

```cpp
#include<iostream>
#include<list>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, x;
    list<int> A, B;

    cin >> n;
    while(n--) {
        cin >> x;
        A.push_back(x);
    }

    cin >> m;
    while(m--) {
        cin >> x;
        B.push_back(x);
    }

    A.merge(B); // Sudah otomatis urut karena inputnya urut

    if(A.empty()) cout << "EMPTY\n";
    else {
        for(const auto& x : A) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
```

---

## 🏁 Rangkuman

|Aspek|Status|Catatan|
|---|---|---|
|Input list A & B|✅|Benar dan efisien|
|Gunakan `.merge()`|✅|Sudah tepat, tapi jangan `sort()` ulang|
|Cek list kosong|🔧|Tambahkan `if(A.empty())`|
|Output|✅|Rapi dan sesuai format|
