Asessment Laporan Stuktur Data

- Nama: Ichya Ulumiddiin
- NIM: 103112400076
- Kelas: 12-IF-05/Struktur Data

1. Kode Program

        #include <iostream>
        using namespace std;

        struct Node {
            int data;
            Node* prev;
            Node* next;
        };

        Node* head = NULL;
        Node* tail = NULL;

        bool isEmpty() {
            return head == NULL;
        }

        void insertLast(int nilai) {
            Node* newNode = new Node();
            newNode->data = nilai;
            newNode->next = NULL;
            newNode->prev = NULL;

            if (isEmpty()) {
                head = tail = newNode;
            } else {
                tail->next = newNode;     
                newNode->prev = tail;    
                tail = newNode;           
            }
        }


        void deleteLast() {
            if (isEmpty()) {
            return; 
            }
            Node* delNode = tail;
            if (head == tail) {
            head = tail = NULL;
            } else {
                tail = tail->prev;       
                tail->next = NULL;
                delete delNode;
            }
        }

        void view() {
            if (isEmpty()) {
                cout << "(List Kosong)" << endl;
                return;
            }
            Node* current = head;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        void reverseListView() {
            if (isEmpty()) {
                cout << "(List Kosong)" << endl;
                return;
            }

            Node* current = head;
            Node* temp = NULL;

            while (current != NULL) {
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;

                current = current->prev;
            }

            if (temp != NULL) {
                temp = head;
                head = tail;
                tail = temp;
            }

                cout << "List setelah di-reverse: ";
                view();
        }

        int main() {
            int pilihan, nilai;

            do {
                cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit" << endl;
                cin >> pilihan;

                switch (pilihan) {
                    case 1:
                        cout << "Masukkan nilai: ";
                        cin >> nilai;
                        insertLast(nilai);
                        break;
                    case 2:
                        deleteLast();
                        break;
                    case 3:
                        view();
                        break;
                    case 4:
                        reverseListView();
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Pilihan salah" << endl;
                }
            } while (pilihan != 0);

            return 0;
            }
```

2. Penjelasan Kode

    1. Struktur struct Node
        int data    : Tempat menyimpan angka (misal: 5, 10, 15).
        Node* prev  : Penunjuk ke arah kiri (sebelumnya).
        Node* next  : Penunjuk ke arah kanan (selanjutnya).
    
    2. Fungsi `insertLast(int nilai)`
        Langkah-langkah:
        1.  Buat Node Baru: Kita siapkan memori untuk node baru, isi datanya dengan `nilai`, dan set pointer `next` & `prev`-nya ke NULL (kosong) dulu.
        2.  Cek Apakah List Kosong:
            -Jika `head` masih NULL (belum ada data), maka node baru ini langsung menjadi `head` (awal) dan `tail` (akhir) sekaligus.
        3.  Jika List Sudah Ada Isi:
            -Kita sambungkan `tail` (node terakhir saat ini) ke node baru. (`tail->next = nodeBaru`)
            -Sebaliknya, node baru juga harus menunjuk balik ke `tail` lama. (`nodeBaru->prev = tail`)
            -Terakhir, pindahkan label `tail` ke node baru tersebut, karena dia sekarang yang paling akhir.

    3. Fungsi `deleteLast()`
        Langkah-langkah:
        1.  Cek Kosong: Jika list kosong, fungsi berhenti (tidak ada yang bisa dihapus).
        2.  Simpan Target: Kita tandai node `tail` saat ini sebagai target yang akan dihapus (`delNode`).
        3.  Kondisi 1 Node: Jika list hanya punya 1 data (`head == tail`), kita set `head` dan `tail` menjadi NULL. List jadi kosong.
        4.  Kondisi Banyak Node:
            -Kita mundurkan label `tail` ke node sebelumnya (`tail = tail->prev`).
            -Putuskan hubungan ke node lama dengan mengisi `next` milik tail baru menjadi NULL.
        5.  Hapus Memori: Hapus `delNode` dari memori komputer agar bersih.

    4. Fungsi `view()`
        Langkah-langkah:
            1.  Siapkan penunjuk (`current`) dan letakkan di `head`.
            2.  Selama `current` tidak NULL (masih menunjuk data):
                -Cetak angkanya ke terminal.
                -Geser penunjuk ke node berikutnya (`current = current->next`).

    5. Fungsi `reverseListView()`
        Langkah-langkah:
        1.  Mulai dari node awal (`head`).
        2.  Lakukan perulangan sampai ujung list:
            Tukar Pointer: Di node tempat kita berdiri, tukar isi `next` dengan `prev`.
                -Simpan `prev` di variabel `temp`.
                -Isi `prev` dengan `next`.
                -Isi `next` dengan `temp` tadi.
            Geser: Pindah ke node berikutnya. *Catatan: Karena arah pointer sudah ditukar, untuk maju kita justru menggunakan pointer `prev`*.
        3.  Tukar Head dan Tail:
            -Setelah semua pointer di dalam node tertukar, struktur list sudah terbalik tapi label `head` dan `tail` masih di tempat lama.
            -Kita harus menukar posisi `head` (yang kini jadi ujung) dengan `tail` (yang kini jadi awal).

3. Output Program

<img width="1108" height="719" alt="Screenshot 2025-11-21 083911" src="https://github.com/user-attachments/assets/a04e0297-3fe6-42f7-bfb0-5287281b2c60" />

4. Penjelasan Lanjutan (Analisis Output)

Pada Hasil Output tersebut bisa dilihat bahwa, Proses dimulai dengan input data 5, 10, 15, dan 20 yang tersimpan secara berurutan. Kemudian, fungsi *delete last* berhasil menghapus elemen terakhir (angka 20), dan fungsi *reverse* membalik sisa data yang ada. Hasil akhir "15 10 5" membuktikan bahwa seluruh logika manipulasi data (tambah, hapus, dan balik urutan) telah berfungsi dengan benar. Penjelasan lebih lengkapnya bisa dilihat pada bagian penjelasan kode.
5. Kesimpulan

    Dari seluruh implementasi kode yang telah dilaksanakan diatas, kita bisa menyimpulkan bahwa, beberapa fungsi yang sudah dijalankan berjalan dengan baik tanpa ada error. Diantaranya yaitu fungsi InsertLast, DeleteLast, View, dan Reverese View juga menampilkan rangkaian kode yang efisien sebagaimana mestinya. Kompleksitas dan Analisis dalam melakukan pengkodingan pada soal diatas harus betul betul dilakukan secara teliti karena ada beberapa fungsi yang memiliki kerumitan sedikit lebih tinggi dibanding fungsi yang lainnya. 

