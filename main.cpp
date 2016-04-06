#include <iostream>
#include "mtrx.h"
#include <assert.h>

using namespace std;

int main()
{
    Rectangle rect;
    rect.set_values(2, 5);
    assert(rect.return_square() == 10);
    rect.set_values(0, 100);
    assert(rect.return_square() == 0);
    rect.set_values(1, 1);
    assert(rect.return_square() == 1);
    return 0;
}
