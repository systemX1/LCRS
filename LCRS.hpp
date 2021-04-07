
#pragma once
#include "LCRS.h"

template <typename ElemType>
void sy::LCRS<ElemType>::reset(const vector<int>& parent, const vector<string>& elem, int size)
{
	destroyForest(root_);
	root_ =  createBTree(parent, elem, 0, size);
	for (int i = size; i < static_cast<int>(parent.size()); )
	{
		if(parent[i] < 0)
		{
			Node<ElemType>* cur = root_;
			while (cur->rChild != nullptr)
			{
				cur = cur->rChild;
			}
			cur->rChild = createBTree(parent, elem, i, parent[i] * (-1));
			i = i + parent[i] * (-1);
		}
	}
}

template<typename ElemType>
sy::Node<ElemType>* sy::LCRS<ElemType>::createBTree(const vector<int>& parent, const vector<string>& elem, int root_idx, int size)
{
	if (root_idx < 0 || root_idx > root_idx + size)
		return nullptr;

	Node<ElemType>* root = new Node<ElemType>(elem[root_idx]);	// 复制根结点
	Node<ElemType>* cur = nullptr;
	for (int i = root_idx; i < root_idx + size; i++) {		// 查找root的孩子
		if (parent[i] == root_idx) {			// 建立以i为根的子树
			Node<ElemType>* sub_tree_root = createBTree(parent, elem, i, size - i + root_idx);
			if (root->lChild == nullptr) {		// subTreeRoot为rt第一棵子树的根
				root->lChild = sub_tree_root;
				cur = sub_tree_root;	        // cur最新复制的子树的根
			}
			else if(cur) {						// subTreeRoot为cur的下一个兄弟
				cur->rChild = sub_tree_root;
				cur = sub_tree_root;
			}
		}
	}
	return root;
	
}

template <typename ElemType>
void sy::LCRS<ElemType>::displayForest(const string& str, const Node<ElemType>* cur, bool isLeft) const
{
	if (cur)
	{
		fmt::print("{}", str.data());

		isLeft ? fmt::print("|-- ") : fmt::print("\\-- ");

		fmt::print("{}\n", cur->data);

		// enter the next tree level - left and right branch
		displayForest(str + (isLeft ? "|   " : "    "), cur->lChild, true);
		displayForest(str + (isLeft ? "|   " : "    "), cur->rChild, false);
	}
}






template <typename ElemType>
void sy::LCRS<ElemType>::destroyForest(Node<ElemType>* cur)
{
	if(cur == nullptr)
		return;
	destroyForest(cur->lChild);
	destroyForest(cur->rChild);
	delete cur;
}




