//Gabriel Goldstein
//gjg180000
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <string>

template <class Type>
class BinarySearchTree
{
public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    Type* getRoot() const
    {
        return root;
    }
    void setRoot(Type* r)
    {
        root = r;
    }
    void insert(Type*, Type*);
    Type* search(const Type&, Type*) const;
    void deleteType(const Type&);
    void destroyBinarySearchTree(Type*);
protected:

private:
    Type* root;
};

template <class Type>
BinarySearchTree<Type>::BinarySearchTree()
{
    root = nullptr;
}

template <class Type>
BinarySearchTree<Type>::~BinarySearchTree()
{
    destroyBinarySearchTree(root);

}

//Do a postorder traversal to delete each node from tree
template <class Type>
void BinarySearchTree<Type>::destroyBinarySearchTree(Type* root)
{
    if(root)
    {
        destroyBinarySearchTree(root->getLeft());
        destroyBinarySearchTree(root->getRight());
        delete root;

    }
}


//Insert into the binary search tree
template <class Type>
void BinarySearchTree<Type>::insert(Type* type, Type* tempRoot)
{
    if(tempRoot)
    {
//If what is being inserted is less than the current root
        if(*type < *tempRoot)
        {
            //If there is no left child, insert the type as the left child
            if(!(tempRoot->getLeft()))
            {
                tempRoot->setLeft(type);
                return;
            }

            //Otherwise, go to the left child
            BinarySearchTree::insert(type, tempRoot->getLeft());
        }

        //If what is being inserted is greater than the current root
        else if(*type > *tempRoot)
        {
            //If there is no right child, insert the type as the right child
            if(!(tempRoot->getRight()))
            {
                tempRoot->setRight(type);
                return;
            }
            //Otherwise, go to the right child
            BinarySearchTree::insert(type, tempRoot->getRight());
        }
    }

    //If there is no root, insert the type as the root
    else
    {
        if(!root)
        {
            root = type;
        }
    }




}

//Do a preorder traversal to search the binary tree
template <class Type>
Type* BinarySearchTree<Type>::search(const Type& type, Type* root) const
{
    //If the end of the tree is reached is reached and nothing has been found, return null
    if (!root)
    {
        return nullptr;
    }

    //If what is being searched for is found, return it
    if(type == *root)
    {
        return root;
    }
    else
    {
        //if what is being searched for is less than the current root, go to the left child
        if(type < *root)
        {
            return BinarySearchTree::search (type, root->getLeft());
        }

        //Otherwise, go to the right child
        else
        {
            return BinarySearchTree::search (type, root->getRight());
        }
    }
}

//Delete from the tree
template <class Type>
void BinarySearchTree<Type>::deleteType(const Type& type)
{
    //If the type to be deleted does not exist, end the function
    if(!search(type, this->root))
    {
        return;
    }
    Type* parent = nullptr;
    Type* child = this->root;

    //Search until the child pointer equals the type to be deleted
    while(*child != type)
    {
        parent = child;
        //If the type is less than the child pointer, move the child pointer to the left
        if(type < *child)
        {
            child = child->getLeft();
        }

        //Otherwise, move the child pointer to the right
        else
        {
            child = child->getRight();
        }
    }

    //If the type to be deleted has no children
    if(!(child->getLeft() || child->getRight()))
    {
        //If the parent pointer is null, make the root null
        if(!parent)
        {
            this->root = nullptr;
        }

        else
        {
            //If the parent pointer's right child equals the type to be deleted, set the parent's right child to null
            if(parent->getRight() == child)
            {
                parent->setRight(nullptr);
            }
            //Otherwise, set the left child of the parent to null
            else
            {
                parent->setLeft(nullptr);
            }
        }
    }

    //If the type to be deleted has a right pointer but not a left pointer
    else if (!(child->getLeft()) && child->getRight())
    {
        //If the parent pointer is null, set the root to be the right child of the type to be deleted
        if(!parent)
        {
            this->root = child->getRight();
        }
        //If the parent's left pointer equals the the type to be deleted, set the left pointer of the parent to the child's right pointer
        else if(parent->getLeft() && *(parent->getLeft()) == *child)
        {

            parent->setLeft(child->getRight());
        }

        //Otherwise, set the right pointer of the parent equal to the child's right pointer
        else
        {
            parent->setRight(child->getRight());
        }

    }

    //If the type to be deleted has a left pointer but not a right pointer
    else if (!(child->getRight()) && child->getLeft())
    {
        //If the parent pointer is null, set the root to be the left child of the type to be deleted
        if(!parent)
        {
            this->root = child->getLeft();
        }

        //If the parent's left pointer equals the the type to be deleted, set the left pointer of the parent to the child's left pointer
        else if(parent->getLeft() && *(parent->getLeft()) == *child)
        {
            parent->setLeft(child->getLeft());
        }

        //Otherwise, set the right pointer of the parent equal to the child's left pointer
        else
        {
            parent->setRight(child->getLeft());
        }
    }

    //Otherwise, if the type to be deleted has both children
    else
    {
        Type* rootChange = child;
        child = child->getLeft();
        //Find the right most root of the left child of the type to be deleted
        while(child->getRight())
        {
            child = child->getRight();
        }
        Type temp = *child;
        //recursively call the function
        deleteType(*child);
        //swap the type to be deleted with the right most root of the left child of the type to be deleted
        *rootChange = temp;
        return;
    }

    //delete the type
    child->setLeft(nullptr);
    child->setRight(nullptr);
    delete child;
    child = nullptr;

}

#endif // BINARYSEARCHTREE_H
