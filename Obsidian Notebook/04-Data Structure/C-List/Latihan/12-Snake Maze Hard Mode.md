---
obsidianUIMode: preview
note_type: latihan
latihan: Snake Maze Hard Mode
sumber: Google.com, AI
tags:
  - list
  - data-structure
date_learned: 2025-07-10T16:05:00
---
---
Wah mantap! 🔥  

Kalau kamu sudah sampai level **simulasi Snake Game**, berarti kamu udah paham banget cara kerja **list sebagai deque**, sliding window, bahkan simulasi posisi dinamis.

Berarti kamu butuh soal yang **menggabungkan list, algoritma, dan state simulation**.

---

# Soal Tantangan – Snake Maze Simulator (Hard Mode)

### 🧩 Deskripsi:

Kamu akan menyimulasikan pergerakan ular dalam sebuah **labirin** berukuran `N x M`. Ular bergerak setiap detik mengikuti perintah arah: `U`, `D`, `L`, `R`.

### 📜 Aturan:

- Ular diawali dengan panjang 1 dan posisi kepala di `(0, 0)`.
    
- Ada beberapa **buah (F)** yang akan muncul pada waktu tertentu di lokasi tertentu.
    
- Jika ular **makan buah**, panjangnya bertambah 1 (ekor tidak bergeser).
    
- Jika ular **tidak makan**, ekornya bergeser maju.
    
- Ular **mati** jika:
    
    - Menabrak dinding (keluar dari grid),
        
    - Menabrak tubuhnya sendiri.
        

### ⏱ Input:

1. Ukuran grid: `N` dan `M`
    
2. Daftar arah per detik: string seperti `"RRDLLUUD..."`
    
3. Daftar buah: list berisi tuple `(t, r, c)` yang berarti buah muncul di `(r, c)` pada waktu ke-`t`.


### 🧠 Output:

- Waktu saat ular mati, atau
    
- Posisi akhir kepala jika ular tidak mati.


### 🔧 Contoh Input:

```python
N = 5
M = 5
perintah = "RRDDLLUU"
buah = [
    (2, 0, 2),  # waktu 2, buah di (0,2)
    (4, 1, 2),  # waktu 4, buah di (1,2)
]
```

### 🧾 Output:

```
Ular mati pada waktu ke-7 karena menabrak dirinya sendiri.
```


### 💡 Hint Implementasi:

- Gunakan `list` sebagai representasi tubuh ular: `[(r1,c1), (r2,c2), ...]`
    
- Simpan buah aktif dalam set posisi
    
- Update tubuh setiap detik
    
- Cek apakah kepala menyentuh dinding atau tubuhnya sendiri

# Jawabanku
## 1 | Pertama dan optimal
Jawaban ini membutuhkan waktu hampir 5 jam untuk penyempurnaan dari bug dan kesalahan logika, ini benar-benar sangat sulit, dan menantang, karena baru pertama kali aku mencoba menyelesaikan tantangan *snake maze game*. Tapi, seiring waktu, mungkin akan ada versi terbaru dari jawaban, mengikuti perkembangan kemampuan belajarku:

```cpp
#include<iostream>
#include<vector>
#include<list>
#include<tuple>
using namespace std;

#define vvi vector<vector<int>>
#define ls list<pair<int, int>>
#define ltp list<tuple<int, int ,int>>

void print(vvi& arena, int f, int x, int y, int idx, ls& snake) {
    cout << "Snake length: " << snake.size() << "\n";

    for (int i = 0; i < arena.size(); i++) {
        for (int j = 0; j < arena[i].size(); j++) {

            // Cek apakah ini posisi kepala ular
            if (snake.front() == make_pair(i, j)) {
                cout << "H ";
            } else if ((i == x && j == y) && (f == idx)) {
                cout << "* ";
            } else if (arena[i][j] == 1) {
                cout << "o ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }

    cout << "Snake cells: ";
    for (auto [r, c] : snake) cout << "(" << r << "," << c << ") ";
    cout << "\n\n";
}


pair<bool, bool> isValid(vvi&arena, ls&snake, int f, int x, int y, int idx, char c, int n, int m){
    auto [headRow, headCol] = snake.front();
    auto [tailRow, tailCol] = snake.back(); 

    int nextHeadRow = headRow;
    int nextHeadCol = headCol;

    if(c=='U') nextHeadRow--;
    else if(c=='D') nextHeadRow++;
    else if(c=='R') nextHeadCol++;
    else if(c=='L') nextHeadCol--;

    if((nextHeadRow < 0 || nextHeadRow >= n) || (nextHeadCol < 0 || nextHeadCol >= m)){
        return {false, false};
    } 

    bool eat = ((nextHeadRow==x && nextHeadCol==y) && (f == idx));
    bool goingToTail = (nextHeadRow == tailRow && nextHeadCol == tailCol);

    // Jika kepala ke tubuh, dan (bukan ke ekor atau ke ekor tapi sedang makan)
    
    /*
    Jika kepala ular masuk ke koordinat ekor, dan dia tidak makan, 
    maka ekor ular tersebut akan sempat berpindah, sehingga memastikan
    ular tidak memakan ujung ekornya sendiri.
    */
    if (arena[nextHeadRow][nextHeadCol] == 1 && (!goingToTail || eat)) {
        return {false, false};
    }
    
    arena[headRow][headCol] = 1;
    snake.push_front({nextHeadRow, nextHeadCol});

    if(!eat){
        snake.pop_back();
        arena[tailRow][tailCol] = 0;
    }
    return {true, eat};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; string s;
    cin >> n >> m;
    cin >> s;

    vector<vector<int>> arena (n, vector<int>(m,0));
    list<pair<int,int>> snake;
    list<tuple<int, int, int>> fruits;

    arena[0][0] = 1;
    snake.push_front({0,0});

    int a, b, c;
    pair<bool, bool> alive;
    while(cin >> a >> b >> c){
        fruits.push_back({a,b,c});
    }

    for(int i=0; i<s.length(); i++){
        int f, x, y;
        if(!fruits.empty()){
            tie(f, x, y) = fruits.front();
            while(f<i && fruits.size()>1){
                fruits.pop_front();
                tie(f, x, y) = fruits.front();
            }
        } else {
            f = n+5;
            x=y=f;
        }

        alive = isValid(arena, snake, f, x, y, i, s[i], n, m);
        if(alive.first){
            print(arena, f, x, y, i, snake);
            if(alive.second){
                fruits.pop_front();
            }
        } else {
            cout << "\nGame Over!\n";
            break;
        }
    }
    return 0;
}
```

# Editorial | Jawaban Pertama
Bagus! Mari kita mulai membuat **editorial super lengkap** dari kode yang kamu kirimkan, dimulai **per fungsi** agar bisa fokus dan jelas. Kita mulai dari bagian pertama: `print`.

---
<br/><br/>
## 🧩 Fungsi `print`

```cpp
void print(vvi& arena, int f, int x, int y, int idx, ls& snake)
```

### 📌 Tujuan:

Fungsi ini bertugas untuk **menampilkan kondisi terkini dari arena permainan** dan posisi ular. Ini sangat penting untuk debugging maupun untuk pemahaman visual tentang posisi kepala, tubuh, dan buah.

### 🧱 Parameter:

|Parameter|Tipe|Keterangan|
|---|---|---|
|`arena`|`vector<vector<int>>`|Matriks permainan, menandai posisi tubuh ular.|
|`f`|`int`|Frame kemunculan buah yang sedang dicek.|
|`x, y`|`int`|Posisi buah yang akan muncul di frame `f`.|
|`idx`|`int`|Index pergerakan ular saat ini.|
|`snake`|`list<pair<int, int>>`|Daftar posisi tubuh ular (kepala di depan).|


### 🧠 Cara Kerja:

1. Menampilkan panjang ular (jumlah node pada `snake`).
    
2. Melakukan iterasi dua dimensi terhadap arena (`i` dan `j`):
    
    - Jika posisi `(i, j)` adalah kepala ular (sama dengan `snake.front()`): cetak `"H"`.
        
    - Jika `(i, j)` adalah lokasi buah dan waktunya sudah tepat (`f == idx`): cetak `"*"` (buah muncul).
        
    - Jika cell `arena[i][j] == 1`: berarti itu bagian tubuh ular → cetak `"o"`.
        
    - Jika tidak ada apa-apa: cetak `"."` (sel kosong).
        
3. Setelah arena dicetak, tampilkan seluruh sel ular satu per satu dari list `snake`.
    


### 🔍 Contoh Output:

Misalkan `snake = {(2,2), (2,1), (2,0)}` dan buah `(*,3,3)` muncul di frame `3`, dan sekarang index gerakan `i == 3`.

```
Snake length: 3
. . . . 
. . . . 
o o H * 
Snake cells: (2,2) (2,1) (2,0)
```


### ✅ Catatan Kelebihan:

- Sudah sangat jelas dan mudah dibaca.
    
- Memprioritaskan tampilan `"H"` untuk kepala dan `"*"` untuk buah, bahkan jika koordinatnya tumpang tindih.
    
- Berguna untuk debugging secara visual.
    

---
<br/><br/>
## 🧩 Fungsi `isValid`

```cpp
pair<bool, bool> isValid(vvi& arena, ls& snake, int f, int x, int y, int idx, char c, int n, int m)
```

### 📌 Tujuan:

Fungsi ini memvalidasi apakah **gerakan ular selanjutnya sah** (valid), dan juga menentukan apakah ular **makan buah atau tidak**. Ini adalah jantung dari aturan permainan.

### 🧱 Parameter:

|Parameter|Tipe|Keterangan|
|---|---|---|
|`arena`|`vector<vector<int>>`|Matriks penanda sel tubuh ular (`1` untuk tubuh).|
|`snake`|`list<pair<int, int>>`|List posisi sel tubuh ular.|
|`f, x, y`|`int`|Waktu dan posisi buah saat ini.|
|`idx`|`int`|Indeks pergerakan sekarang.|
|`c`|`char`|Arah gerakan: `'U'`, `'D'`, `'L'`, `'R'`.|
|`n, m`|`int`|Ukuran arena (baris dan kolom).|

### 🧠 Proses Kerja:

#### 1. Ambil posisi kepala dan ekor

```cpp
auto [headRow, headCol] = snake.front();
auto [tailRow, tailCol] = snake.back();
```

#### 2. Tentukan arah gerakan

```cpp
int nextHeadRow = headRow;
int nextHeadCol = headCol;
```

Lalu `nextHeadRow` atau `nextHeadCol` akan disesuaikan berdasarkan input `c`.

#### 3. Cek apakah gerakan keluar arena

```cpp
if((nextHeadRow < 0 || nextHeadRow >= n) || (nextHeadCol < 0 || nextHeadCol >= m))
```

Jika iya, maka game over (`return {false, false}`).

#### 4. Apakah ular makan buah?

```cpp
bool eat = ((nextHeadRow==x && nextHeadCol==y) && (f == idx));
```

#### 5. Apakah kepala akan ke ekor?

```cpp
bool goingToTail = (nextHeadRow == tailRow && nextHeadCol == tailCol);
```

Catatan: Jika **tidak makan**, maka **ekor akan berpindah**, jadi boleh saja kepala masuk ke sel ekor lama.

#### 6. Cek tabrakan dengan tubuh

```cpp
if (arena[nextHeadRow][nextHeadCol] == 1 && (!goingToTail || eat))
```

Artinya:

- Jika kepala masuk ke tubuh **dan**
    
    - bukan ke ekor, atau
        
    - ke ekor tetapi **sedang makan** (berarti ekor tidak pindah),  
        → maka **game over**.
        

#### 7. Update arena dan ular

```cpp
arena[headRow][headCol] = 1;
snake.push_front({nextHeadRow, nextHeadCol});
```

#### 8. Jika tidak makan, geser ekor

```cpp
if (!eat) {
    snake.pop_back();
    arena[tailRow][tailCol] = 0;
}
```

#### 9. Return hasil

```cpp
return {true, eat};
```

---

### 🧪 Contoh Kasus Penting:

|Kondisi|Hasil|
|---|---|
|Kepala ke luar arena|`false, false`|
|Kepala ke tubuh|`false, false`|
|Kepala ke ekor (tidak makan)|OK|
|Kepala ke ekor (sedang makan)|`false, false`|
|Kepala ke buah|`true, true`|
|Kepala ke kosong|`true, false`|


### ✅ Kelebihan & Ketepatan:

- **Akurat** menangani edge case seperti **kepala ke ekor**.
    
- Memisahkan logika makan/tidak makan.
    
- Mudah dibaca dan efisien.
    
- Logika `(!goingToTail || eat)` sangat penting agar tidak salah deteksi "makan diri sendiri".
    

---
<br/><br/>
## 🧩 Fungsi `main()`

```cpp
int main()
```

Fungsi `main()` ini menyatukan semua komponen:

- Membaca input,
    
- Menyusun arena & ular,
    
- Menyimpan buah,
    
- Memproses pergerakan ular,
    
- Menampilkan hasil simulasi tiap langkah.
    

---

### 📌 Langkah Per Langkah:

### 1. Optimasi I/O

```cpp
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
```

➡ Mengoptimalkan input-output agar lebih cepat. Umum digunakan saat banyak `cin`/`cout`.

### 2. Baca ukuran arena dan pergerakan

```cpp
int n, m;
string s;
cin >> n >> m;
cin >> s;
```

- `n × m`: ukuran grid
    
- `s`: string arah (misal `"RRDDLLUU"`)

### 3. Deklarasi struktur utama

```cpp
vector<vector<int>> arena (n, vector<int>(m, 0));
list<pair<int,int>> snake;
list<tuple<int, int, int>> fruits;
```

- `arena`: matriks untuk melacak sel yang ditempati ular.
    
- `snake`: urutan sel tubuh ular.
    
- `fruits`: daftar buah yang muncul beserta waktunya.

### 4. Inisialisasi ular

```cpp
arena[0][0] = 1;
snake.push_front({0,0});
```

- Kepala ular mulai dari `(0, 0)`
    
- Ditandai sebagai `1` di arena

### 5. Input buah

```cpp
int a, b, c;
while(cin >> a >> b >> c){
    fruits.push_back({a,b,c});
}
```

➡ Membaca EOF (End of File) untuk menambahkan buah dalam list.

### 6. Loop gerakan ular

```cpp
for(int i=0; i<s.length(); i++){
```

Loop selama jumlah langkah yang ada di string `s`.

### 7. Ambil buah yang sesuai waktu

```cpp
if(!fruits.empty()){
    tie(f, x, y) = fruits.front();
    while(f < i && fruits.size() > 1){
        fruits.pop_front();
        tie(f, x, y) = fruits.front();
    }
} else {
    f = n+5;
    x = y = f;
}
```

Logika penting:

- Ambil buah paling depan.
    
- Jika waktunya sudah lewat (`f < i`), buang buah-buah lama.
    
- Kalau tidak ada buah, beri nilai “tidak valid” (`f = n+5` agar `f == idx` tidak pernah benar).

### 8. Panggil `isValid()**`**

```cpp
alive = isValid(arena, snake, f, x, y, i, s[i], n, m);
```

- Periksa apakah langkah sah dan apakah makan.


### 9. Jika masih hidup, print; jika tidak, tamat

```cpp
if(alive.first){
    print(arena, f, x, y, i, snake);
    if(alive.second){
        fruits.pop_front();
    }
} else {
    cout << "\nGame Over!\n";
    break;
}
```

- Jika masih hidup:
    
    - Cetak keadaan.
        
    - Kalau makan buah, hapus dari daftar buah.
        
- Jika tidak hidup: tampilkan “Game Over!”
    

---

## 🏁 Hasil Akhir

Simulasi ular dijalankan langkah demi langkah, dengan:

- Arena diperbarui dinamis.
    
- Ular bertambah jika makan.
    
- Tabrakan ke tubuh/dinding menyebabkan game over.
    
- Setiap langkah ditampilkan.
    

---

## ✅ Kekuatan & Keunggulan:

|Aspek|Keterangan|
|---|---|
|Modular|Logika game dibagi rapi ke fungsi: `isValid`, `print`, `main`.|
|Akurat|Edge case seperti "kepala ke ekor" tertangani dengan baik.|
|Input fleksibel|Buah bisa dimasukkan via EOF.|
|Efisien|Menggunakan `list` untuk snake membuat push/pop depan/belakang efisien.|
|Visual|Fungsi `print()` sangat membantu debugging.|
