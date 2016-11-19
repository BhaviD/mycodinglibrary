#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_

template <typename T>
void InsertionSort(std::vector<T>& v);

template <typename T, typename Compare>
void InsertionSort(std::vector<T>& v, Compare comp); 

template <typename T>
void InsertionSort(std::vector<T>& v)
{
   int i, j, n = v.size();
   T target;

    // place v[i] into the sublist
    //   v[0] ... v[i-1], 1 <= i < n,
    // so it is in the correct position
   for (i = 1; i < n; i++)
   {
      // index j scans down list from v[i] looking for
      // correct position to locate target. assigns it to
      // v[j]
      j = i;
      target = v[i];
      // locate insertion point by scanning downward as long
      // as target < v[j-1] and we have not encountered the
      // beginning of the list
      while (j > 0 && target < v[j-1])
      {
         // shift elements up list to make room for insertion
         v[j] = v[j-1];
         j--;
      }
      // the location is found; insert target
      v[j] = target;
   }
}

template <typename T, typename Compare>
void InsertionSort(std::vector<T>& v, Compare comp)
{
   int i, j, n = v.size();
   T target;

    // place v[i] into the sublist
    //   v[0] ... v[i-1], 1 <= i < n,
    // so it is in the correct position
   for (i = 1; i < n; i++)
   {
      // index j scans down list from v[i] looking for
      // correct position to locate target. assigns it to
      // v[j]
      j = i;
      target = v[i];
      // locate insertion point by scanning downward as long
      // as comp(target, v[j-1]) is true and we have not encountered 
      // the beginning of the list
      while (j > 0 && comp(target, v[j - 1]))
      {
         // shift elements up list to make room for insertion
         v[j] = v[j - 1];
         j--;
      }
      // the location is found; insert target
      v[j] = target;
   }
}

#endif
