#include <bits/stdc++.h>
using namespace std;

/**
 * Brute Force Approach
 * Time Complexity: O(N^2) - Compares every element with every element after it.
 * Space Complexity: O(1)
 */
bool isSortedReverseBruteForce(int nums[], int size)
{
    for (int currentIdx = 0; currentIdx < size; currentIdx++)
    {
        for (int nextIdx = currentIdx + 1; nextIdx < size; nextIdx++)
        {
            // For reverse (descending), a later element cannot be greater than current
            if (nums[nextIdx] > nums[currentIdx])
                return false;
        }
    }
    return true;
}

/**
 * Optimal Approach
 * Time Complexity: O(N) - Single pass through the array.
 * Space Complexity: O(1)
 */
bool isSortedReverseOptimal(int nums[], int size)
{
    for (int i = 1; i < size; i++)
    {
        // Check if current element is greater than the previous one
        int currentElement = nums[i];
        int previousElement = nums[i - 1];

        if (currentElement > previousElement)
            return false;
    }
    return true;
}

int main()
{

    int arr[] = {5, 4, 3, 2, 1};
    // Calculate number of elements: Total size / size of one element
    int n = sizeof(arr) / sizeof(arr[0]);

    // Test Brute Force Method
    bool sortedByBruteForceMethod = isSortedReverseBruteForce(arr, n);
    if (sortedByBruteForceMethod)
        cout << "Array is sorted in reverse (Brute Force)" << endl;
    else
        cout << "Array is not Sorted in reverse" << endl;

    // Test Optimal Method
    bool sortedWithOptimalApproach = isSortedReverseOptimal(arr, n);
    if (sortedWithOptimalApproach)
        cout << "Array is sorted in reverse (Optimal)" << endl;
    else
        cout << "Array is not Sorted in reverse" << endl;
    return 0;
}