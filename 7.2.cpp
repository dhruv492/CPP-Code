#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class FileAnalyzer
{
private:
    vector<string> lines;
    size_t total_chars;
    size_t total_words;
    size_t total_lines;

public:
    FileAnalyzer() : total_chars(0), total_words(0), total_lines(0) {}

    bool readFile(const string& filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cout << "Error: Cannot open file." << endl;
            return false;
        }

        string line;
        while (getline(file, line))
        {
            lines.push_back(line);
            total_chars += line.size() + 1;
            total_lines++;

            size_t pos = 0;
            while (pos < line.size())
            {
                while (pos < line.size() && isspace(line[pos])) pos++;
                if (pos < line.size())
                {
                    total_words++;
                    while (pos < line.size() && !isspace(line[pos])) pos++;
                }
            }
        }

        file.close();
        return true;
    }

    void displayStats() const
    {
        cout << "Lines: " << total_lines << endl;
        cout << "Words: " << total_words << endl;
        cout << "Characters: " << total_chars << endl;
    }
};

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Error: No file specified." << endl;
        return 1;
    }

    FileAnalyzer analyzer;
    if (analyzer.readFile(argv[1]))
    {
        analyzer.displayStats();
    }

    return 0;
}
