#include <iostream>
#include <set>
#include <map>

using namespace std;
template <class T>
class SinglyLinked;

template <class T>
class ListNode
{
	private:
	public:
		ListNode<T> *next;
		T data;
		T getData()
		{
			return data;
		}
		ListNode(T arg_data, ListNode<T> *arg_next) : data(arg_data), next(arg_next)
		{
		}
		friend class SinglyLinked<T>;
};


template <class T>
class SinglyLinked
{
	public:
		ListNode<T> *head;
		SinglyLinked() : head(NULL)
		{
		}
		void insert(T data)
		{
			ListNode<T> *node = new ListNode<T>(data, NULL);
			node->next = head;
			head = node;
		}

		ListNode<T> * findNthToLast(int n)
		{
			//assume n is less than length
			ListNode<T> *node = head;
			ListNode<T> *trailer = head;
			for(int i = 0; i < n-1; i++)
			{
				if( !node )
					return NULL;
				node = node->next;
			}

			while(node->next)
			{
				node = node->next;
				trailer = trailer->next;
			}
				
			return trailer;
		}

		void remove(T arg_data)
		{
			ListNode<T> *node = head;
			if(node->data == arg_data)
			{
				head = head->next;
				delete node;
				return;
			}
			while(node->next)
			{
				if(node->next->data == arg_data)
					break;
				node = node->next;
			}
			ListNode<T> *found = node->next;
			node->next = node->next->next;
			delete found;
		}

		void removeDuplicates()
		{
			map<T, bool> listData;

			ListNode<T> *node;
			ListNode<T> *prev = node;
			for(node = head; node; node = node->next)
			{
				if(listData.find(node->data) != listData.end())
				{
					prev->next = node->next;
					delete node;
				}
				else
				{
					listData.insert( pair<T, bool>(node->data, 1));
				}
				prev = node;
			}
		}

		void print()
		{
			ListNode<T> *node;
			for(node = head; node; node = node->next)
			{
				cout << node->data << endl;
			}
			cout << endl;
		}
	
ListNode<T> * findCircle()
{
	map<ListNode<T>*, bool> addresses;

	ListNode<T>* node = head;

	while(node)
	{
		if(addresses.find(node) != addresses.end())
		{
			return node;
		}
		else
			addresses.insert(pair<ListNode<T>*,bool>(node, 1));

		node = node->next;
	}

	return NULL;
	
}
	
void insertAtEnd(T arg_data)
{
	
	ListNode<T> *node = head;
	if(!node)
	{
		head = new ListNode<T>(arg_data, NULL);
		return;
	}
	while(node->next)
		node = node->next;
	
	ListNode<T> *newNode = new ListNode<T>(arg_data, NULL);

	node->next = newNode;
}

};

template <class T>
void removeNode(ListNode<T> *node)
{
	ListNode<T> *nextNode = node->next;

	node->next = nextNode->next;
	node->data = nextNode->data;

	delete nextNode;
}

template <class T>
ListNode<T>* recursiveNthToLast(ListNode<T> *node, int n, int& count)
{
	if(!node)
	{
		count = 1;
		return 0;
	}
	ListNode<T>* retval = recursiveNthToLast(node->next, n, count);
	if( n == count)
		retval = node;
	count = count + 1;
	
	return retval;
}

SinglyLinked<int>& addLists(SinglyLinked<int>& ll1, SinglyLinked<int>& ll2)
{
	SinglyLinked<int> *sumList = new SinglyLinked<int>;

	ListNode<int> *node1 = ll1.head; ListNode<int> *node2 = ll2.head;

	int sum, carry = 0;
	while(node1 || node2)
	{
		if(node1)
			sum += node1->data;
		if(node2)
			sum += node2->data;
		sum += carry;

		carry = 0;
		sumList->insertAtEnd(sum%10);
		if(sum > 9)
		{
			carry = 1;
		}
		sum = 0;
		if(node1)
			node1 =  node1->next;
		if(node2)
			node2 = node2->next;
	}
	return *sumList;
}
	
