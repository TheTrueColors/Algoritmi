#include <fstream>
#include <iostream>

#include "BinaryHeap.h"
#include "Paziente.h"

int main() {
  BinaryHeap<Paziente>* pQ = new BinaryHeap<Paziente>(5);
  Paziente* p1 = new Paziente("Pippo", "Lino", 23, 1);
  Paziente* p2 = new Paziente("Gina", "Rina", 63, 1);
  Paziente* p3 = new Paziente("Zio", "Tio", 43, 3);
  Paziente* p4 = new Paziente("Pupe", "Tto", 13, 2);
  Paziente* p5 = new Paziente("Lava", "Trice", 23, 2);
  pQ->enqueue(p1)
      ->enqueue(p2)
      ->enqueue(p3)
      ->enqueue(p4)
      ->enqueue(p5)
      ->buildHeap();
  pQ->printQueue();
}