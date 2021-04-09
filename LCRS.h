#pragma once
#ifndef PARENT_CHILD_FOREST_H_SY_
#define PARENT_CHILD_FOREST_H_SY_

#include <vector>
using std::vector;

#include <queue>
using std::queue;

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


		// destroy and rebuild the forest
		void reset(const vector<int>& parent, const vector<string>& elem, int size);
		// create a new tree from empty
		Node<ElemType>* createBTree(const vector<int>& parent, const vector<string>& elem, int root_idx, int size);

		void printLCRS() const { displayForest("", root_, false); }
		// display LCRS BTree
		void displayForest(const string& str, const Node<ElemType>* cur, bool isLeft) const;
		// print the result of 3 ways of traversal
		void printTraverseForest() const;
		// preorder traversal of binary tree 
		void preorderRootTraversal(Node<ElemType>* cur, vector<ElemType>& ret) const;
		// inorder traversal of binary tree 
		void inorderRootTraversal(Node<ElemType>* cur, vector<ElemType>& ret) const;
		// postorder traversal of binary tree 
		void postorderRootTraversal(Node<ElemType>* cur, vector<ElemType>& ret) const;
		// level-order-traversal
		void levelOrderTraversal(vector<ElemType>& ret) const;

		// print extra info 
		void printExtraInfo() const;
		// get the num of forest's trees
		int getForestTreeNum() const;
		// get the max height of forest's trees
		int getForestHeight(Node<ElemType>* cur) const;
		// get the num of forest's leaves
		int getForestLeafNum(Node<ElemType>* cur) const;
		// get the height of BTree
		int getBTreeHeight(Node<ElemType>* cur) const;
		// get the num of BTree's leaves
		int getBTreeLeafNum(Node<ElemType>* cur) const;

		// personal homework: get leaves of tree which has only 1 degree
		int getOneDegreeTreeLeafNum(Node<ElemType>* cur) const;

		static void printVector(vector<ElemType> vec);
	private:
		Node<ElemType>* root_;
	};

}

#endif
