//It is implementing Circular linked list based on pointer in c++
//In case of Circular Linked List, we can insert value into beginning of list and end of list by using tail node only.


#include <iostream>

typedef int Ldata; // Typedef is used for potentianl usage for other data type.


// It is the struct that includes data and next node for node
struct Node {
    Ldata data;
    Node* next;
};

//It is the class that include functions for Linked List
class CLinkedList {

public:
    CLinkedList();               //Constructor 
    ~CLinkedList();              //Deconstructor 
    void insert(Ldata value);   //Insert
    void insertfront(Ldata value); //Insert value into front
    Ldata remove(Ldata value);  //Remove
    bool search(Ldata value);   //Search 
    void display();             //Display
    int count();                //Return number of data in the list


private:
    Node* tail;                  //Head that indicates first node in list
    Node* cur;                   //This pointer helps function in them like search and remove
    Node* before;                  //This pointer helps remove function, so it helps the list maintain after we remove value
    int numofdata;               //Number of value in list

};

//This function is constructor for linked list
//It includes dummy node, so head node always indicates dummy node
CLinkedList::CLinkedList() {
   
    tail = NULL;
    cur = NULL;
    before = NULL;
    numofdata = 0;
}

//This function is deconstructor for linked list, so remove all nodes with value from list
CLinkedList::~CLinkedList() {


    Node* rnode = new Node;   // Declare node to remove value
    tail = tail->next;
    //It repeats until there is no value in the list
    while (numofdata!=0)
    {
        rnode = tail;         //Store head into rnode
        tail = tail->next;    //Head indicates next value now
        std::cout << rnode->data << " is removed" << std::endl;    // Show which value is removed
        delete rnode;         //Because head stores next value now, we can remove previous head that stored in rnode
        numofdata -= 1;
       
    }

    std::cout << "List is removed" << std::endl;  //Show all nodes are removed from list
}

//This function is insert function
//It inserts value into end of list
void CLinkedList::insert(Ldata value) {

    //Making new node
    Node* newnode = new Node;
    newnode->data = value;

    //If there is no value in the list, make new node as tail
    //Because it is circular linked list, tail indicates tail itself when there is tail node only.
    if (tail == NULL) {
        tail = newnode; 
        tail->next = newnode;
    }
    //If there is more than one node, newnode->next has value that tail->next had.
    //Now, tail->next has new node as its value
    //Newnode becomes new tail.
    else{

        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;

        
    }
   
    numofdata++;

}

//It is function that insert the value at the beginning of the list.
void CLinkedList::insertfront(Ldata value) {

    Node* newnode = new Node;
    newnode->data = value;

    if (tail == NULL) {
        tail = newnode;
        tail->next = NULL;
    }
    //Although it looks similar to inserting at the end of list, it does not make new node as new tail
    //We just add new node and make tail indicates it
    else {

        newnode->next = tail->next;
        tail->next = newnode;
    }

    numofdata++;

}

//It is function for search that helps us travel linked list to find value we want.
bool CLinkedList::search(Ldata value) {
 
    //Check whether list has value on it
    if (numofdata == 0){
        std::cout << "There is nothing to search" << std::endl;
    }
    
    //Cur is used to store head because we need to maintain head
    int nums = numofdata;
    cur = tail->next;
    before = tail;

    //Search every value in list
    while (nums!=0)
    {
        //If we find value, it retures true
        if (cur->data == value)
        {
            return true;
        }
        
        before = cur;       //Store prev value that store the value befor current to use for remove function
        cur = cur->next;  //Update cur value to store next value
        nums -= 1;
    }

    return false;
 

}

//It is remove function that removes any node that has value we want to remove
Ldata CLinkedList::remove(Ldata value) {

    //Check whether list is empty
    if (numofdata == 0){
        std::cout << "There is nothing to remove" << std::endl;
        return -1;
    }
    
    //If there is no value we are looking for it, it stops removing and we also update prev and cur pointer to help remove fucntion through search function
    if (!search(value)){
        std::cout << "There is no value you are looking for" << std::endl;
        return -1;
    }

    Node* rnode = cur;          //rnode stores cur value that we made it indicates the node that has value that we want to remove in search function
    Ldata rdata = cur->data;    //Store the value in node that we want to remove, we use this data to return for result of remove
    
    //There are some cases we need to care about
    //1. When we need to remove tail, we need to make cur move back to before node
    //2. Whene there is only one node(tail indicates itself), we need to make tail have null value.
    if (cur == tail){

        if (tail == tail->next)
        {
            tail = NULL;
        }
        else {
            tail = before;
        }

    }
    //If node is not first node, we need to use prev and cur pointer that we made in search function, so prev -> next indicates the node after the node we want to remove
    before->next = cur->next;
    cur = before;

    delete rnode;    // Remove cur value that we want to remove by using rnode
    numofdata--;     // Update number of node in the list
    return rdata;    // Return removed data that we stored above before we remove node

}

//It is function for display, so cur node travels all over list and it prints value in each node.
void CLinkedList::display() {

    if (tail == NULL){

        std::cout << "There is no value we can display." << std::endl;
    }
    cur = tail->next;
    int nums = numofdata;
    
    while (nums !=0)
    {
        std::cout << cur->data << std::endl;
        cur = cur->next;
        nums -= 1;
    }
}

//It is function returns number of value in the list
int CLinkedList::count() {
    return numofdata;
}


int main()
{
    CLinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insertfront(4);

    list.remove(1);
    list.remove(2);
    list.remove(3);
    list.remove(4);
    
 
    list.display();

    
}

