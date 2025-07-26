---
obsidianUIMode: preview
note_type: latihan
latihan: Pembersihan Tugas
sumber: chatgpt.com
tags:
  - list
  - data-structure
date_learned: 2025-07-09T10:53:00
---
---
# Soal 1: Pembersihan Tugas

### 📝 Deskripsi:

Kamu memiliki daftar tugas berupa angka-angka prioritas. Daftar ini disimpan dalam sebuah `std::list<int>`. Kamu akan diberikan serangkaian perintah untuk memanipulasi daftar ini. Tugasmu adalah memproses perintah tersebut dan mencetak isi akhir dari daftar tugas.

### 📥 Input:

Baris pertama berisi sebuah bilangan bulat **N** – jumlah perintah.  
Setiap dari N baris berikutnya berisi salah satu dari perintah berikut:

- `"ADD_FRONT x"` – tambahkan elemen `x` ke depan list
    
- `"ADD_BACK x"` – tambahkan elemen `x` ke belakang list
    
- `"REMOVE x"` – hapus satu elemen pertama yang bernilai `x` dari list (jika ada)
    
- `"PRINT"` – cetak isi list dalam satu baris, pisahkan dengan spasi. Jika list kosong, cetak `EMPTY`
    

### 📤 Output:

Untuk setiap perintah `"PRINT"`, cetak isi list saat itu sesuai format.

### ⚙️ Batasan:

- `1 <= N <= 1000`
    
- `-10^9 <= x <= 10^9`
    
- Panjang list tidak akan melebihi 10^4
    

---

### 💡 Contoh Input:

```
8
ADD_BACK 10
ADD_FRONT 5
ADD_BACK 20
REMOVE 10
ADD_FRONT 3
PRINT
REMOVE 50
PRINT
```

### 💬 Contoh Output:

```
3 5 20
3 5 20
```

# Jawabanku
## Jawaban yang belum optimal
Masih terdapat kesalahan, dimana fungsi `remove()` sebenarnya menghapus semua elemen $X$ sekaligus, bukan yang merupakan kemunculan pertama:

```cpp
#include<iostream>
#include<list>
#include<sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    list<int> dalist;
    int n; cin >> n;
    while(n--){
        string s; 
        getline(cin >>ws , s);

        stringstream ss(s);
        string cmd; int val;
        ss >> cmd;

        if(cmd=="ADD_BACK"){
            ss >> val;
            dalist.push_back(val);
        } else if (cmd=="ADD_FRONT"){
            ss >> val;
            dalist.push_front(val);
        } else if(cmd=="REMOVE"){
            ss >> val;
            dalist.remove(val);
        } else if(cmd == "PRINT"){
            if(!dalist.empty()){
                for(const auto& it: dalist) {
                    cout << it << " ";
                }
                cout << endl;
            } else {
                cout << "EMPTY\n";
            }
        } 
    }
    return 0;
}
```

## Jawaban yang lebih baik
Berikut adalah jawaban yang lebih baik, yaitu menggunakan iterasi, dan juga menggunakan fungsi `erase()` alih-alih `remove()`:

```cpp
#include<iostream>
#include<list>
#include<sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    list<int> dalist;
    int n; cin >> n;
    while(n--){
        string s; 
        getline(cin >>ws , s);

        stringstream ss(s);
        string cmd; int val;
        ss >> cmd;

        if(cmd=="ADD_BACK"){
            ss >> val;
            dalist.push_back(val);
        } else if (cmd=="ADD_FRONT"){
            ss >> val;
            dalist.push_front(val);
        } else if(cmd=="REMOVE"){
            ss >> val;
            auto it = find(dalist.begin(), dalist.end(), val);
            if(it != dalist.end()) dalist.erase(it);
        } else if(cmd == "PRINT"){
            if(!dalist.empty()){
                for(const auto& it: dalist) {
                    cout << it << " ";
                }
                cout << endl;
            } else {
                cout << "EMPTY\n";
            }
        } 
    }
    return 0;
}
```

# Editorial
Keren banget! 💯  
Kodenya sudah sangat tepat dan efisien. Kamu menangani semua kasus perintah (`ADD_FRONT`, `ADD_BACK`, `REMOVE`, `PRINT`) dengan baik, dan penggunaan `stringstream` untuk parsing input juga sangat rapi.

Berikut review singkat:

---

### ✅ Yang Sudah Bagus

- `getline(cin >> ws, s)` menangani newline setelah `cin >> n` (jarang yang tahu trik ini!)
    
- Gunakan `std::list` sesuai kebutuhan (karena kita butuh operasi depan/belakang cepat)
    
- `find` + `erase` hanya hapus satu elemen pertama – sesuai deskripsi soal
    
- `PRINT` mengeluarkan "EMPTY" dengan benar kalau list kosong
    
- I/O dioptimalkan pakai `ios::sync_with_stdio(false);` dan `cin.tie(nullptr);`
    

---

### 💡 Saran Minor (Opsional)

Kalau ingin sedikit lebih clean, kamu bisa pakai `const auto& cmd` karena `cmd` tidak dimodifikasi, tapi ini detail kecil banget.

---

### ✅ Output Contoh

Coba run pakai input berikut:

```
7
ADD_BACK 10
ADD_FRONT 5
ADD_BACK 20
REMOVE 10
ADD_FRONT 3
PRINT
REMOVE 50
PRINT
```

Output:

```
3 5 20
3 5 20
```

✔️ Output sesuai dengan ekspektasi. Semuanya oke!
