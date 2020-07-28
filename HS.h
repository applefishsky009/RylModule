#ifndef HS_H
#define HS_H

#include <vector>
using namespace std;
class HeapSort {
  public:
    HeapSort(vector<int> &h) : start(0), end(h.size() - 1), heapSize(h.size()), heapLength(h.size()) {};
    HeapSort(vector<int> &h, int s, int e) : start(s), end(e), heapSize(e - s + 1), heapLength(e - s + 1) {};
    void heapSort(vector<int> g) {
        buildMaxHeap(g);
        for (int i = end; i >= start; --i) {
            swap(g[start], g[i]);
			--heapSize;
			maxHeapify(g, start);
		}
    }
  private:
    int start;      // 起始点-闭区间
    int end;        // 起始点-闭区间
    int heapSize;   // 有效长度
    int heapLength; // 容量大小
	void maxHeapify(vector<int> &g, int i) {
		int l = left(i), r = right(i), largest = i;
		if (l < start + heapSize && g[largest] < g[l])
			largest = l;
		if (r < start + heapSize && g[largest] < g[r])
			largest = r;
		if (largest != i) {
			swap(g[i], g[largest]);
			maxHeapify(g, largest);	// 逐级下降
		}
	}
	void buildMaxHeap(vector<int> &g) {
		for (int i = start + (heapLength >> 1) - 1; i >= start; --i)
			maxHeapify(g, i);
	}
	int left(int i) {return ((i - start) << 1) + start + 1;};
	int right(int i) {return ((i - start) << 1) + start + 2;};
};
#endif
