#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
         vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {

                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }
        return triangle;
    }

vector<vector<int>> generate(int numRows) {
         vector<vector<int>> triangle;
        for(int row = 1 ; row <=numRows ; row++) {
            vector<int> temp;
            long long ans2=1;
            temp.push_back(1);
            for(int col = 1; col <row ; col++){
                ans2=ans2 * (row-col);
                ans2=ans2 / col;
                temp.push_back(ans2); 
            }
            triangle.push_back(temp);

        }
        return triangle;
    }
    
    int main(){
        return 0;
    }