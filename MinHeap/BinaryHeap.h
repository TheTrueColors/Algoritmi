// Classe di un BinaryHeap generico

#ifndef BinaryHeap_H
#define BinaryHeap_H

#include <iostream>

#include "PriorityQueue.h"

using namespace std;

template <class T>
class BinaryHeap : public PriorityQueue<T> {
 private:
  // Vettore che conterrà i dati dell'heap
  T** queue;

  // Numero di elementi dell'heap
  int heapsize;

  // Grandezza vel vettore dei dati
  int queueLength;

  int heapCall;

  // Metodo per ottenere il figlio sinistro
  int left(int i) {
    return i << 1;  // 2i 2*i
  }

  // Metodo per ottenere il figlio destro
  int right(int i) {
    return (i << 1) | 1;  // 2i+1
  }

  // Metodo per ottenere il parent
  int parent(int i) {
    return i >> 1;  // i/2
  }

  // Metodo per lo scambio di posizione
  void swap(int i, int j) {
    T* tmp = queue[i];
    queue[i] = queue[j];
    queue[j] = tmp;
  }

  // Definizione dell metodo per confrontare due elementi
  double compare(T* a, T* b) { return (*a) - (*b); }

  // Metodo che controlla e/o applica la propietà dell heap su un albero(in
  // questo caso l'albero è rappresentato tramite vettore)
  void heapify(int i) {
    if (i > heapsize) return;
    hCallIncr();
    int l = left(i);
    int r = right(i);
    int v = i;

    if (l <= heapsize && compare(queue[v], queue[l]) < 0) v = l;

    if (r <= heapsize && compare(queue[v], queue[r]) < 0) v = r;

    if (v == i) return;

    swap(i, v);
    heapify(v);
  }

  // Metodo che mi permette di spostare un elemento alla posizione superiore
  void moveUpKey(int i) {
    while (i > 1 && compare(queue[i], queue[parent(i)]) > 0) {
      swap(i, parent(i));
      i = parent(i);
    }
  }

 public:
  // Metodo di stampa
  void print(ofstream& out) {
    if (heapsize < 1) return;

    for (int i = 1; i <= heapsize; i++) {
      out << *queue[i];
      if (i != heapsize) out << " ";
    }
  }

  // Costruttore avendo vettore e grandezza
  BinaryHeap(T** V, int size) {
    queue = V;
    queueLength = size + 1;
    heapsize = size;
    heapCall = 0;
  }

  // Costruttore avendo solo la grandezza
  BinaryHeap(int size) {
    queue = new T*[size + 1];
    queueLength = size + 1;
    heapsize = 0;
    heapCall = 0;
  }

  // Metodo che crea un heap partendo da un vettore non ordinato
  void buildHeap() {
    for (int i = heapsize / 2; i > 0; i--) heapify(i);
  }

  // Metodo per estrarre il min/max
  T* extract() {
    if (heapsize == 0) return NULL;

    swap(1, heapsize);
    heapsize--;
    heapify(1);
    return queue[heapsize + 1];
  }

  // Metodo che mi ritorna l'heap
  T** getPriorityQueue() const { return queue; }

  // Metodo che mi permette di modificare la priorità/valore di un elemento
  void modify(int i, T k) {
    if (i < 1 || i > heapsize) return;

    if (compare(queue[i], &k) >= 0) return;

    delete queue[i];

    queue[i] = new T(k);
    moveUpKey(i);
    return;
  }

  // Metodo per inserire uno ad uno gli elementi
  BinaryHeap<T>* enqueue(T x) {
    if (heapsize == queueLength - 1) return this;
    heapsize += 1;
    queue[heapsize] = new T(x);
    int i = heapsize;
    moveUpKey(i);
    return this;
  }

  // Boh l'ho trovata in un vecchio codice
  void sort() {
    int node_number = heapsize;
    for (int i = 0; i < node_number; i++) extract();
    heapsize = node_number;
  }

  // Metodo che ritorna la dimensione dell heap
  int size() const { return heapsize; }

  void hCallIncr() { heapCall++; }
  int hCall() { return heapCall; }
};

#endif