#include <iostream>

class Vector{
private:
	int* arr;
	unsigned int capacity;
	unsigned int current;
public:
	Vector() {
		std::cout << "Default constructor called.\n";
		arr = new int[1];
		capacity = 1;
		current = 0;
	}

	Vector(int size, int defaultValue) {
		std::cout << "Constructor with parametres called.\n";
		arr = new int[size];
		for (int i = 0; i < size; ++i)
			arr[i] = defaultValue;

		capacity = size;
		current = size;
	}

	void push(int val) {
		if (current == capacity) {
			int* temp = new int[2 * capacity];

			for (int i = 0; i < capacity; ++i)
				temp[i] = arr[i];

			delete[] arr;
			capacity *= 2;
			arr = temp;
		}
		arr[current] = val;
		++current;
	}

	void pop() {
		--current;
	}

	void insert(int index, int data) {
		if (index == capacity)
			push(data);
		else {
			if (index < current) {
				int* temp = new int[capacity + 1];
				for (int i = 0; i < index; ++i)
					temp[i] = arr[i];
				temp[index] = data;
				++capacity;
				for (int j = index + 1; j < capacity + 1; ++j)
					temp[j] = arr[j - 1];
				delete [] arr;
				arr = temp;
			}
			++current;
		}
	}

	int size() {
		return current;
	}

	int getCapacity() {
		return capacity;
	}

	int& operator [] (int n) {
		if (n > capacity)
			std::cout << "There is no such position.\n";	
		return arr[n];
	}

	void print() {
		for (int i = 0; i < current; ++i)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
};

int main() {
	Vector v;
	v.print();
	Vector v1(3, 2);
	v1.print();

	std::cout << "Vector after push(4):\n";
	v1.push(4);
	v1.print();

	std::cout << "Vector after pop method:\n";
	v1.pop();
	v1.print();
	
	std::cout << "Vector after insert 8 value at 1 index:\n";
	v1.insert(1, 8);
	v1.print();

	std::cout << "The number of elements in the vector:\n";
	std::cout << v1.size() << std::endl;

	std::cout << "The size of the storage space currently allocated for the vector:\n";
	std::cout << v1.getCapacity() << std::endl;

	std::cout << "The value at position 2:\n";
	std::cout << v1[2] << std::endl;

	return 0;
}