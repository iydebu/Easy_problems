
#include <iostream>
#include <vector>
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
	
    bool row=false,col=false;
    //searching for zero
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==0){
                //making the mark
                if(i==0) row = true;
                if(j==0) col = true;
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    //using the mark setting zero
    for(int i=1;i<matrix.size();i++){
        for(int j=1;j<matrix[i].size();j++){
        if(matrix[i][0]==0||matrix[0][j]==0) matrix[i][j] =0;
        }
    }
    // setting 0th row and col zero
    if(col)
        for(int i=0;i<matrix.size();i++) matrix[i][0] = 0;
    if(row)
        for(int i=0;i<matrix[0].size();i++) matrix[0][i] = 0;
   
}
int main(){
	int m,n;
	cin>>m>>n;
	vector<vector<int>> matrix(m,vector<int>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>matrix[i][j];
		}
	}
	setZeros(matrix);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}