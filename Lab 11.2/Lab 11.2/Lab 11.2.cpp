/*
* This code is licensed under the Creative Commons
* Attribution - NonCommercial - NoDerivatives 4.0 International License.
* To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/
* or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*
*
* https://bezukh.wixsite.com/blog
* https://github.com/BezukhVladimir
*
* © Developed by Bezukh Vladimir. All right reserved.
*/

/*
* Developed by Bezukh Vladimir
* ИВТ-21-2б
*/

#include <iostream>

template <typename T>
class Stack {
public:
	Stack();
	~Stack();

	T top() const;
	size_t size() const;

	void push(const T& data);
	void pop();

	void clear();

private:
	struct Node {
		Node(T data = T(), Node* pointer_to_next_node = nullptr)
			: data(data), pointer_to_next_node(pointer_to_next_node) {}

		Node(const Node& copy)
			: data(copy.data), pointer_to_next_node(copy.pointer_to_next_node) {}

		Node& operator=(const Node& right) {
			if (this != &right) {
				data = right.data;
				pointer_to_next_node = right.pointer_to_next_node;
			}

			return *this;
		}

		T data;
		Node* pointer_to_next_node;
	};

	void pushFirstNode(Node* node);
	void pushFrontNode(Node* node);

	void popFirstNode();
	void popFrontNode();

	size_t stack_size;
	Node* head_node;
};

template<typename T>
Stack<T>::Stack()
	: stack_size(size_t{0}), head_node(nullptr) {}

template<typename T>
Stack<T>::~Stack()
{
	clear();
}

template<typename T>
T Stack<T>::top() const
{
	return head_node->data;
}

template<typename T>
size_t Stack<T>::size() const
{
	return stack_size;
}

template<typename T>
void Stack<T>::push(const T& data)
{
	Node* new_node = new Node(data);
	stack_size ? pushFrontNode(new_node) : pushFirstNode(new_node);
	++stack_size;
}

template<typename T>
void Stack<T>::pop()
{
	if (stack_size == size_t{0}) return;

	Node* remove_node = head_node;
	(stack_size == size_t{1}) ? popFirstNode() : popFrontNode();
	delete remove_node;
	--stack_size;
}

template<typename T>
void Stack<T>::clear()
{
	if (stack_size == size_t{0}) return;

	Node* remove;
	Node* next_node = head_node;

	while (stack_size) {
		remove = next_node;
		next_node = next_node->pointer_to_next_node;
		delete remove;
		--stack_size;
	}

	head_node = nullptr;
}

template<typename T>
void Stack<T>::pushFirstNode(Node* node)
{
	head_node = node;
}

template<typename T>
void Stack<T>::pushFrontNode(Node* node)
{
	node->pointer_to_next_node = head_node;
	head_node = node;
}

template<typename T>
void Stack<T>::popFirstNode()
{
	head_node = nullptr;
}

template<typename T>
void Stack<T>::popFrontNode()
{
	head_node = head_node->pointer_to_next_node;
}

int main()
{
    std::setlocale(LC_ALL, "Russian");
	
	Stack<int> stack;
	for (int i = 1; i != 6; ++i) {
		stack.push(i); std::cout << stack.top() << ' ';
	} std::cout << '\n';

	while (stack.size()) {
		if (stack.size()) std::cout << stack.top() << ' ';
		stack.pop();
	}
}