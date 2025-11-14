---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Introduction to Competitive Programming
sumber:
  - USACO guide
date_learned: 2025-07-18T21:58:00
tags:
  - general-usaco
---
Link Sumber: 


```cardlink
url: https://usaco.guide/general/intro-cp?lang=cpp
title: "Introduction to Competitive Programming"
description: "Programming competitions, including the USA Computing Olympiad."
host: usaco.guide
favicon: https://usaco.guide/favicon-32x32.png?v=486b7e9b938c7be5463018a5e8da37f8
image: https://usaco.guide/static/2863837723a7041cb58da9f7856ce0fb/0ff54/social-media-image.jpg
```


---
# Introduction to Competitive Programming

## Programming Competitions

Sebuah kompetisi pemrograman umumnya berlangsung selama beberapa jam dan terdiri dari satu set soal. Soal-soal ini **bukanlah soal terbuka**; mereka telah diselesaikan sebelumnya oleh pembuat dan penguji soal, serta dirancang untuk dapat diselesaikan dalam waktu singkat selama kontes.

Secara umum, setiap soal dalam pemrograman kompetitif diselesaikan melalui dua tahap:

1. **Menemukan algoritma**, yang melibatkan keterampilan pemecahan masalah dan intuisi.
    
2. **Mengimplementasikan algoritma**, yaitu menerjemahkan algoritma ke dalam kode yang berfungsi dengan baik menggunakan keterampilan pemrograman.
    

Untuk setiap soal, kamu akan mengirimkan kode yang telah selesai ke _grader_, yaitu sistem penilai yang akan memeriksa jawaban yang dihitung oleh program kamu terhadap sejumlah _test case_ yang telah ditentukan sebelumnya.

Setiap soal biasanya memiliki **batas waktu** (umumnya 2 detik) dan **batas memori** (umumnya 256 megabyte) yang harus dipenuhi oleh programmu.

Bagi kamu yang memiliki pengalaman dalam _software development_, perlu dicatat bahwa pemrograman kompetitif sangat berbeda. Tujuannya adalah menulis program yang:

- Menghasilkan jawaban yang benar,
    
- Berjalan dengan cepat, dan
    
- Dapat diimplementasikan dengan cepat.
    

Perhatikan bahwa **tidak ada** bagian yang menyebutkan _maintainability_ (kemudahan pemeliharaan) kode. Kamu **tidak perlu repot-repot membuat dokumentasi** karena kode hanya perlu bisa dibaca oleh dirimu sendiri selama kontes berlangsung.

Namun, tetap disarankan untuk menjaga **tingkat keterbacaan minimum**, agar kamu tetap bisa memahami apa yang sedang terjadi di dalam kode.

---

```cardlink
url: https://www.youtube.com/watch?v=ueNT-w7Oluw
title: "What is Competitive Programming?"
description: "In this video, I describe what Competitive Programming is all about, including benefits like jobs from top companies!Winning Google Kickstart Round A: https:..."
host: www.youtube.com
favicon: https://www.youtube.com/s/desktop/fba944d3/img/logos/favicon_32x32.png
image: https://i.ytimg.com/vi/ueNT-w7Oluw/maxresdefault.jpg
```


```cardlink
url: https://www.youtube.com/watch?v=F4rykKLcduI
title: "Interview with a Competitive Programmer"
description: "Go to https://squarespace.com/jomatech to get a free trial and 10% off your first purchaseErrichto's channel: https://www.youtube.com/channel/UCBr_Fu6q9iHYQC..."
host: www.youtube.com
favicon: https://www.youtube.com/s/desktop/fba944d3/img/logos/favicon_32x32.png
image: https://i.ytimg.com/vi/F4rykKLcduI/hqdefault.jpg
```

- [[Competitive Programmer's Handook.pdf]]
- [[An introduction to USA computing olympiad.pdf]]
- [[Principles of Algorithmic Problem Solving.pdf]]

---
## Basketball One-on-One

Alice dan Barbara memainkan beberapa pertandingan persahabatan _one-on-one_ (satu lawan satu) setelah bekerja, dan kamu setuju untuk membantu mencatat skor mereka. Aturan permainannya sederhana:

- Setiap tembakan yang berhasil oleh seorang pemain akan memberi mereka 1 atau 2 poin;
    
- Pemain pertama yang mencapai **11 poin menang**, **dengan satu pengecualian**;
    
- Jika skor **imbang 10–10 atau lebih**, aturan sebelumnya diganti menjadi aturan **"menang dengan selisih 2 poin"**: pemain pertama yang unggul **setidaknya 2 poin** dari lawannya akan menang.
    

Contohnya, skor akhir seperti:

- 11–4
    
- 12–10
    
- 20–18  

adalah mungkin, **tapi** skor seperti 11–10 **tidak valid** (karena tidak unggul 2 poin setelah 10–10).


Setiap kali Alice atau Barbara mencetak poin, kamu mencatat:

- huruf **A** atau **B** (menunjukkan siapa yang mencetak poin),
    
- diikuti dengan angka **1** atau **2** (jumlah poin yang dicetak).
    

Kamu memiliki beberapa catatan pertandingan dalam format ini, tetapi tidak ingat siapa yang memenangkan tiap pertandingan. Dapatkah kamu menentukan siapa pemenangnya dari catatan pertandingan?

### Input

Input terdiri dari satu baris dengan **tidak lebih dari 100 karakter**: catatan dari satu pertandingan.  

Catatan tersebut terdiri dari huruf (A atau B) yang bergantian dengan angka (1 atau 2), dan **tidak mengandung spasi atau karakter lain**.  

Setiap catatan merupakan riwayat skor yang valid dari satu pertandingan yang telah selesai, sesuai dengan aturan di atas.

### Output

Cetak satu karakter saja, yaitu **A** atau **B**: pemenang dari pertandingan yang dicatat.

---
### Penyelesaian

Sekilas penyelesaian semacam ini muncul dikepalamu:

```cpp
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    string s; cin >> s;
    int A=0, B=0;
    char win;
    
    for(int i=0; i<s.length(); i++){
        if(s[i]=='A'){
            A+=s[i+1]-'0';
            i++;
        } else if(s[i]=='B'){
            B+=s[i+1]-'0';
            i++;
        }
        
        if(max(A,B)>=11 && abs(A-B)>=2){
            win = (A>B? 'A':'B');
            break;
        } 
    }
    
    cout << win << endl;
    return 0;
}
```

Padahal, sebenarnya penyelesaian dari soal ini sangatlah mudah, kita cukup tahu bahwa ketika permainan sudah terdapat pemenang, maka permainan berakhir. Artinya cukup cetak siapa pemain terakhir yang mencetak angka:

```cpp
#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	cout << s[s.size() - 2];
}
```

---
## USACO

USA Computing Olympiad (USACO) adalah kompetisi pemrograman tingkat nasional di Amerika Serikat yang diselenggarakan empat kali setahun, yaitu pada bulan Desember, Januari, Februari, dan US Open (Maret).

- Kontes reguler berlangsung selama 4 jam, sedangkan US Open berlangsung selama 5 jam.
    
- Setiap kontes terdiri dari tiga soal.
    
- Solusi akan dievaluasi dan diberi skor berdasarkan serangkaian _test case_ yang telah ditentukan sebelumnya.
    
- Skor maksimal adalah 1000 poin, dengan setiap soal memiliki bobot yang sama (sekitar 333 poin).
    

Terdapat empat divisi dalam kontes USACO:

- Bronze

- Silver
    
- Gold
    
- Platinum
    

Setelah setiap kontes, peserta yang memenuhi ambang batas (_cutoff_) tertentu — yang berbeda-beda tergantung kontes — akan dipromosikan ke divisi berikutnya pada kontes mendatang.

👉 Lihat [USACO FAQ](https://usaco.org/index.php?page=faq) untuk informasi lebih lanjut.
