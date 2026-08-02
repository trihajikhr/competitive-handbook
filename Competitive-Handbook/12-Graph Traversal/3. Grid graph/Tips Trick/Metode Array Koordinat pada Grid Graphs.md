---
obsidianUIMode: preview
note_type: tips trick
tips_trick:
sumber:
date_learned:
tags:
---
---
# Metode Array Koordinat pada Grid Graphs

Dalam pemrosesan *grid graph*, menelusuri simpul-simpul tetangga dari suatu posisi $(r, c)$ sering kali menjadi operasi yang paling banyak dieksekusi. Cara paling Naif untuk melakukan eksplorasi ini adalah menggunakan banyak pernyataan percabangan `if` untuk memeriksa setiap arah satu per satu (atas, bawah, kiri, dan kanan). Pendekatan ini rentan terhadap kesalahan penulisan (*bug*), membuat kode menjadi panjang, serta sulit dipelihara.

Metode array koordinat—sering disebut sebagai *direction arrays* atau *offset arrays*—merupakan teknik standar untuk menyederhanakan penelusuran tetangga. Ide utamanya adalah memetakan perubahan posisi (delta) pada sumbu baris dan sumbu kolom ke dalam dua array konstan yang saling berpasangan. Dengan mengiterasi indeks dari array tersebut, eksplorasi ke seluruh arah dapat dilakukan di dalam satu *loop* sederhana.

```cpp
// Pasangan delta untuk pergerakan 4 arah ortogonal: Atas, Bawah, Kiri, Kanan
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

// Contoh iterasi penelusuran tetangga dari sel (r, c)
for (int i = 0; i < 4; ++i) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    
    // nr dan nc sekarang berisi koordinat tetangga ke-i
}
```

Urutan nilai di dalam `dr` dan `dc` bersifat fleksibel selama pasangan indeksnya konsisten. Sebagai contoh, indeks `0` pada kode di atas merepresentasikan pergerakan ke atas karena baris berkurang satu (`dr[0] = -1`) dan kolom tidak berubah (`dc[0] = 0`).

Teknik ini dapat diperluas dengan mudah untuk pergerakan 8 arah (termasuk diagonal) cukup dengan menambah elemen pada kedua array delta menjadi berukuran 8. Selain itu, fungsi pemeriksaan validitas batas *grid* dapat dipisahkan agar logika *traversal* tetap bersih:

```cpp
bool isValid(int r, int c, int R, int C) {
    return (r >= 0 && r < R && c >= 0 && c < C);
}
```

Penggunaan kombinasi array koordinat dan fungsi pengecekan batas ini menjaga kompleksitas waktu akses tetangga tetap $\mathcal{O}(1)$ sekaligus meminimalisasi duplikasi kode pada algoritma seperti BFS, DFS, maupun A*.

## Ekstensi Pergerakan 8 Arah

Untuk kasus yang mengizinkan pergerakan diagonal, array koordinat cukup diperluas dari $4$ menjadi $8$ elemen. Setiap elemen merepresentasikan salah satu arah mata angin dasar beserta empat arah diagonalnya (utara, selatan, barat, timur, barat laut, timur laut, barat daya, timur daya).

```cpp
// Pasangan delta untuk pergerakan 8 arah (ortogonal + diagonal)
const int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

for (int i = 0; i < 8; ++i) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    
    if (isValid(nr, nc, R, C)) {
        // Proses tetangga di koordinat (nr, nc)
    }
}
```

Sebagai alternatif dari penulisan array manual berukuran 8, iterasi 8 arah juga dapat diekspresikan menggunakan dua *loop* bersarang untuk menghasilkan kombinasi delta dari $-1$ hingga $1$. Pendekatan ini berguna ketika urutan eksplorasi arah tidak menjadi masalah, dengan satu kondisi tambahan untuk mengabaikan koordinat sel itu sendiri yaitu $(0, 0)$:

```cpp
for (int dr = -1; dr <= 1; ++dr) {
    for (int dc = -1; dc <= 1; ++dc) {
        if (dr == 0 && dc == 0) continue; // Abaikan posisi asal
        
        int nr = r + dr;
        int nc = c + dc;
        if (isValid(nr, nc, R, C)) {
            // Proses tetangga
        }
    }
}
```