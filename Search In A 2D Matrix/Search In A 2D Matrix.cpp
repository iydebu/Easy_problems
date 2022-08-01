#include <iostream>
#include <vector>
using namespace std;

bool findTargetInMatrix(vector<vector<int>> &mat, int m, int n, int target)
{
  // Write your code here.
  int i = 0, j = n - 1;
  while (i < m && j >= 0)
  {
    // found the elemnt
    if (mat[i][j] == target)
      return true;
    // finding the column which contain the target
    else if (mat[i][j] > target)
      j--;
    // Finding the row which contain the target
    else
      i++;
  }
  return false;
}
int main()
{
  int t = 0;
  cin >> t;
  vector<bool> output;
  for (int i = 0; i < t; i++)
  {
    int m, n, target;
    cin >> m >> n >> target;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> mat[i][j];
      }
    }
    output.push_back(findTargetInMatrix(mat, m, n, target));
  }
  for (int i = 0; i < t; i++)
  {
    if (output[i])
      cout << "True" << endl;
    else
      cout << "False" << endl;
  }
}