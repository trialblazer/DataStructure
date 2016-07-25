/*#include "Tree.h"

Node* Node::find(char value) {
   list<Node*>::iterator t;
   for (t=p.begin(); t!=p.end(); t++)
        if (value == t->data)
            return *t;
   return NULL;
}

void Node::insert(Node* &newnode) {
    p.push_back(newnode);
}

Node* Trie::find(char* value, int size) {
    int j =0;
    Node* p = root.find(value[j]);
    while (j++ != size) {
        if (p == NULL)
            return NULL;
        p = p.find(value[j]);
    }
    return p;
}


bool Trie::insert(char* value, int size) {
    int i = 0, j =0;
    Node* p, temp;
    p = root.find(value[j]);
    while (1) {
        if (p == NULL) {
            temp = new Node(value[j++]);
            root->insert(temp);
            break;
        } else
            p = p->find(value[++j]);
    }
    list<Node*>iterator t;
    Node* pointer = NULL;
    while (j++ != size) {
        for (t=p->begin(); t!=p->end(); t++) {
            pointer = *t->find(value[j++]);
            if (pointer != NULL)
                break;
        }
        if (pointer == NULL) {
            pointer = new Node(value[j++]);
            temp.insert(pointer);
            temp = pointer;
        }
        p = p.find(value[j]);
        if (p == NULL)
            return NULL;
    }
    return p;
}


    if (temp == NULL) {
        temp =
        v[i-1].push_back(temp);
    }
    p->push_back(temp);

*/



#include "Tree.h"
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <stack>

Node* Node::find(char value) {
   list<Node*>::iterator t;
   for (t=p.begin(); t!=p.end(); t++)
        if (value == (*t)->data)
            return *t;
   return NULL;
}

void Node::insert(Node* &newnode) {
    p.push_back(newnode);
}


Node* Trie::find(char* value, int size) {
    int j =-1;
    Node* p = root;
    while (++j != size) {
        p = p->find(value[j]);
        if (p == NULL)
            return NULL;
    }
    return p;
}

Trie::Trie() {
    root = new Node();
    root->data = '#';
}

bool Trie::insert(char* value, int size) {
    int i = 0, j =0;
    bool sign;
    Node* p, *temp = root;
    p = root->find(value[j]);
    while (j < size) {
        sign = false;
        if (p == NULL) {
            p = new Node(value[j++]);
            temp->insert(p);
            sign = true;
        }
        temp = p;
        if (sign)
            p = p->find(value[j]);
        else
            p = p->find(value[++j]);
    }
    return (sign && (size == j));
}

bool Trie::del(char* value, int size) {
    int j =-1;
    stack<Node*> s;
    Node* p = root, *pointer;
    while (++j != size) {
        s.push(p);
        p = p->find(value[j]);
        if (p == NULL)
            return false;
    }
    s.push(p);
    j = 0;
    while (s.size() > 1) {
        p = s.top();
        s.pop();
        int len = p->p.size();
        if (j == 0) {
            if (len != 0)
                return false;
            pointer = p;
            delete p;
            p = s.top();
            p->p.remove(pointer);
            continue;
        }
        if (len == 0) {
            pointer = p;
            delete p;
            p = s.top();
            p->p.remove(pointer);
        } else
            return true;
    }
}


bool Trie::remove() {
    stack<Node*> s;
    list<Node*>::iterator t;
    Node* temp = root;
    s.push(root);
    bool sign = false;
    while (!s.empty()) {
        s.pop();
        for (t=temp->p.begin(); t!=temp->p.end(); t++)
            s.push(*t);
        delete temp;
        if (s.empty())
            break;
        temp = s.top();
    }
    root = NULL;
    return true;
}

void Trie::prin() {
    stack<Node*> s;
    list<Node*>::iterator t;
    Node* temp = root;
    if (root == NULL) {
        std::cout << "empty tree" << std::endl;
        return;
    }
    s.push(root);
    bool sign = false;
    while (!s.empty()) {
        s.pop();
        for (t=temp->p.begin(); t!=temp->p.end(); t++)
            s.push(*t);
        if (s.empty())
            break;
        temp = s.top();
        std::cout << temp->data << "  ";
    }
}



/*
bool Trie::del(char* value, int size) {
    if (find(value, size) == NULL)
        return false;

    int j =-1, s;
    bool sign = true;
    Node *rp, *temp = root;
    while (++j <= size) {
        s = temp->p.size();
        if (s == 0 || j == size) {
            if (s != 0) {
                strcpy(&(temp->data), "#");
                root->insert(temp);
                std::cout << "\ndelete error!\n";
                exit(1);
            } else
            delete temp;
        } else {
            rp = temp->find(value[j]);
            s = rp->p.size();
            if (s == 1) {
                temp->p.remove(rp);
                if (!sign)
                    delete temp;
            }
            temp = rp;
            sign = false;
        }
    }
    return true;
}


bool Trie::_remove(Node* sub) {
    list<Node*>::iterator t;
    Node* pointer, *point;
    for (t=sub->p.begin(); t!=sub->p.end(); t++) {
        std::cout << (*t)->data << "  ";
    }
    for (t=sub->p.begin(); t!=sub->p.end(); t++) {
        point = *t;
        if ((*t)->p.empty()) {
            pointer = *t;
            sub->p.remove(pointer);
            delete *t;
        } else
            _remove(point);
         *t = point;
    }
}

bool Trie::destory(Node* sub) {
    if (sub == NULL)
        return false;
    return _remove(sub);
}
*/





























