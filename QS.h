#ifndef QS_H
#define QS_H

#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
using namespace std;

// 快排, 为了优化最坏情况, 进行随机初始化
// time: O(nlgn)
// space: O(1)
class QuickSort {
  public:
    void randomQuickSort(vector<int> &g, int start, int end) {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(g.begin() + start, g.end() + end() - 1, default_random_engine(seed));
        quickSort(g, start, end);
    }
    void quickSort(vector<int> &g, int start, int end) {
        if (start < end) {
            int q = partition(g, start, end);
            quickSort(g, start, q - 1);
            quickSort(g, q + 1, end);
        }
    }
  private:
    int partition(vector<int> &g, int start, int end) {
        int i = start, j = start - 1;
        for (i = start; i < end; ++i)
            if (g[i] < g[end])  // 将小值放在该放的位置上
                swap(g[i], g[++j]);
        swap(g[++j], g[end]);
        return j;
    }
}
#endif