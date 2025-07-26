---
obsidianUIMode: preview
note_type: latihan
latihan: Snake Game Simulation
sumber: chatgpt.com
tags:
  - list
  - data-structure
date_learned: 2025-07-09T19:01:00
---
---
# 📘 Soal 11: Simulasi Game Ular (Snake)

### 🧠 Deskripsi:

Kamu akan mensimulasikan pergerakan ular dalam grid 2D berukuran `n × m`. Ular mulai dengan panjang 1 dan bergerak mengikuti instruksi. Tiap kali ular memakan makanan, tubuhnya bertambah.

Kamu perlu mencetak **panjang ular** setelah setiap langkah.
### ⚙️ Aturan:

- Kepala ular bergerak sesuai arah: `U`, `D`, `L`, `R`.
    
- Jika tidak makan, ekor ular akan bergerak maju (seperti ular biasa).
    
- Jika posisi kepala menabrak tubuhnya sendiri → game over.
    
- Jika menabrak dinding grid → game over.

### 📥 Input:

```
n m        // ukuran grid
x y        // posisi awal ular (baris, kolom)
k          // jumlah perintah
k baris: satu perintah per baris (arah + is_makan), contoh: R 1
```

`is_makan = 1` artinya ular makan dan tubuh bertambah  
`is_makan = 0` artinya ular tidak makan, ekor mundur
### 📤 Output:

Cetak panjang ular setelah tiap langkah.  
Jika game over, cetak `Game Over` dan hentikan.
### 🧪 Contoh Input:

```
5 5
2 2
4
R 1
D 0
L 1
U 0
```

### 💬 Output:

```
2
2
3
Game Over
```

### 💡 Hint:

Gunakan `list<pair<int, int>>` untuk menyimpan tubuh ular (dari kepala → ekor), karena:

- Menambahkan kepala: `push_front`
    
- Menghapus ekor: `pop_back`
    
- Cek tabrakan mudah pakai iterasi `find`
    

Kalau kamu suka soal ini, kamu bisa langsung coba implementasi sendiri. Atau kalau mau, aku bisa kasih **template awal** atau **solusi penuh** — tinggal pilih.

# Jawabanku
## 1 | Jawaban pertama
Ini adalah jawaban pertamaku, yang kukira sudah benar, tetapi dikatakan masih ada kesalahan logika kecil:

```cpp
#include<iostream>
#include<list>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

#define vvi vector<vector<int>>
#define ls list<pair<int, int>>

void snakeEat(vvi& arena, ls&snake, int b){
    if(b==0){
        auto[zline, zcol] = snake.back();
        snake.pop_back();
        arena[zline][zcol] = 0;
    }
}

bool isValid (vvi& arena, ls& snake, char  a, int b, int n, int m){
    if(a=='U'){
        auto [line, col] = snake.front();
        snakeEat(arena, snake, b);

        if(line==0 || arena[line-1][col]==1) return false;
        else {
            line--;
            snake.push_front({line, col});
            arena[line][col] = 1;
        }
    } else if (a=='R'){
        auto [line, col] = snake.front();
        snakeEat(arena, snake, b);

        if(col== m-1 || arena[line][col+1]==1) return false;
        else {
            col++;
            snake.push_front({line, col});
            arena[line][col] = 1;
        }
    } else if (a=='D'){
        auto [line, col] = snake.front();
        snakeEat(arena, snake, b);

        if(line== n-1 || arena[line+1][col]==1) return false;
        else {
            line++;
            snake.push_front({line, col});
            arena[line][col] = 1;
        }
    } else if (a=='L'){
        auto [line, col] = snake.front();
        snakeEat(arena, snake, b);
        
        if(col == 0 || arena[line][col-1]==1) return false;
        else {
            col--;
            snake.push_front({line, col});
            arena[line][col] = 1;
        }
    }
    return true;
}

void print(vector<vector<int>>& arena) {
    for(const auto& out: arena){
        for(const auto& x: out) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, x, y, k;
    cin >> n >> m;
    cin >> x >> y;
    cin >> k;

    vector<vector<int>> arena (n, vector<int>(m, 0));
    list<pair<int, int>> snake;
    x--; y--;
    snake.push_front({x,y});
    arena[x][y] = 1;
    print(arena);

    bool alive = true;
    while(k--){
        char a; int b;
        cin >> a >> b;
        alive = isValid(arena, snake, a, b, n ,m);
        if(alive){
            cout << snake.size() << endl;
            print(arena);
            cout << endl;
        } else {
            cout << "Game Over\n";
            break;
        }
    }
    return 0;
}
```

## 2 | Jawaban yang sudah benar
Berikut adalah jawabanku yang sudah benar. Aku menemukan cara yang lebih ringkas, lebih efisien, dan benar secara logika. Cara ini lebih baik, dan merupakan contoh penggunaan data structure list yang sesuai:

```cpp
#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;

#define vvi vector<vector<int>>
#define ls list<pair<int,int>>

void print(const vvi& arena, const ls& snake){
    cout << "Snake length: " << snake.size() << endl;
    for(const auto& out: arena){
        for(const auto&x: out){
            cout << x << " ";
        }
        cout << endl;
    }
}

bool isValid(vvi&arena, ls&snake, int n, int m, char c, int eat){
    auto [rowcurr, colcurr] = snake.front();
    auto [zrow, zcol] = snake.back();

    if(c=='U') rowcurr--;
    else if(c=='D') rowcurr++;
    else if(c=='R') colcurr++;
    else if(c=='L') colcurr--;

    if((rowcurr < 0 || rowcurr >= n) || (colcurr < 0 || colcurr >= m)) {
        return false;
    } else if(arena[rowcurr][colcurr] == 1){
        if(!((rowcurr == zrow && colcurr == zcol) && (eat == 0))){
            return false;
        }
    }

    if(eat==0){
        snake.pop_back();
        arena[zrow][zcol] = 0;
    }

    snake.push_front({rowcurr, colcurr});
    arena[rowcurr][colcurr] = 1;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, x, y, k;
    cin >> n >> m;
    cin >> x >> y;
    cin >> k;

    vector<vector<int>> arena (n, vector<int>(m,0));
    list<pair<int,int>> snake;
    x--; y--;
    arena[x][y] = 1;
    snake.push_front({x,y});

    print(arena, snake);

    bool alive = true;
    while(k--){
        char c; int eat;
        cin >> c >> eat;
        alive = isValid(arena, snake, n, m, c, eat);
        if(alive){
            cout << endl;
            print(arena, snake);
        } else {
            cout << "\nGame Over!\n";
            break;
        }
    }
    return 0;
}
```

## 3 | Jawaban terbaiku
Ini adalah versi snake game terbaiku, dimana ular yang disimulasikan disini sudah memiliki kepala, sehingga membuat user tahu dimana kepala ular berada, jauh lebih menarik dari sebelumnya:

```cpp
#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;

#define vvi vector<vector<int>>
#define ls list<pair<int,int>>

void print(const vvi& arena, const ls& snake){
    cout << "Snake length: " << snake.size() << endl;
    for(const auto& out: arena){
        for(const auto&x: out){
            cout << x << " ";
        }
        cout << endl;
    }
}

bool isValid(vvi&arena, ls&snake, int n, int m, char c, int eat){
    auto [rowcurr, colcurr] = snake.front();
    auto [zrow, zcol] = snake.back();

    if(c=='U') rowcurr--;
    else if(c=='D') rowcurr++;
    else if(c=='R') colcurr++;
    else if(c=='L') colcurr--;

    if((rowcurr < 0 || rowcurr >= n) || (colcurr < 0 || colcurr >= m)) {
        return false;
    } else if(arena[rowcurr][colcurr] == 1){
        if(!((rowcurr == zrow && colcurr == zcol) && (eat == 0))){
            return false;
        }
    }

    if(eat==0){
        snake.pop_back();
        arena[zrow][zcol] = 0;
    }

    auto [oldrow, oldcol] = snake.front();
    arena[oldrow][oldcol] = 1;
    
    snake.push_front({rowcurr, colcurr});
    arena[rowcurr][colcurr] = 7;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, x, y, k;
    cin >> n >> m;
    cin >> x >> y;
    cin >> k;

    vector<vector<int>> arena (n, vector<int>(m,0));
    list<pair<int,int>> snake;
    x--; y--;
    arena[x][y] = 7;
    snake.push_front({x,y});

    print(arena, snake);

    bool alive = true;
    while(k--){
        char c; int eat;
        cin >> c >> eat;
        alive = isValid(arena, snake, n, m, c, eat);
        if(alive){
            cout << endl;
            print(arena, snake);
        } else {
            cout << "\nGame Over!\n";
            break;
        }
    }
    return 0;
}
```

## 4 | Peningkatan Tampilan Arena dan perbaikan Minor bug
Terdapat bug ketika ular belum makan sama sekali, dan digerakan oleh user. Versi ini memberbaiki masalah tersebut, dan juga meningkatkan tampilan simulasi arena dan ular:

```cpp
#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;

#define vvi vector<vector<int>>
#define ls list<pair<int,int>>

void print(const vvi& arena, const ls& snake){
    cout << "Snake length: " << snake.size() << endl;
    for(const auto& out: arena){
        for(const auto&x: out){
            if(x==0) cout << ". ";
            else if(x==7) cout << "H ";
            else if(x==1) cout << "o ";
        }
        cout << endl;
    }
}

bool isValid(vvi&arena, ls&snake, int n, int m, char c, int eat){
    auto [rowcurr, colcurr] = snake.front();
    auto [zrow, zcol] = snake.back();

    if(c=='U') rowcurr--;
    else if(c=='D') rowcurr++;
    else if(c=='R') colcurr++;
    else if(c=='L') colcurr--;

    if((rowcurr < 0 || rowcurr >= n) || (colcurr < 0 || colcurr >= m)) {
        return false;
    } else if(arena[rowcurr][colcurr] == 1){
        if(!((rowcurr == zrow && colcurr == zcol) && (eat == 0))){
            return false;
        }
    }

    auto [oldrow, oldcol] = snake.front();
    arena[oldrow][oldcol] = 1;
    
    snake.push_front({rowcurr, colcurr});
    arena[rowcurr][colcurr] = 7;

    if(eat==0){
        snake.pop_back();
        arena[zrow][zcol] = 0;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, x, y, k;
    cin >> n >> m;
    cin >> x >> y;
    cin >> k;

    vector<vector<int>> arena (n, vector<int>(m,0));
    list<pair<int,int>> snake;
    x--; y--;
    arena[x][y] = 7;
    snake.push_front({x,y});

    print(arena, snake);

    bool alive = true;
    while(k--){
        char c; int eat;
        cin >> c >> eat;
        alive = isValid(arena, snake, n, m, c, eat);
        if(alive){
            cout << endl;
            print(arena, snake);
        } else {
            cout << "\nGame Over!\n";
            break;
        }
    }
    return 0;
}
```

## 5 | Versi perbaikan Terus Menerus
Aku menemukan bug dimana ketika ketika ular melakukan gerakan melingkar, dimana kepala tepat  berada dibelakangnya, maka kepala tidak akan tampak, karena nilai di arena diset ke kosong lagi. Mengatasi itu, dilakukan perbaikan kembali, yang mana cukup banyak, karena belajar memang seharusnya terus menerus:

```cpp
#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;

#define vvi vector<vector<int>>
#define ls list<pair<int,int>>

void print(const vvi& arena, const ls& snake){
    cout << "Snake length: " << snake.size() << endl;
    for(const auto& out: arena){
        for(const auto&x: out){
            if(x==0) cout << ". ";
            else if(x==7) cout << "H ";
            else if(x==1) cout << "o ";
        }
        cout << endl;
    }
}

bool isValid(vvi&arena, ls&snake, int n, int m, char c, int eat){
    auto [headRow, headCol] = snake.front();
    auto [zrow, zcol] = snake.back();
    int nHeadRow = headRow;
    int nHeadCol = headCol;

    if(c=='U') nHeadRow--;
    else if(c=='D') nHeadRow++;
    else if(c=='R') nHeadCol++;
    else if(c=='L') nHeadCol--;

    bool toTail = ((nHeadRow == zrow && nHeadCol == zcol) && (eat == 0));

    if((nHeadRow < 0 || nHeadRow >= n) || (nHeadCol < 0 || nHeadCol >= m)) {
        return false;
    } else if(arena[nHeadRow][nHeadCol] == 1){
        if(!toTail){
            return false;
        }
    }

    arena[headRow][headCol] = 1;
    snake.push_front({nHeadRow, nHeadCol});
    arena[nHeadRow][nHeadCol] = 7;

    if(eat==0){
        snake.pop_back();
        if(!toTail) arena[zrow][zcol] = 0;
        else arena[zrow][zcol] = 7;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, x, y, k;
    cin >> n >> m;
    cin >> x >> y;
    cin >> k;

    vector<vector<int>> arena (n, vector<int>(m,0));
    list<pair<int,int>> snake;
    x--; y--;
    arena[x][y] = 7;
    snake.push_front({x,y});

    print(arena, snake);

    bool alive = true;
    while(k--){
        char c; int eat;
        cin >> c >> eat;
        if((c!='U' && c!='D' && c!='R' && c!='L') || (eat!=1 && eat!=0)) continue;
        alive = isValid(arena, snake, n, m, c, eat);
        if(alive){
            cout << endl;
            print(arena, snake);
        } else {
            cout << "\nGame Over!\n";
            break;
        }
    }
    return 0;
}
```

---
<br/><br/><br/>
# Editorial | Jawaban Pertama
Siap! Kita breakdown satu kesalahan logika utama dari kode kamu secara terperinci dulu. Ini akan jadi jawaban pertama, dan setelah itu kamu bisa lanjut menambahkan perbaikan atau versi selanjutnya.

---

## 💥 Kesalahan Logika di Kode Kamu:

### 📌 Kode Terkait:

Contoh dari satu blok arah (misalnya `'R'`):

```cpp
auto [line, col] = snake.front();
snakeEat(arena, snake, b);

if (col == m - 1 || arena[line][col + 1] == 1) return false;

col++;
snake.push_front({line, col});
arena[line][col] = 1;
```

---

## ❌ Kesalahan: Validasi Dilakukan Sebelum Hitung Posisi Target

### 🎯 Penjelasan:

- Kamu langsung melakukan validasi:
    
    ```cpp
    if (arena[line][col + 1] == 1)
    ```
    
    …padahal belum memastikan bahwa `col + 1` adalah posisi target yang akan ditempati, dan **belum mengkaitkannya dengan posisi ekor lama**.

<br/>

- Kamu juga **tidak simpan target posisi secara eksplisit** (`nline`, `ncol`) sehingga tidak bisa melakukan validasi yang lebih kompleks (misalnya: "apakah ini ekor lama?").
<br/>

- **`snakeEat()` dipanggil sebelum tahu posisi target.**  
    Artinya kamu sudah ubah `arena[...]` tanpa tahu apakah itu akan mempengaruhi validasi yang harusnya akurat.
    

---

## 🧪 Contoh Bug:

Ular:

```
[2,2] ← kepala
[2,3] ← ekor
```

Arah: `'R'`, `b = 0` (tidak makan)

- Kamu panggil `snakeEat()` ⇒ `arena[2][3] = 0`
    
- Lalu kamu cek:
    
    ```cpp
    if (arena[2][3] == 1) return false;  // ini selalu false karena barusan kamu ubah
    ```
    

Jadi… kamu **menghindari deteksi tabrakan hanya karena urutan eksekusimu salah**.

---

## 🚨 Intinya:

> Kamu melakukan pengecekan kondisi sebelum mengetahui dengan pasti posisi target, dan setelah memodifikasi arena dengan `snakeEat`.

---

## 💡 Seharusnya:

1. Hitung `nline`, `ncol` terlebih dahulu
    
2. Validasi posisi `(nline, ncol)` terhadap:
    
    - Batas arena
        
    - arena[nline][ncol] == 1 (tabrakan)
        
    - Kecuali: jika tidak makan dan itu adalah posisi ekor
        
3. Baru lakukan `snakeEat()` (karena kamu sudah tahu apakah aman)
    
4. Baru gerakkan kepala
    

---

## 🟢 Rangkuman Jawaban Pertama:

> Kesalahan logika utama di kode kamu adalah **melakukan validasi arena sebelum menghitung dan menyimpan posisi target kepala**, serta **melakukan modifikasi (memotong ekor) sebelum pengecekan**. Ini menyebabkan validasi bisa salah deteksi, terutama ketika kepala berpindah ke posisi ekor lama.

<br/><br/><br/>
# Editorial | Jawaban Kedua
Yes! 🎉 **Versi ini sudah benar secara logika dan urutan** — dan bisa dibilang ini implementasi snake paling solid kalau kamu ingin fokus pada `list` sebagai struktur tubuh ular.

---

## 🔍 Apa yang Sudah Kamu Lakukan dengan Benar:

|Bagian|Status|Penjelasan|
|---|---|---|
|✅ Validasi keluar arena|✔️|Diperiksa sebelum ubah apapun|
|✅ Validasi tabrakan tubuh|✔️|Diperiksa secara eksplisit, **boleh ke ekor jika `eat == 0`**|
|✅ Pemotongan ekor|✔️|Dilakukan setelah validasi|
|✅ Penambahan kepala|✔️|Dilakukan setelah semua aman|
|✅ Update arena|✔️|Konsisten dengan perubahan `snake`|

---

## 💡 Sedikit Saran Peningkatan (Opsional, bukan keharusan):

### 1. Tambahkan return tipe eksplisit:

Kamu bisa tambahkan komentar dokumentasi pada fungsi agar lebih jelas:

```cpp
// Fungsi untuk memvalidasi dan menggerakkan ular
// Return true jika langkah valid dan berhasil dijalankan
bool isValid(...);
```

---

### 2. Tambahkan langkah cetak panjang ular:

Misalnya:

```cpp
cout << "Panjang: " << snake.size() << "\n";
```

---

### 3. Tambahkan tampilan koordinat kepala (debug atau fitur):

```cpp
auto [headRow, headCol] = snake.front();
cout << "Kepala di: (" << headRow+1 << "," << headCol+1 << ")\n";
```

---

## 🧠 Kesimpulan Akhir:

- 💯 **Kode kamu sekarang sudah benar secara logika dan aman untuk edge case**
    
- ✅ Tidak akan salah deteksi tabrakan ke ekor
    
- ✅ Struktur `list` digunakan secara maksimal (front = kepala, back = ekor)
    
- ✅ Tidak ada operasi berbahaya seperti validasi setelah modifikasi
    
- 🧼 Kode sudah bersih dan mudah dibaca
    

<br/><br/><br/>
# Editorial | Pembahasan Jawaban Kedua

### 🔹 1. Header & Namespace

```cpp
#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;
```

📌 **Penjelasan**:

- `iostream`: untuk input/output
    
- `list`: untuk menyimpan tubuh ular (`std::list` cocok karena efisien untuk `push_front` dan `pop_back`)
    
- `vector`: digunakan sebagai arena (grid permainan)
    
- `algorithm`: disertakan tapi tidak digunakan, bisa dihapus
    

---

### 🔹 2. Alias Tipe

```cpp
#define vvi vector<vector<int>>
#define ls list<pair<int,int>>
```

📌 **Penjelasan**:

- `vvi`: alias untuk matriks arena (`vector of vector of int`)
    
- `ls`: alias untuk `list<pair<int, int>>` agar penulisan snake lebih ringkas
    

---

### 🔹 3. Fungsi Cetak Arena

```cpp
void print(const vvi& arena){
    for(const auto& out: arena){
        for(const auto& x: out){
            cout << x << " ";
        }
        cout << endl;
    }
}
```

📌 **Penjelasan**:

- Menampilkan isi `arena` baris per baris
    
- Cocok untuk debugging atau visualisasi status permainan setelah setiap langkah
    

---

### 🔹 4. Fungsi `isValid` — Inti Logika Game

```cpp
bool isValid(vvi& arena, ls& snake, int n, int m, char c, int eat){
```

📌 **Parameter**:

- `arena`: peta permainan
    
- `snake`: tubuh ular
    
- `n`, `m`: ukuran arena
    
- `c`: arah gerak ('U', 'D', 'L', 'R')
    
- `eat`: apakah ular makan (1) atau tidak (0)
    

---

#### 💠 a. Ambil Posisi Kepala & Ekor

```cpp
    auto [rowcurr, colcurr] = snake.front();
    auto [zrow, zcol] = snake.back();
```

📌 **Penjelasan**:

- `snake.front()` = posisi kepala
    
- `snake.back()` = posisi ekor  
    → penting untuk validasi tabrakan ke ekor sendiri saat tidak makan
    

---

#### 💠 b. Hitung Posisi Target Kepala

```cpp
    if(c=='U') rowcurr--;
    else if(c=='D') rowcurr++;
    else if(c=='R') colcurr++;
    else if(c=='L') colcurr--;
```

📌 **Penjelasan**:

- Menentukan posisi baru kepala berdasarkan arah input
    

---

#### 💠 c. Validasi: Apakah Keluar Arena?

```cpp
    if((rowcurr < 0 || rowcurr >= n) || (colcurr < 0 || colcurr >= m)) {
        return false;
    }
```

📌 **Penjelasan**:

- Jika posisi target di luar batas arena, game over
    

---

#### 💠 d. Validasi: Apakah Tabrak Tubuh Sendiri (Kecuali Ekor)?

```cpp
    else if(arena[rowcurr][colcurr] == 1){
        if(!((rowcurr == zrow && colcurr == zcol) && (eat == 0))){
            return false;
        }
    }
```

📌 **Penjelasan**:

- Jika posisi target adalah tubuh ular:
    
    - Tapi **bukan ekor yang akan hilang**
        
    - Dan **kondisinya makan**
        
- Maka itu tabrakan dan `return false`
    

✅ **Inilah bagian penting yang membuat validasi tubuh menjadi benar**

---

#### 💠 e. Jika Tidak Makan, Potong Ekor

```cpp
    if(eat==0){
        snake.pop_back();
        arena[zrow][zcol] = 0;
    }
```

📌 **Penjelasan**:

- Jika tidak makan, maka ekor dihapus agar panjang tetap
    
- Arena di posisi ekor juga dikosongkan (`0`)
    

---

#### 💠 f. Tambahkan Kepala ke Depan

```cpp
    snake.push_front({rowcurr, colcurr});
    arena[rowcurr][colcurr] = 1;
    return true;
```

📌 **Penjelasan**:

- Tambah kepala baru ke list ular
    
- Tandai posisi baru di arena sebagai bagian dari tubuh (`1`)
    
- Kembalikan `true` karena langkah valid
    

---

### 🔹 5. Fungsi `main` — Mengatur Alur Permainan

```cpp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
```

📌 Optimisasi I/O

---

#### 💠 a. Input Ukuran Arena, Posisi Awal, Jumlah Perintah

```cpp
    int n, m, x, y, k;
    cin >> n >> m;
    cin >> x >> y;
    cin >> k;
```

📌 **Penjelasan**:

- `n × m`: ukuran arena
    
- `x, y`: posisi awal (1-based, akan dikonversi ke 0-based)
    
- `k`: jumlah langkah/perintah
    

---

#### 💠 b. Inisialisasi Arena dan Ular

```cpp
    vector<vector<int>> arena (n, vector<int>(m,0));
    list<pair<int,int>> snake;
    x--; y--; // ubah ke 0-based
    arena[x][y] = 1;
    snake.push_front({x,y});
```

📌 **Penjelasan**:

- Buat arena kosong (`0`)
    
- Tandai posisi awal ular (`1`)
    
- Masukkan ke dalam list `snake` sebagai kepala
    

---

#### 💠 c. Cetak Arena Awal

```cpp
    print(arena);
```

---

#### 💠 d. Proses Setiap Perintah

```cpp
    bool alive = true;
    while(k--){
        char c; int eat;
        cin >> c >> eat;
        alive = isValid(arena, snake, n, m, c, eat);
```

📌 **Penjelasan**:

- Baca arah dan status makan
    
- Jalankan `isValid` untuk memproses gerakan
    
- `alive` akan `false` jika ular mati karena tabrakan atau keluar
    

---

#### 💠 e. Tampilkan Arena atau Game Over

```cpp
        if(alive){
            cout << endl;
            print(arena);
        } else {
            cout << "\nGame Over!\n";
            break;
        }
```

📌 **Penjelasan**:

- Jika masih hidup, tampilkan arena terkini
    
- Jika mati, keluarkan pesan akhir
    

---

## ✅ Kesimpulan Editorial

|Komponen|Status|Catatan|
|---|---|---|
|Validasi arena|✅|Tertib dan aman|
|Validasi tubuh|✅|Sudah mempertimbangkan kasus ekor|
|Struktur data|✅|`list` digunakan tepat untuk simulasi tubuh ular|
|Alur kontrol|✅|Bersih dan mudah ditelusuri|
|Debug/visualisasi|✅|Ada fungsi `print` untuk bantu cek arena|

<br/><br/><br/>

# Editorial | Jawaban terbaiku
🔥 **SEMPURNA!** Versi yang ini sudah **clean, logis, dan visualnya mantap**. Kamu telah:

- ✅ Membedakan **kepala (`7`)** dan **tubuh (`1`)**
    
- ✅ Menjaga **arena tetap konsisten**
    
- ✅ Memperbaiki logika pergerakan dan ekor
    
- ✅ Menulis kode yang mudah dibaca dan maintainable
    

---

## ✅ Editorial per Blok (Final Version)


### 🔷 1. Header & Namespace

```cpp
#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;
```

- Standar header yang dibutuhkan untuk `I/O`, `list`, `vector`, dan `algoritma`
    

---

### 🔷 2. Alias Tipe

```cpp
#define vvi vector<vector<int>>
#define ls list<pair<int,int>>
```

- `vvi`: mempermudah penulisan arena (2D grid)
    
- `ls`: untuk menyimpan tubuh ular sebagai list posisi `(row, col)`
    

---

### 🔷 3. Fungsi `print**`**

```cpp
void print(const vvi& arena, const ls& snake){
    cout << "Snake length: " << snake.size() << endl;
    for(const auto& out: arena){
        for(const auto&x: out){
            cout << x << " ";
        }
        cout << endl;
    }
}
```

- Menampilkan panjang ular
    
- Menampilkan isi arena
    
- Kepentingan: Debugging dan visualisasi langkah demi langkah
    

---

### 🔷 4. Fungsi `isValid` — Inti Gerakan

```cpp
bool isValid(vvi&arena, ls&snake, int n, int m, char c, int eat){
```

- Memproses satu langkah gerakan
    
- Cek tabrakan, update tubuh dan arena
    

---

#### 💠 a. Tentukan target posisi kepala baru

```cpp
    auto [rowcurr, colcurr] = snake.front();
    auto [zrow, zcol] = snake.back();

    if(c=='U') rowcurr--;
    else if(c=='D') rowcurr++;
    else if(c=='R') colcurr++;
    else if(c=='L') colcurr--;
```

- Arahkan kepala sesuai perintah
    
- Simpan posisi ekor untuk validasi
    

---

#### 💠 b. Validasi tabrakan arena atau tubuh

```cpp
    if((rowcurr < 0 || rowcurr >= n) || (colcurr < 0 || colcurr >= m)) {
        return false;
    } else if(arena[rowcurr][colcurr] == 1){
        if(!((rowcurr == zrow && colcurr == zcol) && (eat == 0))){
            return false;
        }
    }
```

- Tabrakan ke dinding: langsung `return false`
    
- Tabrakan ke tubuh: **boleh ke ekor sendiri jika tidak makan**
    

---

#### 💠 c. Update tubuh dan arena

```cpp
    if(eat==0){
        snake.pop_back();
        arena[zrow][zcol] = 0;
    }

    auto [oldrow, oldcol] = snake.front();
    arena[oldrow][oldcol] = 1;

    snake.push_front({rowcurr, colcurr});
    arena[rowcurr][colcurr] = 7;
```

- Jika tidak makan, buang ekor
    
- Tandai kepala lama sebagai tubuh (`1`)
    
- Tambahkan kepala baru di posisi baru (`7`)
    

---

### 🔷 5. Fungsi `main` — Loop Game

```cpp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
```

- Optimalisasi input/output
    

---

#### 💠 a. Input dan inisialisasi

```cpp
    int n, m, x, y, k;
    cin >> n >> m;
    cin >> x >> y;
    cin >> k;

    vector<vector<int>> arena (n, vector<int>(m,0));
    list<pair<int,int>> snake;
    x--; y--;
    arena[x][y] = 7;
    snake.push_front({x,y});
```

- Inisialisasi arena dan ular
    
- Tandai posisi kepala pertama
    

---

#### 💠 b. Jalankan perintah

```cpp
    print(arena, snake);
    bool alive = true;
    while(k--){
        char c; int eat;
        cin >> c >> eat;
        alive = isValid(arena, snake, n, m, c, eat);
        if(alive){
            cout << endl;
            print(arena, snake);
        } else {
            cout << "\nGame Over!\n";
            break;
        }
    }
```

- Loop `k` langkah
    
- Setelah tiap langkah: tampilkan arena
    
- Jika `isValid` mengembalikan `false`, tampilkan "Game Over!"
    

---

## 🌟 Penutup

Versi ini sangat solid dan bisa jadi **basis game snake berbasis teks yang sangat bagus**. Sudah cocok untuk:

- Simulasi AI
    
- Penambahan buah otomatis
    
- Skoring & high score
    
- Debugging untuk pathfinding
    
- Atau hanya bersenang-senang 😄
    

---

Siap naik tingkat? Aku bisa bantu:

- 🔺 Menambahkan sistem buah acak
    
- 📈 Menampilkan skor
    
- 🧠 Mengembangkan AI untuk bermain otomatis
    
- 🎮 Menerjemahkan ini ke mode GUI dengan SDL atau SFML
    

