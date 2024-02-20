#include <iostream>
using namespace std;

struct Node {
	int data{};
	Node* next{};
	Node* prev{};

	Node(int data):
		data(data){}
};
class DLL {
private:
	Node* head{};
	Node* tail{};
public:	
	void insertNode(int val) {
		Node* new_node = new Node(val);
		if (head == NULL) {
			head = new_node;
			return;
		}

		Node* current = head;
		while (current->next != NULL) {
			current = current->next;
		}

		current->next = new_node;
		new_node->prev = current;
	}
	void inserthead(int value) {
		Node* new_node = new Node(value);
		if (head == NULL) {
			head = new_node;
		}
		else {
			new_node->next = head;
			head->prev = new_node;
			head = new_node;
		}
	}
	void inserttail(int value) {
		Node* new_node = new Node(value);
		if (head == NULL) {
			head = new_node;
		}
		else {
			Node* tail = head;
			while (tail->next != nullptr) {
				tail = tail->next;
			}
			tail->next = new_node;
			new_node->prev = tail;
		}
	}
	Node* removehead() {
		if (head == NULL);
		Node* temp = head;
		head = head->next;
		temp->next = nullptr;
		delete(temp);
		return head;
	}
	Node* removetail() {
		if (head == NULL || head->next == NULL)return NULL;
		Node* temp = head;
		while (temp->next->next != NULL) {
			temp = temp->next;
		}
		delete(temp->next);
		temp->next = nullptr;
		return head;
	}	
	void delete_even_positions() {
		if (head == NULL || head->next == NULL)
			return;
		Node* temp = head;
		Node* prev = nullptr;
		int position = 1;

		while (temp != NULL) {
			if (position % 2 == 0) {
				if (prev == NULL) { // Deleting the head node
					head = temp->next;
					delete temp;
					temp = head;
				}
				else {
					prev->next = temp->next;
					delete temp;
					temp = prev->next;
				}
			}
			prev = temp;
			temp = temp->next;			
			position++;
		}
	}
	void delete_odd_positions() {
		if (head == nullptr || head->next == nullptr)
			return;

		Node* cur = head;
		int position = 1;

		while (cur != nullptr) {
			if (position % 2 != 0) {
				if (cur == head) { // Deleting the head node
					removehead();
				}
				else {
					Node* prev = cur->prev;
					prev->next = cur->next;
					if (cur->next != nullptr)
						cur->next->prev = prev;
					Node* temp = cur;
					cur = cur->next;
					delete temp;
				}
			}
			cur = cur->next;			
			position++;
		}
	}
	void remove_all_nodes_with_key(int value) {
		if (head == NULL)
			return ;
		if (head->data == value)
			removehead();
		Node* temp = head;
		Node* prev = NULL;
		while (temp) {
			if (temp->data == value) {
				prev->next = temp->next;
				delete(temp);
			}
			prev = temp;
			temp = temp->next;
		}
	}
	Node* reverse_list(Node* head) {
		if (head == NULL || head->next == NULL)
			return head;
		Node* last = NULL;
		Node* cur = head;
		while (cur != NULL) {
			//swaping pointers
			last = cur->prev;
			cur->prev = cur->next;
			cur->next = last;
			cur = cur->prev;
		}
		return last->prev;//the new head
		//TC=>o(n)
	}
	bool is_Palindrome() {
		Node* slow = head;
		Node* fast = head;
		while (fast->next != NULL && fast->next->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}
		//reverse the head
		Node* newhead = reverse_list(slow->next);
		Node* first = head;
		Node* second = newhead;
		//comparing the data of the two pointers
		while (second != NULL) {
			if (first->data != second->data) {
				reverse_list(newhead);
				return false;
			}
			first = first->next;
			second = second->next;
		}
		reverse_list(newhead);
		return true;
	}
	void printList() {
		Node* current = head;
		while (current != NULL) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	void printListreversed() {
		Node* current = head;
		while (current != NULL) {
			cout << current->data << " ";
			current = current->prev;
		}
		cout << endl;
	}
};


int main()
{
	DLL list;
	list.insertNode(1);
	list.insertNode(2);
	list.insertNode(3);
	list.insertNode(4);
	list.insertNode(5);
	list.insertNode(4);

	list.printList();
	//list.reverse_list();
	//list.printListreversed();
	//list.deleteNode();
	list.remove_all_nodes_with_key(4);
	list.printList();


}
