#include <iostream>
#include <string>
#include <vector>

using namespace std;
void display(vector<vector<int>> & arr);
bool isSafe(vector<vector<int>> &chess, int r, int c);
void print_walk(vector<vector<int>> & chess, int r, int c, int move,vector<vector<int>> &dir);
int main(int argc, char **argv)
{
    int n;
    cin>>n;
    int r,c;
    cin>>r>>c;
    vector<vector<int>>chess(n,vector<int>(n));
    vector<vector<int>>dir{{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    print_walk(chess, r,c,1,dir);
}
bool isSafe(vector<vector<int>> &chess, int r, int c)
{
    int n = chess.size();
    if(r >=0 && r <n && c >=0 && c <n && chess[r][c] == 0)
        return true;
    return false;
}
void display(vector<vector<int>> & arr)
{
    int n = arr.size();
    int m = arr[0].size();
    for(int i = 0; i < n; i++)
    {
        for(int j =0; j < m; j++)
        {
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void print_walk(vector<vector<int>> & chess, int r, int c, int move,vector<vector<int>> &dir)
{
    if(move == chess.size() * chess.size())
    {
        chess[r][c] = move;
        display(chess);
        chess[r][c] = 0;
    }


    chess[r][c] = move;
    for(int i = 0 ; i < 8 ;i++)
    {
        int x = r + dir[i][0];
        int y = c + dir[i][1];
        if(isSafe(chess,x,y))
        {
            print_walk(chess,x,y,move + 1, dir);
        }
    }
    chess[r][c] = 0;
}