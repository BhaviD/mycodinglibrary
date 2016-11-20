template <typename T>
class BSTree<T>::iterator
{
    friend class BSTree<T>;
    friend class BSTree<T>::const_iterator;

    public:
        // constructor
        iterator ()
        {}

        // comparison operators. just compare node pointers
        bool operator== (const iterator& rhs) const
        {
            return nodePtr == rhs.nodePtr;
        }

        bool operator!= (const iterator& rhs) const
        {
            return nodePtr != rhs.nodePtr;
        }

        // dereference operator. return a reference to
        // the value pointed to by nodePtr
        T& operator* () const;

        // preincrement. move forward to next larger value
        iterator& operator++ ();

        // postincrement
        iterator operator++ (int);

        // predecrement. move backward to largest value < current value
        iterator& operator-- ();

        // postdecrement
        iterator operator-- (int);

    private:
        // nodePtr is the current location in the tree. we can move
        // freely about the tree using left, right, and parent.
        // tree is the address of the BSTree object associated
        // with this iterator. it is used only to access the
        // root pointer, which is needed for ++ and --
        // when the iterator value is end()
        BSTNode<T> *nodePtr;
        BSTree<T> *tree;

        // used to construct an iterator return value from
        // an BSTNode pointer
        iterator (BSTNode<T> *p, BSTree<T> *t) : nodePtr(p), tree(t)
        {}
};

template <typename T>
class BSTree<T>::const_iterator
{
    friend class BSTree<T>;

    public:
        // constructor
        const_iterator ()
        {}

        // used to convert a const iterator to a const_iterator
        const_iterator (const iterator& pos): nodePtr(pos.nodePtr)
        {}

        // comparison operators. just compare node pointers
        bool operator== (const const_iterator& rhs) const
        {
            return nodePtr == rhs.nodePtr;
        }

        bool operator!= (const const_iterator& rhs) const
        {
            return nodePtr != rhs.nodePtr;
        }

        // dereference operator. return a reference to
        // the value pointed to by nodePtr
        const T& operator* () const;

        // preincrement. move forward to next larger value
        const_iterator& operator++ ();

        // postincrement
        const_iterator operator++ (int);

        // predecrement. move backward to largest value < current value
        const_iterator& operator-- ();

        // postdecrement
        const_iterator operator-- (int);

    private:
        // nodePtr is the current location in the tree. we can move
        // freely about the tree using left, right, and parent.
        // tree is the address of the BSTree object associated
        // with this iterator. it is used only to access the
        // root pointer, which is needed for ++ and --
        // when the iterator value is end()
        const BSTNode<T> *nodePtr;
        const BSTree<T> *tree;

        // used to construct a const_iterator return value from
        // an BSTNode pointer
        const_iterator (const BSTNode<T> *p, const BSTree<T> *t) : nodePtr(p), tree(t)
        {}
};

template <typename T>
T& BSTree<T>::iterator::operator* () const
{
    if (nodePtr == NULL)
        throw ReferenceError("BSTree iterator operator* (): NULL reference");

    return nodePtr->nodeValue;
}

template <typename T>
typename BSTree<T>::iterator& BSTree<T>::iterator::operator++ ()
{
    BSTNode<T> *p;

    if (nodePtr == NULL)
    {
        // ++ from end(). get the root of the tree
        nodePtr = tree->root;

        // error! ++ requested for an empty tree
        if (nodePtr == NULL)
            throw UnderflowError("BSTree iterator operator++ (): tree empty");

        // move to the smallest value in the tree,
        // which is the first node inorder
        while (nodePtr->left != NULL)
            nodePtr = nodePtr->left;
    }
    else if (nodePtr->right != NULL)
    {
        // successor is the furthest left node of
        // right subtree
        nodePtr = nodePtr->right;

        while (nodePtr->left != NULL)
            nodePtr = nodePtr->left;
    }
    else
    {
        // have already processed the left subtree, and
        // there is no right subtree. move up the tree,
        // looking for a parent for which nodePtr is a left child,
        // stopping if the parent becomes NULL. a non-NULL parent
        // is the successor. if parent is NULL, the original node
        // was the last node inorder, and its successor
        // is the end of the list
        p = nodePtr->parent;

        while (p != NULL && nodePtr == p->right)
        {
            nodePtr = p;
            p = p->parent;
        }

        // if we were previously at the right-most node in
        // the tree, nodePtr = NULL, and the iterator specifies
        // the end of the list
        nodePtr = p;
    }
    return *this;
}

template <typename T>
typename BSTree<T>::iterator BSTree<T>::iterator::operator++ (int)
{
    // save current iterator
    iterator tmp = *this;

    // move myself forward to the next tree node
    ++*this;

    // return the previous value
    return tmp;
}

template <typename T>
typename BSTree<T>::iterator& BSTree<T>::iterator::operator-- ()
{
    BSTNode<T> *p;

    if (nodePtr == NULL)
    {
        // -- from end(). get the root of the tree
        nodePtr = tree->root;

        // error! -- requested for an empty tree
        if (nodePtr == NULL)
            throw UnderflowError("BSTree iterator operator--: tree empty");

        // move to the largest value in the tree,
        // which is the last node inorder
        while (nodePtr->right != NULL)
            nodePtr = nodePtr->right;
    } 
    else if (nodePtr->left != NULL)
    {
        // must have gotten here by processing all the nodes
        // on the left branch. predecessor is the farthest
        // right node of the left subtree
        nodePtr = nodePtr->left;

        while (nodePtr->right != NULL)
            nodePtr = nodePtr->right;
    }
    else
    {
        // must have gotten here by going right and then
        // far left. move up the tree, looking for a parent
        // for which nodePtr is a right child, stopping if the
        // parent becomes NULL. a non-NULL parent is the
        // predecessor. if parent is NULL, the original node
        // was the first node inorder, and its predecessor
        // is the end of the list
        p = nodePtr->parent;
        while (p != NULL && nodePtr == p->left)
        {
            nodePtr = p;
            p = p->parent;
        }

        // if we were previously at the left-most node in
        // the tree, nodePtr = NULL, and the iterator specifies
        // the end of the list
        nodePtr = p;
    }

    return *this;
}

template <typename T>
typename BSTree<T>::iterator BSTree<T>::iterator::operator-- (int)
{
    // save current iterator
    iterator tmp = *this;

    // move myself backward to the previous tree node
    --*this;

    // return the previous value
    return tmp;
}


template <typename T>
const T& BSTree<T>::const_iterator::operator* () const
{
    if (nodePtr == NULL)
        throw ReferenceError("BSTree const_iterator operator* (): NULL reference");

    return nodePtr->nodeValue;
}

template <typename T>
typename BSTree<T>::const_iterator& BSTree<T>::const_iterator::operator++ ()
{
    BSTNode<T> *p;

    if (nodePtr == NULL)
    {
        // ++ from end(). get the root of the tree
        nodePtr = tree->root;

        // error! ++ requested for an empty tree
        if (nodePtr == NULL)
            throw UnderflowError("BSTree const_iterator operator++ (): tree empty");

        // move to the smallest value in the tree,
        // which is the first node inorder
        while (nodePtr->left)
            nodePtr = nodePtr->left;
    }
    else if (nodePtr->right)
    {
        // successor is the furthest left node of
        // right subtree
        nodePtr = nodePtr->right;

        while (nodePtr->left)
            nodePtr = nodePtr->left;
    }
    else
    {
        // have already processed the left subtree, and
        // there is no right subtree. move up the tree,
        // looking for a parent for which nodePtr is a left child,
        // stopping if the parent becomes NULL. a non-NULL parent
        // is the successor. if parent is NULL, the original node
        // was the last node inorder, and its successor
        // is the end of the list
        p = nodePtr->parent;

        while (p && nodePtr == p->right)
        {
            nodePtr = p;
            p = p->parent;
        }

        // if we were previously at the right-most node in
        // the tree, nodePtr = NULL, and the iterator specifies
        // the end of the list
        nodePtr = p;
    }
    return *this;
}

template <typename T>
typename BSTree<T>::const_iterator BSTree<T>::const_iterator::operator++ (int)
{
    // save current const_iterator
    const_iterator tmp = *this;

    // move myself forward to the next tree node
    ++*this;

    // return the previous value
    return tmp;
}

template <typename T>
typename BSTree<T>::const_iterator& BSTree<T>::const_iterator::operator-- ()
{
    BSTNode<T> *p;

    if (nodePtr == NULL)
    {
        // -- from end(). get the root of the tree
        nodePtr = tree->root;

        // error! -- requested for an empty tree
        if (nodePtr == NULL)
            throw UnderflowError("BSTree iterator operator--: tree empty");

        // move to the largest value in the tree,
        // which is the last node inorder
        while (nodePtr->right)
            nodePtr = nodePtr->right;
    } 
    else if (nodePtr->left)
    {
        // must have gotten here by processing all the nodes
        // on the left branch. predecessor is the farthest
        // right node of the left subtree
        nodePtr = nodePtr->left;

        while (nodePtr->right)
            nodePtr = nodePtr->right;
    }
    else
    {
        // must have gotten here by going right and then
        // far left. move up the tree, looking for a parent
        // for which nodePtr is a right child, stopping if the
        // parent becomes NULL. a non-NULL parent is the
        // predecessor. if parent is NULL, the original node
        // was the first node inorder, and its predecessor
        // is the end of the list
        p = nodePtr->parent;
        while (p && nodePtr == p->left)
        {
            nodePtr = p;
            p = p->parent;
        }
        // if we were previously at the left-most node in
        // the tree, nodePtr = NULL, and the iterator specifies
        // the end of the list
        nodePtr = p;
    }
    return *this;
}

template <typename T>
typename BSTree<T>::const_iterator BSTree<T>::const_iterator::operator-- (int)
{
    // save current const_iterator
    const_iterator tmp = *this;

    // move myself backward to the previous tree node
    --*this;

    // return the previous value
    return tmp;
}

