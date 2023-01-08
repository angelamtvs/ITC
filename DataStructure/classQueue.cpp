#include <iostream>

class Node {
public:
	int data;
	Node* next;
	Node(int d) {
		data = d;
		next = NULL;
	}
};

class Queue {
private:
	Node* front;
	Node* back;
	int size;
public:
	Queue() {
		front = NULL;
		back = NULL;
		size = 1;
	}
	
	void pop_front() {
		if (front == NULL)
			return;
		Node* temp = front;
		front = front->next;

		if (front == NULL)
			back = NULL;
		delete (temp);
		--size;
	}

	void push_back(int val) {
		Node* temp = new Node(val);
		if (back == NULL) {
			front = temp;
			back = temp;
			return;
		}
		back->next = temp;
		back = temp;
		++size;
	}

	int getSize() {
		return size;
	}

	bool empty() {
		return front == NULL;
	}

	int getFront() {
		return front->data;
	}

	int getBack() {
		return back->data;
	}
};

int main() {
	Queue q;
	q.push_back(10);
	q.push_back(20);
	q.push_back(30);
	q.pop_front();
	std::cout << "The number of elements in queue: " << q.getSize();
	std::cout << "\nThe front element of queue: " << q.getFront();
	std::cout << "\nThe back element of the queue: " << q.getBack();
	std::cout << "\nWhether the queue is empty: " << q.empty();
	std::cout << std::endl;
	return 0;
}