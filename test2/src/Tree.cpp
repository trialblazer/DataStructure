#include "Tree.h"

#include<iostream>
#include<stdlib.h>

Tree::Tree() {
    root = NULL;
    size = 0;
}

Tree::~Tree() {
    destory_(&root);
}

bool Tree::insert(int value) {
    if (root == NULL) {
        root = new Tree_node;
        if (root == NULL) {
            std::cerr << "Memory allocate failure!!\n";
            exit(1);
        }
        root->value = value;
        root->right = NULL;
        root->left = NULL;
    } else {
        Tree_node **pointer = &root;
        while ((*pointer) != NULL) {
            if (value > (*pointer)->value)
                pointer = &((*pointer)->right);
            else
                pointer = &((*pointer)->left);
        }
        (*pointer) = new Tree_node;
        if (*pointer == NULL)
            return false;
        (*pointer)->value = value;
        (*pointer)->right = NULL;
        (*pointer)->left = NULL;
    }
    size++;
    return true;
}


Tree_node* Tree::search_(int key, Tree_node* pointer) {
    if (pointer == NULL)
        return NULL;
    if (pointer->value == key)
        return pointer;

    if (key > pointer->value)
        return search_(key, pointer->right);
    else
        return search_(key, pointer->left);
}


void Tree::remove(int value) {
    //Tree_node *tmpt = search_(value, root);
    //if (tmpt == NULL)
     //   return;
    //remove_(&tmpt);
    //tmpt = NULL;

    remove_(&root, value);
}

void Tree::remove_(Tree_node **pointer, int value) {
    if (*pointer == NULL)
        return;
    if (value == (*pointer)->value) {
        Tree_node **r = &((*pointer)->right);
        Tree_node *tmpt = *pointer;
        if (*r == NULL)
            (*pointer) = (*pointer)->left;
        else {
            Tree_node **l = &((*r)->left);
            if (*l == NULL) {
                //*l = root->left;
                //root = *r;
                *pointer = *r;
                (*r)->left = tmpt->left;
            } else {
                while ((*l)->left != NULL)
                    *l = (*l)->left;
                //root->value = (*l)->value;
                (*pointer)->value = (*l)->value;
                tmpt = *l;
                *l = tmpt->right;
            }
            *l = NULL;
        }
        delete tmpt;
        tmpt = NULL;
        r = NULL;
        size--;
        return;
    }
    if (value > (*pointer)->value)
        remove_(&((*pointer)->right), value);
    else
        remove_(&((*pointer)->left), value);
}


bool Tree::find(int key) {
    find_(key, root);
}

bool Tree::find_(int key, Tree_node *pointer) {
    if (search_(key, pointer) == NULL)
        return false;
    return true;
}


void Tree::destory() {
    destory_(&root);
    size = 0;
}

void Tree::destory_(Tree_node **pointer) {
    //if ((*pointer)->right == NULL && (*pointer)->left == NULL)
    //    return;
    if (*pointer == NULL)
        return;
    destory_(&((*pointer)->right));
    destory_(&((*pointer)->left));
    delete *pointer;
    *pointer = NULL;
}

/*

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

*/

void Tree::preorder() {
    preorder_(root);
}

void Tree::preorder_(Tree_node *pointer) {
    if (pointer == NULL)
        return;
    std::cout << pointer->value << "  ";
    preorder_(pointer->left);
    preorder_(pointer->right);
}


void Tree::inorder() {
    inorder_(root);
}

void Tree::inorder_(Tree_node *pointer) {
    if (pointer == NULL)
        return;
    inorder_(pointer->left);
    std::cout << pointer->value << "  ";
    inorder_(pointer->right);
}


void Tree::postorder() {
    postorder_(root);
}

void Tree::postorder_(Tree_node *pointer) {
    if (pointer == NULL)
        return;
    postorder_(pointer->left);
    postorder_(pointer->right);
    std::cout << pointer->value << "  ";
}


bool Tree::isempty() {
    if (size == 0)
        return true;
    return false;
}


int Tree::getsize() {
    return size;
}

