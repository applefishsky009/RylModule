#ifndef TREE_H
#define TREE_H

#include <queue>
#include <vector>
#include <cassert>
#include <typeinfo>
#include <iostream>
#include <algorithm>
#include <D:\Github\RylModule\vector.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {};
    TreeNode(int x, TreeNode *l, TreeNode *r, TreeNode *p) : val(x), left(l), right(r), parent(p) {};
};

TreeNode *constructTree(const vector<int> &nums = {0, -1, 2, -1, -1, 5, 6, -1, -1, -1, -1, 11, 12})
{
    assert(nums.size() != 0);
    const int n = nums.size();
    TreeNode *root = new TreeNode(nums[0]);
    int vectorUnusedID = 1;
    queue<TreeNode*> rememberQ;
    rememberQ.push(root);
    while (!rememberQ.empty())
    {
        if (rememberQ.front() == nullptr) {
            vectorUnusedID = vectorUnusedID + 2;
            rememberQ.push(nullptr);
            rememberQ.push(nullptr);
            rememberQ.pop();
            continue;
        }
        if (vectorUnusedID < n)
        {
            if (nums[vectorUnusedID] != INT_MIN)
                rememberQ.front()->left = new TreeNode(nums[vectorUnusedID], nullptr, nullptr, rememberQ.front());
            rememberQ.push(rememberQ.front()->left);
        }
        vectorUnusedID++;
        if (vectorUnusedID < n)
        {
            if (nums[vectorUnusedID] != INT_MIN)
                rememberQ.front()->right = new TreeNode(nums[vectorUnusedID], nullptr, nullptr, rememberQ.front());
            rememberQ.push(rememberQ.front()->right);
        }
        vectorUnusedID++;
        if (vectorUnusedID >= n) break;
        rememberQ.pop();
    }
    return root;
}

vector<vector<int>> showTree(TreeNode *root)
{
    assert(root != nullptr);
    vector<vector<int>> tree;
    queue<TreeNode*> levelNodeQ;
    levelNodeQ.push(root);
    int levelNum = 1;
    bool isNull = false;
    while (!levelNodeQ.empty())
    {
        isNull = true;  //假设该层为空
        vector<int> levelVector;
        for (int i = 0; i < levelNum; i++)
        {
            if (levelNodeQ.front() == nullptr)
            {
                levelNodeQ.push(nullptr);
                levelNodeQ.push(nullptr);
                levelVector.push_back(INT_MIN);
            }
            else    //该层有一个不为空，说明还要按层次遍历
            {
                isNull = false;
                levelNodeQ.push(levelNodeQ.front()->left);
                levelNodeQ.push(levelNodeQ.front()->right);
                levelVector.push_back(levelNodeQ.front()->val);
            }
            levelNodeQ.pop();
        }
        tree.push_back(levelVector);
        levelVector.clear();

        levelNum *= 2;
        if (isNull == true)
            break;
    }
    tree.pop_back();
    show2DVector(tree);
    return tree;
}

/*
template <class elementType>
TreeNode<elementType> *constructTree(const vector<elementType> &nums)
{
    assert(nums.size() != 0);
    const int n = nums.size();
    TreeNode<elementType> *root = new TreeNode<elementType>(nums[0]);
    int vectorUnusedID = 1;
    queue<TreeNode<elementType>*> rememberQ;
    rememberQ.push(root);
    while (!rememberQ.empty())
    {
        if (rememberQ.front() == nullptr) {
            vectorUnusedID = vectorUnusedID + 2;
            rememberQ.push(nullptr);
            rememberQ.push(nullptr);
            rememberQ.pop();
            continue;
        }
        if (vectorUnusedID < n)
        {
            if ( (typeid(nums[vectorUnusedID]) == typeid('#') && nums[vectorUnusedID] != '#') || 
                 (typeid(nums[vectorUnusedID]) == typeid(-1) && nums[vectorUnusedID] != -1) )
                rememberQ.front()->left = new TreeNode<elementType>(nums[vectorUnusedID]);
            rememberQ.push(rememberQ.front()->left);
        }
        vectorUnusedID++;
        if (vectorUnusedID < n)
        {
            if ( (typeid(nums[vectorUnusedID]) == typeid('#') && nums[vectorUnusedID] != '#') || 
                 (typeid(nums[vectorUnusedID]) == typeid(-1) && nums[vectorUnusedID] != -1) )
                rememberQ.front()->right = new TreeNode<elementType>(nums[vectorUnusedID]);
            rememberQ.push(rememberQ.front()->right);
        }
        vectorUnusedID++;
        if (vectorUnusedID >= n) break;
        rememberQ.pop();
    }
    return root;
}
*/

#endif