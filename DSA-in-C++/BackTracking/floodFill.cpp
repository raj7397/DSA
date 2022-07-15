#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& arr, int sr, int sc, vector<vector<bool>> &visited);
void flood_fill_path(vector<vector<int>> &arr, int sr, int sc, int dr, int dc, string asf, vector<vector<bool>>visited,vector<vector<int>> &dir,vector<string> &dirName);

int main(int argc, char ** argv)
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i =0 ; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    vector<vector<int>>dir{{-1,0},{0,-1},{1,0},{0,1}};
    vector<string>dirName{"t", "l","d","r"};

    flood_fill_path(arr,0,0, n-1, m-1, "", visited,dir,dirName);
}
void flood_fill_path(vector<vector<int>> &arr, int sr, int sc, int dr, int dc, string asf, vector<vector<bool>>visited,vector<vector<int>> &dir,vector<string> &dirName)
{

    if(sr == dr && sc == dc)
    {
        cout<<asf<<endl;
        return;
    }

    visited[sr][sc] = true;
    for(int i = 0; i < dir.size(); i++)
    {
        int x = sr +dir[i][0];
        int y = sc + dir[i][1];
        if(isSafe(arr,x,y,visited))
            flood_fill_path(arr,x,y,dr,dc,asf+dirName[i],visited,dir,dirName);
    }
    visited[sr][sc] = false;
}
bool isSafe(vector<vector<int>>& arr, int sr, int sc, vector<vector<bool>> &visited)
{
    int n = arr.size();
    int m = arr[0].size();
    if(sr <0 || sr >= n || sc < 0 || sc >= m || arr[sr][sc] == 1 || visited[sr][sc])
        return false;
    return true;
}