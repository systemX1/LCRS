#pragma once
#ifndef PARENT_CHILD_FOREST_H_SY_
#define PARENT_CHILD_FOREST_H_SY_

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <utility>
using std::swap;

#include "fmt/core.h"

#include "Node.h"

namespace sy
{
	// Left-Child Right-Sibling Representation of Forest(LCRS)
	template<typename ElemType>
	class LCRS
	{
	public:
		// Constructor and Destructor
		LCRS() : root_(nullptr) {}
		LCRS(const vector<int>& parent, const vector<string>& elem) : root_(nullptr) {}
		LCRS(const LCRS& other) : root_(other.root_) {}
		LCRS& operator=(const LCRS& rhs)
		{
			if (this != &rhs)
			{
				LCRS tmp(rhs);
				swap(tmp);
			}
			return *this;
		}
		static void destroyForest(Node<ElemType>* cur);
		~LCRS() { destroyForest(root_); }


		
		void reset(const vector<int>& parent, const vector<string>& elem, int size);
		Node<ElemType>* createBTree(const vector<int>& parent, const vector<string>& elem, int root_idx, int size);

		void printLCRS() const { displayForest("", root_, false); }
		void displayForest(const string& str, const Node<ElemType>* cur, bool isLeft) const;

		

	private:
		Node<ElemType>* root_;
	};




}

#endif
