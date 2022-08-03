#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // sorting the algorith is O(nlog(n))
    sort(arr.begin(), arr.end());

    // creating the resultant vector
    vector<vector<int>> result;

    //using two pointers to traverse the array
    int l = 0;
    int r = arr.size() - 1;
    while (l < r)
    {
        // check if the sum is greater to the target sum,  yes make sum samller
        if (arr[l] + arr[r] > s)
            r--;

        // check if the sum is less to the target sum,  yes make sum greater
        else if (arr[l] + arr[r] < s)
            l++;\

        // if the sum is equal to the target sum,  add the pair to the result vector
        else if (arr[l] + arr[r] == s)
        {
            // check if the both pointer has same element, if yes, apply combination formula (n+1)n/2
            if (arr[l] == arr[r])
            {
                int count = (r - l + 1) * (r - l) / 2;
                while (count > 0)
                {
                    result.push_back({arr[l], arr[l]});
                    count--;
                }
                return result;
            }
            
            int count1 = 0;
            int count2 = 0;
            int prev = arr[l];
            // checking if the left pointer is repeating , if yes count nuumber of repetitions
            while (arr[l] == prev)
            {
                l++;
                count1++;
            }
            prev = arr[r];
            // checking if the right pointer is repeating , if yes count nuumber of repetitions
            while (arr[r] == prev)
            {
                r--;
                count2++;
            }
            // counting number of combinatinos by multiplying the counts
            int count = count1 * count2;

            // adding the repeated pairs to the result vector
            while (count > 0)
            {
                result.push_back({arr[l - count1], arr[r + count2]});
                count--;
            }
        }
    }
    // returning the result vector
    return result;
}
int main()
{
    int size = 0;
    cin >> size;
    int s = 0;
    cin >> s;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> result = pairSum(arr, s);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}