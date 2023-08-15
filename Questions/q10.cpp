// COMMON ARRAY OPERATIONS I.E INSERTION , DELETION , SEARCHING , TRAVERSAL

// INSERTION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int arr[] = {2, 3, 5, 6};
//     int size = 4;
//     int newValue = 4;
//     int insertIndex = 2;
//     cout << "original array :" << endl;
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     // shifting elements to the right
//     for (int i = size; i > insertIndex; --i)
//     {
//         arr[i] = arr[i - 1];
//     }
//     // insert the new value
//     arr[insertIndex] = newValue;
//     size++;
//     cout << "modified array is : ";
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// DELETION , TRAVERSAL , SEARCHING

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10] = {1, 2, 3, 4, 5}; // Original array
    int size = 5;                  // Current size of the array

    // Deletion
    int deleteIndex = 2; // Index of the element to be deleted

    // Shift the elements to the left
    for (int i = deleteIndex; i < size - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }
    size--;

    // Display the array after deletion
    cout << "Array after deletion: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Traversal
    cout << "Array traversal: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Searching
    int target = 4; // Element to be searched
    int index = -1; // Index of the element if found

    // Linear search to find the element
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == target)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        cout << "Element found at index " << index << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}
