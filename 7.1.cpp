#include <iostream>
using namespace std;

class WordFrequency
{
    struct WordEntry
    {
        string word;
        int count;
    };

    WordEntry* words;
    int size;
    int capacity;

    void resize()
    {
        int new_capacity = capacity * 2;
        WordEntry* new_words = new WordEntry[new_capacity];

        for (int i = 0; i < size; ++i)
        {
            new_words[i] = words[i];
        }

        delete[] words;
        words = new_words;
        capacity = new_capacity;
    }

    string toLowercase(const string& str)
    {
        string lowerStr = str;
        for (char& ch : lowerStr)
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                ch += ('a' - 'A');
            }
        }
        return lowerStr;
    }

    public:
        WordFrequency(int cap = 10) : size(0), capacity(cap)
        {
            words = new WordEntry[capacity];
        }

        ~WordFrequency()
        {
            delete[] words;
        }

        void insertWord(const string& input_word)
        {
            string word = toLowercase(input_word);

            for (int i = 0; i < size; ++i)
            {
                if (words[i].word == word)
                {
                    words[i].count++;
                    return;
                }
            }

            if (size == capacity)
            {
                resize();
            }

            words[size].word = word;
            words[size].count = 1;
            size++;
        }

        void display() const
        {
            cout << "Word Frequency:\n";
            for (int i = 0; i < size; ++i)
            {
                cout << words[i].word << ": " << words[i].count << endl;
            }
        }
};

int main()
{
    WordFrequency wf;
    string paragraph;

    cout << "Enter paragraph: ";
    getline(cin, paragraph);

    string word;
    for (char ch : paragraph)
    {
        if (ch == ' ' || ch == ',' || ch == '.' || ch == '-')
        {
            if (!word.empty())
            {
                wf.insertWord(word);
                word.clear();
            }
        }
        else
        {
            word += ch;
        }
    }

    if (!word.empty())
    {
        wf.insertWord(word);
    }

    wf.display();

    return 0;
}
