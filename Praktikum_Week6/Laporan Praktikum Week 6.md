## 1. Nama, NIM, Kelas
- **Nama**: Ichya Ulumiddiin
- **NIM**: 103112400076
- **Kelas**: Teknik Informatika 12-05

## 2. Motivasi Belajar Struktur Data

Belajar struktur data itu sebenarnya bukan cuma soal menghafal teori atau koding semata, tapi tentang melatih cara berpikir kita supaya lebih runtut, efisien, dan logis. Bayangkan saja kalau data itu seperti barang di gudang kalau ditata sembarangan pasti susah dicari, tapi kalau disusun pakai sistem, semua jadi cepat, mudah, dan teratur. Dengan menguasai struktur data, kita jadi punya bekal penting buat menyelesaikan masalah dalam pemrograman maupun kehidupan sehari-hari, karena pola pikirnya terbawa untuk mencari solusi paling efektif. Jadi, meskipun kadang terasa rumit di awal, anggap saja setiap materi adalah investasi kecil yang nantinya bikin kita lebih siap menghadapi tantangan di dunia teknologi.

## 3. Dasar Teori

Struktur data adalah cara untuk menyimpan dan mengorganisir data dalam komputer agar dapat digunakan secara efisien. Berikut adalah teori dasar mengenai **Stack**:

Materi yang dibahas dalam kode-kode ini adalah tentang **Stack** (Tumpukan), yang merupakan salah satu bentuk _Abstract Data Type_ (ADT) linear. Konsep fundamental dari stack adalah prinsip **LIFO (Last-In, First-Out)**. Gampangnya, LIFO ini bisa diibaratkan kayak tumpukan piring; piring yang terakhir ditaruh di tumpukan paling atas (Last-In) adalah piring yang akan pertama kali diambil (First-Out). Elemen data hanya bisa ditambah (dimasukkan) dan diambil (dihapus) dari satu ujung yang sama, yang biasa disebut sebagai **TOP** (puncak) dari stack.

Implementasi stack yang digunakan dalam materi kali ini adalah **Static Array Implementation** (atau alokasi kontigu/sekuensial). Dalam implementasi ini, sebuah array dengan ukuran yang tetap (didefinisikan sebagai `MaxEl` di `stack.h`) dialokasikan di memori untuk menyimpan elemen-elemen stack. Sebuah variabel integer, yaitu `TOP`, digunakan sebagai _marker_ atau penanda untuk melacak indeks dari elemen teratas. Ketika stack kosong, `TOP` diatur ke nilai `Nil` (yaitu -1). Sebaliknya, stack dianggap penuh (`IsFull`) ketika `TOP` telah mencapai indeks maksimum array (`MaxEl - 1`).

Selain operasi dasar, kode ini juga mendemonstrasikan algoritma-algoritma yang menggunakan stack. Contohnya adalah fungsi **`balikStack`**, yang menunjukkan salah satu kegunaan klasik stack, yaitu untuk membalik urutan elemen. Algoritma ini bekerja dengan cara mem-`Pop` semua elemen dari stack utama dan mem-`Push`-nya ke sebuah stack bantu (temporary). Hasilnya, elemen-elemen di stack bantu akan memiliki urutan yang terbalik dari stack aslinya. Ada pula fungsi **`pushAscending`** yang menunjukkan manipulasi stack lebih lanjut, di mana elemen dimasukkan sedemikian rupa sehingga isi stack tetap terurut (dalam kasus ini, terurut _descending_ dari TOP ke bawah) dengan bantuan stack temporary.
## 4. Guided
### 4.1 Guided 1

![[stackH.png]]

**Penjelasan**:

`stack.h` pada dasarnya berfungsi sebagai _header file_ atau "cetak biru" yang mendefinisikan struktur data dan prototipe fungsi untuk Tumpukan (Stack). Fungsinya adalah sebagai kontrak atau antarmuka yang memberi tahu file `.cpp` lain (seperti `stack.cpp` dan `main.cpp`) tentang apa saja yang tersedia. Di bagian awal, terdapat _header guard_ (`#ifndef`, `#define`, `#endif`) yang krusial untuk mencegah error "redeclaration" jika file ini di-_include_ lebih dari satu kali. File ini kemudian mendefinisikan beberapa konstanta penting menggunakan `#define`: `MaxEl` (di-set ke 20) yang menentukan kapasitas maksimum array stack, menjadikannya implementasi stack statis, dan `Nil` (di-set ke -1) yang digunakan sebagai nilai penanda untuk `TOP` saat stack dalam keadaan kosong. Selanjutnya, `typedef int infotype` digunakan untuk membuat alias tipe data, sehingga jika di masa depan tipe data yang disimpan stack perlu diubah (misalnya dari `int` ke `float`), perubahan hanya perlu dilakukan di satu baris ini. Inti dari file ini adalah deklarasi `struct Stack`, yang membungkus dua komponen utama: `infotype info[MaxEl]`, yaitu array statis sebagai "wadah" penyimpan data, dan `int TOP`, sebuah variabel integer yang berfungsi sebagai penanda (marker) untuk melacak indeks elemen teratas stack. Terakhir, file ini mendaftarkan semua prototipe fungsi (deklarasi) yang akan diimplementasikan di `stack.cpp`. Ini mencakup fungsi-fungsi dasar seperti `CreateStack`, `IsEmpty`, `IsFull`, `Push`, `Pop`, dan `printInfo`, serta fungsi tambahan yang lebih spesifik seperti `balikStack`, `pushAscending`, dan `getInputStream`.

### 4.2 Guided 2

![[stackCPP.png]]

**Penjelasan**:

`stack.cpp` adalah file implementasi yang berisi "dapur" atau definisi kode aktual dari semua fungsi yang telah dideklarasikan dalam `stack.h`. Ini dimulai dengan meng-`include "stack.h"` agar ia mengenali struktur `Stack`, konstanta `MaxEl` dan `Nil`, serta `infotype`, dan juga meng-`include <iostream>` untuk kebutuhan _input-output_ (seperti `cout`). Di dalamnya, setiap prototipe fungsi diwujudkan: **`CreateStack`** menginisialisasi tumpukan dengan mengatur `S.TOP = Nil`. Fungsi boolean **`IsEmpty`** dan **`IsFull`** menyediakan logika pengecekan kondisi, masing-masing mengembalikan `true` jika `S.TOP == Nil` atau jika `S.TOP == MaxEl - 1`. Operasi inti, **`Push`**, pertama-tama memeriksa apakah stack tidak penuh; jika ya, ia akan menaikkan (inkremen) `S.TOP` (atau mengaturnya ke 0 jika ini adalah elemen pertama) sebelum menempatkan elemen baru `X` ke `S.info[S.TOP]`. Sebaliknya, **`Pop`** memeriksa apakah stack tidak kosong, lalu mengambil elemen di `S.info[S.TOP]`, menurunkan (dekrementasi) `S.TOP`, dan mengembalikan elemen yang diambil tersebut (atau mengembalikan -999 jika kosong). Fungsi **`printInfo`** digunakan untuk visualisasi, mencetak "Stack kosong" atau melakukan _looping_ mundur dari `TOP` ke 0 untuk menampilkan semua isi stack. Selain itu, file ini mengimplementasikan fungsi-fungsi tambahan: **`balikStack`** bekerja dengan membuat `Stack temp`, memindahkan semua elemen dari `S` ke `temp` (menggunakan `Pop` dari `S` dan `Push` ke `temp`), yang secara alami membalik urutan, lalu menyalin `temp` kembali ke `S`. Fungsi **`pushAscending`** adalah algoritma sisip terurut (insertion sort) yang menggunakan `Stack temp` untuk mem-`Pop` sementara elemen-elemen yang lebih kecil dari `X`, lalu mem-`Push` `X` ke `S`, dan akhirnya mengembalikan elemen-elemen dari `temp` kembali ke atas `S`, memastikan stack tetap terurut menaik (dari atas ke bawah). Terakhir, **`getInputStream`** adalah fungsi _helper_ yang membaca satu baris masukan dari pengguna sebagai _string_, lalu mengiterasi setiap karakter, mengubah digit (seperti '4') menjadi angka (`int` 4), dan mem-`Push` setiap digit satu per satu ke dalam stack.

### 4.3 Guided 3

![[mainCPP.png]]

**Penjelasan**:

File `main.cpp` ini pada dasarnya adalah **program utama** atau _driver_ yang tugasnya adalah "memakai" atau "menguji" struktur data Stack yang sudah kita definisikan di `stack.h` dan `stack.cpp`. Dia meng-`include "stack.h"` supaya bisa mengenali `struct Stack` dan semua fungsinya, dan juga meng-`include <iostream>` untuk bisa menggunakan `cout` (mencetak ke layar). Di dalam fungsi `int main()`, program ini pertama-tama mendeklarasikan sebuah variabel stack bernama `S`, lalu langsung menginisialisasinya dengan memanggil `CreateStack(S)`. Inti dari file ini adalah sebagai skenario pengujian, di mana ia melakukan serangkaian operasi `Push` dan `Pop` secara spesifik: `Push(3)`, `Push(4)`, `Push(8)`, `Pop()`, `Push(2)`, `Push(3)`, `Pop()`, dan terakhir `Push(9)`. Setelah tumpukan `S` terisi dengan urutan tersebut, program mencetak label "Stack sebelum dibalik:" dan memanggil `printInfo(S)` untuk menunjukkan isi stack saat itu. Kemudian, program ini menguji fungsionalitas utama yaitu `balikStack(S)`, yang akan membalik urutan semua elemen di dalam `S`. Sebagai pembuktian, program lalu mencetak label "Stack sesudah dibalik:" dan memanggil `printInfo(S)` sekali lagi, sehingga kita bisa membandingkan kondisi sebelum dan sesudah stack dibalik.

**Hasil Output main.cpp**:

![[Pasted image 20251101114822.png]]

## 5. Unguided
### 5.1 Unguided 1

![[Ungu1.png]]

**Penjelasan**:

`Unguided1.cpp` ini sebenernya punya fungsi yang **hampir 100% identik** dengan file `main.cpp`. Dia juga berperan sebagai _driver_ atau program utama untuk menguji fungsionalitas dari `Stack` yang kita buat. Sama seperti `main.cpp`, file ini meng-`include "stack.h"` dan `<iostream>`. Di dalam fungsi `int main()`, hal pertama yang dilakuin adalah mencetak "Hello World!" ke layar, yang jadi satu-satunya pembeda kecil dari `main.cpp`. Setelah itu, semua langkahnya sama persis: dia mendeklarasikan `Stack S`, memanggil `CreateStack(S)`, lalu menjalankan urutan operasi yang sama persis: `Push(3)`, `Push(4)`, `Push(8)`, `Pop()`, `Push(2)`, `Push(3)`, `Pop()`, dan `Push(9)`. Program ini juga mencetak isi stack "sebelum dibalik", memanggil fungsi `balikStack(S)`, dan terakhir mencetak isi stack lagi "sesudah dibalik" untuk menunjukkan bahwa urutannya telah berhasil dibalik.

**Output**:

![[Pasted image 20251101115304.png]]

### 5.2 Unguided 2

![[Ungu2.png]]

**Penjelasan**:

`Unguided2.cpp` ini juga bertindak sebagai program _driver_ (program utama), tapi kali ini tujuannya adalah untuk menguji secara spesifik fungsi `pushAscending`. Setelah meng-`include` `stack.h` dan `iostream`, di dalam `main`, program ini membuat `Stack S` dan menginisialisasinya. Berbeda dari file _driver_ sebelumnya, file ini tidak menggunakan `Push` biasa, melainkan memanggil `pushAscending` secara berurutan dengan nilai 3, 4, 8, 2, 3, dan 9. Ini adalah skenario pengujian untuk melihat bagaimana fungsi tersebut menangani penyisipan elemen agar tumpukan tetap terurut (sesuai logika di `stack.cpp`). Setelah semua nilai dimasukkan, `printInfo(S)` dipanggil untuk menampilkan hasil dari proses `pushAscending`. Sebagai tambahan, program ini kemudian juga menguji fungsi `balikStack(S)` pada tumpukan yang sudah terurut tadi, dan mencetak hasilnya lagi.

**Output**:

![[Pasted image 20251101115733.png]]

### 5.3 Unguided 3

![[Ungu3.png]]

**Penjelasan**:

`Unguided3.cpp` ini adalah program _driver_ yang fokus utamanya adalah untuk menguji fungsionalitas `getInputStream(S)`. Sama seperti yang lain, dia meng-`include` `stack.h` dan `iostream`. Di dalam `main`, setelah membuat dan menginisialisasi `Stack S`, program ini langsung memanggil `getInputStream(S)`. Ini artinya, program akan berhenti sejenak dan meminta pengguna untuk mengetikkan serangkaian angka, yang kemudian akan diproses dan dimasukkan ke dalam stack oleh fungsi tersebut. Setelah stack terisi sesuai input pengguna, program memanggil `printInfo(S)` untuk menampilkan hasilnya. Sebagai langkah pengujian tambahan, program ini kemudian memanggil `balikStack(S)` untuk membalik isi stack yang baru saja diinput oleh pengguna, dan mencetaknya lagi dengan `printInfo(S)` untuk menunjukkan kondisi stack setelah dibalik.

**Output**:

![[Pasted image 20251101120811.png]]

## 6. Kesimpulan

Secara keseluruhan, keenam codingan tersebut menyajikan satu paket lengkap yang mendemonstrasikan definisi, implementasi, dan pengujian dari struktur data **Stack (Tumpukan) statis** berbasis array. Strukturnya terbagi jelas: `stack.h` bertindak sebagai _interface_ atau "cetak biru" yang mendefinisikan `struct Stack` (terdiri dari array `info[MaxEl]` dan `int TOP`) serta mendeklarasikan semua prototipe fungsi. Kemudian, `stack.cpp` bertindak sebagai file implementasi yang berisi kode logika aktual untuk semua fungsi tersebut, mulai dari operasi dasar (`Push`, `Pop`, `IsEmpty`, `IsFull`) hingga fungsi-fungsi utilitas yang lebih kompleks (`balikStack`, `pushAscending`, `getInputStream`). Empat file sisanya (`main.cpp`, `Unguided1.cpp`, `Unguided2.cpp`, `Unguided3.cpp`) adalah program _driver_ atau penguji yang masing-masing memiliki skenario spesifik: `main.cpp` dan `Unguided1.cpp` menguji urutan dasar `Push`/`Pop` dan fungsi `balikStack`, `Unguided2.cpp` secara khusus menguji fungsionalitas `pushAscending`, dan `Unguided3.cpp` secara khusus menguji fungsionalitas `getInputStream`.

## 7. Referensi

1. Fathurrozi, M., & WN, H. (2024). Application of Stack Data Structure in Application Development. _JASIC (Journal of Applied Science, Informatics, and Computing)_, _2_(1), 1-8.
2. Mak, T., & Mitrović, S. (2024). Execution Efficiency of the use of Array and Linked-List Implementations of a Stack Abstract Data Types... in Methods of an Android Application. _TEM Journal_, _13_(2), 1618–1632.
3. Novikov, E., Glushkov, A., & Ignatev, D. (2021). Technology Stack Selection Model for Software Design of Digital Platforms. _Mathematics_, _9_(4), 308.
4. Setiyawan, D., & Simarmata, E. P. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. _JUTECH : Journal Education and Technology_, _3_(2), 116-123.