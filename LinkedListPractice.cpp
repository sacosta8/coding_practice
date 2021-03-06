// BinaryTreePractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Node {
public:
	Node * next;
	string message;

	Node() {
		next = NULL;
	}

	Node(string node_message) {
		next = NULL;
		message = node_message;
	}

	void setMessage(string node_message) {
		message = node_message;
	}

};

class LinkedList {
public:
	Node * head;
	string title;
	int size;

	LinkedList() {
		head = NULL;
		title = "No_Title";
		size = 0;
	}

	LinkedList(Node * new_head) {
		head = new_head;
		title = "No_Title";
		size = 1;
	}

	LinkedList(Node * new_head, string list_title) {
		head = new_head;
		title = list_title;
		size = 1;
	}

	LinkedList(string list_title) {
		head = NULL;
		title = list_title;
		size = 0;
	}
	//Inserting from the front for O(1) time complexity, not O(N) time complexity by moving to the back and placing it at the end
	void insert(Node * node) {
		if (head) {
			Node * temp = head;
			head = node;
			head->next = temp;
			size++;
			return;
		}
		head = node;
		node->next = NULL;
		size++;
		return;
	}
	
	void remove(int index) {
		int counter = 0;
		if (head) {
			if (index == 0) {
				if (head->next) {
					Node * temp = head->next;
					string saved_message = head->message;
					delete head;
					cout << "Deleted index " << counter << " containing message: " << saved_message << endl << endl;
					head = temp;
					size--;
					return;
				}
				delete head;
				head = NULL;
				size--;
				return;
			}
	
			if (!head->next) {
				cout << "remove unsuccessful. Index " << index << " out of bounds" << endl << endl;
			}

			counter++;
			Node * temp = head;
			Node * cur = temp->next;
			while (cur->next) {
				if (index == counter) {
					temp->next = cur->next;
					string saved_message = cur->message;
					delete cur;
					cout << "Deleted index " << counter << " containing message: " << saved_message << endl << endl;
					size--;
					return;
				}
				temp = temp->next;
				cur = cur->next;
				counter++;
			}
			if (index == counter) {
				temp->next = NULL;
				string saved_message = cur->message;
				delete cur;
				cout << "Deleted index " << counter << " containing message: " << saved_message << endl << endl;
				size--;
				return;
			}
		}
		cout << "remove unsuccessful. Index " << index << " out of bounds" << endl << endl;
		return;
	}

	//Used as an update if the size is somehow incorrect. Should not to be used after every insert or deletion because of its O(N) time complexity. Use size variable for the most part. 
	int listSize() {
		int counter = 0;
		if (head) {
			counter++;
			Node * temp = head;
			while (temp->next) {
				temp = temp->next;
				counter++;
			}
		}
		size = counter;
		return counter;
	}
	//Merges two linked lists permanently
	void permanentMerge(LinkedList * other) {
		Node * cur1 = this->head;
		Node * cur2 = other->head;

		if (cur1 && cur2) {
			Node * temp1 = cur1->next;
			Node * temp2 = cur2->next;
			while (cur1->next && cur2->next) {
				cur1->next = cur2;
				cur2->next = temp1;
				cur1 = temp1;
				cur2 = temp2;
				temp1 = cur1->next;
				temp2 = cur2->next;
			}
			if (!temp1 && temp2) {
				cur1->next = cur2;
				other->head = head;
				cout << "Merge successful" << endl << endl;
				return;
			}

			if (temp1 && !temp2) {
				cur1->next = cur2;
				cur2->next = temp1;
				other->head = head;
				cout << "Merge successful" << endl << endl;
				return;
			}

			cur1->next = cur2;
			cur2 = NULL;
			other->head = head;
			cout << "Merge successful" << endl << endl;
			return;

		}
		cout << "Merge unsuccessful" << endl << endl;
		return;
	}

	//O(N) time and space complexity to check if two lists are anagrams of each other
	bool LinkedListAnagram(LinkedList * other) {
		if (size == other->size && head && other->head) {
			map<string, int> map;

			Node * temp = head;
			map.emplace(temp->message,1);
			while (temp->next) {
				temp = temp->next;
				map.emplace(temp->message, 1);
			}
			Node * otherTemp = other->head;
			if (map.count(otherTemp->message) == 0) {
				return false;
			}
			while (otherTemp->next) {
				otherTemp = otherTemp->next;
				if (map.count(otherTemp->message) == 0) {
					return false;
				}
			}
			return true;
			
		}
		return false;
	}

	void printLinkedList() {
		int counter = 0;
		cout << title << ": " << endl << "___________________" << endl << endl;
		if (head) {
			Node * temp = head;
			cout << "Head of "<< title << ": " <<  temp->message << endl;
			counter++;
			while (temp->next) {
				temp = temp->next;
				cout << counter <<  ": " << temp->message << endl;
				counter++;
			}
			cout << endl;
			return;
		}
		cout << "Linked List is empty" << endl << endl;
		return;
	}
};



int main()
{
	cout << "Beginning of insert test: " << endl << "__________________________" << endl << endl;

	LinkedList list1("FIRST LIST");
	list1.insert(new Node("HELLO"));
	list1.insert(new Node("WORLD"));
	list1.insert(new Node("AGAIN"));
	list1.printLinkedList();
	
	LinkedList list2("second list");
	list2.insert(new Node("hello"));
	list2.insert(new Node("world"));
	list2.insert(new Node("again"));
	list2.printLinkedList();

	LinkedList list3("THIRD LIST");
	list3.insert(new Node("HELLO"));
	list3.insert(new Node("WORLD"));
	list3.insert(new Node("AGAIN"));
	list3.insert(new Node("title"));
	list3.insert(new Node("card"));
	list3.printLinkedList();

	cout << "End of insert test: " << endl << "__________________________" << endl << endl;

	cout << "Beginning of list size test" << endl << "__________________________" << endl << endl;

	list1.printLinkedList();
	cout << "Size: " << list1.listSize() << endl << endl;
	list2.printLinkedList();
	cout << "Size: " << list2.listSize() << endl << endl;

	cout << "End of list size test " << endl << "__________________________" << endl << endl;

	cout << "Beginning of permanent merge test: " << endl << "__________________________" << endl << endl;

	list1.permanentMerge(&list2);
	list1.printLinkedList();
	list2.printLinkedList();

	cout << "End of permanent merge test " << endl << "__________________________" << endl << endl;

	cout << "Beginning of anagram test: " << endl << "__________________________" << endl << endl;

	

	if (!list1.LinkedListAnagram(&list3)) {
		cout << list1.title << " is not an anagram of " << list3.title << endl << endl;
	}
	else {
		cout << list1.title << " is an anagram of " << list3.title << endl << endl;
	}

	if (!list1.LinkedListAnagram(&list2)) {
		cout << list1.title << " is not an anagram of " << list2.title << endl << endl;
	}
	else {
		cout << list1.title << " is an anagram of " << list2.title << endl << endl;
	}

	cout << "End of anagram test " << endl << "__________________________" << endl << endl;

	cout << "Beginning of deletion test: " << endl << "__________________________" << endl << endl;

	list1.printLinkedList();
	list1.remove(2);
	list1.printLinkedList();
	list1.remove(0);
	list1.printLinkedList();
	list1.remove(3);
	list1.printLinkedList();
	list1.remove(3);
	list1.printLinkedList();

	cout << "End of deletion test " << endl << "__________________________" << endl << endl;


	int t; 
	cin >> t;
    return 0;
}

