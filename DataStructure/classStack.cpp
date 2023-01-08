#include <iostream>

class Node {
public:
	int data;
	Node* link;
};

class Stack{
private:
	Node* top;
	int size;
public:
	Stack() {
		top = NULL;
		size = 0;
	}

	void pop() {
		Node* temp;
		if (top == NULL) {
			std::cout << "Stack overflow.\n";
			exit(1);
		}
		else {
			temp = top;
			top = top->link;
			temp->link = NULL;
			free(temp);
			--size;
		}

	}

	void push(int data) {
		Node* temp;
		temp = new Node();
		if (!temp) {
			std::cout << "Heap overflow.\n";
		}
		temp->data = data;
		temp->link = top;
		top = temp;
		++size;
	}

	int getSize() {
		return size;
	}

	bool empty() {
		return top == NULL;
	}

	int topEl() {
		if (!empty())
			return top->data;
		else
			exit(1);
	}

	void print() {
		Node* temp;
		if (top == NULL)
			std::cout << "\nStack underflow.\n";
		else {
			temp = top;
			while (temp != NULL) {
				std::cout << temp->data << "->";
				temp = temp->link;
			}
		}
	}
};

int main() {
	Stack st;
	st.push(11);
	st.push(22);
	st.push(33);
	
	st.print();

	std::cout << "\nTop element is " << st.topEl() << std::endl;

	st.pop();

	st.print();
	std::cout << "\nThe number of elements in the stack is: " << st.getSize();
	std::cout << std::endl;
	std::cout << "Whether the stack is empty: " << st.empty() << std::endl;
	return 0;
}