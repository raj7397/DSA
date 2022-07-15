#include <iostream>
#include <string>
#include <vector>

using namespace std;
static int no_of_sol = 0;
void solve_nqueen();
void nqueen(vector<vector<int>>&chess, int row);
bool is_safe(vector<vector<int>>& chess, int row, int col);
void print_sol(vector<vector<int>> &);
void solve_knight_walk();
bool knight_walk(vector<vector<int>>&, int , int, int, vector<int>&,vector<int> &);
bool is_safe_kwalk(vector<vector<int>> & walk,int r, int c);

int main(int argc, char **argv)
{
 //   solve_nqueen();
    solve_knight_walk();
}
bool is_safe_kwalk(vector<vector<int>> & walk,int r, int c)
{
    if(r < 0 || r >= walk.size() || c < 0 || c >= walk.size() || walk[r][c] != 0)
        return false;
    return true;
}
void solve_knight_walk()
{
    int n;
    cin>>n;
    int x,y;
    cin>>x>>y;
    vector<vector<int>>kwalk(n,vector<int>(n,0));
    vector<int>xcod {-2,-1,1,2,2,1,-1,-2};
    vector<int> ycod{1, 2, 2, 1, -1, -2,-2,-1};
    knight_walk(kwalk, x, y,1, xcod, ycod);
}
bool knight_walk(vector<vector<int>>& walk, int x, int y, int move,vector<int> &xcod, vector<int> & ycod)
{
    //For one solutions
  if(move == walk.size() * walk.size())
    {
        walk[x][y] = move;
        print_sol(walk);
        walk[x][y] = 0;
        return true;;
    }

    walk[x][y] = move;
    for(int i = 0 ; i < 8; i++)
    {
        int r = x + xcod[i];
        int c = y + ycod[i];
        if(is_safe_kwalk(walk,r,c))
        {
            if(knight_walk(walk, r, c, move + 1, xcod,ycod))    
                return true;
        }
    }
    walk[x][y] = 0;
    return false;

    // For all solutions
 /*   if(move == walk.size() * walk.size())
    {
        walk[x][y] = move;
        print_sol(walk);
        walk[x][y] = 0;
        return;
    }

    walk[x][y] = move;
    for(int i = 0 ; i < 8; i++)
    {
        int r = x + xcod[i];
        int c = y + ycod[i];
        if(is_safe_kwalk(walk,r,c))
        {
            knight_walk(walk, r, c, move + 1, xcod,ycod);
        }
    }
    walk[x][y] = 0;*/

}

void solve_nqueen()
{
    int n;
    cin>>n;
    vector<vector<int>> chess(n,vector<int>(n,0));
    nqueen(chess, 0);
    cout<<"# of sol for "<<n<<" "<<no_of_sol<<endl;

}
bool is_safe(vector<vector<int>> & chess, int row, int col)
{
    for(int i = row - 1; i >= 0; i--)
    {
        
        if(chess[i][col])
            return false;
    }
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--,j--)
    {
        if(chess[i][j])
            return false;
    }
    for(int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--,j++)
    {
        if(chess[i][j])
            return false;
    }
    return true;
        
}
void print_sol(vector<vector<int>> & chess)
{
    for(int i = 0; i < chess.size(); i++)
    {
        for(int j = 0; j < chess[0].size(); j++)
        {
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void nqueen(vector<vector<int>> &chess ,int row)
{
    if(row == chess.size())
    {
        print_sol(chess);
        no_of_sol++;
        return;
    }

 for(int c = 0 ; c < chess.size(); c++)
 {
     if(is_safe(chess,row,c))
     {
         chess[row][c] = 1;
         nqueen(chess, row + 1);
         chess[row][c] = 0;
     }
 }   
}