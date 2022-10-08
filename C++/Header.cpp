#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>

namespace test
{
    void a(char *a );
}

int main()
{
    char b[12]="12345678910";
    test::a(b);
    return 0;
}
