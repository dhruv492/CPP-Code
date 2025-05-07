#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string text;
    getline(cin, text);

    map<string, int> wordFrequency;
    stringstream ss(text);
    string word;

    while (ss >> word)
    {
        ++wordFrequency[word];
    }

    for (const pair<const string, int>& entry : wordFrequency)
    {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
