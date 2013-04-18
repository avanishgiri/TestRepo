#include <iostream>
#include "singlyLinked.h"
using namespace std;

int main()
{
	SinglyLinked<int> linked;
	SinglyLinked<int> linked2;

	linked2.insert(4);
	linked2.insert(5);
	linked2.insert(2);

	linked.insert(5);
	linked.insert(6);
	linked.insert(7);
	linked.insert(8);
	linked.print();
	linked.remove(7);
	linked.insert(5);
	linked.insert(5);
	cout << endl;
	linked.print();
	
	linked.removeDuplicates();
	cout << endl;
	linked.print();
	
	int *sex = new int(0);
	cout <<	recursiveNthToLast(linked.head,2,*sex)->getData() << endl << endl;

	linked2.insert(9);
	SinglyLinked<int> sum = addLists(linked, linked2);

	
	linked.insert(12);
	linked.print();

	cout << linked.head->next->next->next->data << endl;; 
	cout << linked.head->next->data << endl;

	linked.head->next->next->next->next = linked.head->next;


	cout << "--"; cout << linked.findCircle()->data;
}

