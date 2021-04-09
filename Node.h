#pragma once
#ifndef NODE_H_SY_
#define NODE_H_SY_

#include <utility>
using std::swap;

namespace sy
{
	template<typename ElemType>
	struct Node
	{
		Node(ElemType x, Node<ElemType>* l = nullptr, Node<ElemType>* r = nullptr) : data(std::move(x)), lChild(l), rChild(r) {}
		Node(const Node<ElemType>& other) : data(other.data), lChild(other.lChild), rChild(other.rChild) {}
		Node<ElemType>& operator=(const Node<ElemType>& rhs)
		{
			if (this != &rhs)
			{
				Node tmp(rhs);
				swap(tmp);
			}
			return *this;
		}
		Node<ElemType>(Node<ElemType>&& other) noexcept : data(other.data), lChild(other.lChild), rChild(other.rChild)
		{
			other.rChild = nullptr;
			other.lChild = nullptr;
		}
		Node<ElemType>& operator=(Node<ElemType>&& rhs) noexcept
		{
			if (this != &rhs)
			{
				data = rhs.data;
				lChild = rhs.lChild;
				rChild = rhs.rChild;
				rhs.lChild = nullptr;
				rhs.rChild = nullptr;
			}
			return *this;
		}

		~Node() = default;

		ElemType data;
		Node* lChild, * rChild;
	};
}


#endif
