#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int idata) {
        data = idata;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addNode(int data) {
        Node* node = new Node(data);

        if (head == NULL) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void deleteNode(int data) {
        Node* current = head;

        while (current != NULL) {
            if (current->data == data) {
                if (current->prev != NULL) {
                    current->prev->next = current->next;
                }

                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }

                delete current;
                return;
            }
            current = current->next;
        }
    }

    void printList() {
        Node* current = head;

        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
    }

    void deleteAll() {
        Node* current = head;

        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = NULL;
        tail = NULL;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.addNode(1);
    dll.addNode(2);
    dll.addNode(3);
    dll.addNode(4);
    dll.addNode(5);
    
    dll.deleteNode(3);
    dll.printList();
    
    dll.deleteAll();

    return 0;
}