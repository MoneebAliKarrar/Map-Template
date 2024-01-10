#ifndef MAP_H
#define MAP_H
#include "Employee.h"
#include <iostream>
using namespace std;
template <typename Key, typename Value> class Map {
  private:
	struct Node {
		Key key;
		Value value;
		Node* next;
		Node(const Key& k, const Value& v) : key(k), value(v), next(nullptr) {}
	};
	Node* head;

  public:
	Map() : head(nullptr){};
	~Map();
	Map(const Map& other);
	void add(const Key& k, const Value& v);
	Map& operator=(const Map& other);
	Value* find(const Key& key) const;

	friend ostream& operator<<(ostream& os, const Map& mape)
	{
		typename Map<Key, Value>::Node* current = mape.head;
		while (current != nullptr) {
			os << "Key: " << current->key << ", Value: " << current->value
			   << endl;
			current = current->next;
		}
		return os;
	}
};

template <typename Key, typename Value> Map<Key, Value>::~Map()
{
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}
template <typename Key, typename Value>
Map<Key, Value>::Map(const Map& other) : head(nullptr)
{
	Node* current = other.head;
	while (current != nullptr) {
		add(current->key, current->value);
		current = current->next;
	}
}
template <typename Key, typename Value>
void Map<Key, Value>::add(const Key& k, const Value& v)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->key == k) {
			// Key already exists, ignore the new value and return
			return;
		}
		current = current->next;
	}
	Node* newnode = new Node(k, v);
	if (head == nullptr || newnode->key < head->key) {
		newnode->next = head;
		head = newnode;
	}
	else {
		Node* current = head;
		while (current->next != nullptr && newnode->key > current->next->key) {
			current = current->next;
		}
		newnode->next = current->next;
		current->next = newnode;
	}
}
template <typename Key, typename Value>
Map<Key, Value>& Map<Key, Value>::operator=(const Map& other)
{
	if (this != &other) {
		while (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		Node* current = other.head;
		while (current != nullptr) {
			add(current->key, current->value);
			current = current->next;
		}
	}
	return *this;
}
template <typename Key, typename Value>
Value* Map<Key, Value>::find(const Key& key) const
{
	Node* current = head;
	while (current != nullptr) {
		if (current->key == key) {
			return &(current->value);
		}
		else {
			current = current->next;
		}
	}
	return nullptr;
}

#endif // MAP_H
