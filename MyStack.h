#pragma once
template <typename T, size_t size>
class MyStack
{
	T m_data[size];
	size_t m_size;
public:
	MyStack();
	MyStack(size_t N, T&& val = T());
	void push(const T& elem);
	T pop(); 
	T& operator[](size_t ind); 
};


template <typename T, size_t size>
MyStack<T, size>::MyStack()
{
	for (size_t i = 0; i < size; i++)
	{
		m_data[i] = T();
	}
	m_size = size;
}

template <typename T, size_t size>
MyStack<T, size>::MyStack(size_t N, T&& val)
{
	if (N > size)
	{
		throw std::out_of_range("ERROR! Out of range!");
	}
	m_size = N;
	for (size_t i = 0; i < N; i++)
	{
		m_data[i] = val;
	}

}

template <typename T, size_t size>
void MyStack<T, size>::push(const T& elem)
{
	if (m_size == size) {
		throw std::out_of_range("ERROR! MyStack is full.");
	}
	m_data[m_size] = elem;
	m_size++;
}

template <typename T, size_t size>
T MyStack<T, size>::pop()
{
	if (m_size == 0) {
		throw std::out_of_range("ERROR! MyStack is empty.");
	}
	return std::move(m_data[m_size--]);
}

template <typename T, size_t size>
T& MyStack<T, size>::operator[](size_t ind)
{
	if (ind < m_size) {
		return m_data[ind];
	}
	else {
		throw std::out_of_range("Wrong index!");
	}
}