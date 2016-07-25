#include "RedBlack_Tree.h"
#include <ctime>
#include <stdlib.h>

int main()
{
    RedBlack_Tree t;
    srand(time(NULL));
    for (int i=0; ; i++)
        t.insert(rand());
    return 0;
}
