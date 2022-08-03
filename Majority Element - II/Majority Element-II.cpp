#include <iostream>
#include <vector>
using namespace std;
vector<int> majorityElementII(vector<int> &arr)
{   
    // array for storing final answer
    vector<int> ans;
    int n = arr.size();
    // variables for storing the elements that occur more than n/3 times
    int first_candidate = 0, second_candidate = 0;
    // variables for storing frequency of candidates elements
    int first_count = 0, second_count = 0;

    // iterate through the array
    for(int i=0;i<n;i++){

        // Increment first_count if the current element is equal to firstCandidate
        if(arr[i]==first_candidate) first_count++;

        // Increment second_count if the current element is equal to secondCandidate
        else if(arr[i]==second_candidate) second_count++;
        
        //Changing value of first_candidate if first Count is zero
        else if(first_count==0){
            first_candidate = arr[i];
            first_count = 1;
            continue;
        }

        // Changing value of second_candidate if second Count is zero
        else if(second_count==0){
            second_candidate = arr[i];
            second_count = 1;
            continue;
        }

        // otherwise decrement first_count and second_count
        else{
            first_count--;
            second_count--;
        }
    }
    first_count = 0;
    second_count = 0;

    // verifying the frequency of candidates elements
    for(int i=0;i<n;i++){
        if(arr[i]==first_candidate) first_count++;
        else if(arr[i] == second_candidate) second_count++;
    }

    // checking the creteria for majority elements
    if(first_count>n/3) ans.push_back(first_candidate);
    if(second_count>n/3) ans.push_back(second_candidate);

    // return the final answer
    return ans;
}
int main()
{
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    vector<int> res = majorityElementII(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}