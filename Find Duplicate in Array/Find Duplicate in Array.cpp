#include <iostream>
#include <vector>
using namespace std;
int findDuplicate(vector<int> &arr, int n)
{
  // Write your code here.
  for (int i = 0; i < n; i++)
  {
    // getting the index
    int index = abs(arr[i]) - 1;
    if (arr[index] < 0) 
    {
      return index + 1; // returning the duplicate element
    }
    else
    {
      arr[index] = -arr[index]; // marking the elemnt -ve
    }
  }
}
int main()
{
  int t = 0;
  cin >> t;
  vector<int> output;
  for (int j = 1; j <= t; j++)
  {
    int size = 0;
    cin >> size;
    vector<int> arr;
    for (int i = 0; i < size; i++)
    {
      int num;
      cin >> num;
      arr.push_back(num);
    }
    output.push_back(findDuplicate(arr, size));
  }
  for (int i = 0; i < output.size(); i++)
  {
    cout << output[i] << endl;
  }
}