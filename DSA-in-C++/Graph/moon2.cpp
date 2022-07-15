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

int find(int x, vector<int>&parent)
{
    if(parent[x] == x)
        return x;
    int pox = parent[x];
    int ra = find(pox, parent);
    parent[x] = ra;
    return ra;
}
void unionBySize(int s1, int s2,vector<int>&parent,vector<int>&size)
{
    if(size[s1] > size[s2])
    {
        parent[s2] = s1;
        size[s1]+=size[s2];
    }
    else
    {
        parent[s1] = s2;
        size[s2]+=size[s1];
    }

}
long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<int>parent(n);
    vector<int>size(n);
    for(int i = 0;i < n;i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
    for(int i = 0; i < astronaut.size();i++)
    {
        int u = astronaut[i][0];
        int v = astronaut[i][1];
        int uLeader = find(u,parent);
        int vLeader = find(v, parent);
        if(uLeader != vLeader)
        {
            unionBySize(uLeader, vLeader, parent,size);
        }
    }
    vector<int>comp;
    for(int i = 0; i < parent.size();i++)
    {
        if(parent[i] == i)
        {
            comp.push_back(size[i]);
        }
    }
    cout<<"comp size: "<<comp.size()<<endl;
    cout<<"n: "<<n<<endl;
    long long int total = (n * (n - 1))/2;
    cout<<"total: "<<total<<endl;
    long long int temp = 0;
    long long int sameWays = 0;
    for(int i = 0; i< comp.size();i++)
    {
        temp=(comp[i]*(comp[i] - 1))/2;
    //    cout<<"temp: "<<temp<<endl;
        sameWays+=temp;
    }
    cout<<"sameWays: "<<sameWays<<endl;
    long long int ans = total - sameWays;
    cout<<"ans: "<<ans<<endl;
    return ans;

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

    long long result = journeyToMoon(n, astronaut);

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
