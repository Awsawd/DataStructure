//list.h
#include<stdlib.h>

template<class T>
class List
{
	struct Node
	{
		T data;
		Node* prev, * next;
		Node(const T&d=T(),Node* p=NULL,Node* n=NULL):data(d),prev(p),next(n){}
	};

	int size;
	Node* head;
	Node* tail;
	void init()
	{
		size = 0; head = new Node; tail = new Node; head->next = tail; tail->next = head;
	}
	public:
		class const_iterator
		{
		protected:
			Node* current;
			T& retrieve()const { return current->data; }
			const_iterator(Node* p):current(p){}
			friend class List<T>;
		public:
			const_iterator() : current(NULL){}
			const T& operator*()const { return retrieve(); }
			const_iterator& operator++()
			{
				current = current->next;
				return *this;
			}
			const_iterator operator++(int)
			{
				const_iterator old = *this;
				++(*this);
				return old;
			}
			const_iterator& operator--()
			{
				current = current->prev;
				return *this;
			}
			const_iterator operator--(int)
			{
				const_iterator old = *this;
				--*this;
				return old;
			}
			bool operator==(const const_iterator& rhs)const
			{
				return (current == rhs.current);
			}
			bool operator!=(const const_iterator& rhs)const
			{
				return (current != rhs.current);
			}
		};
		
	class iterator:public const_iterator
	{
	protected:
		 iterator(Node* p, Node* node) :const_iterator(p), current(node) {}
		friend class List<T>;
	public:
		iterator() {}
		T& operator*() { return (retrieve()); }
		const T& operator*()const { return const_iterator::operator*(); }
		iterator& operator++()
		{
			current = current->next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}
		iterator& operator--()
		{
			current = current->prev;
			return *this;
		}
		iterator operator--(int)
		{
			iterator old = *this;
			--(*this);
			return old;
		}
	};
	List() { init(); }
	List(const List<T>& l) { init(); operator=(l); }
	~List() { Clear(); delete head; delete tail; }

	const List& operator=(const List& l);
	int Size()const{ return size };
	bool Empty()const { return size == 0; }
	void Clear() { while (!Empty()) Pop_front(); }

	iterator begin() { return (iterator(head->next)); }
	const_iterator begin()const { return (const_iterator(head->next)); }
	iterator end() { return (iterator(tail)); }
	const_iterator end()const { return (const_iterator(tail)); }

	T& Front() { return *begin(); }
	const T& Front()const { return *begin(); }
	T& Back() { return (*--end()); }

	const T& Back()const {return ( *--end()); }
	void Push_front(const T& item) { Insert(begin(), item); }
	void Push_back(const T& item) { Insert(begin(), item); }
	void Pop_front() { Erase(begin()); }
	void Pop_back() { Erase(--end()); }
	iterator Erase(iterator itr);
	iterator insert(iterator itr,const T& item);
};

