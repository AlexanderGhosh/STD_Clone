#pragma once

namespace alx {
	// double linked list
	template<typename T>
	class list {
		struct ListItem {
			ListItem* _prev;
			ListItem* _next;
			T _item;
		};
	private:
		size_t _size;
		ListItem* _front; 
		ListItem* _back;
	public:
		list() : _size(0), _front(nullptr), _back(nullptr) { }
		
		~list() {
			_front = _front->_next; // step forward once
			while (1) {
				delete _front->_prev; // delete the prev item
				if (_front->_next)
					_front = _front->_next; // continue until reached the end of the list
				else
					break;
			}
			delete _front;
		}

		size_t size() const { return _size; }

		void push_back(const T&& item) {
			ListItem* newItem = new ListItem();
			if (!newItem) throw "cannot allocate memory of required size";
			newItem->_item = item;
			newItem->_prev = _back;
			newItem->_next = nullptr;
			if(_back) _back->_next = newItem;
			_back = newItem;
			if (!_front) _front = newItem;
			++_size;
		}

		void push_front(const T&& item) {
			ListItem* newItem = new ListItem();
			if (!newItem) throw "cannot allocate memory of required size";
			newItem->_item = item;
			newItem->_prev = nullptr;
			newItem->_next = _front;
			if(_front) _front->_prev = newItem;
			_front = newItem;
			if (!_back) _back = newItem;
			++_size;
		}
	};
}