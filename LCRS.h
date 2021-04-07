#pragma once
#ifndef PARENT_CHILD_FOREST_H_SY_
#define PARENT_CHILD_FOREST_H_SY_

#include <string>
using std::string;

#include <utility>
using std::move;
using std::swap;

#include "Node.h"

namespace sy
{
	// Left-Child Right-Sibling Representation of Forest(LCRS)
	template<typename ElemType>
	class LCRS
	{
	public:
		// Constructor and Destructor
		LCRS() = default;
		LCRS(const string& infix);
		
		
		static void destroyForest(Node<ElemType>* t);
		~LCRS() { destroyTree(root); }

		

	private:
		Node<ElemType>* root;
	
	};




}

#endif
