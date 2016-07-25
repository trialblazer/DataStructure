#include "Stack.h"

List::Creat_List(L head) {

void List::Prin_List(L head) {
    if(Empty_List(head))
        std::cout << "The list is empty, prin failure!!" << std::endl;
    else {
        while(head != NULL) {
            std::cout << head->number << "  :  " << head->total << std::endl;
            head=head->next;
        }
    }
}

void Free_List(L head)
    L = new L sizeof(node);
    if(L == NULL) {
        std::cerr << "Memory allocate failure!!" << std::endl;
        return;
    }
    int datanum=1, tem;
    std::cout << "Please input a number: ";
    std::cin >> tem;
    L->number = datanum;
    L->total = tem;
    L->next = NULL;
    L->top = NULL;
    L pointer = head;
    while(1) {
        datanum++;
        L ne=new L sizeof(node);
        std::cout << "Please input a number: ";
        std::cin >> tem;
        if(tem == 0) break;
        ne->number = datanum;
        ne->total = tem;
        ne->next = NULL;
        ne->top = pointer;
        pointer->next = ne;
        pointer = ne;
    }
    return head;
}
