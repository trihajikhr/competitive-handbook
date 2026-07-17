---
obsidianUIMode: preview
note_type: book theory
judul_materi:
sumber:
date_learned:
tags:
---
Link Sumber: 

---

> [!IMPORTANT]
>  

# Teori, Desain Mekanis, Penanganan Kolisi, dan Implementasi Sistem Hash Table: Panduan Komprehensif untuk Penguasaan Konseptual

Struktur data adalah metode terstruktur untuk mengorganisasi, menyimpan, dan memanipulasi data di dalam memori komputer agar operasi dapat berjalan secara efisien. Di antara berbagai struktur data linear seperti array dan linked list, atau struktur data non-linear seperti *tree* dan *graph*, *hash table* menonjol sebagai salah satu struktur data yang paling efisien dalam hal kecepatan akses data.

Tujuan utama dari *hash table* adalah menyediakan kemampuan untuk mencari (_search_), memasukkan (_insert_), dan menghapus (_delete_) data dengan kompleksitas waktu rata-rata konstan, atau ditulis secara matematis sebagai $\Theta(1)$. Pencapaian ini jauh melampaui array biasa yang membutuhkan waktu linear $O(n)$ untuk pencarian acak, atau _Binary Search Tree_ (BST) seimbang yang memerlukan waktu logaritmik $O(\log n)$.

Secara historis, prinsip *hashing* dirancang pertama kali oleh Hans Peter Luhn pada tahun 1947 di IBM untuk memecahkan masalah pencarian cepat pada data senyawa kimia terenkode. Gagasan Luhn untuk mengelompokkan data ke dalam kompartemen-kompartemen kecil yang disebut _buckets_ kemudian dikembangkan secara formal menjadi struktur data *hash table* modern yang kita gunakan saat ini.

| Struktur Data      | Pencarian (Rata-rata) | Pencarian (Terburuk) | Penyisipan (Rata-rata) | Penyisipan (Terburuk) | Penghapusan (Rata-rata) | Penghapusan (Terburuk) |
| ------------------ | --------------------- | -------------------- | ---------------------- | --------------------- | ----------------------- | ---------------------- |
| Hash Table         | $\Theta(1)$<br>       | $O(n)$<br><br>       | $\Theta(1)$<br><br>    | $O(n)$<br><br>        | $\Theta(1)$<br><br>     | $O(n)$<br><br>         |
| Unsorted Array     | $O(n)$                | $O(n)$               | $O(1)$                 | $O(1)$                | $O(n)$                  | $O(n)$                 |
| Sorted Array       | $O(\log n)$           | $O(\log n)$          | $O(n)$                 | $O(n)$                | $O(n)$                  | $O(n)$                 |
| Binary Search Tree | $O(\log n)$<br><br>   | $O(n)$               | $O(\log n)$<br><br>    | $O(n)$                | $O(\log n)$<br><br>     | $O(n)$                 |

## Arsitektur Utama Hash Table: Dari Kunci ke Indeks

Desain mekanis dari sebuah *hash table* terdiri dari empat komponen utama yang saling berinteraksi: array internal (tabel penampung), fungsi hash, mekanisme resolusi kolisi, dan sistem pengubahan ukuran dinamis (_resizing_). Di dalam hash table, data disimpan dalam bentuk pasangan kunci (_key_) dan nilai (_value_). Pengguna memberikan sebuah kunci unik untuk mengidentifikasi data, dan hash table bertugas menyimpan nilai yang berkorespondensi dengan kunci tersebut di dalam array memori.

```c
  +-------------+     +---------------+     +------------+     +------------------------+
  | Kunci (Key) | --> | Fungsi Hash   | --> | Kompresor  | --> | Indeks Array (0 s/d m) |
  +-------------+     +---------------+     +------------+     +------------------------+
```

Proses transformasi kunci menjadi indeks fisik array melibatkan dua tahapan matematis yang krusial:

- **Pembangkitan Kode Hash (Hash Code Generation)**: Kunci masukan, yang dapat berupa objek kompleks seperti string, gambar, atau tipe data kustom, dikonversi menjadi representasi numerik integer. Di dalam Java, setiap objek mewarisi metode `hashCode()` yang menghasilkan integer ini.
    
- **Kompresi Indeks (Index Compression)**: Karena nilai integer dari kode hash bisa sangat besar atau negatif, nilai tersebut harus dikompresi agar pas dengan rentang indeks fisik array internal, yaitu dari $0$ hingga $m - 1$ (di mana $m$ adalah ukuran kapasitas array). Kompresor yang paling umum adalah operasi modulo sisa pembagian:
    
    $$\text{Indeks} = \text{Hash Code} \pmod m$$
    

### Kontrak Keterhasan (Hashability Contract)

Agar sebuah objek dapat digunakan sebagai kunci di dalam hash table, objek tersebut harus memenuhi syarat keterhasan (_hashable_). Persyaratan ini mendikte dua aturan utama:

1. **Imutabilitas dan Konsistensi**: Nilai hash dari suatu objek tidak boleh berubah selama masa hidup objek tersebut. Jika objek bersifat mutable (nilainya dapat diubah) dan komponen internalnya berubah setelah dimasukkan ke dalam hash table, kode hash-nya juga akan berubah. Akibatnya, saat pencarian dilakukan, sistem akan menghitung indeks yang berbeda dan gagal menemukan nilai tersebut, menyebabkan kebocoran memori. Oleh karena itu, tipe data imut seperti string dan angka sangat ideal sebagai kunci. Tipe data mutable seperti linked list atau dictionary dilarang keras digunakan sebagai kunci.
    
2. **Kontrak Kesetaraan (Equality Contract)**: Jika dua objek secara logis dianggap sama berdasarkan perbandingan kesetaraan (`equals` atau `==`), maka kedua objek tersebut wajib menghasilkan nilai hash yang identik. Sebaliknya, dua objek yang menghasilkan nilai hash yang sama belum tentu setara secara logis, karena keterbatasan ukuran output hash.
    

### Metode Pemetaan Fungsi Hash

Pemilihan algoritme untuk fungsi hash sangat menentukan seberapa merata kunci-kunci didistribusikan ke seluruh slot array. Beberapa metode pemetaan yang populer di antaranya:

- **Division Method (Metode Pembagian)**: Rumus indeks dihitung dengan mengambil sisa pembagian kunci $k$ dengan ukuran tabel $m$. Sangat disarankan untuk memilih nilai $m$ berupa angka prima yang tidak dekat dengan perpangkatan dua guna mengurangi bias pembagian dan mengoptimalkan penyebaran kunci.
    
- **Multiplication Method (Metode Perkalian)**: Kunci $k$ dikalikan dengan konstanta pecahan $A$ (di mana $0 < A < 1$), kemudian bagian pecahan dari hasil perkalian tersebut diambil dan dikalikan dengan kapasitas tabel $m$. Metode ini lebih fleksibel karena nilai $m$ tidak harus berupa angka prima.
    
- **Polynomial Rolling Hash**: Digunakan khusus untuk kunci bertipe string. Metode ini mengonversi string menjadi angka dengan memperlakukan setiap karakter sebagai koefisien polimonial terhadap basis prima tertentu.
    

### Perbandingan Fungsi Hash Kriptografi dan Non-Kriptografi

Dalam merancang struktur data hash table untuk kebutuhan komputasi praktis, pengembang harus memilih antara fungsi hash kriptografi atau non-kriptografi.

- **Fungsi Hash Kriptografi** (seperti SHA-256 atau SHA-3) dirancang untuk memberikan jaminan keamanan absolut. Fungsi ini memiliki sifat _collision resistance_ yang sangat kuat, artinya secara matematis sangat sulit menemukan dua input berbeda yang menghasilkan hash yang sama. Namun, kekuatan ini menuntut kalkulasi matematis yang kompleks, sehingga kecepatannya sangat lambat.
    
- **Fungsi Hash Non-Kriptografi** (seperti SeaHash atau MurmurHash) mengabaikan aspek keamanan demi performa kecepatan maksimal. Fungsi ini berfokus pada minimalisasi kolisi tidak sengaja pada data normal dan penyebaran bit secara acak. Sebagai perbandingan, fungsi SeaHash mampu mengeksekusi data dengan kecepatan hingga 0.24 siklus CPU per byte, menjadikannya puluhan kali lipat lebih cepat daripada fungsi kriptografi.
    

Kelemahan dari fungsi non-kriptografi adalah kerentanannya terhadap _Hash Denial-of-Service (DoS) Attack_. Jika penyerang mengetahui fungsi hash yang digunakan oleh aplikasi web (misalnya saat mengirimkan data JSON), penyerang dapat merekayasa ribuan parameter kunci yang semuanya menghasilkan indeks hash yang sama (kolisi masif).

Hal ini akan memaksa hash table bekerja pada performa terburuknya, yaitu $O(n)$, yang secara instan menghabiskan sumber daya CPU server. Untuk memitigasi serangan ini, bahasa pemrograman modern menyisipkan _salt_ acak secara dinamis saat runtime, sehingga nilai hash dari kunci yang sama akan selalu berbeda pada setiap sesi eksekusi aplikasi.

|**Kategori Fungsi**|**Contoh Algoritme**|**Kecepatan (Siklus CPU/Byte)**|**Keamanan Kolisi Sengaja**|**Aplikasi Utama**|
|---|---|---|---|---|
|**Kriptografi**|SHA-256|Lambat (~7.8 atau lebih)|Sangat Aman|Cryptocurrency, Tanda Tangan Digital|
|**Legacy Kriptografi**|MD5|Sedang|Rentan (Kolisi ditemukan dalam hitungan detik)|Verifikasi File Non-Sensitif|
|**Non-Kriptografi**|SeaHash|Sangat Cepat (~0.24)|Tidak Aman (Mudah dieksploitasi)|Struktur Data Memori, Cache, Bloom Filter|

## Operasi Dasar dan Siklus Hidup Data

Tabel hash mengabstraksi penyimpanan data melalui antarmuka operasional yang sederhana. Setiap operasi bekerja dengan mengonversi kunci secara langsung menjadi alamat memori fisik:

1. **Penyisipan (`put` atau `add`)**: Sistem menerima kunci dan nilai. Kunci dilewatkan ke fungsi hash untuk menentukan slot tujuan. Jika slot kosong, node baru dibuat dan disimpan. Jika kunci sudah ada, nilai lama diperbarui dengan nilai baru.
    
2. **Pencarian (`get` atau `lookup`)**: Sistem menghitung indeks dari kunci yang dicari. Algoritme langsung melompat ke slot indeks tersebut di memori. Jika kunci pada slot tersebut cocok dengan kunci pencarian (berdasarkan perbandingan kesetaraan), nilainya dikembalikan. Jika tidak cocok akibat adanya kolisi, pencarian dilanjutkan sepanjang rantai kolisi.
    
3. **Penghapusan (`remove` atau `delete`)**: Mencari lokasi elemen berdasarkan kunci, lalu menghapus hubungan node tersebut (pada separate chaining) atau menandai slot tersebut sebagai terhapus (pada open addressing).
    
4. **Pengecekan Kapasitas (`getSize` dan `isEmpty`)**: Memantau metrik internal berupa jumlah pasangan kunci-nilai aktif yang tersimpan dan menentukan apakah tabel dalam keadaan kosong.
    

```
Alur Operasi get(Key):
[Hitung Hash] -> [Dapatkan Indeks] -> [Lompat ke Indeks Array] -> [Apakah Key Sama?]
                                                                         |
                                                 +-----------------------+-----------------------+
                                                 | Ya                                            | Tidak (Kolisi)
                                                 v                                               v
                                          [Kembalikan Value]                            [Telusuri Rantai/Probe]
```

## Teorema Kolisi dan Prinsip Matematis Wadah

Meskipun fungsi hash dirancang dengan presisi matematis tinggi untuk menyebarkan kunci secara acak, fenomena kolisi adalah kepastian mutlak yang tidak dapat dihindari. Hal ini didasarkan pada **Pigeonhole Principle** (Prinsip Sarang Burung Dara): jika terdapat $n$ burung dara yang ingin dimasukkan ke dalam $m$ sarang, dan $n > m$, maka minimal ada satu sarang yang menampung lebih dari satu burung dara.

Dalam konteks komputasi, semesta kunci potensial yang dapat dimasukkan bersifat tak terbatas, sedangkan kapasitas fisik memori komputer ($m$) selalu terbatas. Oleh karena itu, efisiensi dari struktur data hash table tidak diukur dari kemampuannya untuk mencegah kolisi secara total, melainkan dari seberapa elegan dan efisien sistem tersebut menyelesaikan kolisi saat terjadi.

## Teknik Resolusi Kolisi Terperinci

Ada dua metodologi utama dalam menyelesaikan masalah kolisi pada hash table: _Separate Chaining_ (Chaining Terpisah) dan _Open Addressing_ (Pengalamatan Terbuka).

### 1. Separate Chaining (Open Hashing)

Metode _Separate Chaining_ menyelesaikan kolisi dengan cara membuat rantai penyimpanan eksternal pada setiap slot array yang mengalami kolisi. Slot array itu sendiri tidak menyimpan pasangan data secara langsung, melainkan menyimpan pointer yang menunjuk ke sebuah struktur data dinamis, biasanya berupa linked list.

```
Array Indeks
[0] ---> [15, "A"] -> [25, "B"] -> NULL   (Kolisi di indeks 0)
[1] ---> NULL
[2] ---> [12, "C"] -> NULL
[3] ---> NULL
```

#### Simulasi Kasus Chaining Terpisah

Misalkan sebuah hash table memiliki kapasitas ukuran $m = 5$, dengan fungsi hash sederhana $h(k) = k \pmod 5$. Kita ingin menyisipkan urutan kunci berikut: $12, 15, 22, 25,$ dan $37$.

- **Penyisipan 12**: $12 \pmod 5 = 2$. Slot indeks 2 kosong. Node dengan kunci $12$ diletakkan di slot 2.
    
- **Penyisipan 15**: $15 \pmod 5 = 0$. Slot indeks 0 kosong. Node dengan kunci $15$ diletakkan di slot 0.
    
- **Penyisipan 22**: $22 \pmod 5 = 2$. Slot indeks 2 telah terisi oleh kunci 12 (terjadi kolisi). Sistem membuat linked list pada indeks 2, menyisipkan node $22$ di belakang node $12$.
    
- **Penyisipan 25**: $25 \pmod 5 = 0$. Slot indeks 0 telah terisi oleh 15 (kolisi). Node $25$ ditambahkan ke rantai linked list indeks 0.
    
- **Penyisipan 37**: $37 \pmod 5 = 2$. Slot indeks 2 terisi oleh 12 dan 22 (kolisi). Node $37$ ditambahkan ke rantai linked list indeks 2.
    

Hasil akhir representasi fisik memori:

- Indeks 0: `[15]` $\rightarrow$ `[25]`
    
    [cite: 25]
    
- Indeks 1: `empty`
    
- Indeks 2: `[12]` $\rightarrow$ `[22]` $\rightarrow$ `[37]`
    
    [cite: 25]
    
- Indeks 3: `empty`
    
- Indeks 4: `empty`
    

#### Optimasi Transformasi Pohon (Treeification)

Apabila fungsi hash menghasilkan distribusi data yang buruk, semua data dapat menumpuk pada satu indeks tunggal. Hal ini mendegradasi performa pencarian menjadi pencarian linear $O(n)$ pada linked list.

Untuk mengatasi degradasi ekstrem ini, terhitung sejak Java 8, kelas `HashMap` mengimplementasikan strategi optimasi hibrida: jika jumlah node dalam satu rantai bucket melampaui `TREEIFY_THRESHOLD` (bernilai 8) dan total kapasitas tabel telah mencukupi, linked list tersebut akan dikonversi menjadi balanced tree (Pohon Merah-Hitam / Red-Black Tree). Struktur pohon menjamin batas atas pencarian terburuk turun drastis dari linear $O(n)$ menjadi logaritmik $O(\log n)$.

Sebaliknya, jika elemen berkurang akibat operasi penghapusan hingga di bawah `UNTREEIFY_THRESHOLD` (bernilai 6), pohon tersebut akan dikembalikan menjadi linked list biasa untuk menghemat konsumsi memori.

### 2. Open Addressing (Closed Hashing)

Dalam metode _Open Addressing_, semua elemen disimpan secara fisik di dalam array tabel itu sendiri. Tidak ada linked list atau struktur luar yang digunakan. Ketika terjadi kolisi, sistem secara aktif melakukan penyelidikan (_probing_) ke slot-slot tetangga sesuai dengan pola aritmetika tertentu hingga menemukan slot yang masih kosong.

#### Tiga Strategi Penyelidikan Utama

**A. Linear Probing** Mencari slot kosong secara linear satu per satu dengan melompat ke slot berikutnya secara berurutan. Rumus indeksnya adalah:

$$h(k, i) = (h'(k) + i) \pmod m$$

Di mana $i$ adalah nomor iterasi kolisi. Meskipun sangat mudah dihitung dan memiliki _cache locality_ yang luar biasa karena elemen-elemen berada di memori fisik yang berdampingan, metode ini menderita masalah **Primary Clustering**. Elemen-elemen cenderung menumpuk membentuk kluster kontinu yang panjang, sehingga pencarian slot kosong membutuhkan waktu yang semakin lama.

**B. Quadratic Probing** Mengurangi dampak penumpukan linear dengan menambahkan nilai kuadrat dari nomor kolisi. Rumusnya adalah:

$$h(k, i) = (h'(k) + c_1 \cdot i + c_2 \cdot i^2) \pmod m$$

Meskipun berhasil memecahkan masalah kluster linear kontinu, metode ini rentan terhadap **Secondary Clustering**, di mana kunci-kunci yang memiliki nilai hash awal sama akan melewati jalur penyelidikan yang persis sama, menciptakan kemacetan pencarian sekunder.

**C. Double Hashing** Menggunakan fungsi hash kedua ($h_2(k)$) untuk menentukan jarak lompatan penyelidikan ketika terjadi kolisi. Rumus pencarian slot kosongnya adalah:

$$h(k, i) = (h_1(k) + i \cdot h_2(k)) \pmod m$$

Karena jarak lompatan bergantung pada kalkulasi kunci itu sendiri, _double hashing_ berhasil mengeliminasi masalah _primary_ maupun _secondary clustering_. Jalur penyelidikan menjadi sangat acak dan terdistribusi merata, namun memiliki komputasi yang lebih berat dan kinerja cache memori yang kurang efisien karena lompatan memori yang tidak berurutan.

#### Simulasi Kasus Open Addressing dengan Linear Probing

Misalkan kita memiliki kapasitas array $m = 7$, menggunakan fungsi hash $h(k) = k \pmod 7$, dan menyelesaikan kolisi menggunakan _Linear Probing_. Kita akan menyisipkan kunci: $50, 700, 76, 85, 92, 73,$ dan $101$.

- **Penyisipan 50**: $50 \pmod 7 = 1$. Slot 1 kosong. Simpan 50 di slot 1.
    
- **Penyisipan 700**: $700 \pmod 7 = 0$. Slot 0 kosong. Simpan 700 di slot 0.
    
- **Penyisipan 76**: $76 \pmod 7 = 6$. Slot 6 kosong. Simpan 76 di slot 6.
    
- **Penyisipan 85**: $85 \pmod 7 = 1$. Slot 1 telah terisi oleh 50 (kolisi). Melakukan linear probing ke indeks berikutnya: $(1 + 1) \pmod 7 = 2$. Slot 2 kosong. Simpan 85 di slot 2.
    
- **Penyisipan 92**: $92 \pmod 7 = 1$. Slot 1 terisi (kolisi). Probe ke indeks 2: terisi (kolisi). Probe ke indeks 3: $(1 + 2) \pmod 7 = 3$. Slot 3 kosong. Simpan 92 di slot 3.
    
- **Penyisipan 73**: $73 \pmod 7 = 3$. Slot 3 telah terisi oleh 92 (kolisi). Probe ke indeks 4: $(3 + 1) \pmod 7 = 4$. Slot 4 kosong. Simpan 73 di slot 4.
    
- **Penyisipan 101**: $101 \pmod 7 = 3$. Slot 3 terisi (kolisi). Probe ke indeks 4: terisi (kolisi). Probe ke indeks 5: $(3 + 2) \pmod 7 = 5$. Slot 5 kosong. Simpan 101 di slot 5.
    

Keadaan akhir memori fisik tabel:

- Slot [0]: 700
    
- Slot [1]: 50
    
- Slot [2]: 85
    
- Slot [3]: 92
    
- Slot [4]: 73
    
- Slot [5]: 101
    
- Slot [6]: 76
    

## Dilema Penghapusan pada Open Addressing: Mekanisme Tombstone

Operasi penghapusan (_deletion_) di dalam hash table yang menerapkan _Open Addressing_ tidak boleh dilakukan dengan cara langsung mengosongkan slot fisik menjadi `null` atau kosong. Jika sebuah elemen di tengah rantai penyelidikan (_probe sequence_) dihapus secara fisik dan diubah menjadi status kosong, maka rantai pencarian untuk elemen lain di belakangnya akan rusak.

```
Keadaan Awal:
Index:   [0]      [1]      [2]      [3]
Data:  700(H:0)  50(H:1)  85(H:1)  92(H:1)

Kasus Salah (Hapus 85 langsung diubah ke NULL):
Index:   [0]      [1]      [2]      [3]
Data:  700(H:0)  50(H:1)   NULL    92(H:1)

Jika kita mencari 92 (Hash:1):
Lompat ke indeks 1 (ada 50) -> lanjut ke indeks 2 (menemui NULL).
Sistem langsung berhenti dan berasumsi "92 TIDAK ADA" (Padahal 92 ada di indeks 3).
```

### Solusi Lazy Deletion dengan Tombstone

Untuk mengatasi putusnya rantai penyelidikan, diimplementasikan mekanisme penandaan khusus bernama **Tombstone** (Batu Nisan) atau status `AVAILABLE`. Ketika sebuah data dihapus, objek data lama diganti dengan sebuah objek dummy khusus.

- **Saat Operasi Pencarian (`get`)**: Ketika algoritme pencarian mendapati slot berisi penanda Tombstone, algoritme tidak boleh berhenti. Tombstone dianggap sebagai "slot terisi dengan data yang tidak cocok", sehingga pencarian wajib melanjutkan penyelidikan ke indeks berikutnya agar rantai probe tidak terputus.
    
- **Saat Operasi Penyisipan (`put`)**: Slot berisi Tombstone dianggap sebagai "slot kosong yang dapat digunakan kembali". Sistem dapat langsung menimpa Tombstone tersebut dengan data baru yang ingin disisipkan guna mengoptimalkan pemanfaatan ruang.
    

Meskipun memecahkan masalah kebenaran fungsional, penumpukan Tombstone yang terlalu banyak akibat tingginya frekuensi penyisipan dan penghapusan akan memperburuk kinerja. Jarak penyelidikan rata-rata akan semakin panjang karena operasi pencarian harus melewati banyak Tombstone sebelum menemukan data asli atau slot kosong sejati.

Sebagai alternatif, pada variasi _Linear Probing_ sederhana, pengembang dapat menerapkan **Local Reorganization** (Reorganisasi Lokal/Knuth's Shift-Back Deletion). Metode ini secara fisik menggeser elemen-elemen di belakang elemen yang dihapus untuk menutup celah kosong tanpa memerlukan penanda Tombstone, meskipun lebih kompleks untuk diimplementasikan.

## Dinamika Load Factor dan Algoritme Rehashing

Performa dari sebuah hash table sangat bergantung pada metrik kepadatan data di dalam tabel, yang secara matematis didefinisikan sebagai **Load Factor** ($\alpha$):

$$\alpha = \frac{n}{m}$$

Di mana $n$ adalah jumlah total elemen yang saat ini tersimpan, dan $m$ adalah total kapasitas slot array tersedia.

### Batas Toleransi Load Factor

Pada metode _Separate Chaining_, nilai $\alpha$ secara teori dapat melebihi $1.0$, karena rantai linked list di luar tabel dapat bertambah panjang tanpa batas. Namun, performa akan terus menurun secara gradual seiring memanjangnya rantai. Batas optimal untuk chaining biasanya berkisar antara $1.0$ hingga $3.0$.

Pada metode _Open Addressing_, kapasitas array bersifat mutlak sehingga nilai $\alpha$ tidak akan pernah bisa melampaui $1.0$. Ketika $\alpha$ mendekati angka $1.0$, frekuensi kolisi meningkat secara eksponensial, dan waktu pencarian slot kosong akan meroket drastis. Batas atas aman yang disepakati untuk menghindari degradasi performa pada open addressing adalah antara $0.6$ hingga $0.75$.

|**Karakteristik Performa**|**Load Factor Rendah (α≤0.2)**|**Load Factor Ideal (α≈0.75)**|**Load Factor Sangat Tinggi (α≥0.95)**|
|---|---|---|---|
|**Kemungkinan Kolisi**|Sangat rendah (hampir tidak ada)|Sedang (terkendali secara konstan)|Sangat tinggi (kolisi masif di setiap operasi)|
|**Efisiensi Penggunaan Memori**|Sangat buruk (banyak ruang memori terbuang percuma)|Optimal (keseimbangan terbaik memori vs kecepatan)|Sangat efisien secara ruang, namun merusak kinerja|
|**Kecepatan Operasi Rata-rata**|Instan ($\Theta(1)$ sejati)|Sangat cepat dan stabil mendekati $O(1)$<br><br>[cite: 13, 35]|Sangat lambat (mendekati pencarian linear $O(n)$)|

### Mekanisme Kerja Algoritme Rehashing

Apabila nilai $\alpha$ telah melampaui batas ambang batas (_threshold_) yang ditentukan (misalnya standar bawaan Java adalah $0.75$), hash table harus memperbesar dirinya secara dinamis. Proses perluasan memori dan pemetaan ulang seluruh data ini disebut **Rehashing**.

```
Algoritme Rehashing:
1. Trigger: Load Factor > Threshold (misal 0.75) [cite: 19, 35]
2. Alokasikan Array Baru berukuran 2 kali lipat dari ukuran lama
3. Untuk setiap slot di Array Lama:
     Untuk setiap Node/Elemen di slot tersebut:
       - Ambil Key
       - Hitung ulang Hash Code & Indeks Baru berdasarkan Ukuran Array Baru
       - Sisipkan Elemen ke dalam Array Baru [cite: 10, 19, 35]
4. Dealokasikan Array Lama dari Memori [cite: 6]
```

Meskipun operasi rehashing membutuhkan waktu pengerjaan yang mahal yaitu linear $O(n)$ karena harus menyalin seluruh elemen, operasi ini sangat jarang terjadi karena ukuran kapasitas tabel dilipatgandakan secara eksponensial.

Biaya komputasi $O(n)$ dari operasi tunggal ini berhasil diredam oleh jutaan penyisipan cepat bernilai $O(1)$. Melalui analisis amortisasi (_amortized analysis_), terbukti bahwa biaya rata-rata per operasi penyisipan tetap berada pada nilai konstan $O(1)$.

## Studi Kasus Bahasa Pemrograman Modern

Analisis komparatif pada runtime tingkat produksi menunjukkan bagaimana para insinyur sistem mengoptimalkan trade-off hash table untuk kinerja dunia nyata.

### 1. Java: Pertarungan `HashMap` vs `Hashtable`

Dalam ekosistem pemrograman Java, terdapat dua implementasi utama yang sering membingungkan pemula: `java.util.HashMap` dan `java.util.Hashtable`. Meskipun keduanya berbasis struktur data hash table, ada perbedaan arsitektur yang mendasar di antara keduanya.

|**Parameter Perbandingan**|**java.util.HashMap**|**java.util.Hashtable (Legacy)**|
|---|---|---|
|**Sinkronisasi Thread**|Tidak tersinkronisasi (tidak aman untuk multithreading langsung, namun sangat cepat)|Tersinkronisasi penuh (thread-safe, namun lambat karena overhead penguncian memori)|
|**Penanganan Nilai `null`**|Mengizinkan satu kunci bernilai `null` dan banyak nilai bernilai `null`<br><br>[cite: 9, 22]|Sama sekali tidak mengizinkan kunci atau nilai bernilai `null`<br><br>[cite: 14]|
|**Status Kelas**|Modern, bagian dari Java Collections Framework|Legasi (_legacy class_ sejak Java 1.0, digantikan oleh `ConcurrentHashMap` untuk multithreading modern)|
|**Struktur Internal**|Array dari node linked list yang bertransformasi menjadi Red-Black Tree pada tingkat kolisi tinggi|Array dari node linked list konvensional tanpa pohon|

### 2. Python: Revolusi Compact Dictionary

Sebelum rilis Python 3.6, representasi dictionary (`dict`) di Python memakan memori yang sangat besar. Python menggunakan array sparse terbuka yang menyimpan entri objek secara langsung. Karena harus menyisakan banyak slot kosong agar load factor tetap rendah, sebagian besar memori terbuang secara sia-sia.

Sejak Python 3.6 (dan diresmikan pada Python 3.7), Python menerapkan arsitektur **Compact Dictionary**. Di bawah arsitektur baru ini, data dipisahkan menjadi dua array yang berbeda:

1. **Array Indeks Sparse**: Array berukuran kecil yang hanya menampung nilai integer indeks. Indeks ini diperoleh dari hasil sisa pembagian hash kunci.
    
2. **Array Entri Padat (Dense Array)**: Array kontinu tanpa celah kosong yang menyimpan data aktual secara berurutan sesuai urutan waktu masuk data: `<hash, key, value>`.
    

```
Representasi Memori Compact Dict Python 3.6+:
Array Indeks Sparse: [  0  | -1 |  1  | -1 |  2  ]  (Sangat hemat memori)
                           |        |        |
                           v        v        v
Array Entri Padat:  [[hash1, k1, v1], [hash2, k2, v2], [hash3, k3, v3]] (Kontinu, tanpa celah)
```

Inovasi ini menghemat penggunaan memori dictionary di Python hingga 30-40%. Selain itu, karena data riil disimpan secara berurutan pada array entri padat, efek samping positif dari struktur ini adalah Python `dict` kini secara otomatis mempertahankan urutan waktu penyisipan kunci (_insertion-order preservation_).

## Skenario Aplikasi Praktis di Industri Perangkat Lunak

Tabel hash adalah roda penggerak utama di balik layar berbagai teknologi skala industri modern:

- **Sistem Penyimpanan Cepat dan Caching**: Memori cache berbasis RAM seperti Redis menggunakan hash table untuk menyediakan akses instan dalam hitungan milidetik terhadap data web yang paling sering diakses pengguna.
    
- **Pengelolaan Variabel pada Kompiler**: Kompiler bahasa pemrograman memelihara tabel simbol (_symbol table_) berbasis hash table untuk melacak cakupan variabel, tipe data, dan alamat memori fungsi secara instan saat kode program dikompilasi.
    
- **Pencarian Pola String (Algoritme Rabin-Karp)**: Menggunakan fungsi hashing bergulir (_rolling hash_) untuk mendeteksi kesamaan string, sangat krusial dalam perangkat lunak deteksi plagiarisme dan mesin pencari teks.
    
- **Verifikasi Integritas Data dan Deduplikasi**: Membandingkan sidik jari digital berkode hash (seperti MD5 atau SHA-256) untuk mendeteksi apakah dua file berukuran gigabyte identik tanpa perlu membaca isi keseluruhan file bit-per-bit.
    
- **Database Indexing**: Mempercepat eksekusi kueri pencarian pada basis data relasional berskala besar tanpa perlu melakukan pemindaian menyeluruh pada hard disk.