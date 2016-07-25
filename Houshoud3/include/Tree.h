#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <vector>
#include <list>

using namespace std;

class Node {
public:
    char data;
    list<Node*> p;

public:
    Node() {}
    Node(char value):data(value) {}
    Node* find(char value);
    void insert(Node*&);
};

class Trie {
    Node* root;

public:
    Trie();
    ~Trie() {remove();}
    Node* find(char*, int size);
    bool insert(char*, int size);
    bool del(char*, int size);
    bool remove();

    void prin();
};







































































/*
#define Max 5
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct TreeNode {
    int data;
    struct TreeNode* rchild;
    struct TreeNode* lchild;
}TreeNode, *Link;

typedef struct BinaryTree {
    TreeNode* root;

    BinaryTree():root(NULL) {}

    void creat();
    bool insert(int iterm);
    void level_order();
    void pre_order();
    void in_order();
    void post_order();
}BinaryTree;

void BinaryTree::creat() {
    printf("please input %d datas:", Max);
    int i, temp, a[Max];
    for (i=0; i<Max; i++)
        scanf("%d", &a[i]);
    for (i=0; i<Max; i++)
        insert(temp);
}

bool BinaryTree::insert(int iterm) {
    Link p = root;
    while (p != NULL) {
        if (iterm > p->data)
            p = p->rchild;
        else p = p->lchild;
    }
    p = (Link)malloc(sizeof(TreeNode));
    if (p == NULL) {
        printf("Error!!");
        exit(1);
    }
    p->data = iterm;
    p->rchild = NULL;
    p->lchild = NULL;
}

void BinaryTree::level_order() {
    printf("binary-Level_order: \n");
    queue<Link> q;
    Link r = root;
    q.push(r);
    while (!q.empty()) {
        r = q.front();
        printf("%-3d", r->data);
        q.pop();
        if (r->lchild != NULL)
            q.push(r->lchild);
        if (r->rchild != NULL)
            q.push(r->rchild);
    }
}
*/
#endif // TREE_H_INCLUDED
