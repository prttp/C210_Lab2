#pragma once
template <typename T>
class MyStack2
{
	class Node
	{
	public:
		T m_data;
		Node* pNext;
		Node(const T& data):m_data(data) {};
	};
	Node* m_pHead;
public:
	MyStack2() { m_pHead = nullptr; size = 0; }
	~MyStack2();
	MyStack2(const MyStack2&);
	MyStack2<T> operator=(const MyStack2& s);

	size_t size;
	void push(const T&);
	void pop(); 
	T& last() const; // return the last element
private:
	void Print(std::ostream&, Node*) const;
	void Clone(Node*, Node*);
	template <typename T> friend std::ostream& operator<< (std::ostream& o, const MyStack2<T>& stack);
};

template <typename T>
MyStack2<T>::MyStack2(const MyStack2& s)
{
	Node* ps = s.m_pHead;
	for (size_t i = 0; i < s.size; i++) {
		push(ps->m_data);
		ps = ps->pNext;
	};
	size = s.size;
	
}

template <typename T>
void MyStack2<T>::Clone(Node* node, Node* p) // push nodes (all before <p>) in "right" order 
{
	
	if (node->pNext && node->pNext != p)

	{
		Clone(node->pNext, p);
	}
	push(node->m_data);
	

}

template <typename T>
MyStack2<T> MyStack2<T>::operator=(const MyStack2& s)
{
	if (this != &s) ////////////////////////////FLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAG
	{
		Node* p = m_pHead;
		Node* ps = s.m_pHead;
		Node* tmp = p;
		if (size <= s.size) {
			while (p != 0) {
				p->m_data = ps->m_data;
				tmp = p;
				p = p->pNext;
				ps = ps->pNext;
				
			} 
			if (size == 0) { push(ps->m_data); tmp = m_pHead; ps = ps->pNext;}
			for (size_t i = size; i < s.size; i++) {
				
				tmp->pNext = new Node(ps->m_data);
				tmp = tmp->pNext;
				ps = ps->pNext;
				
			}
			size = s.size;	///Clone(ps, p);
			tmp->pNext = nullptr;
			
		}
		else {
			for (size_t i = 0; i < s.size; i++) {
				p->m_data = ps->m_data;
				tmp = p;
				p = p->pNext;
				ps = ps->pNext;
			}
			for (size_t i = s.size; i < size; i++) {
				ps = p->pNext;
				delete p;
				p = ps;
			}
			
			tmp->pNext = nullptr;
			size = s.size;
		}// TODO: insert return statement here

		return *this;

	}
}

template <typename T>
void MyStack2<T>::push(const T& data)
{
	Node* node = new Node(data);
	if (size == 0) { node->pNext = nullptr; }
	else {
		node->pNext = m_pHead;
	}
	m_pHead = node;
	size++;
}

template <typename T>
T& MyStack2<T>::last() const
{
	if (!m_pHead)
	{
		throw std::out_of_range("Error! MyStack2 is empty.");
	}
	else {
		return m_pHead->m_data;
	}
}

template <typename T>
void MyStack2<T>::pop()
{
	if (!m_pHead)
	{
		throw std::out_of_range("Error! MyStack2 is empty.");
	}
	else
	{
		Node* tmp = m_pHead->pNext;
		delete m_pHead;
		m_pHead = tmp;
		size--;
	}
}

template<typename T>
std::ostream& operator<< (std::ostream& o, const MyStack2<T>& stack)
{
	if (stack.m_pHead)
	{
		stack.Print(o, stack.m_pHead);
		o << stack.m_pHead->m_data;
	}
	return o;
}

template <typename T>
void MyStack2<T>::Print(std::ostream& o, Node* node) const
{
	node = node->pNext;
	if (node)
	{
		Print(o, node);
		o << node->m_data;
	}
}
//template <typename T>
//void MyStack2<T>::Print(std::ostream& o, Node* node) const
//{
//	
//	if (node)
//	{
//		Print(o,  node->pNext;);
//		o << node->m_data;
//	}
//}
template <typename T>
MyStack2<T>::~MyStack2()
{
	Node* tmp = m_pHead;
	for (size_t i = 0; i < size; i++)
	{
		m_pHead = tmp->pNext;
		delete tmp;
		tmp = m_pHead;
	}
}