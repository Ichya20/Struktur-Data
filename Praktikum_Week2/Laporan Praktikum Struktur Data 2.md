
## 1. Nama, NIM, Kelas

- **Nama**: Ichya Ulumiddiin

- **NIM**: 103112400076

- **Kelas**: 12-IF-05

  
## 2. Motivasi Belajar Struktur Data

Belajar struktur data itu sebenarnya bukan cuma soal menghafal teori atau koding semata, tapi tentang melatih cara berpikir kita supaya lebih runtut, efisien, dan logis. Bayangkan saja kalau data itu seperti barang di gudang kalau ditata sembarangan pasti susah dicari, tapi kalau disusun pakai sistem, semua jadi cepat, mudah, dan teratur. Dengan menguasai struktur data, kita jadi punya bekal penting buat menyelesaikan masalah dalam pemrograman maupun kehidupan sehari-hari, karena pola pikirnya terbawa untuk mencari solusi paling efektif. Jadi, meskipun kadang terasa rumit di awal, anggap saja setiap materi adalah investasi kecil yang nantinya bikin kita lebih siap menghadapi tantangan di dunia teknologi.


## 3. Dasar Teori

Struktur data adalah cara untuk menyimpan dan mengorganisir data dalam komputer agar dapat digunakan secara efisien. Berikut adalah teori dasar mengenai Array, Pointer, dan Fungsi:

- **Konsep Array dan Pengolahan Data**
	Array merupakan struktur data yang berfungsi menyimpan sekumpulan nilai dengan tipe yang sama dalam satu variabel. Dalam C++, elemen array disimpan secara berurutan di memori, sehingga dapat diakses dengan indeks tertentu seperti `arr[i]`. Penggunaan array mempermudah pengolahan data dalam jumlah banyak, misalnya menyimpan stok buku atau nilai siswa. _“Struktur array menjadi dasar penting dalam pengelolaan data karena memungkinkan penyimpanan dan pemrosesan informasi secara efisien serta terorganisir”_ (Kusuma & Rahmadani, 2023).

- **Pointer dan Manipulasi Memori**
	Pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Dengan pointer, program dapat mengakses dan mengubah nilai variabel secara langsung melalui alamatnya, bukan salinannya. Hal ini meningkatkan efisiensi dan fleksibilitas dalam pengolahan data. Contohnya pada program diskon harga dan stok buku, pointer digunakan untuk memodifikasi nilai asli tanpa menyalin data. _“Pemahaman konsep pointer menjadi landasan dalam memahami cara kerja memori komputer serta efisiensi manipulasi data pada bahasa C dan C++”_ (Santoso & Wirawan, 2022).
	
- **Fungsi dan Parameter Referensi**
	Fungsi dalam C++ digunakan untuk memecah program menjadi bagian-bagian kecil yang dapat digunakan kembali. Salah satu konsep pentingnya adalah _pass by reference_, yaitu ketika variabel dikirim ke fungsi bukan sebagai salinan, tetapi sebagai referensi ke variabel asli. Dengan begitu, perubahan di dalam fungsi langsung mempengaruhi data aslinya. _“Penggunaan parameter referensi dalam fungsi memungkinkan efisiensi pemrosesan data dan mendukung prinsip modularitas dalam pemrograman”_ (Putri & Nugroho, 2021).

## 4. Guided

### 4.1 Guided 1

c:\Users\ICHYA ULUMIDDIN\OneDrive\Pictures\code.png

  **Penjelasan :**
	  Program itu digunakan untuk menampilkan laporan berapa banyak buku yang dibaca selama seminggu. Data jumlah buku tiap hari disimpan di dalam array `bukuPerHari`, lalu program menampilkan hasilnya satu per satu mulai dari hari ke-1 sampai hari ke-7. Selain itu, program juga menghitung total semua buku yang dibaca dalam seminggu, tapi hasil totalnya belum ditampilkan karena tidak ada perintah `cout` untuk mencetaknya.
	  
**Output** :

c:\Users\ICHYA ULUMIDDIN\OneDrive\Pictures\Screenshots\Screenshot 2025-10-04 175845.png

### 4.2 Guided 2

c:\Users\ICHYA ULUMIDDIN\OneDrive\Pictures\code 2.png

**Penjelasan :**
	Program ini berfungsi untuk menampilkan harga sebuah produk dan memberikan diskon 10% dengan bantuan pointer. Pertama, variabel `hargaProduk` menyimpan harga awal produk sebesar 50.000. Lalu, dibuat pointer `ptrHarga` yang menyimpan alamat memori dari variabel `hargaProduk` menggunakan tanda `&`. Program kemudian menampilkan harga awal dan alamat memorinya di layar. Setelah itu, pointer digunakan untuk mengubah nilai `hargaProduk` secara langsung dengan rumus `*ptrHarga = *ptrHarga * 0.9`, yang berarti harga dikalikan 0.9 (atau diskon 10%). Karena pointer menunjuk langsung ke variabel aslinya, maka nilai `hargaProduk` ikut berubah. Terakhir, program menampilkan harga produk setelah diskon diterapkan.

**Output :**

c:\Users\ICHYA ULUMIDDIN\OneDrive\Pictures\Screenshots\Screenshot 2025-10-04 180128.png

### 4.3 Guided 3

c:\Users\ICHYA ULUMIDDIN\OneDrive\Pictures\code 3.png

**Penjelasan :**
	Program ini digunakan untuk menghitung dan menampilkan nilai seorang siswa sebelum dan sesudah mendapat bonus. Pertama, fungsi `hitungRataRata()` menghitung nilai rata-rata dari nilai tugas dan UTS dengan rumus `(nilaiTugas + nilaiUts) / 2.0f`. Lalu, fungsi `cetakProfil()` digunakan untuk menampilkan nama siswa dan nilainya ke layar. Fungsi `beriNilaiBonus()` menambah nilai siswa sebesar 5 menggunakan parameter referensi (`float& nilai`), sehingga perubahan nilainya langsung memengaruhi variabel asli. Di dalam fungsi `main()`, nama siswa diset ke "Budi" dengan nilai tugas 80 dan UTS 90. Program menghitung nilai rata-rata, menampilkan profil awal, kemudian memberikan bonus 5 poin, dan terakhir menampilkan profil siswa setelah mendapatkan bonus. 

**Output :**

c:\Users\ICHYA ULUMIDDIN\OneDrive\Pictures\Screenshots\Screenshot 2025-10-04 180514.png

## 5. Unguided

### 5.1 Unguided 1

c:\Users\ICHYA ULUMIDDIN\OneDrive\Pictures\code 4.png

**Penjelasan :**
	Program ini digunakan untuk mengelola data stok buku menggunakan array dan pointer. Fungsi `cetakStok()` menampilkan seluruh isi array stok buku dengan format yang rapi. Fungsi `hitungTotalStok()` menjumlahkan semua elemen dalam array untuk mengetahui total stok buku yang tersedia. Fungsi `cariStokPalingSedikit()` mencari nilai stok paling sedikit dengan membandingkan tiap elemen array dan mengembalikan alamat memorinya menggunakan pointer. Fungsi `tambahStokBonus()` kemudian menambahkan stok sebanyak 10 pada buku dengan stok paling sedikit menggunakan pointer tersebut. Di bagian `main()`, program menyimpan data awal stok buku dalam array `stokBuku`, menampilkan stok awal, menghitung total stok, mencari buku dengan stok terendah, menambah bonus stok pada buku tersebut, lalu menampilkan hasil akhir setelah penambahan stok dilakukan.

**Output :**

c:\Users\ICHYA ULUMIDDIN\OneDrive\Pictures\Screenshots\Screenshot 2025-10-04 180716.png

## 6. Kesimpulan

Berdasarkan pembahasan berbagai program C++, dapat disimpulkan bahwa pemahaman terhadap konsep dasar seperti **array, pointer, fungsi, referensi**, dan **operasi aritmetika** merupakan fondasi penting dalam pemrograman tingkat lanjut. Array digunakan untuk menyimpan dan mengelola sekumpulan data secara efisien, sementara pointer memberikan kemampuan bagi programmer untuk mengakses dan memodifikasi data langsung melalui alamat memori, sehingga meningkatkan efisiensi dan fleksibilitas program. Penggunaan parameter referensi dalam fungsi memperkuat prinsip _modular programming_ dengan memungkinkan perubahan nilai variabel secara langsung tanpa perlu menyalin data. Selain itu, operasi aritmetika pada tipe data numerik seperti _float_ mendukung perhitungan yang lebih presisi dan akurat. Dengan memahami dan menguasai konsep-konsep tersebut, seorang programmer dapat membangun program yang tidak hanya efisien dan terstruktur, tetapi juga mampu menangani permasalahan komputasi yang lebih kompleks secara optimal.


## 7. Referensi

1. Kusuma, A. P., & Rahmadani, D. (2023). _Implementasi Struktur Data Array dalam Efisiensi Pengolahan Data pada Bahasa Pemrograman C++_. Jurnal Teknologi dan Informatika, 9(2), 115–124.

2. Santoso, R., & Wirawan, T. (2022). _Analisis Pemanfaatan Pointer untuk Efisiensi Memori dalam Bahasa Pemrograman C++_. Jurnal Ilmiah Informatika dan Komputer, 7(1), 45–53.

3. Putri, S. D., & Nugroho, B. (2021). _Studi Penggunaan Parameter Referensi pada Pemrograman Berorientasi Prosedural di C++_. Jurnal Riset Sistem Informasi dan Teknologi, 6(3), 210–218.