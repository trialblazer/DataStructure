/*#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

#define Max 50
int Nu=0;

typedef class
{C:\Users\trialblazer\AppData\Roaming\CodeBlocks\default.workspace
public:
    class* Init();
    int Creat_tree(class* root);
    void Destory(class* root);
    void Prin(class* root);
    class* Insert(class* root);
    class* delete_tree(class* root);
    void search_tree(class* root);
private:
    char name[Max];
    int number;
    int level;
    class* parent;
    class* right;
    class* left;
}node, *Link;

Link node::Init()
{
    Link root;
    root=(Link)malloc(sizeof(node));
    if(root==NULL)
        cout<<"failure!!"<<endl;
    else {
        char dataname[Max];
        ++Nu;
        cout<<"Please input the dataname: ";
        cin>>dataname;
        if(dataname[0]=='0')
            return 1;
        root->number=Nu;
        for(int i=0; i<Max; i++)
            root->name[i]=dataname[i];
        root->left=NULL;
        root->right=NULL;
        root->parent=NULL;
    }
    return root;
}

void node::Prin(Link root)
{
    while(root!=NULL) {
        cout<<root->number<<"   --->    "<<root->name<<endl;
        Prin(root->right);
        Prin(root->left);
    }
}

void node::Destory(Link root)
{
    if(root==NULL)
        free(root);
    else {
        Destory(root->left);
        Destory(root->right);
    }
}

int node::Creat_tree(Link root)
{
    int i;
    char dataname[Max];
    ++Nu;
    cout<<"Please input the dataname: ";
    cin>>dataname;
    if(dataname[0]=='0')
        return 1;
    root->number=Nu;
    for(int i=0; i<Max; i++)
        root->name[i]=dataname[i];
    root->left=NULL;
    root->right=NULL;
    root->parent=NULL;
    ne=(Link)malloc(sizeof(node));
    cout<<"Please input the dataname:  ";
    cin>>dataname;
    if(dataname[0]=='0')
        return 1;
    datanum=ne->number;
    for(int i=0; i<Max; i++)
        dataname[i]=ne->name[i];
    ne->left=NULL;
    ne->right=NULL;
    if(datanum%2==0) {
        pointer->left=ne;
        ne->parent=pointer;
    }
    else {
        pointer->right=ne;
        ne->parent=pointer;
    }
}



Link node::Insert(Link root)
{

}

Link node::delete_tree(Link root)
{

}


*/








/*

#include<stdio.h>
#include<stdlib.h>

#define Max 10

typedef struct stacknode
{
    int number;
    struct stacknode *top;
}node,*stack;

void Init(stack L)
{
    L=(stack)malloc(sizeof(node));
    L->top=NULL;
}

void push(stack L, int num)
{
    stack ne;
    ne=(stack)malloc(sizeof(node));
    int i;
    ne->number=num;
    ne->top=L->top;
    L->top=ne;
}

int pop(stack L)
{
    int i, n;
    if(L->top!=NULL) {
        stack pointer=(L->top)->top;
        //stack pointer;
        //pointer=L;
        //L=L->next;
        //free(pointer);
        //return n;
        free(L->top);
        L->top=pointer;
        return n;
    } else {
        printf("Full!!");
    }

}

int main()
{
    stack L;
    Init(L);
    int i, n;
    for(i=0; i<Max; i++)
    {
        printf("Please input the number:  ");
        scanf("%d", &n);
        if(n==0)
            break;
        push(L, n);
    }
    for(i=0; i<Max; i++) {
        printf("%d\n", pop(L));
    }
    return 0;
}
*/

#include<iostream>

#include"Stack.h"

using namespace std;

int main()
{
    Stack s;
    for(int i=0; i<200; i++) {
        s.push(i);
    }

    while(!s.empty()) {
        cout << s.top() << "  ";
        s.pop();
    }
    return 0;
}
