#include <iostream>
using namespace std;

struct Node { //struktur node
    int data;
    Node* next; //pointer ke node berikutnya
};
//fungsi untuk mencari node dengan nilai tertentu (Binary Search)
void append(Node*& head, int value){
    Node* newNode = new Node{value, nullptr}; //membuat node baru
    if(!head)head = newNode; //jika head null, head jadi newNode
    else {
        Node* temp = head; //mulai dari head
        while (temp->next) temp = temp->next;{ //pindah ke node berikutnya selama masih ada node
        }
        temp->next = newNode; //sambungkan node terakhir ke newNode
    }
}
//FUngsi binary search pada linked list
Node* binarySearch(Node* head, int key){ //Node* ini pointer (kembalian) //fs binary search
    int size = 0; //var size diisi 0
    for (Node* current = head; current; current = current->next) size++; //menghitung ukuran linked list
    Node *start = head; //pointer awal
    Node *end = nullptr; //pointer akhir
    while(size > 0){
        int mid = size / 2; //mencari mid
        Node* midNode = start; //pointer midNode mulai dari start
        for(int i = 0; i < mid; i++) midNode = midNode->next; //pindah ke mid
        if(midNode->data == key) return midNode; //jika data ketemu, kembalikan midNode
        if (midNode->data < key){ //jika data midNode lebih kecil dari key,kita cari di sebelah kanan
            start = midNode->next; //Mulai pencarian dari node setelah midNode
    }
    else { //jika data midNode lebih besar dari key, kita cari di sebelah kiri
        end = midNode; //Batasi pencarian ke bagian kiri
    }
    size -= mid; //Kurangi ukuran size dengan mid
    }
    return nullptr; //Jika key tidak ditemukan
}
//fungsi utama
int main(){
    Node* head = nullptr; //inisialisasi linked list kosong
    append(head, 10); //menambah node dengan nilai 10
    append(head, 20); //menambah node dengan nilai 20
    append(head, 30); //menambah node dengan nilai 30
    append(head, 40); //menambah node dengan nilai 40
    append(head, 50); //menambah node dengan nilai 50
    Node* result = binarySearch(head, 40); //mencari node dengan nilai 40
    cout << (result ? "Found" : "Not Found") << endl; //condition? value_if_true : value_if_false
    return 0;
}
