#ifndef PriorityQueue_H
#define PriorityQueue_H

template <class T>
class PriorityQueue {
 public:
  virtual T extract() = 0;
  virtual double compare(T* a, T* b) = 0;
  virtual PriorityQueue<T>* enqueue(T x) = 0;
  virtual void printQueue() const = 0;
};

#endif