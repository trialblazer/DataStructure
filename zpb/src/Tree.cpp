#include "Tree.h"

#include<iostream>
#include<stdlib.h>

Tree::Tree() {
    root = NULL;
    total = 0;
}

Tree::~Tree() {
    destory();
}

bool Tree::insert(int value) {
    if(root == NULL) {
        root = new Tree_Node;
        if(root == NULL) {
            std::cout << "memory allocate failure!!\n";
            return false;
        }
        root->value = value;
        root->right = NULL;
        root->left = NULL;
        total++;
        return true;
    }

    Tree_Node **pointer;
    pointer = &root;
    while(1) {
        if((*pointer) == NULL)
            break;
        if(value>(*pointer)->value)
            pointer = &((*pointer)->right);
        else
            pointer = &((*pointer)->left);
    }
    *pointer = new Tree_Node;
    if(*pointer) {
        (*pointer)->value = value;
        (*pointer)->right = NULL;
        (*pointer)->left = NULL;
        total++;
        return true;
    }
    return false;
}

void Tree::_prin(Tree_Node* pointer) {
    if (pointer != NULL) {
        _prin(pointer->left);
        std::cout << pointer->value << "\t";
        _prin(pointer->right);
    }
}

void Tree::prin() {
    return _prin(root);
}

bool Tree::remove(int value) {
    return _remove(value, &root);
}

bool Tree::_remove(int value, Tree_Node **pointer) {
    if(*pointer == NULL)
        return false;

    if((*pointer)->value == value) {
        Tree_Node *r = (*pointer)->right;
        Tree_Node **l;
        Tree_Node *tem;
        if(r == NULL) {
            tem = *pointer;
            *pointer = (*pointer)->left;
        } else {
            l = &(r->left);
            if(*l) {
                while((*l)->left != NULL)
                    (*l) = (*l)->left;
                (*pointer)->value = (*l)->value;
                tem = *l;
                *l = NULL;
            } else {
                tem = *pointer;
                *pointer = r;
                r->left = tem->left;
            }
        }
        delete tem;
        total--;
        return true;
    }
    if(value<(*pointer)->value)
        return _remove(value, &((*pointer)->left));
    return _remove(value, &((*pointer)->right));
}

void Tree::destory() {
    _destory(&root);
}

void Tree::_destory(Tree_Node **pointer) {
    if (*pointer) {
        // if(!((*pointer)->left == NULL || (*pointer)->right == NULL)) {
            _destory(&((*pointer)->right));
            _destory(&((*pointer)->left));
        // }
        Tree_Node *tem = *pointer;
        // *pointer = NULL;
        delete tem;
        *pointer = NULL;
    }
}
