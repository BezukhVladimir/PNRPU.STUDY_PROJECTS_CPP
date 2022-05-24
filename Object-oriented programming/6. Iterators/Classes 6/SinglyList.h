#pragma once

#include<string>
#include<iostream>

template <typename T>
class SinglyList
{
private:
	struct Node;

public:
	class Iterator
	{
	public:
		Iterator() : current_node(nullptr) {}
		Iterator(Node* node)
			: current_node(node) {}

		T operator*() const { /* std::cout << "YES!" */; return current_node->data; }

		bool operator==(const Iterator& right) const {
			return current_node == right.current_node;
		}

		bool operator!=(const Iterator& right) const {
			return !(*this == right);
		}

		Iterator& operator++() {
			if (current_node != nullptr)
				current_node = current_node->pointer_to_next_node;

			return *this;
		}

		Iterator& operator+(int shift) {
			while (shift--) {
				if (current_node != nullptr)
					current_node = current_node->pointer_to_next_node;
				else
					break;
			}

			return *this;
		}

	private:
		Node* current_node;
	};

public:
	SinglyList();
	~SinglyList();

	size_t size() const;

	void pushBack(const T& data);
	void pushFront(const T& data);

	void popBack();
	void popFront();

	void insert(int index, const T& data);
	void remove(int index);

	void clear();

	Iterator begin() const;
	Iterator end() const;

	T& operator[](const int& index);
	void operator*(const int& multiplier);

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
	void pushBackNode(Node* node);
	void pushFrontNode(Node* node);
	void insertRightToNode(Node* current_node, Node* insert_node);

	void popFirstNode();
	void popBackNode();
	void popFrontNode();
	void removeNextNode(Node* node);

	size_t normalizeIndex(int index) const;
	Node* findNode(const size_t& index) const;

	size_t list_size;
	Node* head_node;
	Node* tail_node;
};

template<typename T>
SinglyList<T>::SinglyList()
	: list_size(size_t{ 0 }), head_node(nullptr), tail_node(nullptr) {}

template<typename T>
SinglyList<T>::~SinglyList()
{
	clear();
}

template<typename T>
size_t SinglyList<T>::size() const
{
	return list_size;
}

template<typename T>
void SinglyList<T>::pushBack(const T& data)
{
	Node* new_node = new Node(data);
	list_size ? pushBackNode(new_node) : pushFirstNode(new_node);
	++list_size;
}

template<typename T>
void SinglyList<T>::pushFront(const T& data)
{
	Node* new_node = new Node(data);
	list_size ? pushFrontNode(new_node) : pushFirstNode(new_node);
	++list_size;
}

template<typename T>
void SinglyList<T>::popBack()
{
	if (list_size == size_t{ 0 }) return;
	Node* remove_node = tail_node;
	(list_size == size_t{ 1 }) ? popFirstNode() : popBackNode();
	delete remove_node;
	--list_size;
}

template<typename T>
void SinglyList<T>::popFront()
{
	if (list_size == size_t{ 0 }) return;
	Node* remove_node = head_node;
	(list_size == size_t{ 1 }) ? popFirstNode() : popFrontNode();
	delete remove_node;
	--list_size;
}

template<typename T>
void SinglyList<T>::insert(int index, const T& data)
{
	Node* new_node = new Node(data);
	if (list_size == size_t{ 0 }) { pushFirstNode(new_node); ++list_size; return; }
	size_t normalize_index = normalizeIndex(index);
	if (normalize_index == size_t{ 0 }) pushFrontNode(new_node);
	else {
		Node* found_node = findNode(--normalize_index);
		insertRightToNode(found_node, new_node);
	}
	++list_size;
}

template<typename T>
void SinglyList<T>::remove(int index)
{
	if (list_size == size_t{ 0 }) { return; }

	Node* remove_node = head_node;
	if (list_size == size_t{ 1 }) { popFirstNode(); delete remove_node; --list_size; return; }

	size_t normalize_index = normalizeIndex(index);
	if (normalize_index == size_t{ 0 }) popFrontNode();
	else if (normalize_index == list_size - size_t{ 1 }) {
		remove_node = tail_node; popBackNode();
	}
	else {
		Node* node = findNode(--normalize_index);
		remove_node = node->pointer_to_next_node;
		removeNextNode(node);
	}
	delete remove_node;
	--list_size;
}

template<typename T>
void SinglyList<T>::clear()
{
	if (list_size == size_t{ 0 }) return;
	Node* remove;
	Node* next_node = head_node;
	while (list_size) {
		remove = next_node;
		next_node = next_node->pointer_to_next_node;
		delete remove;
		--list_size;
	}
	head_node = nullptr;
	tail_node = nullptr;
}

template<typename T>
typename SinglyList<T>::Iterator SinglyList<T>::begin() const
{
	return Iterator(head_node);
}

template<typename T>
typename SinglyList<T>::Iterator SinglyList<T>::end() const
{
	return Iterator(nullptr);
}

template<typename T>
T& SinglyList<T>::operator[](const int& index)
{
	return findNode(normalizeIndex(index))->data;
}

template<typename T>
inline void SinglyList<T>::operator*(const int& multiplier)
{
	if (list_size == size_t{0}) return;

	Node* current_node = head_node;

	while (current_node != nullptr)
	{
		current_node->data *= multiplier;
		current_node = current_node->pointer_to_next_node;
	}
}

template<typename T>
void SinglyList<T>::pushFirstNode(Node* node)
{
	head_node = node;
	tail_node = node;
}

template<typename T>
void SinglyList<T>::pushBackNode(Node* node)
{
	tail_node->pointer_to_next_node = node;
	tail_node = node;
}

template<typename T>
void SinglyList<T>::pushFrontNode(Node* node)
{
	node->pointer_to_next_node = head_node;
	head_node = node;
}

template<typename T>
void SinglyList<T>::insertRightToNode(Node* current_node, Node* insert_node)
{
	insert_node->pointer_to_next_node = current_node->pointer_to_next_node;
	current_node->pointer_to_next_node = insert_node;
}

template<typename T>
void SinglyList<T>::popFirstNode()
{
	head_node = nullptr;
	tail_node = nullptr;
}

template<typename T>
void SinglyList<T>::popBackNode()
{
	Node* node = findNode(list_size - size_t{ 2 });
	removeNextNode(node);
	tail_node = node;
}

template<typename T>
void SinglyList<T>::popFrontNode()
{
	head_node = head_node->pointer_to_next_node;
}

template<typename T>
void SinglyList<T>::removeNextNode(Node* node)
{
	node->pointer_to_next_node = node->pointer_to_next_node->pointer_to_next_node;
}

template<typename T>
size_t SinglyList<T>::normalizeIndex(int index) const
{
	int temp_size = static_cast<int>(list_size);
	index %= temp_size; if (index < 0) index += temp_size;
	return static_cast<size_t>(index);
}

template<typename T>
typename SinglyList<T>::Node* SinglyList<T>::findNode(const size_t& index) const
{
	if (index == size_t{ 0 }) return head_node;
	if (index == list_size - size_t{ 1 }) return tail_node;

	Node* node = head_node;
	for (size_t counter = 0; counter != index; ++counter)
		node = node->pointer_to_next_node;

	return node;
}