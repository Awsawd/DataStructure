#include<iostream>
#include"BTNode.h"
#include "Queue.h"
template<class T>
BTNode<T>* GetNewNode(const T& item, BTNode<T>* lp = NULL, BTNode<T>* rp = NULL)
{
	BTNode<T>* p;
	p = new BTNode<T>(item, lp, rp);
	if (p == NULL)
	{
		cerr << "Memory allocation failure!" << endl;
		exit(1);
	}
	return p;
}

template<class T>
void Level(const BTNode<T>* t)
{
	if (t == NULL)
		return;
	Queue < const BTNode<T>* >Q;
	Q.Push(t);
	while (!Q.Empty)
	{
		t = Q.Pop();
		cout << t->data;
		if (t->left)
			Q.Push(t->left);
		if (t->right)
			Q.Push(t->right);
	}

	int main()
	{
		BTNode<char>* nullp = NULL;
		BTNode<char>* fp = GetNewNode('F');
		BTNode<char>* dp = GetNewNode('D', fp);
		BTNode<char>* bp = GetNewNode("B", nullp, dp);
		BTNode<char>* ep = GetNewNode('E');
		BTNode<char>* cp = GetNewNode('C', nullp, ep);
		BTNode<char>* ap = GetNewNode('A', bp, cp);
		Level(ap);
		cout << endl; 
		return 0;
	}
}