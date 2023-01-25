//It is implementing Stack by using array in C++
//Stack has characteristic that Last in First out

#include <iostream>


#define STACK_LEN 100   //Length for array

typedef int Data; 

class Stack {

public:
	Stack();		//Constructor
	void push(Data value);  //Push to stack
	Data pop();		//Pop from stack
	Data peek();		//Peek from stack
	bool isEmpty();         //Check whether stack is empty

private:
	Data arr[STACK_LEN];    //array
	int topindex;		//index for array
};

//Constructor that initialize value
Stack::Stack() {
	topindex = -1;        //Initialize index with -1 because array starts from 0, so we need to initialize it with -1 first
}

//Push to stack
//It is adding value into stack because of characteristic of stack, value is added to top of stack always.
void Stack::push(Data value) {

	//When Stack is full, it prints error message
	if (topindex == STACK_LEN - 1) {
		std::cout << "Stack is full" << std::endl;
		return;
	}

	topindex += 1;		//Increase value for index
	arr[topindex] = value;  //Put value into array
}

//Pop from stack
//It is removing value from stack because of characteristic of stack, value is removed from top of stack first.
Data Stack::pop() {
	
	//If there is no value in the stack, it returns error message
	if (topindex == -1) {
		std::cout << "There is nothing to pop" << std::endl;
		return -1;
	}

	Data rdata = arr[topindex];	//Store value we want to pop first.
	topindex -= 1;			//Decrease vlaue for index, so it means one value is removed from stack

	return rdata;	//return removed value

	
}

//Peek from stack
//Because pop function remove and return value, it is used to get data from stack without removing
Data Stack::peek() {

	return arr[topindex];
}

//It is a function to check whether stack is empty
bool Stack::isEmpty() {

	//-1 means stack is empty, so it returns true
	if (topindex == -1){
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


	while (!s.isEmpty())
	{
		std::cout << s.pop() << std::endl;
	}
}
