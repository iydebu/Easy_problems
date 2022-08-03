#include <iostream>
#include <vector>
using namespace std;
int findMajorityElement(int arr[], int n)
{
    int count = 0;
    int maj_ele = 0;

    // finding the mejority element
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            maj_ele = arr[i];
            count++;
            continue;
        }
        if (arr[i] == maj_ele)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    // find the majority element frequency
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == maj_ele)
        {
            count++;
        }
    }
    // if the frequency is greater than n/2 then return the majority element return that element
    if (count > n / 2)
    {
        return maj_ele;
    }
    // otherwise return false
    else
    {
        return -1;
    }
}
int main()
{
    int t;
    cin >> t;
    vector<int> output;
    for (int k = 0; k < t; k++)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        output.push_back(findMajorityElement(arr, n));
        delete[] arr;
    }
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
}