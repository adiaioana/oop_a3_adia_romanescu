#pragma once
template<class T> class ArrayIterator {

private:
	T** val;

public:

	ArrayIterator() {
		val = new T*;
	}
	ArrayIterator(T** al) {
		val = al;
	}
	ArrayIterator& operator ++ () {
		val++;
		return *this;
	}

	ArrayIterator& operator -- () {
		val--;
		return *this;
	}

	bool operator= (ArrayIterator<T>& other) {
		this.val = other.val;
		return *this;
	}


	bool operator!=(ArrayIterator<T>& other)
	{
		return (val != other.val);
	}

	T* GetElement() {
		return *val;
	}

	T* operator*()
	{
		return *val;
	}
};

