//It is implementing stack based on linked list

#include <iostream>

typedef int Data; 

//Struct for Node
struct Node {
	Data data;
	Node* next;
};

//Class for stack
class Stack {

public:
	Stack();				//Constructor
	void push(Data value);  //Push to stack
	Data pop();				//Pop from stack
	Data peek();			//Peek from stack
	bool isEmpty();         //Check whether stack is empty

private:
	Node* head;
};

//Constructor that initialize value
Stack::Stack() {

	head = NULL;
}

//Push to stack
//It is adding value into stack because of characteristic of stack, value is added to top of stack always.
void Stack::push(Data value) {


	Node* newnode = new Node;   //Make new node 
	newnode->data = value;		//Put value into data for node
	newnode->next = head;		//Connect new node to head;

	head = newnode;				//Make new node as head

}

//Pop from stack
//It is removing value from stack because of characteristic of stack, value is removed from top of stack first.
Data Stack::pop() {
	
	//If there is no value in the stack, return error message
	if (head == NULL) {
		std::cout << "There is no data we can remove" << std::endl;
	}


	Node* rnode = head;			//Declare and initialize new node for remove as head that is target of our remove
	Data rdata = head->data;	//Store target data into rdata

	head = head->next;			//Move head to next because we already store head into rnode

	delete rnode;				//Delete rnode that has previous head value

	return rdata;				//Return data we removed

}

//Peek from stack
//Because pop function remove and return value, it is used to get data from stack without removing
Data Stack::peek() {

	//If there is no value in the stack, it returns error message 
	if (head == NULL) {
		std::cout << "There is no data we can peek" << std::endl;
	}

	//Return data in the head node
	return head->data;

}

//It is a function to check whether stack is empty
bool Stack::isEmpty() {

	//If head is null, it means stack is empty
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	Stack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	std::cout<<s.peek()<<std::endl;

	s.pop();
	s.pop();

	std::cout << "Display by removing all values" << std::endl;

	while (!s.isEmpty()) {
		std::cout << s.pop() << std::endl;
	}

	
}
