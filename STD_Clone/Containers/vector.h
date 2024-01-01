#pragma once

namespace alx {
	// continuouse block of memory on the stack
	// NOT IMPLEMENTED beacuse it needs a custom allocator (memory pool) because the default doesnt support arrays of size non const
	template<typename T>
	class vector_s {
	private:
		size_t size_;
		T* data_;
	public:
		vector_s() : size_(0), data_(nullptr) { throw "not implemented"; }
		vector_s(size_t size) : size_(size), data_(nullptr) {
			throw "not implemented";
			T temp[size];
			data_ = std::move(temp);
			temp = nullptr;
		}

		// makes sure there is enough capacity but doesnt change 
		void reserve();

		void push_back(const T& value);
		void push_front(const T& value);
	};
}
