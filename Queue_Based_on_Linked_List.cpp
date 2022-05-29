//It is implementing circular queue in c++
//It is based on Linke List

#include <iostream>

typedef int Data;

//Node for queue
struct Node {
	Node* next;
	Data data;
};

//Class for Linekd List Queue
class LQueue {
private:
	Node* front;			//Front value that has first value in queue
	Node* rear;				//Rear value that has last value in queue
 
public:
	LQueue();				//Constructor for Circular Queue
	void enqueue(Data data);//Enqueue to add value into queue
	Data dequeue();         //Dequeue to remove value from queue
	Data qpeek();			//Peek first value from queue
	bool QIsEmpty();		//Check whether queue is empty 

};

//Consturctor function for class
LQueue::LQueue() {
	front = NULL;
	rear = NULL;
}


//Function that checks whether queue is empty
bool LQueue::QIsEmpty() {

	//If front is NULL, it means queue is empty
	if (front == NULL) {
		return true;
	}
	else {
		return false;
	}

}

//Function that adds value into queue
void LQueue::enqueue(Data data) {

	//Make newnode to put into queue
	Node* newnode = new Node;
	newnode->next = NULL;
	newnode->data = data;

	//If front is NULL, make front and rear indicate newnode
	if (front == NULL) {
		front = newnode;
		rear = newnode;
	}
	//If there is more than one node in the queue, make rear indicate newnode and make newnode as rear
	else {
		
		rear->next = newnode;
		rear = newnode;
	}

}

//Function that removes value from queue
Data LQueue::dequeue() {

	//If queue is empty, print error message and exit
	if (QIsEmpty()) {
		std::cout << "Queue is empty" << std::endl;
		exit(-1);
	}
	
	//Store node and data to remove
	Node* rnode = front;
	Data rdata = front->data;

	//Move front to next front and remove node and return data
	front = front->next;
	delete rnode;

	return rdata;
}

//Fucntion that peeks value from queue
Data LQueue::qpeek() {

	//If queue is empty, print error message and exit
	if (QIsEmpty()) {
		std::cout << "Queue is empty" << std::endl;
		exit(-1);
	}

	//return value to peek
	return front->data;
}


int main() {

	LQueue lq;

	lq.enqueue(1);
	lq.enqueue(2);
	lq.enqueue(3);
	lq.enqueue(4);
	lq.enqueue(5);

	std::cout << lq.qpeek() << std::endl;

	while (!lq.QIsEmpty()) {
		std::cout << lq.dequeue() << std::endl;
	}


	
}
