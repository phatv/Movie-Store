#include "tree.h"

//------------------------------------------------------------------------------
// Constructor
// Default constructor for Tree class
Tree::Tree()
{
	_root = NULL;
	_size = 0;
}

//------------------------------------------------------------------------------
// Copy
// Copy constructor for Tree
// Relies on assignment operator=
Tree::Tree(const Tree &tree)
{
	_root = NULL;
	_size = tree._size;
	*this = tree;
}

//------------------------------------------------------------------------------
// Destructor
// Destructor for Tree class
// Relies on makeEmpty
Tree::~Tree()
{
	makeEmpty();
}

//------------------------------------------------------------------------------
// insert
// Inserts a NodeData * of a given object into the tree. 
// Returns whether sucessful or not. 
bool Tree::insert(NodeData *nd)
{
	if (nd != NULL)
	{
		return insertHelper(_root, nd);
	}
	else
	{
		return false;
	}
}

bool Tree::insertHelper(Node * &curr, NodeData *nd)
{
	// If current is NULL, creates new node and sets as current
	if (curr == NULL)
	{
		Node *temp = new Node;
		temp->data = nd;
		curr = temp;
		curr->left = NULL;
		curr->right = NULL;
		_size++;
		return true;
	}
	// If not, goes compares itself to current and goes left if smaller,
	// right if bigger
	else if (*curr->data > *nd)
	{
		return insertHelper(curr->left, nd);
	}
	else if (*curr->data < *nd)
	{
		return insertHelper(curr->right, nd);
	}
	else
	{
		return false;
	}
}

//------------------------------------------------------------------------------
// retrieve
// Retrieves a NodeData * of a given object in the tree
// (via pass-by-reference parameter)
// Returns whether found or not. 
bool Tree::retrieve(const NodeData &nd, NodeData * &result) const
{
	if (!isEmpty())
	{
		Node *temp = _root;
		return retrieveHelper(temp, nd, *&result);
	}
	else
	{
		return false;
	}
}

bool Tree::retrieveHelper(Node * &curr, const NodeData &nd,
	NodeData * &result) const
{
	if (curr != NULL)
	{
		// Found, sets object to passed in pointer and returns true
		if (*curr->data == nd)
		{
			result = curr->data;
			return true;
		}
		// Compares data to current, goes left if smaller and right if bigger
		else if (*curr->data > nd)
		{
			return retrieveHelper(curr->left, nd, result);
		}
		else if (*curr->data < nd)
		{
			return retrieveHelper(curr->right, nd, result);
		}
		// Not found, returns false
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//------------------------------------------------------------------------------
// remove
bool Tree::remove(const NodeData &obj)
{
	return removeHelper(_root, obj);
}

bool Tree::removeHelper(Node * &curr, const NodeData &obj)
{
	if (curr == NULL)
	{
		return false;
	}
	else
	{
		if (*curr->data != obj)
		{
			if (*curr->data > obj)
			{
				return removeHelper(curr->left, obj);
			}
			else
			{
				return removeHelper(curr->right, obj);
			}
		}
		else
		{
			if ((curr->left == NULL) && (curr->right == NULL))
			{
				Node *temp = curr;
				curr = NULL;
				delete temp->data;
				temp->data = NULL;
				delete temp;
				temp = NULL;
				_size--;
				return true;
			}
			else if ((curr->left == NULL) || (curr->right == NULL))
			{
				if (curr->left == NULL)
				{
					Node *temp = curr;
					curr = curr->right;
					delete temp->data;
					temp->data = NULL;
					temp->right = NULL;
					delete temp;
					temp = NULL;
					_size--;
					return true;
				}
				else
				{
					Node *temp = curr;
					curr = curr->left;
					delete temp->data;
					temp->data = NULL;
					temp->left = NULL;
					delete temp;
					temp = NULL;
					_size--;
					return true;
				}
			}
			else
			{
				NodeData *temp = findMax(curr->left);
				*curr->data = *temp;
				return removeHelper(curr->left, *temp);
			}
		}
	}
}

NodeData* Tree::findMax(Node * &curr)
{
	Node *temp = curr;
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp->data;
}

//------------------------------------------------------------------------------
// isEmpty
// Returns whether the tree is empty
bool Tree::isEmpty() const
{
	if (_root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//------------------------------------------------------------------------------
// makeEmpty
// Makes the tree empty by deleting all objects in the tree
void Tree::makeEmpty()
{
	if (!isEmpty())
	{
		emptyHelper(_root);
		_size = 0;
	}
}

void Tree::emptyHelper(Node * & curr)
{
	if (curr != NULL)
	{
		emptyHelper(curr->left);
		emptyHelper(curr->right);
		delete curr->data;
		delete curr;
		curr = NULL;
	}
}

//------------------------------------------------------------------------------
// getSize
int Tree::getSize() const
{
	return _size;
}

//------------------------------------------------------------------------------
// getHeight
// Returns the height of a given object
// Leaves are height of one
int Tree::getHeight(const NodeData &nd) const
{
	Node *temp = _root;
	// Height of object if found
	int height = 0;
	heightHelper(temp, nd, height);
	return height;
}

int Tree::heightHelper(Node * &curr, const NodeData &nd, int &height) const
{
	if (curr != NULL)
	{
		// Finds height of left and right subtree
		int left = heightHelper(curr->left, nd, height);
		int right = heightHelper(curr->right, nd, height);
		// If both are zero, we are at leaf and return one
		// If leaf is target, set height to one
		if (left == 0 && right == 0)
		{
			if (*curr->data == nd)
			{
				height = 1;
			}
			return 1;
		}
		else
		{
			int result = 0;
			// Determines greater height of the left and right subtree
			(left > right) ? result = left : result = right;
			// If current is target, height is set to result +1
			// +1 is to account for self
			if (*curr->data == nd)
			{
				height = result + 1;
			}
			// If not found, returns height +1
			// +1 is to account for self
			return result + 1;
		}
	}
	// Not found or NULL
	else
	{
		return 0;
	}
}

//------------------------------------------------------------------------------
// bstreeToArray
// A routine fills an array of NodeData* by using an inorder traversal 
// of the tree. It leaves the tree empty. 
// Assumes array is equal to or larger than tree and full of NULLs. 
void Tree::bstreeToArray(NodeData *nd[])
{
	if (_root != NULL)
	{
		// beginning of the array
		int index = 0;
		toArrayHelper(_root, nd, index);
		//_root = NULL;
		//_size = 0;
	}
}

int Tree::toArrayHelper(Node * &curr, NodeData *nd[], int index)
{
	if (curr != NULL)
	{
		// Inserts left subtree into array first
		// int child is number of how many objects were inserted into array
		int child = toArrayHelper(curr->left, nd, index);
		// Adds current index to child
		index += child;
		// Inserts self into array
		nd[index] = curr->data;
		// Inserts right subtree into array
		child += toArrayHelper(curr->right, nd, index + 1);
		// Removes pointer to NodeData
	//	delete curr;
	//	curr = NULL;
		// Returns increment of left and right childs
		return child + 1;
	}
	else
	{
		return 0;
	}
}

//------------------------------------------------------------------------------
// arrayToBSTree
// A routine builds a balanced Tree from a sorted array (assumed) 
// of NodeData* leaving the array filled with NULLs. 
void Tree::arrayToBSTree(NodeData *nd[])
{
	int size = 0;
	bool loop = true;
	// Finds size of array
	while (loop)
	{
		if (nd[size] == NULL)
		{
			loop = false;
		}
		else
		{
			size++;
		}
	}
	toTreeHelper(_root, nd, 0, size - 1);
	_size = size;
}

void Tree::toTreeHelper(Node * &curr, NodeData *nd[],
	const int &min, const int &max)
{
	// if min equals max, curr is a leaf
	// inserts node as a leaf
	if (min == max)
	{
		// if current is not NULL, deletes object and replaces 
		// it with the new object
		if (curr != NULL)
		{
			delete curr->data;
			emptyHelper(curr->left);
			emptyHelper(curr->right);
			curr->data = nd[min];
		}
		// Creates new node and sets it to the object
		else
		{
			Node *temp = new Node;
			temp->data = nd[min];
			temp->left = NULL;
			temp->right = NULL;
			curr = temp;
		}
		// Sets position in the array to NULL
		nd[min] = NULL;
	}
	// Inserts middle node
	else if (min < max)
	{
		// finds size of current subarray
		int size = (max - min);
		// mid of current subarray
		int index = (size / 2) + min;
		// if Node is not NULL, deletes old data and sets new one
		if (curr != NULL)
		{
			delete curr->data;
			curr->data = nd[index];
		}
		// if current is NULL, creates new node and sets data
		else
		{
			Node *temp = new Node;
			temp->data = nd[index];
			temp->left = NULL;
			temp->right = NULL;
			curr = temp;
		}
		// Current position in array is set to NULL
		nd[index] = NULL;
		// inserts smaller half of array into left subtree
		toTreeHelper(curr->left, nd, min, index - 1);
		// inserts bigger half of array into right subtree
		toTreeHelper(curr->right, nd, index + 1, max);
	}
	// deletes any extra nodes from previous tree
	else
	{
		emptyHelper(curr);
	}
}

//------------------------------------------------------------------------------
// operator=
// Assignment operator
/* REMOVED BECAUSE IT WAS CAUSING PROBLEMS
Tree& Tree::operator=(const Tree &tree)
{
	if (tree._root != NULL)
	{
		Node *temp = tree._root;
		assignmentHelper(temp, _root);
		_size = tree._size;
	}
	else
	{
		makeEmpty();
	}
	return *this;
}

void Tree::assignmentHelper(Node * &curr, Node * &copy)
{
	if (curr != NULL)
	{
		// If current isn't NULL, replaces data without delete node
		if (copy != NULL)
		{
			*copy->data = *curr->data;
		}
		// If current is empty, creates new node and adds in the data
		else
		{
			Node *temp = new Node;
			NodeData *tempData = new NodeData(*curr->data);
			temp->data = tempData;
			temp->left = NULL;
			temp->right = NULL;
			copy = temp;
		}
		//Traverses left and right subtree
		assignmentHelper(curr->left, copy->left);
		assignmentHelper(curr->right, copy->right);
	}
	else
	{
		// Deletes extra subtrees from previous tree
		if (copy != NULL)
		{
			emptyHelper(copy);
		}
	}
}*/

//------------------------------------------------------------------------------
// operator==
// Determine if two trees are equal
bool Tree::operator==(const Tree &tree) const
{
	if (_root != NULL && tree._root != NULL)
	{
		// Needed because of the const BS
		Node *temp = _root;
		Node *other = tree._root;
		return equalsHelper(temp, other);
	}
	else
	{
		return false;
	}
}

bool Tree::equalsHelper(Node * &curr, Node * &other) const
{
	// checks if both are NULL or not
	if (curr != NULL && other != NULL)
	{
		//if the data is different, returns false
		if (*curr->data != *other->data)
		{
			return false;
		}
		else
		{
			// checks left and right subtree for both
			return equalsHelper(curr->left, other->left)
				&& equalsHelper(curr->right, other->right);
		}
	}
	// if both are NULL, returns true
	else if (curr == NULL && other == NULL)
	{
		return true;
	}
	// returns false if one is NULL and one is not
	else
	{
		return false;
	}
}

//------------------------------------------------------------------------------
// Operator!=
// Determines if two trees are not equal
// Relies on operator==
bool Tree::operator!=(const Tree &tree) const
{
	return !(*this == tree);
}

//------------------------------------------------------------------------------
// displaySideways
// Displays the tree sideways
// provided by Professor Zander
void Tree::displaySideways() const {
	sideways(_root, 0);
}

void Tree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}

//------------------------------------------------------------------------------
// Operator<<
// Output operator displays tree as inorder traversal
ostream& operator<<(ostream &outStream, const Tree &tree)
{
	tree.outputHelper(outStream);
	return outStream;
}

// this is needed to avoid a const BS
void Tree::outputHelper(ostream &outStream) const
{
	Node *temp = _root;
	outputHelperHelper(outStream, temp);
	outStream << endl;
}

void Tree::outputHelperHelper(ostream &outStream, Node * &curr) const
{
	if (curr != NULL)
	{
		outputHelperHelper(outStream, curr->left);
		outStream << *curr->data << " ";
		outputHelperHelper(outStream, curr->right);
	}
}