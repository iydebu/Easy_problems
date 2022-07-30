#include <iostream>
#include <vector>
using namespace std;
vector<vector<long long int>> printPascal(int n)
{
  // creating the vector array
  vector<vector<long long int>> pascal;
  for (int i = 0; i <= n; i++)
  {
    vector<long long int> row;
    for (int j = 0; j < i; j++)
    {
      if (j == 0 || j == i - 1)
      { // if it is the first or last element
        row.push_back(1);
        row.push_back(1);
      }
      else
      {
        // adding two  previous elements
        row.push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
      }
    }
    // adding the row to the pascal array
    pascal.push_back(row);
  }
  // returning the jagged array
  return pascal;
}
int main()
{
  int n;
  cin >> n;
  vector<vector<long long int>> pascal = printPascal(n);
  for (int i = 0; i < pascal.size(); i++)
  {
    for (int j = 0; j < pascal[i].size(); j++)
    {
      cout << pascal[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}