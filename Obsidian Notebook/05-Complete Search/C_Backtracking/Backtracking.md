---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 05TH-CSBT-0001
nama_algoritma: Backtracking
kategori_algoritma: complete search
kesulitan: 🥈 medium
time_complexity: 🟢 O(1) 🔵 O(log n) 🟡 O(√n) 🟠 O(n) 🟤 O(n log n) 🟣 O(n²) 🟧 O(n³) 🔴 O(2ⁿ) ⚫ O(n!) ⚪O(formula)
memory_complexity: 🟢 O(1) 🔵 O(log n) 🟡 O(√n) 🟠 O(n) 🟤 O(n log n) 🟣 O(n²) 🟧 O(n³) 🔴 O(2ⁿ) ⚫ O(n!) ⚪O(formula) ✅ → Stable ❌ → Unstable
sumber: deepseek.com & kantinit.com & chatgpt.com
date_learned: 2025-04-14T19:27:00
tags:
  - complete-search
  - backtracking
---
#complete-search #backtracking 

---
# Backtracking Algorithm
![[Backtracking-1.png]]
**Algoritma Backtracking** adalah teknik penyelesaian masalah yang berbasis pada *pencarian sistematis* (brute-force) dengan mencoba berbagai kemungkinan solusi secara bertahap dan mundur (*backtrack*) jika menemui jalan buntu.  

### Konsep Dasar Backtracking  
1. **Eksplorasi Solusi**: Mencoba membangun solusi langkah demi langkah.  
2. **Pengecekan Kriteria**: Jika langkah saat ini valid, lanjut ke langkah berikutnya.  
3. **Backtrack**: Jika langkah tidak valid (tidak memenuhi syarat), mundur ke langkah sebelumnya (*backtrack*) dan coba alternatif lain.  

### Ciri Khas Backtracking  
- **Rekursif**: Biasanya diimplementasikan dengan rekursi.  
- **Pruning**: Mengabaikan cabang solusi yang tidak mungkin valid (*pruning*), sehingga lebih efisien daripada brute-force murni.  

## Algoritma Backtracking
Contoh Pseudocode Backtracking  
```python
def backtrack(solusi, langkah):  
    if solusi_lengkap(solusi):  
        return solusi  
    for pilihan in kemungkinan_pilihan:  
        if valid(pilihan):  
            tambahkan pilihan ke solusi  
            hasil = backtrack(solusi, langkah + 1)  
            if hasil != "gagal":  
                return hasil  
            hapus pilihan dari solusi  # Backtrack  
    return "gagal"  
```

Contoh penerapan algoritma Backtracking pada problem N-Queens Problem:

```cpp
void search(int y) {
    if (y == n) {
        count++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (column[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}
```
# Contoh Algoritma Backtracking
## Algoritma Sudoku
```cpp
#include <iostream>
using namespace std;

const int N = 9;
int grid[N][N];

bool isValid(int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) return false; // cek baris
        if (grid[i][col] == num) return false; // cek kolom
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool solve() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(row, col, num)) {
                        grid[row][col] = num;
                        if (solve()) return true;
                        grid[row][col] = 0; // backtrack
                    }
                }
                return false; // tidak ada angka valid
            }
        }
    }
    return true; // selesai
}

void printGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

int main() {
    // Contoh papan Sudoku (0 = kosong)
    int input[N][N] = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };

    // Salin ke grid global
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            grid[i][j] = input[i][j];

    if (solve()) {
        cout << "Solusi Sudoku:" << endl;
        printGrid();
    } else {
        cout << "Tidak ada solusi!" << endl;
    }

    return 0;
}
```

### 🧩 Masalah Sudoku

- **Tujuan:** Mengisi papan 9×9 dengan angka 1–9
    
- **Aturan:**
    
    - Setiap baris, kolom, dan kotak 3×3 harus berisi angka 1–9 **tanpa duplikat**.
        

---

### 💡 Pendekatan Backtracking

1. Cari sel kosong (nilai `0`).
    
2. Coba isi dengan angka 1 sampai 9.
    
3. Cek apakah valid:
    
    - Tidak ada angka yang sama di baris, kolom, dan kotak 3×3.
        
4. Jika valid, lanjut ke sel berikutnya.
    
5. Jika tidak, **backtrack** dan coba angka lain.
    


### 📌 Keterangan:

- `solve()` adalah fungsi utama dengan backtracking.
    
- `isValid()` memastikan angka aman untuk ditempatkan.
    
- Jika papan penuh dan valid → solusi ditemukan.
    
- Jika tidak bisa diisi dengan angka manapun, **kembali ke langkah sebelumnya** → backtrack.
    
## N Quens Problem

### 👑 Penjelasan Singkat: N-Queens

- Tujuan: Menempatkan `n` ratu di papan `n × n` sehingga **tidak ada dua ratu saling menyerang** (tidak boleh satu baris, kolom, atau diagonal).
    
- Teknik: **Backtracking**.
    

---

### ✅ C++ Implementation: N-Queens Solver

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n; // Ukuran papan catur
vector<int> pos; // Menyimpan posisi ratu di setiap baris (index = baris, value = kolom)
int count = 0;

vector<bool> column;
vector<bool> diag1;
vector<bool> diag2;

void printBoard() {
    for (int i = 0; i < n; i++) {
        string row(n, '.');
        row[pos[i]] = 'Q';
        cout << row << endl;
    }
    cout << endl;
}

void search(int y) {
    if (y == n) {
        count++;
        printBoard(); // Tampilkan solusi
        return;
    }

    for (int x = 0; x < n; x++) {
        if (column[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;

        pos[y] = x;
        column[x] = diag1[x + y] = diag2[x - y + n - 1] = true;
        search(y + 1);
        column[x] = diag1[x + y] = diag2[x - y + n - 1] = false;
    }
}

int main() {
    cout << "Masukkan nilai N: ";
    cin >> n;

    pos.resize(n);
    column.assign(n, false);
    diag1.assign(2 * n - 1, false);
    diag2.assign(2 * n - 1, false);

    search(0);

    cout << "Jumlah solusi: " << count << endl;
    return 0;
}
```

---

### 📌 Penjelasan Struktur

- `pos[i] = j` → ratu di baris ke-`i` kolom ke-`j`.
    
- `column[x]` → apakah kolom `x` sudah dipakai.
    
- `diag1[x+y]` dan `diag2[x−y+n−1]` → untuk mengecek diagonal.
    

---

### 🧪 Contoh Output untuk `n = 4`:

```
.M..     // artinya Q di kolom ke-2
...Q
Q...
..Q.

..Q.     // solusi kedua
Q...
...Q
.M..
```

# Backtracking Complexity
### 1. Kompleksitas Waktu (Time Complexity)  
Backtracking memiliki kompleksitas waktu **eksponensial** (biasanya $(O(b^d))$ atau $O(n!)$), tergantung pada masalah:  
- **Faktor yang Memengaruhi**:  
  - $b$: Jumlah pilihan per langkah (*branching factor*).  
  - $d$: Kedalaman rekursi maksimum.  
- **Contoh Kasus**:  
  - **N-Queens**: $O(n!)$ karena setiap ratu mengurangi pilihan untuk ratu berikutnya.  
  - **Knapsack**: $O(2^n)$ karena setiap item memiliki 2 pilihan (diambil/tidak).  
- **Optimasi**: Dengan *pruning* (pemangkasan cabang tidak valid), kompleksitas bisa berkurang, tetapi tetap eksponensial dalam kasus terburuk (*worst-case*).  

---

### 2. Penggunaan Memori (Space Complexity)  
- **Kompleksitas Memori**: $O(d)$, di mana $d$ adalah kedalaman rekursi.  
  - Memori digunakan untuk **stack rekursi** dan penyimpanan solusi sementara.  
  - Contoh: Pada *N-Queens*, $d = n$ (jumlah ratu).  
- **Catatan**: Jika solusi disimpan (misal: semua solusi Sudoku), memori bisa meningkat menjadi $O(d \times k)$, dengan $k$ adalah jumlah solusi.  

---

### 3. Stabilitas (Stable/Unstable)  
- **Tidak Stabil (*Unstable*)**  
  Backtracking tidak termasuk algoritma *stable* karena:  
  - **Tidak Mempertahankan Urutan Relatif**: Pilihan solusi bergantung pada urutan pencarian dan *backtracking*. Misal, dalam *permutasi*, urutan solusi bisa berubah tergantung langkah eksplorasi.  
  - **Non-Deterministik**: Hasil bisa berbeda jika urutan pilihan diubah (kecuali diatur eksplisit).  

---

### Perbandingan Singkat  
| Aspek                | Analisis untuk Backtracking            |     |
| -------------------- | -------------------------------------- | --- |
| **Time Complexity**  | Eksponensial ($O(b^d)$, $O(n!)$, dll.) |     |
| **Space Complexity** | Linear terhadap kedalaman $(O(d))$     |     |
| **Stabilitas**       | Unstable (urutan solusi tidak tetap)   |     |

---

### Contoh Kasus: N-Queens  
- **Time**: $O(n!)$ (setiap ratu mengurangi pilihan).  
- **Space**: $O(n)$ untuk stack rekursi.  
- **Stable?** Tidak, karena urutan solusi tergantung pencarian.  

Backtracking efisien untuk masalah dengan *constraints* ketat (sehingga *pruning* bisa mengurangi pencarian), tetapi tidak cocok untuk data besar karena kompleksitas eksponensial.

# Aplikasi Backtracking
1. **Permainan Puzzle**:  
   - *N-Queens Problem*: Menempatkan N ratu di papan catur tanpa saling serang.  
   - *Sudoku*: Mengisi grid angka dengan aturan tertentu.  
   - *Rat in a Maze*: Dalam masalah ini, terdapat labirin dan seekor tikus yang berada di satu titik. Tujuan dari masalah ini adalah untuk menemukan jalur keluar dari labirin.
1. **Kombinatorial**:  
   - *Knapsack Problem*: Memilih barang dengan nilai maksimal dan berat terbatas.  
   - *Graph Coloring*: Mewarnai node graph dengan syarat tetangga tidak sama warna.  

## Keunggulan dan kelemahan
### Keunggulan Backtracking
✔ **Fleksibel**: Cocok untuk masalah dengan banyak solusi atau constraints.  
### Kelemahan Backtracking
✖ **Kompleksitas Waktu**: Bisa tinggi (eksponensial) jika tidak dioptimasi (*pruning*).  
## Kesimpulan
Backtracking adalah dasar dari banyak algoritma lain seperti *Branch and Bound* atau *Dynamic Programming* untuk masalah optimasi.    