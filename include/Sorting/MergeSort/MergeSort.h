#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

// the elements in the ranges [first,mid) and [mid,last) are
// ordered. the function merges the ordered sequences into
// an ordered sequence in the range [first,last)
template <typename T>
void Merge(std::vector<T>& v, int first, int mid, int last);

// sorts v in the index range [first,last) by merging
// ordered sublists
template <typename T>
void MergeSort(std::vector<T>& v, int first, int last);

template <typename T>
void Merge(std::vector<T>& v, int first, int mid, int last)
{
    // temporary vector to merge the sorted sublists
    std::vector<T> tempVector;
    int indexA, indexB, indexV;

    // set indexA to scan sublistA (index range [first,mid)
    // and indexB to scan sublistB (index range [mid, last)
    indexA = first;
    indexB = mid;

    // while both sublists are not exhausted, compare v[indexA] and
    // v[indexB]copy the smaller to vector temp using push_back()
    while (indexA < mid && indexB < last)
        if (v[indexA] < v[indexB])
        {
            tempVector.push_back(v[indexA]);    // copy element to temp
            indexA++;                               // increment indexA
        }
        else
        {
            tempVector.push_back(v[indexB]);    // copy element to temp
            indexB++;                               // increment indexB
        }

    // copy the tail of the sublist that is not exhausted
    while (indexA < mid)
    {
        tempVector.push_back(v[indexA]);
        indexA++;
    }

    while (indexB < last)
    {
        tempVector.push_back(v[indexB]);
        indexB++;
    }

    // copy vector tempVector using indexV to vector v using indexA
    // which is initially set to first
    indexA = first;

    // copy elements from temporary vector to original list
    for (indexV = 0; indexV < tempVector.size(); indexV++)
    {
        v[indexA] = tempVector [indexV];
        indexA++;
    }
}

// sorts v in the index range [first,last) by merging
// ordered sublists
template <typename T>
void MergeSort(std::vector<T>& v, int first, int last)
{
    // if the sublist has more than 1 element continue
    if (first + 1 < last)
  {
        // for sublists of size 2 or more, call MergeSort()
        // for the left and right sublists and then
        // merge the sorted sublists using Merge()
        int midpt = (last + first) / 2;

        MergeSort(v, first, midpt);
        MergeSort(v, midpt, last);
        Merge(v, first, midpt, last);
   }
}

#endif // _MERGE_SORT_H_
