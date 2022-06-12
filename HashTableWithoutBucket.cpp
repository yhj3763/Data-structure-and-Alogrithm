//It is implementing HashTable in c++
//In this code, I use chaning to solve collision 
#include <iostream>

//Defining length for array
#define ARRAY_LENGHTH 10

//It is struct for Node that include key, value and node to next
struct Node {
	int key;
	int value;
	Node* next;
};


//It is class for HashTable
class HashTable {
public:
	HashTable();							//It is constructor for HashTable
	void insert(int key, int value);		//It is insert function for HashTable
	void remove(int key);					//It is remove function for HashTable
	bool search(int key);					//It is search function for HashTable
	void print();							//It is print function for HashTable
	bool isempty();							//It is isempty function for HashTable


private:
	int totalnum;							//It is variable to store total number of data in HashTable
	Node* arr[ARRAY_LENGHTH];				//It is pointer array to store address for buckets
	int hashfunction(int key);				//It is hashfunction to use to make hash based on key in HashTable

};

//It is a constructor for HashTable
//Initialize values for class HashTable and struct Bucket
HashTable::HashTable() {
	totalnum = 0;

	//Initializing buckets and assign memory into nodes to use it to store hash
	for (int i = 0; i < ARRAY_LENGHTH; i++) {

		arr[i] = NULL;
	}
}

//It is hash function to make hash based on input key
//It is basic one to use to implement hashtable
int HashTable::hashfunction(int key) {
	return key % ARRAY_LENGHTH;
}

//It is insert function to put value into hash table
void HashTable::insert(int key, int value) {

	//Make hash by using hash function with key
	int hashkey = hashfunction(key);

	//Make new node to put into hash table
	Node* newnode = new Node;
	newnode->next = NULL;
	newnode->key =key;
	newnode->value = value;

	//If bucket has no node in it, we just make head in the node as new node, and increase count
	if (arr[hashkey] == NULL) {
		arr[hashkey] = newnode;
	}
	//If there is more than one value in the node, we need to connect new node to head and make new node as new head 
	else {

		Node* cur = arr[hashkey];
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;

	}

	//Increase total number of data in the hash table
	totalnum++;
	return;

}

//It is function to remove hash from hash table
void HashTable::remove(int key) {

	//Make hash by using hash function with key
	int hashkey = hashfunction(key);

	//If node has no node in it, we need to return with error message
	if (arr[hashkey] == NULL) {
		std::cout << "There is nothing to remove in the hash table with key" << std::endl;
		return;
	}
	//If node has one value, we just delete value and put NULL into it
	else if (arr[hashkey]->next == NULL) {
		delete(arr[hashkey]);
		arr[hashkey] = NULL;
	}
	//If node has more than one vlaue, we need to find exact value we want to remove
	else {
		//Make two nodes for target and previous to delete target
		Node* target = arr[hashkey];
		Node* prev = arr[hashkey];

		//Finding target that has key we want to remove
		while (target != NULL) {
			
			if (target->key == key) {
				break;
			}
			prev = target;
			target = target->next;
		}

		//If there is no target we want to remove, return with error message
		if (target == NULL) {
			std::cout << "There is nothing to remove in the hash table with key" << std::endl;
			return;
		}
		//If we found the value we want to remove, remove value
		else {
			prev->next = target->next;
			delete(target);

		}

	}

	//Update total number 
	totalnum--;
	return;


}

//It is search function to find value with key
bool HashTable::search(int key) {

	//Make hash with hash function with key
	int hashkey = hashfunction(key);

	//Based on hash key, store target we want to find into target node
	Node* target = arr[hashkey];

	//If there is no value in the bucket, return false with error message
	if (target == NULL) {
		std::cout << "There is no value you are looking for with key" << std::endl;
		return false;
	}
	//if there is more than one value in the bucket, go into loop
	else {

		//Find place that store key we are searching
		while (target != NULL) {

			if (target->key == key) {
				return true;
			}
			target = target->next;
		}
	}
	//If we cannot find value, just return false
	return false;

}

//It is isempty function to return true or false based on total number of data
bool HashTable::isempty() {

	if (totalnum == 0) {
		return true;
	}
	else {
		return false;
	}
}

//It is function to print all values in the HashTable with format
void HashTable::print() {
	
	for (int i = 0; i < ARRAY_LENGHTH; i++) {
		std::cout << "[Index " << i << "] ";

			Node* cur = arr[i];
			while (cur != NULL) {
				std::cout << "-> [Key is " << cur->key << " Value is " << cur->value << " ]";
				cur = cur->next;
			}
			std::cout << std::endl;
	}
}


int main() {


	HashTable h;
	h.insert(11, 2);
	h.insert(21, 2);
	h.insert(31, 2);

	h.insert(32, 3);
	h.insert(33, 4);
	h.insert(34, 5);
	h.insert(35, 6);
	h.insert(36, 7);
	h.insert(30, 2);

	h.remove(33);
	h.remove(41);

	h.print();

	if (h.search(21)) {
		std::cout << "There is value you are looking for" << std::endl;
	}
	else {
		std::cout << "There is no value you are looking for" << std::endl;
	}
	
	if (h.isempty()) {
		std::cout << "It is empty" << std::endl;
	}
	else {
		std::cout << "It is not empty" << std::endl;
	}
}
