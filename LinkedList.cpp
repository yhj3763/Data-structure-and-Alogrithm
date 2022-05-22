//It is implementing linked list based on pointer in c++

#include <iostream>

typedef int Ldata; // Typedef is used for potentianl usage for other data type.


// It is the struct that includes data and next node for node
struct Node {
    Ldata data;
    Node* next;
};

//It is the class that include functions for Linked List
class LinkedList {

public:
    LinkedList();               //Constructor 
    ~LinkedList();              //Deconstructor 
    void insert(Ldata value);   //Insert
    Ldata remove(Ldata value);  //Remove
    bool search(Ldata value);   //Search 
    void display();             //Display
    int count();


private:
    Node* head;                  //Head that indicates first node in list
    Node* cur;                   //This pointer helps function in them like search and remove
    Node* prev;                  //This pointer helps remove function, so it helps the list maintain after we remove value
    int numofdata;               //Number of value in list

};

//This function is constructor for linked list
LinkedList::LinkedList() {
    
    head = NULL;
    cur = NULL;
    prev = NULL;
    numofdata = 0;
}

//This function is deconstructor for linked list, so remove all nodes with value from list
LinkedList::~LinkedList() {


    Node* rnode = new Node;   // Declare node to remove value

    //It repeats until there is no value in the list
    while (head!= NULL)
    {
        rnode = head;         //Store head into rnode
        head = head->next;    //Head indicates next value now
        std::cout << rnode->data << " is removed" << std::endl;    // Show which value is removed
        delete rnode;         //Because head stores next value now, we can remove previous head that stored in rnode
       
    }

    std::cout << "List is removed" << std::endl;  //Show all nodes are removed from list
}

//This function is insert function
//In the linked list, there are three kind of functions for insert.
//1. insert function that insert value into beginning of list (This way is used for this case and it gives good performance because it does not have to travel)
//2. insert function that insert value into end of list (For this function, we need to make tail node that tracks end of list to make insert easier
//3. insert function that insert value into middle of list(For this function, we need to use previous node so we can make previous node indicate new node and new node 
//indicate next node.
//We can put multiple insert functions for linked list, but usually inserting at the beginning is used for studying data structure. However, it needs to be selected based on
//need that can give better performance.
void LinkedList::insert(Ldata value) {

    Node* newnode = new Node;
    newnode->next = NULL;
    newnode->data = value;

    if (head == NULL){
        head = newnode;
    }
    else{

        newnode->next = head;
        head = newnode;

    }

    numofdata++;

}

//It is function for search that helps us travel linked list to find value we want.
bool LinkedList::search(Ldata value) {
 
    //Check whether list has value on it
    if (numofdata == 0){
        std::cout << "There is nothing to search" << std::endl;
    }
    
    //Cur is used to store head because we need to maintain head
    cur = head;

    //Search every value in list
    while (cur != NULL)
    {
        //If we find value, it retures true
        if (cur->data == value)
        {
            return true;
        }
        
        prev = cur;       //Store prev value that store the value befor current to use for remove function
        cur = cur->next;  //Update cur value to store next value
    }

    return false;
 

}

//It is remove function that removes any node that has value we want to remove
Ldata LinkedList::remove(Ldata value) {

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
    
    //If cur is first value in the list, we just make head indicates next value of cur pointer
    if(cur == head){
       
        head = cur->next;

    }
    //If node is not first node, we need to use prev and cur pointer that we made in search function, so prev -> next indicates the node after the node we want to remove
    else {
        
        prev->next = cur->next;     
    }
    delete rnode;    // Remove cur value that we want to remove by using rnode
    numofdata--;     // Update number of node in the list
    return rdata;    // Return removed data that we stored above before we remove node
  

}

//It is function for display, so cur node travels all over list and it prints value in each node.
void LinkedList::display() {

    cur = head;
    
    while (cur != NULL)
    {
        std::cout << cur->data << std::endl;
        cur = cur->next;
    }
}

//It is function returns number of value in the list
int LinkedList::count() {
    return numofdata;
}


int main()
{
    LinkedList* list = new LinkedList;

    list->insert(1);
    list->insert(2);
    list->insert(3);
    list->insert(4);
    list->insert(5);
    list->insert(6);
    list->insert(7);

    list->remove(2);
    list->remove(5);
    list->remove(7);
    list->remove(1);

    list->display();


    
}

