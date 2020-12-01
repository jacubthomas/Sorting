#ifndef QSORT_H
#define QSORT_H

#include <algorithm>
#include <functional>
#include <vector>

template <class T, class TComparator>
void quicksort_help(std::vector<T> &vec, int L, int R, TComparator comparator);

template <class T, class TComparator>
T &median_of_three(T &a, T &b, T &c, TComparator comparator) {

  // if 2 elements equal then choose one as median
  if (a == b)
    return b;
  else if (b == c)
    return b;
  else if (a == c)
    return c;

  if (comparator(a, b)) {

    // a < b < c
    if (comparator(b, c))
      return b;

    // c < a < b
    else if (comparator(c, a))
      return a;

    // a < c < b
    else
      return c;
  }

  else {
    // b < a < c
    if (comparator(a, c))
      return a;

    // b < c < a
    else if (comparator(b, c))
      return c;

    // c < b < a
    else
      return b;
  }
}

// this function selects a pivot using median of three, and then repositions all
// lesser elements to the left of pivot & all greater elements to the right.
// After, it returns the pivot index.
template <class T, class TComparator>
int partition(std::vector<T> &vec, TComparator &comparator, int low, int high) {

  // "i" will track location of pivot for end-of-function swap
  int i = low;

  // pivot is the value returned from median of three call
  T pivot =
      median_of_three(vec[low], vec[(low + high) / 2], vec[high], comparator);

  // partitions the elements around the pivot accordingly
  for (int j = low; j <= high; j++) {
    if (comparator(vec[j], pivot)) {
      std::swap(vec[i], vec[j]);

      // updates the pivot index
      i++;
    }
  }

  // finds the pivot index for swap
  typename std::vector<T>::iterator it =
      std::find(vec.begin(), vec.end(), pivot);
  int pivot_idx;
  if (it != vec.end())
    pivot_idx = it - vec.begin();

  // swaps pivot into correct index
  std::swap(vec[i], vec[pivot_idx]);
  return i;
}

template <class T, class TComparator>
void quicksort(std::vector<T> &vec, TComparator comparator) {
  quicksort_help(vec, 0, vec.size() - 1, comparator);
}

template <class T, class TComparator>
void quicksort_help(std::vector<T> &vec, int L, int R, TComparator comparator) {

  // base case: if recursive calls have partitioned to 1 element (or less) do
  // nothing! 1 element is always sorted.
  if (L >= R)
    return;

  // middle is the pivot returned by partition. This pivot is exactly positioned
  // in the vector.
  int middle = partition(vec, comparator, L, R);

  // recursive calls around the pivot
  quicksort_help(vec, L, middle - 1, comparator);
  quicksort_help(vec, middle + 1, R, comparator);
}

#endif
