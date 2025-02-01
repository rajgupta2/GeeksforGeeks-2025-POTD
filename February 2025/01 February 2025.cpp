/*
Word Search
You are given a two-dimensional mat[][] of size n*m containing English alphabets and a string word. Check if the word exists on the mat. The word can be constructed by using letters from adjacent cells, either horizontally or vertically. The same cell cannot be used more than once.
*/
class Solution {
  public:
    bool isWordMatch(vector<vector<char>>& mat, string& word,int ind,char ch,int row,int col){

        if(row<0 || row>=mat.size() || col<0 || col>=mat[0].size()) return false;

        if(ind>=word.size()) return true;

        if(ind==word.size()-1 && word[ind]==mat[row][col]) return true;

        if(word[ind]==mat[row][col]){
            char ch=mat[row][col];
            mat[row][col]='-1';

            bool res= isWordMatch(mat,word,ind+1,word[ind+1],row,col+1) ||
            isWordMatch(mat,word,ind+1,word[ind+1],row+1,col) ||
            isWordMatch(mat,word,ind+1,word[ind+1],row-1,col) ||
            isWordMatch(mat,word,ind+1,word[ind+1],row,col-1);

            mat[row][col]=ch;
            return res;
        }
        return false;
    }

    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        char firstChar=word[0];
        int n=mat.size();
        int m=mat[0].size();
        if(word.size()>n*m) return false;
        vector<pair<int,int>> start;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==firstChar)
                 start.push_back({i,j});
            }
        }

        for(auto e:start){
            int row=e.first;
            int col=e.second;
            if(isWordMatch(mat,word,0,word[0],row,col))
            return true;
        }
        return false;
    }
};