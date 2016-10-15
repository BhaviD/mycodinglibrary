#ifndef _SHELL_SORT_H_
#define _SHELL_SORT_H_

/* For details and explanation, refer Page #215 of
 * "Data Structures in C++ using STL", William Ford & William Topp
 */

#include <vector>

// Sort an array of type T using Shell Sort
template <typename T>
void ShellSort(T arr[], int n);

// Sort an vector of type T using Shell Sort
template <typename T>
void ShellSort(std::vector<T>& v);

template <typename T>
void ShellSort(T arr[], int n)
{
    int k = 1;
    T target{};

    /* Calculate interval i.e. k */
    while(k <= n / 9)
        k = 3 * k + 1;

    while(k > 0)
    {
        int l{};
        while(l < k)
        {
            for (int i = l + k; i < n; i += k)
            {
                // index j scans down list from arr[i] looking for
                // correct position to locate target. assigns it to
                // arr[j]
                int j = i;
                target = arr[i];
                // locate insertion point by scanning downward as long
                // as target < arr[j - k] and we have not encountered the
                // beginning of the list
                while (j > l && target < arr[j - k])
                {
                    // shift elements up list to make room for insertion
                    arr[j] = arr[j - k];
                    j -= k;
                }
                // the location is found; insert target
                arr[j] = target;
            }
            ++l;
        }
        k = (k - 1) / 3;
    }
}

template <typename T>
void ShellSort(std::vector<T>& v)
{
    /* Calculate interval i.e. k */
    int n = v.size(), k = 1;
    T target{};
    while(k <= n / 9)
        k = 3 * k + 1;

    while(k > 0)
    {
        int l{};
        while(l < k)
        {
            for (int i = l + k; i < n; i += k)
            {
                // index j scans down list from v[i] looking for
                // correct position to locate target. assigns it to
                // v[j]
                int j = i;
                target = v[i];
                // locate insertion point by scanning downward as long
                // as target < v[j - k] and we have not encountered the
                // beginning of the list
                while (j > l && target < v[j - k])
                {
                    // shift elements up list to make room for insertion
                    v[j] = v[j - k];
                    j -= k;
                }
                // the location is found; insert target
                v[j] = target;
            }
            ++l;
        }
        k = (k - 1) / 3;
    }
}

#endif
