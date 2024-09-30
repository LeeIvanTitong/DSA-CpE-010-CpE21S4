#include <iostream>
using namespace std;

class Node {           //  N O D E  STRUCTURE
public:
    int value;
    Node* next;
};


bool isPrime(int n) {                            // 'FUNCTION' TO CHECK IF NUMBER IS PRIME
    if (n <= 1) return false;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

Node* createNode(int value) {                 // 'FUNCTION' TO CREATE NEW NODE
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    
    
    for (int i = 2; i < 20; i++) {
        if (isPrime(i)) {
            Node* newNode = createNode(i);
            if (head == nullptr) {
                head = newNode;  // HEAD FOR  first prime number
                tail = newNode;  
            } else {
                tail->next = newNode;  // TAIL FOR  last node
                tail = newNode;        //  UPDATE
            }
        }
    }
    
    
    cout << "Prime numbers less than 20: ";      // DISPLAY 
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
    
    cout << "Head of the list: " << head->value << endl;
    cout << "Tail of the list: " << tail->value << endl;
    
    return 0;
}
