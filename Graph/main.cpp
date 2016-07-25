#include "Test.h"
#include "Graph_Lnk.h"
#include "Graph_Matrix.h"

int main() {
    Test<Graph_Lnk> tgl;
    Test<Graph_Matrix> tgm;

    //tgm.menue();
    tgl.menue();
    return 0;
}
