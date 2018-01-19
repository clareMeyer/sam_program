//sorts.h

#ifndef SORTS_H
#define SORTS_H

template <typename T>
class Sorts
{
public:
  static void mergeSort(T arr[], int size);
private:
  static void merge(T* a1, T* a2, int size1, int size2);
};
#include "Sorts.hpp"
#endif
