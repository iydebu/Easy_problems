#include <iostream>
using namespace std;
void sort012(int *arr, int n)
{
  int count0 = 0, count1 = 0, count2 = 0;
  // counting the frequency of 0, 1, 2
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0)
      count0++;
    else if (arr[i] == 1)
      count1++;
    else
      count2++;
  }
  // filling the array with 0, 1, 2
  for (int i = 0; i < count0; i++)
    arr[i] = 0;
  for (int i = 0; i < count1; i++)
    arr[count0 + i] = 1;
  for (int i = 0; i < count2; i++)
    arr[count0 + count1 + i] = 2;
}

int main()
{
  int size = 0;
  cin >> size;
  int *arr = new int[size];
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  sort012(arr, size);
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  delete[] arr;
}