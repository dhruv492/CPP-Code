#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

class WordFrequencyAnalyzer
{
private:
    map<string, int> wordFrequency;

public:
    void processText(const string& text)
    {
        stringstream ss(text);
        string word;

        while (ss >> word)
        {
            ++wordFrequency[word];
        }
    }

    void displayFrequency() const
    {
        for (const pair<const string, int>& entry : wordFrequency)
        {
            cout << entry.first << ": " << entry.second << endl;
        }
    }
};

int main()
{
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    WordFrequencyAnalyzer analyzer;
    analyzer.processText(text);
    analyzer.displayFrequency();

    return 0;
}
