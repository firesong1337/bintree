
#ifndef CPPTHIRD_BINARYTREE_H
#define CPPTHIRD_BINARYTREE_H

#include <ostream>
#include "BinaryTreeNode.h"

class BinaryTree {
public:
    BinaryTree();

    ~BinaryTree();

    void Erase(int value);

    bool Find(int value);

    int Size();

    void Clear();

    void Insert(int value);

    friend std::ostream &operator<<(std::ostream &ostream, const BinaryTree &rhs);

private:
    BinaryTreeNode *head;

    std::ostream &Print(std::ostream &ostream, BinaryTreeNode *rhs) const;

    void deleteLeaf(BinaryTreeNode *node);

    int FindSize(BinaryTreeNode * node);
};


#endif //CPPTHIRD_BINARYTREE_H
