#include "Map.h"
#include <cstdio>
#include <functional>
#include<iostream>

int main()
{

    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";

    m[30] = "Poo";
    int index, key;
    const char* value;
   Map<int,const char*>:: Iterator x;
    for (auto x : m)

    {
        index = x.Index; key = x.Key; value = x.Value;
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }

    m[20] = "result";

    for (auto x : m)

    {

        index = x.Index; key = x.Key; value = x.Value;
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }

    return 0;

}