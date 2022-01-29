#include <iostream>

using namespace std;

int search(int arr[], int size, int target)
{
      for (int i = 0; i < size; i++)
      {
            if (arr[i] == target)
            {
                  return i;
            }
      }
      return -1;
}

int main()
{
      int arr[] = {12, 52, 69, 78, 23, 5, 6, 8, 4, 64};
      int r = search(arr, 10, 61);
      if (r == -1)
      {
            cout << "Element is not present in array";
      }
      else
      {
            cout << "Element is present at index " << r;
      }
      return 0;
}