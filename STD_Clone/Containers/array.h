#pragma once

namespace alx {
	// an arry of continuous memory of size n on the stack
	template<typename T, size_t n>
	class array_s {
	private:
		T data_[n];
		size_t bytes() const { return n * sizeof(T); }
	public:
		array_s() = default;
		array_s(T* data) {
			memset(data_, data, n);
		}

		void fill(const T& value) {
			memset(&data_[0], value, bytes());
		}
		size_t size() const { return n; }

		const T& at(size_t idx) const { return data_[idx]; }
		T& at(size_t idx) { return data_[idx]; }

		const T& operator[](size_t idx) const { return at(idx); }
		T& operator[](size_t idx) { return at(idx); }
	};

	// an arry of continuous memory of size n on the heap
	template<typename T, size_t n>
	class array_h {
	private:
		T* data_;

		size_t bytes() const { return n * sizeof(T); }
	public:
		array_h() : data_(nullptr) {
			data_ = new T[n];
		}
		~array_h() {
			delete[] data_;
		}
		// copy constructor
		array_h(const array_h& b) : data_(nullptr) {
			memcpy(data_, b.data_, bytes());
		}
		// copy asignment
		array_h operator=(const array_h& b) = delete;

		// move constructor
		array_h(array_h&& b) {
			delete[] data_;
			data_ = b.data_;
			b.data_ = nullptr; // this is done so when b's destructor is called (at the end of this function?)  it doesnt delete the array data
		}

		// move asignment
		array_h& operator=(array_h&& b) {
			delete[] data_;
			data_ = b.data_;
			b.data_ = nullptr;
			return *this;
		}

		void fill(const T& value) {
			memset(data_, value, bytes());
		}
		size_t size() const { return n; }

		const T& at(size_t idx) const { return data_[idx]; }
		T& at(size_t idx) { return data_[idx]; }

		const T& operator[](size_t idx) const { return at(idx); }
		T& operator[](size_t idx) { return at(idx); }
	};
}
