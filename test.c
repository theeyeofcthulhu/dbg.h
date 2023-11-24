#include <stdio.h>

#include "dbg.h"

int function(int a, int b)
{
    puts("test");
    return a+b;
}

int main(int argc, char **argv)
{
    (void)argc;

    HERE();
    MSG("at main");

    DBG(argv[0]);

    const char *msg = "Hello";
    DBG(msg);

    int n = 3;
    DBG(n);
    DBG((unsigned int)n + 2);

    long double uld = 333.333f;
    DBG(uld);

    long long a = 23123123;
    unsigned long long b = 12341234345;

    DBG(a);
    DBG(b);

    float f = 3.2f;
    DBG(f);

    float f2 = 1.2f;
    DBG(f2);

    const float c = 3.0;
    DBG(c);

    char stack_str[] = "test";
    DBG(stack_str);

    int ptr = 3;
    D(&ptr);

    char ptr2 = 'a';
    D((int*) &ptr2);

    DBG(function(2,3));
}
