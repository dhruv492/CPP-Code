#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Error: No file specified." << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if (!file)
    {
        cout << "Error: Cannot open file." << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    size_t total_chars = 0, total_words = 0, total_lines = 0;

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

    cout << "Lines: " << total_lines << endl;
    cout << "Words: " << total_words << endl;
    cout << "Characters: " << total_chars << endl;

    return 0;
}

