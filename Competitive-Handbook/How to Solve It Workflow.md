![](src/How%20to%20Solve%20It%20Workflow-1.png)
---

# Problem Solving Workflow — Competitive Programming
*Berdasarkan "How to Solve It" oleh Pólya*

---

## Fase 1 — Pahami Soal
> Tujuan: buat gambaran utuh soal di kepala sebelum menulis satu baris kode pun.

- [ ] Baca soal dari awal sampai akhir tanpa berhenti
- [ ] Identifikasi: apa yang diberikan (input) dan apa yang diminta (output)?
- [ ] Catat batasan: rentang N, batas waktu, memori, tipe data
- [ ] Gambar ulang contoh input/output dengan tangan — jangan lewati sampel
- [ ] Bisa parafrasakan soal dengan kata-katamu sendiri? Kalau belum, baca ulang

---

## Fase 2 — Bedah Soal
> Pisahkan: data yang diketahui, yang tidak diketahui, dan kondisi/syarat. Pertimbangkan satu per satu lalu kombinasikan.

- [ ] Apa "objek" utama soal ini? (graf, string, array, angka, interval...)
- [ ] Estimasi kompleksitas target dari constraint N (O(N log N)? O(N²)?)
- [ ] Coba buat contoh kecil buatan sendiri di luar sampel, lalu verifikasi ekspektasi
- [ ] Apakah soal bisa dipecah jadi subproblem yang lebih sederhana?
- [ ] Pikirkan edge case: N=0, N=1, semua nilai sama, nilai negatif, overflow

---

## Fase 3 — Cari Ide & Rancang Solusi
> Tinjau dari berbagai sisi. Hubungkan dengan soal yang pernah kamu selesaikan. Ide bisa datang bertahap — syukuri setiap ide kecil.

- [ ] Tulis solusi brute force terlebih dahulu — ini baseline untuk memvalidasi ide
- [ ] Apakah ini pernah kamu lihat sebelumnya? (DP, greedy, two pointer, binary search, BFS/DFS...)
- [ ] Jika suatu problem tidak bisa dipecahkan, maka pasti ada problem lain yang lebih sederhana yang tidak bisa dipecahkan, temukan, dan pecahkan problem itu lebih dulu.
- [ ] Coba ubah representasi: balikkan array, gunakan komplemen, pertimbangkan graf
- [ ] Verifikasi ide pada contoh kecil sebelum mulai coding
- [ ] Sketch pseudocode atau langkah algoritma secara ringkas
- [ ] Hitung perkiraan operasi: apakah masuk dalam time limit?

---

## Fase 4 — Implementasi
> Tulis kode sesuai rencana. Mulai dari langkah besar, lalu turun ke detail. Pastikan setiap bagian benar sebelum lanjut.

- [ ] Implementasi struktur utama terlebih dahulu, sisakan TODO untuk detail
- [ ] Uji dengan sampel soal — apakah outputnya cocok?
- [ ] Uji edge case yang sudah dicatat di fase 2
- [ ] Cek off-by-one error, index loop, dan kondisi batas
- [ ] Jika WA: debug dengan contoh kecil, bukan langsung ganti algoritma

---

## Fase 5 — Looking Back (Refleksi)
> Setelah AC atau setelah contest. Fase ini yang membuatmu lebih baik dari waktu ke waktu.

- [ ] Apakah solusi bisa disederhanakan? Adakah kode redundan?
- [ ] Apa "inti" dari ide solusi ini? Bisa ditulis satu kalimat?
- [ ] Baca editorial atau solusi orang lain — adakah pendekatan lebih elegan?
- [ ] Catat teknik atau pola baru yang kamu pelajari dari soal ini
