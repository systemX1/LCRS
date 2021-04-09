
#pragma once
#include "LCRS.h"

template <typename ElemType>
void sy::LCRS<ElemType>::reset(const vector<int>& parent, const vector<string>& elem, int size)
{
	destroyForest(root_);
	if(parent.empty())
	{
		root_ = nullptr;
		return;
	}
		
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

	auto* root = new Node<ElemType>(elem[root_idx]);	// 复制根结点
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

template <typename ElemType>
void sy::LCRS<ElemType>::printTraverseForest() const
{
	fmt::print("Pre-Root Order Traversal:\t");
	vector<ElemType> ret1;
	preorderRootTraversal(root_, ret1);
	printVector(ret1);

	fmt::print("In-Root Order Traversal:\t");
	vector<ElemType> ret2;
	inorderRootTraversal(root_, ret2);
	printVector(ret2);

	fmt::print("Post-Root Order Traversal:\t");
	vector<ElemType> ret3;
	postorderRootTraversal(root_, ret3);
	printVector(ret3);

	fmt::print("Level Order Traversal:\t\t");
	vector<ElemType> ret4;
	levelOrderTraversal(ret4);
	printVector(ret4);
}

template <typename ElemType>
void sy::LCRS<ElemType>::preorderRootTraversal(Node<ElemType>* cur, vector<ElemType>& ret) const
{
	if(cur == nullptr)
		return;
	ret.push_back(cur->data);
	preorderRootTraversal(cur->lChild, ret);
	preorderRootTraversal(cur->rChild, ret);
}

template <typename ElemType>
void sy::LCRS<ElemType>::inorderRootTraversal(Node<ElemType>* cur, vector<ElemType>& ret) const
{
	if (cur == nullptr)
		return;
	inorderRootTraversal(cur->lChild, ret);
	ret.push_back(cur->data);
	inorderRootTraversal(cur->rChild, ret);
}

template <typename ElemType>
void sy::LCRS<ElemType>::postorderRootTraversal(Node<ElemType>* cur, vector<ElemType>& ret) const
{
	if (cur == nullptr)
		return;
	postorderRootTraversal(cur->lChild, ret);
	postorderRootTraversal(cur->rChild, ret);
	ret.push_back(cur->data);
}

template <typename ElemType>
void sy::LCRS<ElemType>::levelOrderTraversal(vector<ElemType>& ret) const
{
	queue<Node<ElemType>*> que;
	auto* dummy = new Node<ElemType>(root_->data, root_, nullptr);
	que.push(dummy);
	while (!que.empty())
	{
		Node<ElemType>* cur = que.front();
		que.pop();
		if(cur != dummy)
			ret.push_back(cur->data);
		if(cur->lChild != nullptr)
		{
			cur = cur->lChild;
			que.push(cur);
			while (cur->rChild != nullptr)
			{
				cur = cur->rChild;
				que.push(cur);
			}
		}
	}
}

template <typename ElemType>
void sy::LCRS<ElemType>::printExtraInfo() const
{
	int n = 0;
	n = getForestTreeNum();
	fmt::print("The number of the tree{}: \t\t\t{}\n", n > 1 ? "s" : "", n);
	fmt::print("The height of the forest:\t\t\t{}\n", getForestHeight(root_));
	n = getForestLeafNum(root_);
	fmt::print("The number of the forest's lea{}:\t\t{}\n", n > 1 ? "ves" : "f", n);
	fmt::print("The height of the BTree:\t\t\t{}\n", getBTreeHeight(root_));
	fmt::print("The size of the BTree:\t\t\t\t{}\n", getBTreeSize(root_));
	n = getBTreeLeafNum(root_);
	fmt::print("The number of the BTree's lea{}:  \t\t{}\n", n > 1 ? "ves" : "f",  n);
	n = getOneDegreeTreeLeafNum(root_);
	fmt::print("The number of the forest's One-Degree node{}:\t{}\n", n > 1 ? "s" : "", n);
}

template <typename ElemType>
int sy::LCRS<ElemType>::getForestTreeNum() const
{
	int ret = 0;
	auto cur = root_;
	while (cur != nullptr)
	{
		ret++;
		cur = cur->rChild;
	}
	return ret;
}

template <typename ElemType>
int sy::LCRS<ElemType>::getForestHeight(Node<ElemType>* cur) const
{
	if (cur == nullptr)
		return 0;
	return max(1 + getForestHeight(cur->lChild), getForestHeight(cur->rChild));
}

template <typename ElemType>
int sy::LCRS<ElemType>::getForestLeafNum(Node<ElemType>* cur) const
{
	if (cur == nullptr)
		return 0;
	if (cur->lChild == nullptr)
		return 1 + getForestLeafNum(cur->rChild);
	return getForestLeafNum(cur->lChild) + getForestLeafNum(cur->rChild);
}

template <typename ElemType>
int sy::LCRS<ElemType>::getBTreeHeight(Node<ElemType>* cur) const
{
	if(cur == nullptr)
		return 0;
	return 1 + max(getBTreeHeight(cur->lChild), getBTreeHeight(cur->rChild));
}

template <typename ElemType>
int sy::LCRS<ElemType>::getBTreeSize(Node<ElemType>* cur) const
{
	if (cur == nullptr)
		return 0;
	return 1 + getBTreeSize(cur->lChild) + getBTreeSize(cur->rChild);
}

template <typename ElemType>
int sy::LCRS<ElemType>::getBTreeLeafNum(Node<ElemType>* cur) const
{
	if (cur == nullptr)
		return 0;
	int n = 0;
	if (cur->lChild == nullptr && cur->rChild == nullptr)
		n = 1;
	return n + getBTreeLeafNum(cur->lChild) + getBTreeLeafNum(cur->rChild);
}

template <typename ElemType>
int sy::LCRS<ElemType>::getOneDegreeTreeLeafNum(Node<ElemType>* cur) const
{
	if (cur == nullptr)
		return 0;
	int n = 0;
	if (cur->lChild != nullptr && cur->lChild->rChild == nullptr)
		n = 1;
	return n + getOneDegreeTreeLeafNum(cur->lChild) + getOneDegreeTreeLeafNum(cur->rChild);
}


template <typename ElemType>
void sy::LCRS<ElemType>::printVector(vector<ElemType> vec)
{
	for (const auto& i : vec)
		fmt::print("{} ", i);
	fmt::print("\n");
}














