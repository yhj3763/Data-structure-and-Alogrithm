//It is implementing Doubly Linked List based on pointer in c++
//In case of Doubly Linked List, we can insert value into beginning of list and end of list by using tail node only.


#include <iostream>

typedef int Ldata; // Typedef is used for potentianl usage for other data type.


//Node struct that include data, pointer to next, and pointer to prev
//Unlike other linked list, doubly linked list needs to have prev to connect to previous value
struct Node {
    Ldata data;
    Node* next;
    Node* prev;
};

//Class for Doubly Linked List
class DLinkedList {
public:
    DLinkedList();

    void insert(Ldata value); //Insert
    void remove(Ldata value); //remove
    bool search(Ldata value); //search
    void display();           //print


private:
    Node* head;               //head to indicate first node in the list
    Node* cur;                //cur to travel all over list when we need
    Node* before;             //before to connect to next value after we remove value
    int numofdata;
};

//Constructor to initialize values
DLinkedList::DLinkedList() {

    head = NULL;
    cur = NULL;
    before = NULL;
    numofdata = 0;
}

//Insert value into beginning of the list
void DLinkedList::insert(Ldata value) {

    //Make new node to add
    Node* newnode = new Node;
    newnode->data = value;

    //If there is no value, make newnode as head that have no prev and next
    if (head == NULL) {
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
    }
    //If there is more than one value, connect new node to head, connect new node to NULL because it is first node, and make new node as head 
    else {
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;
        head = newnode;
    }

    numofdata += 1;
}

//Search value in the list. If there is value, it returns true. If there is no vlaue, it returns false.
bool DLinkedList::search(Ldata value) {

    //If there is nothing in the list, it returns false
    if (head == NULL) {
        std::cout << "There is no value in the list" << std::endl;
        return false;
    }

    //put head to cur to maintain head
    cur = head;

    //loop until it finds value
    while (cur != NULL) {

        if (cur->data == value) {
            return true;
        }

        before = cur;
        cur = cur->next;
    }

    return false;
}

//Remove value based on value we found in the search
void DLinkedList::remove(Ldata value) {

    //If there is nothing in the list, return nothing
    if (head == NULL) {
        std::cout << "There is no value we can remove" << std::endl;
        return;
    }

    //If there is no value we find in the list, it also returns nothing
    if (!search(value)) {
        std::cout << "There is no value in the list" << std::endl;
        return;
    }

    //We made cur have node we want to remove, so we can put cur into remove node
    Node* rnode = cur;

    //If there is only one value, we can just make head null
    if (numofdata == 1) {

        head = NULL;

    }
    //If there is more than one value and remove node is head, we can make head->next head, and make head->prev have NULL
    else if (rnode == head) {
        head = head->next;
        head->prev = NULL;
    }
    //If the node that we want to remove is placed at the end of list, we can make before->next have NULL
    else if (rnode->next == NULL) {
        before->next = NULL;
    }
    //When we remove value from middle of list, we connect before->next to cur->next, and cur->next->prev to before
    else {

        before->next = cur->next;
        cur->next->prev = before;

    }

    //Finally, we remove node in the remove node
    delete rnode;
    numofdata -= 1;

}

//Print values in the list
void DLinkedList::display() {

    //If there is no value, it returns nothing
    if (head == NULL) {
        std::cout << "There is no value in the list" << std::endl;
        return;
    }

    //put head into cur
    cur = head;

    //print value from beginning
    std::cout << "Original order ------ " << std::endl;
    while (cur != NULL) {
        std::cout << cur->data << std::endl;

        before = cur;
        cur = cur->next;
    }

    //To print value from end, we need to put before into cur
    cur = before;
    
    //Print value from end by using cur
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
