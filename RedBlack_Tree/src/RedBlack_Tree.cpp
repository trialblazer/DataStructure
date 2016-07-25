#include "RedBlack_Tree.h"
#include <iostream>

using std::cout;

void RedBlack_Tree::destory(TreeNode* current) {
    if (current == NULL)
        return;
    if (current->lchild != NULL) {
        delete current->lchild;
        current->lchild = NULL;
    }
    if (current->rchild != NULL) {
        delete current->rchild;
        current->rchild = NULL;
    }
    delete current;
    current = NULL;
}

TreeNode** RedBlack_Tree::locate(int value) {
    TreeNode** sub = &root;
    while (*sub != NULL) {
        if ((*sub)->data > value)
            *sub = (*sub)->lchild;
        else *sub = (*sub)->rchild;
    }
    return sub;
}

bool RedBlack_Tree::insert(int value) {
     TreeNode** sub = locate(value);
     if (sub == NULL && root == NULL) {
        TreeNode* newnode = new TreeNode(value, false);
        if (newnode == NULL)
            return false;
        root = newnode;
        root->parent = NULL;
     } else {
         TreeNode* newnode = new TreeNode(value);
         if (newnode == NULL)
            return false;
         *sub = newnode;
         adjust(sub);
     }
     return true;
}

void RedBlack_Tree::adjust(TreeNode** sub) {
    TreeNode** father = &((*sub)->parent), **gradfather = NULL;
    if (*father == NULL) {
        (*sub)->red_black = false;
        return;
    }
    if ((*father)->red_black == false)
        return;
    gradfather = &((*sub)->parent);
    if ((*gradfather)->lchild == *father) {
        if ((*father)->lchild == *sub) {
            if ((*father)->rchild == NULL) {
                (*father)->rchild = *gradfather;
                (*father)->red_black = false;
                (*gradfather)->red_black = true;
                *gradfather = *father;
            } else {
                (*gradfather)->lchild = (*father)->rchild;
                (*father)->rchild = *gradfather;
                (*sub)->red_black = false;
                *gradfather = *father;
                adjust(gradfather);
            }
        } else {
            if ((*gradfather)->rchild == NULL) {
                (*sub)->lchild = *father;
                (*sub)->rchild = *gradfather;
                (*gradfather)->red_black = true;
                (*sub)->red_black = false;
                *gradfather = *sub;
            } else {
                (*sub)->lchild = *father;
                (*sub)->rchild = *gradfather;
                (*father)->red_black = false;
                *gradfather = *sub;
                adjust(gradfather);
            }
        }
    } else {
        if ((*father)->rchild == *sub) {
            if ((*father)->lchild == NULL) {
                (*father)->lchild = *gradfather;
                (*father)->red_black = false;
                (*gradfather)->red_black = true;
                *gradfather = *father;
            } else {
                (*gradfather)->rchild = (*father)->lchild;
                (*father)->lchild = *gradfather;
                (*sub)->red_black = false;
                *gradfather = *father;
                adjust(gradfather);
            }
        } else {
            if ((*gradfather)->lchild == NULL) {
                (*sub)->rchild = *father;
                (*sub)->lchild = *gradfather;
                (*gradfather)->red_black = true;
                (*sub)->red_black = false;
                *gradfather = *sub;
            } else {
                (*sub)->rchild = *father;
                (*sub)->lchild = *gradfather;
                (*father)->red_black = false;
                *gradfather = *sub;
                adjust(gradfather);
            }
        }
    }
}

void RedBlack_Tree::adjust_(TreeNode** sub) {
    TreeNode** pointer = &((*sub)->parent);
    TreeNode *temp = (*pointer)->rchild, *position = NULL;
    if (*sub == NULL) {
        if ((*pointer)->red_black == true) {
            (*pointer)->red_black = false;
            temp->red_black = true;
        } else {
            if (temp->red_black == false) {
                temp->red_black = true;
                position = (*pointer)->parent;
                temp = *pointer;
                while (1) {
                    TreeNode* cur = position->rchild == temp? position->lchild:position->rchild;
                    if (cur->red_black == false) {
                        cur->red_black = true;
                        adjust(&cur);
                    } else {
                        cur->lchild->red_black = true;
                        adjust(&(cur->lchild));
                        cur->rchild->red_black = true;
                        adjust(&(cur->rchild));
                    }
                    position = position->parent;
                    temp = cur;
                    if (position == root)
                        return;
                }
            } else {
                (temp->lchild)->red_black = true;
                (*pointer)->rchild = temp->lchild;
                temp->lchild = *pointer;
                temp->red_black = false;
                *pointer = temp;
            }

        }
    } else {
        (*sub)->red_black = false;
    }
}

bool RedBlack_Tree::remove(int value) {
    TreeNode** sub = locate(value);
    if (*sub == NULL)
        return false;
    TreeNode** pointer = &(root->rchild);
    while (*pointer != NULL) {
        *pointer = (*pointer)->lchild;
    }
    *pointer = (*pointer)->parent;
    (*sub)->data = (*pointer)->data;
    bool color = (*pointer)->red_black;
    TreeNode* temp = *pointer;
    delete temp;
    *pointer = (*pointer)->rchild;
    if (color != true)
        adjust_(pointer);
    return true;
}

void RedBlack_Tree::_in_order(TreeNode* sub) {
    if (sub == NULL)
        return;
    _in_order(sub->lchild);
    cout << sub->data << "  ";
    _in_order(sub->rchild);
}












