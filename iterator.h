#ifndef ITERATOR_H
#define ITERATOR_H

#include <cassert>
#include <iostream>
using namespace std;

template <class InputIterator>
void showByIterator(InputIterator first, InputIterator last)
{
    assert(first != last);
    InputIterator temp = last - 1;
    while (first != temp)
    {
        cout << *first << ends;
        ++first;
    }
    cout << *temp << endl;
    return;
}

#endif