#ifndef BinaryHeap_H
#define BinaryHeap_H

#include "Paziente.h"
#include "PriorityQueue.h"

using namespace std;

template <class T>
class BinaryHeap {
 private:
  T** queue;
  int queueLength;
  int heapSize;

  int left(int i) { return i << 1; }
  int right(int i) { return i << 1 | 1; }
  int parent(int i) { return i >> 1; }

  void swap(int i, int j) {
    T* tmp = queue[i];
    queue[i] = queue[j];
    queue[j] = tmp;
  }

  double compare(T* a, T* b) { return b->getPriority() - a->getPriority(); }
  void heapify(int i) {
    if (i > heapSize) return;
    int l = left(i);
    int r = right(i);
    int v = i;

    if (l <= heapSize && compare(queue[v], queue[l])) v = l;
    if (r <= heapSize && compare(queue[v], queue[r])) v = r;
    if (v = i) return;
    swap(i, v);
    heapify(v);
  }

  void moveUpKey(int i) {
    while (i > 1 && compare(queue[i], queue[parent(i)]) > 0) {
      swap(i, parent(i));
      i = parent(i);
    }
  }

 public:
  BinaryHeap(int size) {
    queue = new T*[size + 1];
    queueLength = size + 1;
    heapSize = 0;
  }

  BinaryHeap<T>* enqueue(T* x) {
    if (heapSize == queueLength - 1) return this;
    heapSize += 1;
    queue[heapSize] = x;
    int i = heapSize;
    moveUpKey(i);
    return this;
  }

  void buildHeap() {
    for (int i = heapSize / 2; i > 0; i--) heapify(i);
  }

  void modify(int i, T k) {
    if (i < 1 || i > heapSize) return;

    if (compare(queue[i], &k) >= 0) return;

    delete queue[i];

    queue[i] = new T(k);
    moveUpKey(i);
    return;
  }

  T* extract() {
    if (heapSize == 0) return NULL;

    swap(1, heapSize);
    heapSize--;
    heapify(1);
    return queue[heapSize + 1];
  }

  T** getPrioQueue() { return queue; }
  int getSize() { return heapSize; }

  void printQueue() {
    for (int i = 1; i <= heapSize; i++) cout << *queue[i];
    cout << endl;
  }
};

#endif