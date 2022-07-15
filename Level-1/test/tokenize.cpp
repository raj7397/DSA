#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    string line = "/a/./b/../../c/";
     
    // Vector of string to save tokens
    vector <char> tokens;
     
    // stringstream class check1
    stringstream check1(line);
     
    char intermediate;
     
    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, '/'))
    {
        tokens.push_back(intermediate);
    }
     
    // Printing the token vector
    for(int i = 0; i < tokens.size(); i++)
        cout << tokens[i] << '\n';
}