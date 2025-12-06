## 1. Nama, NIM, Kelas
- **Nama**: Ichya Ulumiddiin
- **NIM**: 103112400076
- **Kelas**: Teknik Informatika 12-05

## 2. Motivasi Belajar Struktur Data

Belajar struktur data itu sebenarnya bukan cuma soal menghafal teori atau koding semata, tapi tentang melatih cara berpikir kita supaya lebih runtut, efisien, dan logis. Bayangkan saja kalau data itu seperti barang di gudang kalau ditata sembarangan pasti susah dicari, tapi kalau disusun pakai sistem, semua jadi cepat, mudah, dan teratur. Dengan menguasai struktur data, kita jadi punya bekal penting buat menyelesaikan masalah dalam pemrograman maupun kehidupan sehari-hari, karena pola pikirnya terbawa untuk mencari solusi paling efektif. Jadi, meskipun kadang terasa rumit di awal, anggap saja setiap materi adalah investasi kecil yang nantinya bikin kita lebih siap menghadapi tantangan di dunia teknologi.

## 3. Dasar Teori

Struktur data adalah cara untuk menyimpan dan mengorganisir data dalam komputer agar dapat digunakan secara efisien. Berikut adalah teori dasar mengenai **Multi Linked List dan Circular Linked List**:

**Multi Linked List** merupakan struktur data dinamis yang terdiri dari sekumpulan list yang berbeda namun memiliki keterhubungan satu sama lain. Dalam implementasi studi kasus data Pegawai, struktur ini memodelkan hubungan hierarkis di mana elemen pada **List Induk (Pegawai)** bertindak sebagai parent yang memiliki pointer khusus untuk menunjuk ke **List Anak.** Hal ini memungkinkan setiap simpul pada List Induk untuk memiliki daftar elemen anaknya sendiri secara independen. Secara teknis, implementasi ini menggunakan struktur *Doubly Linked List* baik untuk induk maupun anak, ditandai dengan adanya pointer next dan prev yang memungkinkan penelusuran data dilakukan dua arah (maju dan mundur). Operasi pada Multi Linked List memiliki aturan ketergantungan yang ketat; misalnya, saat melakukan penghapusan elemen induk, maka seluruh elemen anak yang berelasi dengan induk tersebut juga harus dihapus secara otomatis.

Sementara itu, **Circular Linked List** adalah variasi dari linked list di mana elemen terakhir (Last) tidak menunjuk ke NULL sebagai penanda akhir, melainkan kembali menunjuk ke elemen pertama (First), sehingga membentuk siklus tertutup atau lingkaran. Struktur ini diterapkan pada studi kasus data Mahasiswa yang menyimpan informasi Nama, NIM, Jenis Kelamin, dan IPK. Berbeda dengan list linear biasa, penelusuran pada *Circular List* tidak memiliki ujung mati; iterasi elemen dilakukan dengan memeriksa apakah pointer next dari simpul saat ini telah kembali ke alamat elemen pertama. Hal ini sangat berguna untuk aplikasi yang membutuhkan perputaran data yang terus-menerus tanpa perlu mereset pointer ke awal secara manual.

## 4. Guided
### 4.1 Guided 1



**Penjelasan**:

**File multilist.h** bertindak sebagai antarmuka utama yang mendefinisikan kerangka kerja struktur data Multi Linked List, dimulai dengan penggunaan header guards dan definisi tipe data untuk menjamin konsistensi penamaan di seluruh program. Inti dari file ini terletak pada pendefinisian empat struct utama, yaitu struct `elemen_anak` dan struct `list_anak` sebagai sub-list, serta struct `elemen_induk` yang dirancang unik karena memiliki field khusus bertipe `list_anak`, sehingga menciptakan hubungan hierarkis di mana setiap simpul induk secara otomatis "menggendong" list anaknya sendiri. Seluruh struktur ini kemudian dikelola oleh struct `list_induk` dan didukung oleh serangkaian deklarasi prototipe fungsi atau ADT (Abstract Data Type) yang mencakup manajemen memori, operasi dasar pembuatan list, hingga manipulasi data seperti insert, delete, dan search, yang memungkinkan logika program antara data Induk dan Anak dapat diimplementasikan secara modular namun tetap terintegrasi.

### 4.2 Guided 2



**Penjelasan**:

**File multilist.cpp** merupakan unit implementasi utama yang berisi logika operasional untuk manajemen List Induk dalam struktur Multi Linked List. Di dalamnya terdapat realisasi teknis dari fungsi-fungsi primitif, dimulai dari fungsi alokasi yang bertugas memesan memori untuk elemen induk sekaligus menginisialisasi pointer list anak di dalamnya agar siap digunakan (set NULL). File ini menangani seluruh manipulasi data pada level induk menggunakan algoritma Doubly Linked List standar seperti pengaturan pointer `next` dan `prev` pada prosedur `insert` dan `delete` serta menyediakan fungsi printInfo yang menerapkan logika perulangan bersarang `(nested loop)` untuk menelusuri setiap node induk dan kemudian mengakses sub-list anaknya guna menampilkan seluruh hierarki data secara terstruktur.

### 4.3 Guided 3



**Penjelasan**:

**File multilist_anak.cpp** berperan sebagai modul spesifik yang menangani seluruh operasi manajemen data pada level sub-list atau List Anak, memisahkannya dari logika utama List Induk agar kode lebih terstruktur. Di dalamnya terdapat implementasi teknis untuk alokasi memori `(alokasiAnak)` guna membentuk node anak baru, serta serangkaian prosedur manipulasi data meliputi penambahan `(insert)` dan penghapusan `(delete)` elemen di posisi awal maupun akhir list. Seluruh operasi dalam file ini bekerja berdasarkan mekanisme Doubly Linked List, memanfaatkan pointer `next` dan `prev` untuk menghubungkan antar elemen anak, sehingga pengelolaan data bawahan dapat dilakukan secara dinamis dan independen sebelum nantinya dihubungkan ke induk yang relevan.

### 4.4 Guided 4



**Penjelasan**:

**File main.cpp** bertindak sebagai program penggerak utama `(driver code)` yang berfungsi untuk menguji integrasi dan fungsionalitas dari struktur data Multi Linked List yang telah didefinisikan sebelumnya. Di dalam file ini, struktur list induk diinisialisasi terlebih dahulu, diikuti dengan alokasi memori untuk menciptakan beberapa node induk dan node anak. Poin krusial dalam file ini adalah demonstrasi pembentukan relasi hierarkis, di mana node-node anak disisipkan secara spesifik ke dalam field list anak milik pointer induk tertentu (misalnya menggunakan P1->anak), membuktikan bahwa setiap induk dapat menampung sub-list data yang berbeda secara independen sebelum akhirnya seluruh struktur data ditampilkan ke layar untuk verifikasi .

**Output**:



## 5. Unguided
### 5.1 Unguided 1



**Penjelasan**:

**Langkah pertama** dalam program ini adalah persiapan struktur data. Program dimulai dengan mendeklarasikan variabel `list_induk` dan memanggil prosedur createList untuk menginisialisasi pointer first dan last menjadi NULL. Hal ini memastikan bahwa wadah utama untuk menampung data pegawai (induk) sudah siap dalam keadaan kosong dan bersih sebelum ada data yang dimasukkan.

**Langkah kedua** adalah pengisian data Induk (Pegawai). Program mengalokasikan memori untuk membuat node-node induk baru dan memasukkannya ke dalam list menggunakan variasi fungsi yang berbeda, yaitu `insertFirstInduk`, `insertLastInduk`, dan `insertAfterInduk`. Tujuannya adalah untuk menguji apakah pointer list induk mampu menangani penambahan data di posisi awal, akhir, maupun di tengah-tengah antrean secara tepat tanpa memutus rantai data.

**Langkah ketiga** adalah pembentukan relasi hierarkis (Data Anak). Pada tahap ini, program tidak hanya membuat data anak, tetapi secara spesifik "menyuntikkan" data tersebut ke dalam sub-list milik induk tertentu. Misalnya, program mengakses node Induk 1, lalu menggunakan fungsi insertLastAnak untuk menambahkan data anak ke dalamnya. Proses ini membuktikan bahwa setiap node induk benar-benar memiliki gerbong list anaknya sendiri yang terpisah dari induk lainnya.

**Langkah keempat** adalah validasi visual tahap awal. Setelah semua data dimasukkan, program memanggil fungsi `printInfo` untuk menampilkan seluruh hierarki data ke layar. Langkah ini berfungsi untuk memverifikasi bahwa data induk sudah tersusun urut dan setiap induk menampilkan daftar anak yang sesuai dengan yang telah diinputkan sebelumnya.

**Langkah terakhir** adalah pengujian penghapusan data (Delete). Program mensimulasikan skenario penghapusan dengan memanggil fungsi `deleteLastAnak` pada salah satu induk. Setelah penghapusan dilakukan, `printInfo` dipanggil kembali untuk memastikan bahwa data anak yang dihapus benar-benar hilang dari memori, sementara data induk dan data anak lainnya tetap aman dan tidak terganggu

**Output**:



### 5.2 Unguided 2
**Circular.h**



**Penjelasan**:

**File circular.h** ibarat cetak biru atau resep utama untuk program Circular List data Mahasiswa. Di bagian pertamanya, file ini menyiapkan wadah khusus yang membungkus semua identitas mahasiswa seperti `Nama`, `NIM`, `Jenis Kelamin`, dan `IPK` menjadi satu paket lengkap agar tidak tercecer. Selain itu, bagian ini juga menyiapkan bentuk "gerbong" data yang punya penghubung ke data berikutnya, serta menyiapkan pintu masuk utama bernama first agar program tahu dari mana harus mulai membaca lingkaran data tersebut .

Bagian kedua file ini berisi daftar menu atau perintah apa saja yang bisa dilakukan oleh program, tanpa perlu menuliskan detail rumitnya di sini. Di sini didaftarkan perintah-perintah penting seperti cara membuat list baru, cara memesan tempat untuk data baru, hingga cara menambah dan menghapus data mahasiswa baik di urutan pertama, terakhir, maupun di tengah-tengah. Dengan adanya daftar ini, bagian lain dari program bisa langsung memanggil fitur seperti pencarian NIM atau pencetakan data tanpa perlu bingung memikirkan bagaimana cara kerjanya di balik layar.

**Circular.cpp**



**Penjelasan**:

**File circular.cpp** berisi "otak" atau kode program sebenarnya yang menjalankan semua perintah yang sudah didaftarkan di file header tadi. Di sini dituliskan langkah-langkah detail, mulai dari menyiapkan list kosong hingga logika rumit saat menambahkan data baru. Poin paling penting di file ini adalah cara program menjaga agar data tetap melingkar; setiap kali ada data baru yang ditambahkan (baik di depan maupun belakang), program akan otomatis mengatur agar data paling akhir selalu kembali menunjuk ke data pertama, sehingga lingkarannya tidak pernah terputus.

Bagian selanjutnya mengatur bagaimana cara menghapus dan menampilkan data agar tidak berantakan. Saat menghapus data (terutama data pertama), program akan cerdas mencari data paling belakang untuk memberitahu bahwa "ketua barisan" sudah ganti, supaya lingkaran tetap tersambung rapi. Selain itu, fitur `printInfo` di sini dibuat khusus menggunakan teknik perulangan yang akan berjalan mengelilingi lingkaran tepat satu putaran penuh, sehingga semua nama mahasiswa bisa tampil di layar tanpa menyebabkan program berputar-putar selamanya tanpa henti.

**Unguided2.cpp**



**Penjelasan**:

**Unguided3.cpp** berperan sebagai "pusat komando" untuk menjalankan program Circular List data mahasiswa. Langkah pertamanya adalah menyiapkan daftar kosong, lalu mulai memasukkan data mahasiswa satu per satu. Uniknya, program ini tidak memasukkan data secara sembarangan, melainkan menggunakan strategi pengurutan manual agar hasilnya nanti otomatis rapi berurutan sesuai NIM (dari 01 sampai 08) persis seperti yang diminta pada gambar soal, meskipun urutan codingnya terlihat acak .

Untuk menyusun barisan yang rapi tersebut, program ini mendemonstrasikan kecanggihan pointer dengan mencampur berbagai cara input. Ada data yang dipaksa masuk di paling depan menggunakan `insertFirst`, ada yang ditaruh di paling belakang dengan `insertLast`, dan banyak juga yang diselipkan "nyelip" di tengah-tengah antrean menggunakan `insertAfter` (misalnya menyisipkan Bobi tepat setelah Ali). Setelah semua tersusun, program memanggil perintah `printInfo` untuk menampilkan hasilnya ke layar, membuktikan bahwa lingkaran data mahasiswa sudah terbentuk sempurna tanpa putus .


## 6. Kesimpulan

Secara keseluruhan, praktikum ini melatih kita untuk membangun struktur data yang lebih canggih daripada sekadar daftar biasa. Di bagian `Multi Linked List`, kita belajar membuat data bertingkat seperti hubungan "Orang Tua dan Anak" (Pegawai), di mana setiap Pegawai punya "gerbong" daftar anaknya masing-masing yang terpisah, sehingga jika orang tuanya dihapus, data anaknya pun ikut hilang. Sementara itu, di bagian `Circular Linked List`, kita belajar membuat barisan data Mahasiswa yang "melingkar" tanpa ujung, ibarat orang-orang yang bergandengan tangan membentuk lingkaran di mana orang paling belakang langsung nyambung ke orang paling depan. Inti dari semua latihan ini adalah mengasah kemampuan logika kita dalam memainkan "pointer" untuk menyambungkan data dengan berbagai pola unik, baik itu pola bertingkat maupun pola lingkaran yang tak terputus.

## 7. Referensi

1. **Nugraha, A.S. dan Rowhari, H.**, 2019. _'Analisis Penggunaan Memori pada Implementasi Multi Linked List untuk Pemetaan Data Hierarkis'._ Jurnal Pengembangan Teknologi Informasi dan Ilmu Komputer, 3(4), pp. 340–348.
2. **Wahyuni, S. dan Purnomo, A.**, 2020. _'Implementasi Struktur Data Circular Linked List pada Sistem Penjadwalan Round Robin'._ Jurnal Teknologi Informasi dan Ilmu Komputer (JTIIK), 5(3), pp. 200–208.
3. **Santoso, L.W.**, 2021. _'Perancangan Struktur Data Dinamis Menggunakan Konsep Doubly Linked List'._ Jurnal Infra, 9(1), pp. 12–18.
