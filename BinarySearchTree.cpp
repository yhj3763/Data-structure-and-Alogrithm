//It is implementing Binary Search Tree in C++;
#include <iostream>

typedef int Data;

//It is node struct to store data and left and right
struct Node {
	Data data;
	Node* left;
	Node* right;
};


//It is class for Binary Search Tree
class BStree {
private:
	Node* root;						//it includes node to indicate root

public:
	BStree();						//It is constructor for Binary Search Tree
	void insert(Data value);		//It is insert function for Binary Search Tree
	bool search(Data target);		//It is search function to check whether value is in Binary Search Tree
	Node* getroot();				//It is getroot function to root for traversal
	Node* remove(Data target);		//It is remove function for Binary Search Tree
	void preorder(Node* travel);	//It is function for Preorder Traversal
	void inorder(Node* travel);		//It is function for Inorder Traversal
	void postorder(Node* travel);	//It is function for Postorder Traversal
	
};


//It is constructor for Binary Search Tree
BStree::BStree() {
	root = NULL;
}

//It is insert function for Binary Search Tree
void BStree::insert(Data value) {

	//Declare node for parent and current node
	Node* parent = NULL;
	Node* cur = root;

	//We need to find place that cur has NULL value to store new value
	while (cur != NULL) {

		//If we find value we want to insert in tree, it returns
		//Because it does not allow same value
		if (cur->data == value){
			return;
		}
	
		//We need to use parent node to insert value, so we store current value before we change value below
		parent = cur;

		//if cur node has bigger value than the value we want insert
		//Move current node to left that means smaller value than parent
		if (cur->data > value) {
			cur = cur->left;
			
		}
		//If cur node has smaller value than the value we want insert
		//Move current node to right that means bigger value than parent
		else {
			cur = cur->right;
		}

	}

	//We found placce to insert new value above
	//We need to make new node to insert and initialize
	Node* newnode = new Node;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = value;

	//if parent is not NULL that means tree has some values in it
	//if new value has smller value than value in parent node, it is stored in left node of parent node
	//if new value has bigger value than value in parent node, it is stored in right node of parent node
	//If parent node is NULL, we just put new node into root
	if (parent != NULL) {
		
		if (value < parent->data) {
			parent->left = newnode;
		}
		else {
			parent->right = newnode;
		}
	}
	else {
		root = newnode;
	}
}

//It is search function to check value in the binary Search Tree
bool BStree::search(Data target) {

	//If there is nothing in the tree, just return false
	if (root == NULL) {
		return false;
	}

	//To maintain root, put root into cur node
	Node* cur = root;
	Data cd;

	//It is repeating until current node finds target value or reach end of tree
	while (cur != NULL) {

		//Store data into variable to compare to target
		cd = cur->data;

		//If we finds target value, it returns true
		if (cd == target) {
			return true;
		}
		//if target value is smaller than current value, move to left
		else if (cd > target) {
			cur = cur->left;
		}
		//if target value is bigger than current value, move to right
		else {
			cur = cur->right;
		}
	}

	return false;
}

//It is function to get root from tree
Node* BStree::getroot() {
	return root;
}

//It is function to remove target value from tree
Node* BStree::remove(Data target) {

	//There are two ways we can use.
	//First, we can make temp root that has root as right node
	//Therefore, we can make code clearer little bit
	//Node* temproot = new Node;
	//temproot->right = root;
	//Node* parent = temproot;

	//Second, we can put some codes to deal with deleting root case
	//Making nodes for parent and current and store root into them
	//Making node to store delete value
	Node* parent = root;
	Node* cur = root;
	Node* del;

	//We need to find target value, so it works until we find value or reach end of tree
	while (cur != NULL && cur->data != target) {

		//Store current to parent to use it later.
		parent = cur;

		//If current value is bigger than target, move to left
		if (cur->data > target) {
			cur = cur->left;
		}
		//If current value is smaller than target, move to right
		else {
			cur = cur->right;
		}
	}

	//If there is no value in the tree, just return NULL with message
	if (cur == NULL) {
		std::cout << "There is no value to remove in the tree" << std::endl;
		return NULL;
	}

	//Now, we found place to remove value, so store current into del node to remove value
	del = cur;

	//Case 1, there is no child for target
	if (del->left == NULL && del->right == NULL) {

		//When root is target to remove, it does not have parent, so just put NULL into root
		if (del == root) {
			root = NULL;
			return del;
		}

		//if target is not root and has parent, we need to know target is left or right side of parent and store NULL for parent
		if (parent->left == del) {
			parent->left = NULL;
		}
		else {
			parent->right = NULL;
		}
	}
	//Case 2. there is only one child for target
	else if (del->left == NULL || del->right == NULL) {

		//Make node to store child for target
		Node* delchild;

		//If target has left child only, store it into delchild
		if (del->left != NULL) {
			delchild = del->left;
		}
		//if target has right child only, store it into delchild
		else {
			delchild = del->right;
		}

		//If target node is root, just make root indicates delchild
		if (del == root) {
			root = delchild;
			return del;
		}

		//If target node is not root and has parent, 
		//we need to decide whether del was left or right for parent to connect delchild to parent of del
		if (parent->left == del) {
			parent->left = delchild;
		}
		else {
			parent->right = delchild;
		}

	}
	//Case 3. there are two child for target node
	//We can choose one of two to replace value
	//1. we can choose biggest value in the left side
	//2. we can choose smallest value in the right side
	//It is based on way 2.
	else {

		//Store right side of target into replace node
		//Store target value into parent of replace node 
		Node* replace = del->right;
		Node* replaceparent = del;
		int deldata;

		//We need to repeat it until last value of left side in right side
		//When it goes to next value, we need to update replaceparent and replace nodes
		while (replace->left != NULL) {
			replaceparent = replace;
			replace = replace->left;
		}

		//Store data in the target value into delete data
		//Store data for replace node that we found above into data in target
		deldata = del->data;
		del->data = replace->data;

		//if the replace node we found is left side of replace parent, store right side of replace node into parent
		//Because we found most left side in right side, there is no left anymore, we just need to connect right of replace to its parent
		if (replaceparent->left == replace) {
			replaceparent->left = replace->right;
		}
		//If there is tree that only has value in the right side
		//We need to think about else case here.
		//Because parent does not have left side, we just need to connect right of replace node to its parent right side
		else {
			replaceparent->right = replace->right;
		}

		//Now we need to store replace node into del because we put this node into target place
		//Therefore, we do not need it from original place
		del = replace;
		del->data = deldata;
	}

	//It is part when I choose first way to deal with root node
	//if (temproot->right != root) {
	//	root = temproot->right;
	//}

	//delete temproot;

	return del;
}

//It is function for preorder
void BStree::preorder(Node* travel) {

	if (travel == NULL) {
		return;
	}

	std::cout << travel->data << std::endl;
	preorder(travel->left);
	preorder(travel->right);


}

//It is function for inorder
void BStree::inorder(Node* travel) {

	if (travel == NULL) {
		return;
	}

	inorder(travel->left);
	std::cout << travel->data << std::endl;
	inorder(travel->right);


}

//It is function for postorder
void BStree::postorder(Node* travel) {

	if (travel == NULL) {
		return;
	}

	postorder(travel->left);
	postorder(travel->right);
	std::cout << travel->data << std::endl;


}



int main() {

	BStree bs;

	bs.insert(8);
	bs.insert(3);
	bs.insert(6);
	bs.insert(2);
	bs.insert(10);
	bs.insert(9);
	bs.insert(11);

	Node* s;


	s=bs.remove(8);
	delete s;



	if (bs.search(4)) {
		std::cout << "There is value you are looking for" << std::endl;
	}
	else {
		std::cout << "There is no value you are looking for" << std::endl;
	}

	bs.inorder(bs.getroot());

}
