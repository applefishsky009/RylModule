#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

template <class elementType>
void show1DVector(const vector<elementType> &nums)
{
    assert(nums.size() != 0);
    const int col = nums.size();
    for (int i = 0; i < col - 1; i++)
        cout << nums[i] << ends;
    cout << nums[col - 1] << endl;
    return;
}

template <>
void show1DVector(const vector<string> &str)
{
    assert(str.size() != 0);
    const int row = str.size();
    for (int i = 0; i < row; i++)
        cout << str[i] << endl;
    return;
}

template <class elementType>
void show2DVector(const vector<vector<elementType>> &matrix)
{
    assert(matrix.size() != 0);
    const int n = matrix.size();
    for (auto x : matrix)
    {
        if (x.size() > 0)
            show1DVector(x);
        else
            cout << "NULL" << endl;
    }
    return;
}

//模板特例化
template<>
void show2DVector(const vector<vector<string>> &matrix)
{
    assert(matrix.size() != 0);
    for (auto x : matrix)
    {
        for (auto y : x)
            cout << y << endl;
        cout << endl;
    }
    return;
}



template <class elementType>
void reverseVectorInPlace(vector<elementType> &nums) {
    assert(nums.size() != 0);
    const int n = nums.size();
    for (int i = 0; i < n / 2; i++)
        swap(nums[i], nums[n - i - 1]);
} 

#endif