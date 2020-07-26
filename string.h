#ifndef STRING_H
#define STRING_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> stringTOVectorInt(const char split = ',')
{
    vector<int> result;
    char c[256];
    if (cin.getline(c, 250))
    {
        string tmp(c);
        tmp.push_back(split);
        size_t start = 0;
        size_t locate = tmp.find(split, start);
        while (locate != string::npos)
        {
            string slice = tmp.substr(start, locate - start);
            int intSlice = atoi(slice.c_str());
            result.push_back(intSlice);
            start = ++locate;
            locate = tmp.find(split, start);
        }
    }
    return result;
}

#endif