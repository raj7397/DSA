#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve_maze_with_jumps_top_down();
vector<string> maze_with_jumps_top_down(int ,int ,int, int);
int main(int argc, char **argv)
{
    solve_maze_with_jumps_top_down();
}
void solve_maze_with_jumps_top_down()
{
    int n,m;
    cin>>n>>m;
    vector<string> ans = maze_with_jumps_top_down(0, 0, n-1,m-1);
    cout<<"Printing ans; "<<endl;
    for(int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
}
vector<string> maze_with_jumps_top_down(int sr, int sc ,int dr, int dc)
{
    if(sr == dr && sc == dc)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> myAns;
    for(int jmp = 1; sc+jmp <= dc; jmp++)
    {
        vector<string> recAns = maze_with_jumps_top_down(sr, sc+jmp, dr,dc);
        for(auto x : recAns)
        {
            myAns.push_back("h"+to_string(jmp)+x);
        }
    }
    for(int jmp = 1; sr+jmp <= dr; jmp++)
    {
        vector<string> recAns = maze_with_jumps_top_down(sr+jmp, sc, dr,dc);
        for(auto x : recAns)
        {
            myAns.push_back("v"+to_string(jmp)+x);
        }
    }
    for(int jmp = 1; sr+jmp <= dr && sc+jmp <= dc; jmp++)
    {
        vector<string> recAns = maze_with_jumps_top_down(sr+jmp, sc+jmp, dr,dc);
        for(auto x : recAns)
        {
            myAns.push_back("d"+to_string(jmp)+x);
        }
    }
    return myAns;
}