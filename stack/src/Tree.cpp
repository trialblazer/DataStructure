#include "Tree.h"

#include <iostream>
#include <cstdlib>

Tree::Tree()
{
    root = NULL;
    total=0;
}

Tree::~Tree()
{
    /// TreeNode * pointer = root;
    /// total = 0;
    destory(root);
}

bool Tree::empty()
{
    if (root == NULL)
        return true;
    return false;
}

bool Tree::insert(int value)
{
    if (empty())
    {
        root = new TreeNode;
        if (root == NULL)
            return false;
        root->right = NULL;
        root->left = NULL;
        root->value = value;
    }
    else
    {
        /***********************************/
        // TreeNode * pointer;
        // pointer = root;
        // while (pointer != NULL) {
        //    if (value > pointer->value)
        //        pointer = pointer->right;
        //    else
        //        pointer = pointer->left;
        //}

        /***********************************/
        // TreeNode ** pointer;
        // (*pointer) = root;
        // while ((*pointer) != NULL) {
        //    if (value > (*pointer)->value)
        //        *pointer = (*pointer)->right;
        //    else
        //        *pointer = (*pointer)->left;
        //}

        /*************************************/
        // TreeNode ** pointer = &root;
        // while ((**pointer) != NULL) {
        //    if (value > (**pointer)->value)
        //        (**pointer) = (**pointer)->right;
        //    else
        //        (**pointer) = (**pointer)->left;
        // }

        TreeNode ** pointer = &root;
        while ((*pointer) != NULL)
        {
            if (value > (**pointer).value)
                pointer = &((**pointer).right);
            else
                pointer = &((*pointer)->left);
        }
        *pointer = new TreeNode;
        if ((*pointer) == NULL)
            return false;
        (*pointer)->right = NULL;
        (*pointer)->left = NULL;
        (*pointer)->value = value;
    }
    total++;
    return true;
}

void Tree::destory(TreeNode * pointer) {
    /// if (pointer->left == NULL && pointer->right == NULL)
    if (pointer != NULL) {
        destory(pointer->right);
        destory(pointer->left);
        delete pointer;
        total--;
    }
}
/*
bool Tree::_remove(int value, TreeNode * pointer) {
    if (pointer == NULL)
        return false;

    if (pointer->value == value) {
        TreeNode *right = pointer->right;
        TreeNode *p;
        if (right == NULL) {
            /// p = pointer;r
            /// pointer = p->left;
            p = pointer->left;
            if (p != NULL) {
                pointer->value = p->value;
                pointer->right = p->right;
                pointer->left = p->left;
                delete p;
            } else {
                pointer = NULL;
            }
        } else {
            p = right->left;
            if (p != NULL) {
                while(p->left != NULL) {
                    right = right->left;
                    p = p->left;
                }

                pointer->value = p->value;
                if (p->right == NULL)
                    right->left = NULL;
                else
                    right->left = p->right;
                delete p;
            } else {
                pointer->right = right->right;
                pointer->value = right->value;
                delete right;
            }
        }
        total--;
        p = NULL;
        right = NULL;
        return true;
    }
    if (value<pointer->value)
        return _remove(value, pointer->left);
    return _remove(value, pointer->right);
}*/

bool Tree::_remove(int value, TreeNode **pointer) {
    if (*pointer == NULL)
        return false;

    if (value == (*pointer)->value) {
        TreeNode *right = (*pointer)->right;
        TreeNode *left;
        if (right == NULL) {
            left = *pointer;
            /// pointer = &((*pointer)->left);
            *pointer = (*pointer)->left;
        } else {
            left = right->left;
            if (left == NULL) {
                left = *pointer;
                *pointer = (*pointer)->right;
            } else {
                TreeNode *parent = right;
                while(left->left != NULL) {
                    parent = left;
                    left = left->left;
                    // parent = patrent->left;
                }
                (*pointer)->value = left->value;
                // parent = left->right;
                parent->left = left->right;
                // left = left->right;
            }
        }
        delete left;
        total--;
        return true;
    }
    if (value > (*pointer)->value)
        return _remove(value, &((*pointer)->right));
    return _remove(value, &((*pointer)->left));
}

bool Tree::remove(int value) {
    return _remove(value, &root);
}

void Tree::_intravel(TreeNode * root) {
    if (root) {
        _intravel(root->left);
        std::cout << root->value << " ";
        _intravel(root->right);
    }
}

void Tree::intravel() {
    _intravel(root);
}

bool Tree::insert1(int value) {
    return _insert1(value, &root);
}

bool Tree::_insert1(int value, TreeNode **pointer) {
    if (*pointer == NULL) {
        *pointer = new TreeNode;
        if ((*pointer) == NULL)
            return false;
        (*pointer)->value = value;
        (*pointer)->right = NULL;
        (*pointer)->left = NULL;
        total ++;
        return true;
    }
    if (value>(*pointer)->value)
        return _insert1(value, &((*pointer)->right));
    return _insert1(value, &((*pointer)->left));
}

bool Tree::find(int value) {
    return _find(value, root);
}

/// bool Tree::_find(int value, TreeNode **pointer) {
bool Tree::_find(int value, TreeNode *pointer) {
    if (pointer == NULL)
        return false;
    if (value == pointer->value)
        return true;
    if (value > pointer->value)
        return _find(value, pointer->right);
    return _find(value, pointer->left);
}

int Tree::depth() {
    return _depth(root);
}

int Tree::_depth(TreeNode * pointer) {
    if (pointer == NULL)
        return 0;
    int m = 1+_depth(pointer->left);
    int n = 1+_depth(pointer->right);
    return m>n? m:n;
}

































