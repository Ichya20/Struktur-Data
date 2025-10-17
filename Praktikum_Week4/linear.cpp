#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; //pointer ke node berikutnya
};
//fungsi untuk mencari node dengan nilai tertentu (Linear Search)
Node* linearSearch(Node* head, int key){ //Node* ini pointer (kembalian) //fs linear search

    Node* current = head; //current ini pointer yg nunjuk ke node

    while (current != nullptr) { //selama masih ada node
        if (current->data == key) return current; //jika data ketemu
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; //Tidak ditemukan
}
//Prosedur untuk menambah node
void append(Node*& head, int value) {

    Node* newNode = new Node{value, nullptr}; //membuat node baru

    if(!head)head = newNode; //jika head null, head jadi newNode
    else {
        Node* temp = head; //mulai dari head
        while (temp->next) temp = temp->next;{ //pindah ke node berikutnya selama masih ada node
        }
        temp->next = newNode; //sambungkan node terakhir ke newNode
    }
}
//fungsi utama
int main(){
    Node* head = nullptr; //inisialisasi head sebagai null
    append(head, 10); //menambah node dengan nilai 10
    append(head, 20); //menambah node dengan nilai 20
    append(head, 30); //menambah node dengan nilai 30
    Node* result = linearSearch(head, 20); //mencari node dengan nilai 20
    cout << (result ? "Found" : "Not Found") << endl; //condition? value_if_true : value_if_false
    return 0;
}