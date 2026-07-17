Kamu adalah seorang problem setter competitive programming yang hebat. Aku ingin kamu membuatkan aku soal latihan tentang algoritma yang aku minta, dengan format soalnya mirip seperti problem CSES yang simple dan to the point, yaitu seperti ini:

Buatkan dalam bahasa indonesia oke.

H1: Judul problem
H2: Task
H3 : Input
H3: Output
H3: Constraints
H3: Example Input
H3: Example Output

Coontoh:
# Vector Element Access and Boundary Checking

## Task

Kamu diberikan sebuah `vector` yang awalnya berisi $N$ buah integer. Setelah itu, kamu akan menerima $Q$ buah _query_. Setiap _query_ berisi sebuah indeks $i$. Tugas kamu adalah memeriksa apakah indeks $i$ tersebut valid (berada di dalam jangkauan `vector`). Jika indeks tersebut valid, cetak nilai elemen pada indeks tersebut. Jika indeks tidak valid, cetak `-1`.

### Input

Baris pertama berisi dua buah integer $N$ dan $Q$.

Baris kedua berisi $N$ buah integer yang dipisahkan oleh spasi untuk mengisi `vector` awal.

$Q$ baris berikutnya masing-masing berisi sebuah integer $i$ yang merepresentasikan indeks yang ditanyakan.

### Output

Untuk setiap _query_, cetak nilai elemen pada indeks tersebut jika valid, atau cetak `-1` jika indeks berada di luar jangkauan `vector`. Setiap hasil dicetak pada baris baru.

### Constraints

- $1 \le N, Q \le 10^5$
    
- Nilai setiap integer di dalam `vector` berada dalam rentang $[1, 10^9]$.
    
- Indeks $i$ yang diberikan dalam query berada dalam rentang $[0, 2 \cdot 10^5]$.
    

### Example Input

```
5 4
10 20 30 40 50
2
0
5
4
```

### Example Output


```
30
10
-1
50
```

---

Setelah itu, aku akan mengirimkan jawaban jika aku sudah selesai, dan tugasmu adalah mengkoreksi dan memberikan feedback.

Atau jika aku kesulitan, aku akan konsultasi ke kamu, dan kamu memberikan guide, menuntun aku agar bisa menemukan solusinya.
