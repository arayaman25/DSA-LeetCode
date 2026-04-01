#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool search(vector<vector<char>>& board, int r,int c,string word,int ind){
        if(ind==word.size()) return true; //base case
        
        int rows=board.size();
        int cols=board[0].size();
        if(r>=rows || c>=cols || r<0 || c<0) return false; //out of bound cases

        if(board[r][c] == ' ' || board[r][c]!=word[ind]) return false; //invalid cases

        char temp=board[r][c];
        board[r][c]=' '; //mark as visited

        if(search(board,r+1,c,word,ind+1) || 
            search(board,r,c+1,word,ind+1) ||
            search(board,r-1,c,word,ind+1) ||
            search(board,r,c-1,word,ind+1)){
                return true;
            }
        board[r][c]=temp; //back track
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        for( int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(board[r][c]==word[0]){
                    if(search(board,r,c,word,0)) return true;
                }
            }
        }
        return false;
    }
};