#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<iostream>

typedef class List
{
public:
    bool Empty_List(List* head);
    bool Insert_List(int value, int index, List* head);
    bool Free_List(List* head);
    int Get_List(List* head, int index);
    void Prin_List(List* head);
    List* Creat_List(List* head);
private:
    int number;
    int total;
    class List* next;
    class List* top;
}node, *L;

#endif // STACK_H_INCLUDED
