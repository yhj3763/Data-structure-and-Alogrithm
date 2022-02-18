#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* link;
};


void Insert(Node** head, int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->link = NULL;
	if (*head != NULL) temp->link = *head;
	*head = temp;


}
void Print(Node* head)
{
	cout << "List is: ";
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->link;
	}
	cout << endl;
}


int main()
{
	Node* head = NULL;
	cout << "How many numbers?" << endl;
	int n,x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the number \n";
		cin >> x;
		Insert(&head, x);
		Print(head);
	}

}
