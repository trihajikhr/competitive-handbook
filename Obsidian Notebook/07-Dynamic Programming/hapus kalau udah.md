Siap 👍 aku akan rapikan daftar soal DP pemula itu dengan **format MathJax** supaya lebih elegan dan mudah dibaca.

---

# 📘 Daftar Soal Dynamic Programming (DP) untuk Pemula

Berikut adalah masalah-masalah klasik yang biasanya dipakai untuk mengenalkan konsep **memoization (top-down)** dan **tabulation (bottom-up)**.

---

### 1. **Fibonacci Numbers**

* Definisi:

  $$
  F(0) = 0, \quad F(1) = 1, \quad F(n) = F(n-1) + F(n-2)
  $$
* Masalah: Hitung $F(n)$.
* **Tipe DP**: Top-down / Bottom-up.

---

### 2. **Climbing Stairs**

* Masalah: Ada $n$ anak tangga, tiap langkah bisa naik $1$ atau $2$ tangga. Berapa banyak cara mencapai anak tangga ke-$n$?
* Relasi:

  $$
  dp[n] = dp[n-1] + dp[n-2]
  $$
* **Tipe DP**: Sama seperti Fibonacci.

---

### 3. **0/1 Knapsack**

* Masalah: Diberikan $n$ barang, masing-masing dengan nilai $v_i$ dan bobot $w_i$. Dengan kapasitas tas $W$, tentukan nilai maksimum yang bisa diperoleh.
* Relasi:

  $$
  dp[i][j] = \max \big( dp[i-1][j], \; v_i + dp[i-1][j-w_i] \big)
  $$
* **Tipe DP**: Bottom-up 2D.

---

### 4. **Subset Sum**

* Masalah: Apakah ada subset dari array $A$ yang jumlah elemennya tepat $S$?
* Relasi:

  $$
  dp[i][j] = dp[i-1][j] \; \lor \; dp[i-1][j - A[i]]
  $$
* **Tipe DP**: Bottom-up.

---

### 5. **Partition Equal Subset Sum**

* Masalah: Apakah array $A$ bisa dibagi menjadi dua subset dengan jumlah sama?
* Observasi: Sama dengan **Subset Sum** dengan target $\tfrac{\text{total}}{2}$.
* **Tipe DP**: Bottom-up.

---

### 6. **Coin Change (Counting Ways)**

* Masalah: Diberikan koin $\{c_1, c_2, \dots, c_m\}$ tak terbatas, berapa banyak cara membuat jumlah $N$?
* Relasi:

  $$
  dp[n] = \sum_{c \in \text{coins}} dp[n-c]
  $$
* **Tipe DP**: Bottom-up 1D.

---

### 7. **Longest Common Subsequence (LCS)**

* Masalah: Cari panjang subsekuens terpanjang yang sama dari dua string $X$ dan $Y$.
* Relasi:

  $$
  dp[i][j] = \begin{cases}
    dp[i-1][j-1] + 1 & \text{jika } X[i] = Y[j] \\
    \max(dp[i-1][j], dp[i][j-1]) & \text{lainnya}
  \end{cases}
  $$
* **Tipe DP**: Bottom-up 2D.

---

### 8. **Longest Increasing Subsequence (LIS)**

* Masalah: Dari array $A$, cari panjang subsekuens terpanjang yang menaik.
* Relasi:

  $$
  dp[i] = 1 + \max_{j < i, \, A[j] < A[i]} dp[j]
  $$
* **Tipe DP**: Bottom-up.

---

### 9. **Unique Paths (Grid Path)**

* Masalah: Hitung banyak jalur dari $(0,0)$ ke $(m-1,n-1)$ hanya dengan langkah kanan/bawah.
* Relasi:

  $$
  dp[i][j] = dp[i-1][j] + dp[i][j-1]
  $$
* **Tipe DP**: Bottom-up 2D.

---

### 10. **Palindromic Substrings**

* Masalah: Hitung banyak substring palindromik dari string $S$.
* Relasi:

  $$
  dp[i][j] = (S[i] = S[j]) \land (dp[i+1][j-1] \text{ atau } j-i < 2)
  $$
* **Tipe DP**: Bottom-up 2D.

---

### 11. **House Robber**

* Masalah: Dari array $A$, pilih elemen tidak bersebelahan agar jumlah maksimal.
* Relasi:

  $$
  dp[i] = \max(dp[i-1], \; A[i] + dp[i-2])
  $$
* **Tipe DP**: Bottom-up 1D.

---

### 12. **Rod Cutting**

* Masalah: Potong batang panjang $n$ agar nilai total maksimum dengan daftar harga potongan.
* Relasi:

  $$
  dp[i] = \max_{1 \leq j \leq i} \big( price[j] + dp[i-j] \big)
  $$
* **Tipe DP**: Bottom-up.

---

### 13. **Edit Distance**

* Masalah: Hitung operasi minimum (insert, delete, replace) untuk ubah string $A \to B$.
* Relasi:

  $$
  dp[i][j] = \begin{cases}
    dp[i-1][j-1] & \text{jika } A[i] = B[j] \\
    1 + \min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) & \text{lainnya}
  \end{cases}
  $$
* **Tipe DP**: Bottom-up 2D.

---

⚡ Nah, ini daftar paling umum yang biasanya dipakai untuk mengenalkan DP ke pemula.

Mau aku susun juga **urutan belajar (progression)** dari yang paling mudah → menengah, biar lebih enak dipakai buat latihan STRIKE-mu?
