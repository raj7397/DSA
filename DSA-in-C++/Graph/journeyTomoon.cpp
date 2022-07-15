#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */

void helper(vector<int> graph[], int u, vector<bool>&visited,int &asf, vector<int>&temp)
{
    visited[u] = true;
    temp.push_back(u);
    asf++;
    for(int i = 0; i < graph[u].size();i++)
    {
        int v = graph[u][i];
        if(!visited[v])
            helper(graph, v, visited, asf,temp);
    }
}
int journeyToMoon(int n, vector<vector<int>> astronaut) {
    long long ans = n * (n -1)/2;
    
    vector<int>graph[n];
    for(int i = 0; i < astronaut.size();i++)
    {
        int u = astronaut[i][0];
        int v = astronaut[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int>comp;
    
    vector<bool>visited(n,false);
    vector<vector<int>>allComp;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            vector<int>temp;
            int tempAns= 0;
            helper(graph, i,visited,tempAns,temp);
 //           allComp.push_back(temp);
            ans = ans - ((tempAns * (tempAns - 1))/2);
       //     comp.push_back(tempAns);
        }
            
    }
    for(int i = 0; i < allComp.size() - 1; i++)
    {
        for(int j = i + 1; j < allComp.size();j++)
        {
            int n1 = allComp[i].size();
            int n2 = allComp[j].size();
            ans = ans + n1*n2;
        }
    }
    cout<<"ans: "<<ans<<endl;
    return ans;
   /* for(int i = 0; i < comp.size() - 1;i++)
    {
        for(int j = i + 1; j < comp.size();j++)
        {
            ans+=comp[i]*comp[j];
        }
    }
    return ans;*/

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
