#include <iostream>
#include <vector>

using namespace std;
bool isSafe(int r,int c, vector<string>&grid,int sr,int sc,char ch)
{
    int n = grid.size();
    int m = grid[0].size();
    if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] != ch)
        return false;
    return true;
}
bool helper(vector<string>&grid,int sr,int sc, int p1,int p2,vector<vector<int>>&dir,int &idx, string &key)
{
    if(idx == key.size() )
    {
 //       visited[sr][sc] = true;
        return true;
    }
       // return true;
   // visited[sr][sc] = true;
    for(int i = 0; i < dir.size();i++)
    {
        int x = sr + dir[i][0];
        int y = sc + dir[i][1];
        if(isSafe(x,y,grid,p1,p2,key[idx]))
        {
            cout<<"sr: "<<sr<<" sc: "<<sc<<" x: "<<x<<" y: "<<y<<" curr idx: "<<idx<<endl;
            idx++;
            bool ra = helper(grid,x,y,sr,sc,dir,idx,key);
            if(ra)
                return true;
            idx--;
        }
    }
    return false;
}

int exist(vector<string> &A, string B) {
    
    
    int n = A.size();
    int m = A[0].size();
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    vector<vector<int>>dir = {{-1,0},{0,1},{1,0},{0,-1}};
    int idx = 1;
    for(int i = 0; i < A.size();i++)
    {
        for(int j = 0; j < A[0].size();j++)
        {
            if(A[i][j] == B[0])
            {
                idx = 1;
                bool isFound = helper(A,i,j,-1,-1,dir,idx,B);
                if(isFound)
                {
                    cout<<"i: "<<i<<" j: "<<j<<endl;
                    return true;
                }
                    //return true;
            }
        }
    }
    return false;
    
}


int main()
{
    vector<string> A ={"FCDFFD", "DEGEBA", "FEDCGD", "DFCECC", "EEAFCF", "EEBGAE", "AAGCAE", "BGCBFC"};
    cout<<"ans: "<<exist(A,"CDCDEDD")<<endl;
    vector<string> B = {"FEDCBECD", "FABBGACG", "CDEDGAEC", "BFFEGGBA", "FCEEAFDA", "AGFADEAC", "ADGDCBAA", "EAABDDFF"};
    cout<<"ans2: "<<exist(B,"BCDCB")<<endl;
}
