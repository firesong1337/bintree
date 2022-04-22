#include <iostream>
#include "BinaryTree.h"

BinaryTree::BinaryTree()
        : head(nullptr) {

}

void BinaryTree::Insert(int value) {
    if (head == nullptr) {
        head = new BinaryTreeNode(value);
    } else {
        BinaryTreeNode *current = head;
        while (true) {
            if (value < current->value) {
                if (current->left == nullptr) {
                    current->left = new BinaryTreeNode(value);
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (value > current->value) {
                    if (current->right == nullptr) {
                        current->right = new BinaryTreeNode(value);
                        break;
                    } else {
                        current = current->right;
                    }
                } else {
                    break;
                }
            }
        }
    }
}

std::ostream &operator<<(std::ostream &ostream, const BinaryTree &rhs) {
    return rhs.Print(ostream, rhs.head);
}

std::ostream &BinaryTree::Print(std::ostream &ostream, BinaryTreeNode *rhs) const {
    if (rhs != nullptr) {
        Print(ostream, rhs->left);
        std::cout << " " << rhs->value << std::endl;
        Print(ostream, rhs->right);
    }
    return ostream;
}

BinaryTree::~BinaryTree() {
    Clear();
}

void BinaryTree::Clear() {
    deleteLeaf(head);
    head = nullptr;
}

void BinaryTree::deleteLeaf(BinaryTreeNode *node) {
    if (node != nullptr) {
        deleteLeaf(node->left);
        deleteLeaf(node->right);
        delete node;
    }
}

bool BinaryTree::Find(int value) {
    BinaryTreeNode *current = head;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        } else if (current->value > value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

int BinaryTree::FindSize(BinaryTreeNode *node) {
    if (node != nullptr) {
        return 1 + FindSize(node->left) + FindSize(node->right);
    }
    return 0;
}

int BinaryTree::Size() {
    return FindSize(head);
}

void BinaryTree::Erase(int value) {
    BinaryTreeNode *Temp = head, *Parent = head, *marker;
    if (Temp == nullptr) {
        throw std::runtime_error("Невозможно удалить элемент из пустого дерева!");
    } else {
        while (Temp != nullptr && Temp->value != value) {
            Parent = Temp;
            if (Temp->value < value) {
                Temp = Temp->left;
            } else {
                Temp = Temp->right;
            }
        }
    }
    marker = Temp;
    if (Temp == nullptr) {

    } else if (Temp == head) {
        if (Temp->right == nullptr && Temp->left == nullptr) {
            head = nullptr;
        } else if (Temp->left == nullptr) {
            head = Temp->right;
        } else if (Temp->right == nullptr) {
            head = Temp->left;
        } else {
            BinaryTreeNode *NewTemp;
            NewTemp = Temp->right;
            while (NewTemp->left != nullptr) {
                Temp = NewTemp;
                NewTemp = Temp->left;
            }
            if (NewTemp != Temp->right) {
                Temp->left = NewTemp->right;
                Temp->right = head->right;
            }
            NewTemp->left = head->left;
            head = NewTemp;

        }
    } else {
        if (Temp->right == nullptr && Temp->left == nullptr) {
            if (Parent->right == Temp) {
                Parent->right = nullptr;
            } else {
                Parent->left = nullptr;
            }
        } else if (Temp->left == nullptr){
            if (Parent->right == Temp){
                Parent->right = Temp->right;
            }
            else{
                Parent->left = Temp->left;
            }
        }else if (Temp->right == nullptr){
            if (Parent->right == Temp){
                Parent->right = Temp->left;
            }
            else{
                Parent->left = Temp->left;
            }
        } else{
            BinaryTreeNode * NewTemp;
            Parent = Temp;
            NewTemp = Temp->right;
            while (NewTemp->left != nullptr){
                Parent = NewTemp;
                NewTemp = NewTemp->left;
            }
            if (NewTemp != NewTemp->right){
                Temp->left = NewTemp->right;
                Temp->right = Parent->right;
            }
            NewTemp->left = Parent->left;
            Parent = NewTemp;
        }
    }
    delete marker;
}


