#include <iostream>

// Rule of 3 알아보기

class LinkedList {
    private: 
        struct Node {
            int data;
            Node* next;
            Node(int value) : data(value), next(nullptr) {}
        };

        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(void);
        ~LinkedList(void);
        void push_back(int value);
        void push_front(int value);
        void pop_back();
        // void pop_front();
        void print(void);
        // void get_last(void);
};

LinkedList::LinkedList(void) {
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

LinkedList::~LinkedList(void) {
    Node* ptr = this->head;
    Node* next = nullptr;

    while (ptr) {
        next = ptr->next;
        std::cout << "(메모리 해제) data = " << ptr->data << std::endl;
        delete ptr;
        ptr = next;
    }

    std::cout << "\n메모리 해제 완료";
}

void LinkedList::push_back(int value) {
    Node* new_node = new Node(value); 

    if (this->tail != nullptr) {
        this->tail->next = new_node;
        this->tail = new_node;
    }
    else {
        this->tail = new_node;
        this->head = new_node;
    }

    this->length += 1;
}

void LinkedList::push_front(int value) {
    Node* new_node = new Node(value);

    if (this->head) {
        new_node->next = this->head;
    }
    else {
        this->tail = new_node;
    }
    
    this->head = new_node;
    this->length += 1;
}

void LinkedList::pop_back() {
    // tail 갱신
    // 노드가 1개 일때 head ta


    if (this->length == 0) {
        return;
    }

    Node* prev = nullptr;
    Node* last = this->head;

    while (last != this->tail) {
        prev = last;
        last = last->next;
    }

    if (prev) {
        prev->next = nullptr;
    }

    delete last;
}


// void LinkedList::pop_front() {

// }

void LinkedList::print() {
    Node* ptr = this->head;
    
    while (ptr != nullptr) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }

    std::cout << std::endl;
}

// void LinkedList::get_last(void) {
//     std::cout << this->tail->data;
//     std::cout << "\nasdasdasdasdasdasdsad";
// }


int main(void) {
    LinkedList ll = LinkedList();

    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    // ll.get_last();
    ll.print();

    return 0;
}