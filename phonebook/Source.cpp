#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

void addRecord();

struct Node {
	/*main structure for the dynamic implementation is here.*/
	string name;
	int number;
	Node *next;//This points the next node

};

struct Node *start;
Node *head = NULL;
	

struct Node_list {
	/*In this secition I am creating a list to control all the functions in here*/
	
	int counter;
	int counter2;
	Node *traverse = NULL;
	Node * x;
	Node * prePtr;

	string searchedname;

	
	void addRecord();	
	void print_list(Node *x);
	void list_alphabetically(Node *start);
	void ÝnsertBegining();
	void Ýnsertatmiddle(Node *start);
	void insertAtEnd(Node *start); 
	void UpdateRecord(Node *start);
	void search(Node *start,string isim);
	void bubbleSort(Node * start,int counter);
	void swap(Node * a, Node * b);
	
};


//this function list the phone book non-alphabetically
void Node_list::print_list(Node *x) {


	
	
	while (x !=NULL) {//while node does not equal to null(this means at the end of the node)this function prints the name and number 
		
		cout << x->name << endl;
		cout << x->number << endl;
		x = x->next;

	}

};

void Node_list::list_alphabetically(Node*start)
{
	bubbleSort(start, counter);//before the list alphabetically I use bubblesort to sort string values
	print_list(start);//then it prints the list as alphabetically

}


void Node_list::ÝnsertBegining()
{
	int counter = 0;
	if (traverse = NULL) {//to control whether the beggining node is empty or not,then it is create a node and getting values for node

		traverse = traverse->next;
		traverse = new Node;

		cout << ("Enter a number ");
		cin >> traverse->number;
		cout << ("Enter a name ");
		cin >> traverse->name;
		traverse->next = head;
		head = traverse;

	}
	else {
		while (traverse) {//this is going at the end of the node


			traverse = traverse->next;


		}
		traverse = new Node;//to add a new node it creates a new one

		cout << ("Enter a number ");//then it gets the values
		cin >> traverse->number;
		cout << ("Enter a name ");
		cin >> traverse->name;
		traverse->next = head;
		head = traverse;
		counter++;//counter is for checking the list is empty or not basically,I use this value for another functions.It is global value
	}
}

void Node_list::Ýnsertatmiddle(Node *start)
{
	Node*new_node;
	new_node = new Node;
	Node* x = start;
	Node* pretraverse = start;
	Node*traverse = start;
	int len = 0;

	while (x != NULL) {
		x = x->next;
		len++;
	}
	if (len % 2 == 0) {
		for (int i = 0; i <((len) / 2);i++) {

			pretraverse = traverse;
			traverse = traverse->next;
			
		}
		cout << ("Enter a number ");
		cin >> new_node->number;
		cout << ("Enter a name ");
		cin >> new_node->name;
		new_node->next = pretraverse->next;

		/*move the next of prev_node as new_node */
		pretraverse->next = new_node;
	}
	else {
		for (int i = 0; i < ((len + 1) / 2);i++) {
			pretraverse = traverse;
			traverse = traverse->next;
		}

		cout << ("Enter a number ");
		cin >> new_node->number;
		cout << ("Enter a name ");
		cin >> new_node->name;
		new_node->next = pretraverse->next;

		/*move the next of prev_node as new_node */
		pretraverse->next = new_node;
	}
	

}
	


void Node_list::insertAtEnd(Node *start)
{
	Node*new_node;
	new_node = new Node;
	Node *traverse = start;
	while (traverse->next != NULL) {
		traverse = traverse->next;
		traverse->next = new_node;
	}
	cout << ("Enter a number ");
	cin >> new_node->number;
	cout << ("Enter a name ");
	cin >> new_node->name;


}

void Node_list::UpdateRecord(Node * start)
{

	int counter2 = 0;
	string isim2;
	Node* start4 = start;
	Node* prestart4 = start;
	string updatesearch;
	cout << "Enter a name to update contact" << endl;
	cin >> updatesearch;

	while (start4 != NULL) {//It is same as the search function
		isim2 = start4->name;
		if (isim2 == updatesearch) {
			
			counter2++;
			updatesearch = isim2;
		}
		prestart4 = start4;
		start4 = start4->next;
		if (counter == 1) {
			return;
		}



	}
	if (counter2 == 0) {
		cout << "There is no contact in this name" << endl;
		return;
	}
	
	
	
	else {

		//changing name or number

		string choose;
		cout << "To change the name press 1, To change the number press 0,To change both press 2. " << endl;
		cin >> choose;
		if (choose == "1") {
			string changedname;
			cout << "Enter a new name" << endl;
			cin >> changedname;
			prestart4->name = changedname;
		}
		else if (choose == "0") {
			int changednumber;
			cout << "Enter a new number" << endl;
			cin >> changednumber;
			prestart4->name = changednumber;
		}
		else if (choose == "2") {

			string changedname;
			cout << "Enter a new name" << endl;
			cin >> changedname;
			prestart4->name = changedname;

			int changednumber;
			cout << "Enter a new number" << endl;
			cin >> changednumber;
			prestart4->name = changednumber;

		}
	}

		
	
		
	
}

void Node_list::search(Node * start,string isim)
{
	int counter2 = 0;
	string isim2;
		Node* start3 = start;
		while (start3 != NULL) {
			isim2 = start3->name;
			if (isim2 == isim) {//checking the desired name 
				cout << start3->number<<endl;
				counter2++;
				searchedname = isim2;
			}
			start3 = start3->next;
			if (counter == 1) {//if start3 ->next is null it returns the main function
				return;
			}
			


		}
		if (counter2 == 0) {
			cout << "There is no contact in this name" << endl;
		}
}



void Node_list::bubbleSort(Node * start,int counter)//it sorts the phone list via to string values(I used strcmp function to compare the names)
{
	Node *start2 = start;
	Node * preptr;
	for (int i = counter; i > 0; i--) {
		
		string a = start2->name;
		preptr = start2;
		start2 = start2->next;
		
		if (counter == 1) {
			return;
		}
		string b = start2->name;
		int cmpvalue = strcmp(a.c_str(),b.c_str());
		if (cmpvalue > 0) {
			swap(preptr,start2->next);
		}
		
	}

}




/* function to swap data of two nodes a and b*/
void Node_list::swap(struct Node *a, struct Node *b)
{
	string temp = a->name;
	a->name = b->name;
	b->name = temp;

	int temp1 = a->number;
	a->number = b->number;
	b->number = temp1;
}

              
void Node_list::addRecord() {

	int counter = 0;
	if (traverse = NULL) {
		
		traverse = traverse->next;
		traverse = new Node;

		cout << ("Enter a number ");
		cin >> traverse->number;
		cout << ("Enter a name ");
		cin >> traverse->name;
		traverse->next = head;
		head= traverse;
		
	}
	else {
		while (traverse) {
			
			
			traverse = traverse->next;

			
		}
		traverse = new Node;

		cout << ("Enter a number ");
		cin >> traverse->number;
		cout << ("Enter a name ");
		cin >> traverse->name;
		traverse->next = head;
		head = traverse;
		counter++;//counter is for checking the list is empty or not basically,I use this value for another functions.It is global value
	}

	//bubbleSort(head, counter);
	//print_list(head);


	

}




int main() {


	
	Node_list list;
	

	
	
		string isim;
		int countermain = 0;
		string command;
		
		cout << "To begin with adding a new Record press 1" << endl;
		
		list.addRecord();
		while (1) {
			cout << "To exit PRESS 0" << endl;
			cout << "To add a new Record PRESS 1" << endl;
			cout << "To list the phonebook alphabetically PRESS 2" << endl;
			cout << "To search name press PRESS 3" << endl;
			cout << "To update record press PRESS 4" << endl;
			cout << "To insert at the beggining PRESS 5" << endl;
			cout << "To insert at the middle PRESS 6" << endl;
			cout << "To insert at the end PRESS 7" << endl;
			cout << "To print list non-alphabetically PRESS 8" << endl;
			cin >> command;
			if (command == "0") {
				break;
			}
			if (command == "1") {
				list.addRecord();
			}
			else if (command == "2") {
				list.list_alphabetically(head);
			}
			else if (command == "3") {
				cout << "Search name" << endl;
				cin >> isim;
				list.search(head, isim);
			}
			else if (command == "4") {
				list.UpdateRecord(head);
			}
			else if (command == "5") {
				list.ÝnsertBegining();
			}
			else if (command == "6") {
				list.Ýnsertatmiddle(head);
			}
			else if (command == "7") {
				list.insertAtEnd(head);
			}
			else if (command == "8") {
				list.print_list(head);
			}
			else {
				cout << "Please enter a appropriate number" << endl;
			}
			if (command == "0") {
				break;
			}
		}
		
	
	return 0;

}

void addRecord() {

}