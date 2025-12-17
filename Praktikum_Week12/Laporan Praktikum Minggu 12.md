## 1. Nama, NIM, Kelas
- **Nama**: Ichya Ulumiddiin
- **NIM**: 103112400076
- **Kelas**: Teknik Informatika 12-05

## 2. Motivasi Belajar Struktur Data

Belajar struktur data itu sebenarnya bukan cuma soal menghafal teori atau koding semata, tapi tentang melatih cara berpikir kita supaya lebih runtut, efisien, dan logis. Bayangkan saja kalau data itu seperti barang di gudang kalau ditata sembarangan pasti susah dicari, tapi kalau disusun pakai sistem, semua jadi cepat, mudah, dan teratur. Dengan menguasai struktur data, kita jadi punya bekal penting buat menyelesaikan masalah dalam pemrograman maupun kehidupan sehari-hari, karena pola pikirnya terbawa untuk mencari solusi paling efektif. Jadi, meskipun kadang terasa rumit di awal, anggap saja setiap materi adalah investasi kecil yang nantinya bikin kita lebih siap menghadapi tantangan di dunia teknologi.

## 3. Dasar Teori

Struktur data adalah cara untuk menyimpan dan mengorganisir data dalam komputer agar dapat digunakan secara efisien. Berikut adalah teori dasar mengenai **Graph**:

**Graph** merupakan himpunan tidak kosong yang terdiri dari elemen node *(vertex)* dan garis penghubung *(edge)*. Konsep ini sering diilustrasikan dalam kehidupan sehari-hari, misalnya lokasi tempat kost dan laboratorium dianggap sebagai node, sementara jalan yang menghubungkan keduanya adalah edge. Dalam implementasi teknisnya, struktur node induk berisi informasi data itu sendiri, sedangkan struktur node anak atau edge menyimpan informasi berupa alamat memori *(address)* yang merujuk pada node induk atau node tujuan untuk membentuk sebuah relasi.

Berdasarkan arah hubungannya, graph dibedakan menjadi *Directed Graph* (graph berarah) dan *Undirected Graph* (graph tidak berarah). Pada graph berarah, setiap garis penghubung memiliki orientasi tertentu, sehingga jika node A terhubung ke node B, hubungan sebaliknya belum tentu berlaku; berbeda dengan graph tak-berarah di mana hubungan antar node bersifat otomatis bolak-balik tanpa arah spesifik. Representasi graph dalam memori komputer dapat dilakukan menggunakan Matriks Ketetanggaan (Array 2 Dimensi) atau *Multi Linked List*, namun metode Multi Linked List lebih disukai dan digunakan dalam praktikum ini karena sifat dinamisnya yang mampu menangani perubahan jumlah data secara efisien.

Aspek penting lainnya dalam pemahaman graph adalah konsep ketetanggaan, di mana node A dikatakan bertetangga dengan node B jika keduanya dihubungkan langsung oleh sebuah edge. Untuk mengunjungi atau menelusuri setiap node dalam graph, digunakan metode standar seperti *Breadth First Search* (BFS) dan *Depth First Search* (DFS). BFS bekerja dengan mengunjungi node level demi level mulai dari *root* (kedalaman 0) lalu melebar ke tetangganya, sedangkan DFS bekerja dengan menelusuri satu jalur hingga ke simpul terdalam *(subtree)* secara rekursif sebelum kembali ke simpul sebelumnya.

## 4. Guided
### 4.1 Guided 1

<img width="1372" height="1698" alt="graphH" src="https://github.com/user-attachments/assets/dc69899e-77a0-4662-8eb0-2218f2e46881" />


**Penjelasan**:

**File `graph.h`** berfungsi sebagai berkas header yang mendefinisikan tipe data abstrak (ADT) dan deklarasi struktur untuk merepresentasikan graf menggunakan metode *adjacency list* atau senarai berantai. Di dalamnya terdapat definisi struktur data utama, yaitu `ElmNode` untuk merepresentasikan simpul yang memuat informasi data, penanda kunjungan (visited), serta pointer ke sisi pertama dan simpul berikutnya; `ElmEdge` untuk merepresentasikan sisi penghubung yang menyimpan alamat simpul tujuan; serta struktur Graph yang menyimpan alamat elemen pertama. Selain mendefinisikan tipe data pointer seperti `adrNode` dan `adrEdge`, file ini juga berisi prototipe atau deklarasi fungsi-fungsi primitif—seperti pembuatan graph, alokasi memori node, penambahan simpul `(insertNode)`, penghubungan antar simpul `(connectNode)`, serta prosedur penelusuran (DFS dan BFS)—yang memungkinkan pemisahan antara deklarasi antarmuka dengan implementasi logikanya agar program lebih terstruktur dan modular.

### 4.2 Guided 2

<img width="926" height="1318" alt="graphInit" src="https://github.com/user-attachments/assets/0ff6d52a-ba89-4c59-99c6-48585dc2e83b" />


**Penjelasan**:

**File `graph_init.cpp`** berisi implementasi kode dari fungsi-fungsi dasar yang bertugas melakukan inisialisasi struktur dan alokasi memori untuk pembentukan graph. Di dalam file ini terdapat fungsi `createGraph` yang menyiapkan state awal graph dengan mengeset pointer utama ke `NULL` , serta fungsi `allocateNode` yang memesan ruang memori untuk simpul baru sekaligus memberikan nilai awal pada atributnya, seperti mengisi informasi data dan mengatur status `visited` menjadi false. Selain itu, file ini menangani logika penambahan simpul melalui fungsi `insertNode`, yang bekerja dengan memanggil fungsi alokasi lalu menelusuri senarai simpul yang ada hingga elemen terakhir *(traversal)* untuk menyambungkan simpul baru tersebut di bagian belakang *(insert last)*, sehingga graph dapat menyimpan data node secara dinamis.

### 4.3 Guided 3

<img width="1172" height="1318" alt="grapEdge" src="https://github.com/user-attachments/assets/b9e68c63-2442-40ef-9130-16ea0c7acc47" />


**Penjelasan**:

**File `graph_edge.cpp`** berisi implementasi logika untuk memanipulasi hubungan antar simpul, dimulai dengan fungsi pencarian `findNode` yang menelusuri senarai simpul secara linear untuk mendapatkan alamat memori simpul berdasarkan informasi nilainya. Fungsi inti dalam file ini adalah `connectNode`, yang bertanggung jawab menciptakan relasi antara dua simpul yang valid dengan cara mengalokasikan elemen edge baru yang berisi pointer ke simpul tujuan. Secara teknis, penyisipan edge ini dilakukan menggunakan metode *insert first*, di mana sisi baru ditambahkan tepat di awal senarai ketetanggaaan *(firstEdge)* dari simpul asal, sehingga memungkinkan pembentukan struktur relasi antar node secara efisien.

### 4.4 Guided 4

<img width="1234" height="2838" alt="graphPrint" src="https://github.com/user-attachments/assets/6c7a5a59-0314-446a-9b8f-bc71814bd978" />


**Penjelasan**:

**File `graph_print.cpp`** menangani logika visualisasi struktur data graph dengan menampilkan daftar simpul beserta hubungan ketetanggaannya ke layar konsol. Fungsi utama di dalamnya, `printGraph`, bekerja menggunakan mekanisme perulangan bersarang *(nested loop)*, di mana perulangan luar menelusuri senarai simpul utama *(list of nodes)* satu per satu, sementara perulangan dalam menelusuri senarai sisi *(list of edges)* yang terhubung pada setiap simpul tersebut. Dengan mengakses pointer `firstEdge` dari simpul yang sedang diproses, fungsi ini dapat mencetak informasi simpul induk diikuti oleh seluruh simpul tujuan yang menjadi tetangganya, sehingga memberikan representasi tekstual yang jelas dari struktur adjacency list yang telah dibangun.

### 4.5 Guided 5

<img width="910" height="1204" alt="graphMain" src="https://github.com/user-attachments/assets/8f580cad-c199-47df-a2f3-999637f4a828" />


**Penjelasan**:

**File `main.cpp`** berperan sebagai program utama atau driver yang mengintegrasikan dan menguji seluruh fungsionalitas ADT Graph yang telah didefinisikan dalam file header. Alur eksekusinya dimulai dengan mendeklarasikan variabel bertipe Graph dan melakukan inisialisasi awal melalui `createGraph`, dilanjutkan dengan tahap pembentukan simpul menggunakan fungsi `insertNode` untuk memasukkan data (seperti 'A' hingga 'D') ke dalam struktur data. Setelah simpul-simpul tersedia, program memanggil fungsi `connectNode` untuk membangun topologi jaringan dengan menetapkan sisi atau garis hubung antar node yang spesifik, dan diakhiri dengan pemanggilan fungsi `printGraph` untuk memvisualisasikan hasil akhir struktur graph tersebut ke layar konsol guna memverifikasi kebenaran logika program.

**Output**:

<img width="1008" height="157" alt="Screenshot 2025-12-16 204450" src="https://github.com/user-attachments/assets/ab7b0966-e16e-462f-ad2b-57ba4573803c" />



## 5. Unguided
### 5.1 Unguided 1

<img width="1280" height="1166" alt="graphUnguided1" src="https://github.com/user-attachments/assets/ce57120c-f6bf-42c7-8e2f-d65f15f806fe" />


**Penjelasan**:

**Unguided 1** ini intinya meminta kita mengubah kodingan graf yang tadinya cuma "satu arah" menjadi "dua arah" atau tidak berarah `(Undirected Graph)`. Kalau di latihan sebelumnya `(Guided)` hubungan antar node itu seperti jalan satu jalur (misal dari A bisa ke B, tapi B belum tentu bisa ke A), di tugas ini kita diminta membuat struktur yang berlaku bolak-balik. Jadi, kita perlu menyusun node dari A sampai H sesuai gambar di modul, di mana jika A terhubung ke B, otomatis B juga terhubung ke A .

Cara mengerjakannya fokus pada pengubahan fungsi `connectNode`. Kita memodifikasi logika kodingannya supaya setiap kali kita menyambungkan dua node, program langsung membuat dua jalur sekaligus: satu dari node asal ke tujuan, dan satu lagi dari tujuan kembali ke asal. Setelah program dijalankan, hasil cetakannya (print) akan memperlihatkan daftar simpul yang saling "berteman" satu sama lain, membuktikan bahwa jalur tersebut sudah terhubung secara bolak-balik sesuai soal .

**Output**:

<img width="463" height="240" alt="Screenshot 2025-12-17 143555" src="https://github.com/user-attachments/assets/32c220db-a798-4734-b60a-b2ec540dea26" />


### 5.2 Unguided 2

<img width="1280" height="1242" alt="graphUnguided2" src="https://github.com/user-attachments/assets/fc77b6ec-4838-44e5-a469-fd9f4ec02407" />


**Penjelasan**:

**Unguided 2** meminta kita untuk membuat fitur penelusuran graf menggunakan metode Depth First Search `(DFS)`. Jika di latihan pertama kita hanya membangun "jalan" antar kota `(node)`, di latihan ini kita diminta membuat program yang bisa menyusuri jalan tersebut dari awal sampai akhir. Cara kerja DFS ini mirip seperti orang yang sedang menjelajahi labirin: ia akan terus berjalan menelusuri satu lorong sedalam mungkin sampai mentok (tidak ada jalan lagi), baru kemudian dia mundur sedikit `(backtracking)` untuk mencari lorong lain yang belum pernah dilewati.

Dalam kodingannya, kita menggunakan teknik rekursif (fungsi yang memanggil dirinya sendiri) agar program bisa otomatis pindah dari satu node ke tetangganya yang paling dalam. Hal yang paling penting di sini adalah kita harus memberi "tanda" pada setiap node yang sudah didatangi (menggunakan status visited), supaya program tidak bingung dan berputar-putar di tempat yang sama. Hasil akhirnya nanti berupa deretan huruf yang muncul di layar, menunjukkan urutan perjalanan program dari node pertama hingga node terakhir yang berhasil ditemukan.

**Output**:

<img width="444" height="55" alt="Screenshot 2025-12-17 143643" src="https://github.com/user-attachments/assets/6d70502d-148c-4d51-a88d-cc84e1ba3642" />


### 5.3 Unguided 3

<img width="1280" height="1242" alt="graphUnguided3" src="https://github.com/user-attachments/assets/e0fc4e82-8bd2-4cf3-8945-581dd71903f6" />


**Penjelasan**:

**Unguided 3** meminta kita membuat program penelusuran graf menggunakan metode Breadth First Search `(BFS)`. Berbeda dengan DFS yang "menusuk" sedalam mungkin ke satu jalur, BFS ini cara kerjanya "melebar" layer demi layer. Bayangkan seperti riak air saat kita melempar batu ke kolam; penelusuran dimulai dari titik tengah `(node awal)`, lalu menyebar ke semua tetangga terdekatnya dulu secara merata, baru setelah itu lanjut ke tetangganya tetangga `(level berikutnya)`. Jadi, program akan memastikan semua teman dekat disapa dulu sebelum pindah ke teman yang lebih jauh posisinya.

Secara teknis, untuk mengerjakan ini kita membutuhkan bantuan struktur data bernama Queue atau antrian. Prinsipnya persis seperti antrean loket: node yang pertama datang akan dilayani (dicetak) duluan, dan saat node tersebut selesai dilayani, semua tetangganya akan dimasukkan ke barisan paling belakang antrean. Program akan terus mengambil node dari depan antrean satu per satu sampai antrean kosong, sambil tetap menandai node mana saja yang "sudah dikunjungi" agar tidak ada yang masuk antrean dua kali.

**Output**:

<img width="491" height="58" alt="Screenshot 2025-12-17 143718" src="https://github.com/user-attachments/assets/fe14620f-a6c8-4955-9c8b-a43ac2e3e203" />


## 6. Kesimpulan

Implementasi struktur data Graph menggunakan metode *Adjacency* List terbukti efisien karena sifat dinamisnya dalam merepresentasikan hubungan antar simpul tanpa batasan alokasi memori statis . Perbedaan utama dalam praktikum ini terlihat pada modifikasi logika penghubung, di mana konsep *Directed Graph* (satu arah) pada materi awal dikembangkan menjadi *Undirected Graph* (dua arah/timbal balik) untuk memenuhi kebutuhan latihan dengan memastikan setiap koneksi memiliki jalur balik otomatis. Pemahaman mengenai struktur ini semakin diperkuat melalui penerapan algoritma penelusuran, yaitu DFS yang menyusuri kedalaman jalur secara rekursif dan BFS yang menyebar secara melebar menggunakan antrean, yang secara keseluruhan mendemonstrasikan bagaimana data yang kompleks dapat diorganisir dan ditelusuri secara sistematis .

## 7. Referensi

1. **Tim Dosen Kuwu** (2025) *Draft Modul Praktikum Struktur Data: Graph.* Bandung: School of Computing, Telkom University .
2. **Cormen, T.H., Leiserson, C.E., Rivest, R.L. and Stein, C.** (2009) *Introduction to Algorithms.* 3rd edn. Cambridge, MA: MIT Press.
3. **Sedgewick, R.** (2002) *Algorithms in C++ Part 5: Graph Algorithms.* 3rd edn. Boston: Addison-Wesley Professional.
