//It is implementing Circular linked list based on pointer in c++
//In case of Doubly Linked List, we can insert value into beginning of list and end of list by using tail node only.


#include <iostream>

typedef int Ldata; // Typedef is used for potentianl usage for other data type.



struct Node {
    Ldata data;
    Node* next;
    Node* prev;
};

class DLinkedList {
public:
    DLinkedList();

    void insert(Ldata value);
    void remove(Ldata value);
    bool search(Ldata value);
    void display();


private:
    Node* head;
    Node* cur;
    Node* before;
    int numofdata;
};

DLinkedList::DLinkedList() {

    head = NULL;
    cur = NULL;
    before = NULL;
    numofdata = 0;
}

void DLinkedList::insert(Ldata value) {

    Node* newnode = new Node;
    newnode->data = value;

    if (head == NULL) {
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
    }
    else {
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;
        head = newnode;
    }

    numofdata += 1;
}

bool DLinkedList::search(Ldata value) {

    if (head == NULL) {
        std::cout << "There is no value in the list" << std::endl;
        return false;
    }

    cur = head;

    while (cur != NULL) {
        
        if (cur->data == value) {
            return true;
        }

        before = cur;
        cur = cur->next;
    }

    return false;
}

void DLinkedList::remove(Ldata value) {
    
    if (head == NULL) {
        std::cout << "There is no value we can remove" << std::endl;
        return ;
    }

    if (!search(value)) {
        std::cout << "There is no value in the list" << std::endl;
        return;
    }

    Node* rnode = cur;

    if (numofdata == 1) {
        
        head = NULL;

    }
    else if (rnode == head) {
        head = head->next;
        head->prev = NULL;
    }
    else if (rnode->next == NULL) {
        before->next = NULL;
    }

    else {

        before->next = cur->next;
        cur->next->prev = before;

    }

    delete rnode;
    numofdata -= 1;
    
}

void DLinkedList::display() {
    
    if (head == NULL) {
        std::cout << "There is no value in the list" << std::endl;
        return;
    }

    cur = head;

    std::cout << "Original order ------ " << std::endl;
    while (cur != NULL) {
        std::cout << cur->data << std::endl;

        before = cur;
        cur = cur->next;   
    }

    cur = before;
    std::cout << "Reverse order ------ " << std::endl;
    while (cur != NULL) {
        std::cout << cur->data << std::endl;

        cur = cur->prev;
    }


}

int main()
{
    DLinkedList DL;

    DL.insert(1);
    DL.insert(2);
    DL.insert(3);
 
    DL.remove(1);
    DL.remove(2);
    DL.remove(3);
    DL.remove(4);
  
   

    DL.display();

    
}

