#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void insertFirst(List &L, address P) {
    P->next = L.first; // Set pointer next dari P ke elemen pertama saat ini
    P->prev = Nil; // Set pointer prev P ke Nil karena menjadi elemen pertama
    if (L.first != Nil) L.first->prev = P; // Jika list tidak kosong, set prev elemen pertama lama ke P
    else L.last = P; // Jika list kosong, set last juga ke P
    L.first = P; //Update first list menjadi P
}

void insertLast(List &L, address P) {
    P->prev = L.last; // Set pointer prev dari P ke elemen terakhir saat ini
    P->next = Nil; 
    if (L.last != Nil) L.last->next = P; // Jika list tidak kosong, set next elemen terakhir lama ke P
    else L.first = P; // Jika list kosong, set first juga ke P
    L.last = P; // Update last list menjadi P
}

void insertAfter(List &L, address P, address R) {
    P->next = R->next; // Set pointer next dari P ke elemen setelah R
    P->prev = R; // Set pointer prev dari P ke R
    if (R->next != Nil) R->next->prev = P; // Jika R bukan elemen terakhir, set prev elemen setelah R ke P
    else L.last = P; // Jika R adalah elemen terakhir, update last list menjadi P
    R->next = P; // Set pointer next dari R ke P
}

address alokasi(infotype x) {
    address P = new elmlist; // Alokasi memori untuk elemen baru
    P->info = x; // Set info elemen baru
    P->next = Nil; // Inisialisasi next ke Nil
    P->prev = Nil; // Inisialisasi prev ke Nil
    return P; // Kembalikan alamat elemen baru
}

void printInfo(List L) {
    address P = L.first; // Set P ke elemen pertama list
    while (P != Nil) { // Loop selama P tidak Nil
        cout << P->info << " "; // Cetak info dari P
        P = P->next; // Pindah ke elemen berikutnya
    }
    cout << endl;
}



void insertBefore(List &L, address P, address R) {
    if (R == L.first) {
        insertFirst(L, P);
    } 
    else {
        P->next = R;
        P->prev = R->prev;
        R->prev->next = P; // Sambungkan next dari node sebelum R ke P
        R->prev = P;       // Sambungkan prev dari R ke P
    }
}

void printReverse(List L) {
    address P = L.last; // Mulai dari elemen terakhir
    while (P != Nil) { // Loop selama P tidak Nil
        cout << P->info << " "; // Cetak info dari P
        P = P->prev; // Pindah ke elemen sebelumnya
    }
    cout << endl;
}

int main() {
    List L;
    L.first = Nil;
    L.last = Nil;
    address P1 = alokasi(1);
    address P3 = alokasi(3);
    address P2 = alokasi(2);
    insertFirst(L, P1);
    insertLast(L, P3); 
    insertLast(L, P2);
    cout << "TASK 1: INSERT OPERATIONS" << endl;
    cout << "List awal:" << endl;
    cout << "Forward: ";
    printInfo(L);
    cout << "Backward: ";
    printReverse(L); // Memanggil printReverse
    address P4 = alokasi(4);
    insertBefore(L, P4, P2); // Panggil insertBefore
    cout << "Berhasil insert 4 sebelum 2" << endl;
    address P5 = alokasi(5);
    insertBefore(L, P5, P1); // Panggil insertBefore
    cout << "Berhasil insert 5 sebelum 1" << endl;
    cout << "List setelah insertBefore:" << endl;
    cout << "Forward: ";
    printInfo(L);
    cout << "Backward: ";
    printReverse(L);
    return 0;
}