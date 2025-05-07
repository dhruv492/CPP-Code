#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Directory
{
    map<string, vector<string>> folderMap;

public:
    void createFolder(const string& folderName)
    {
        if (folderMap.find(folderName) == folderMap.end())
        {
            folderMap[folderName] = vector<string>();
            cout << "Folder '" << folderName << "' created." << endl;
        }
        else
        {
            cout << "Folder '" << folderName << "' already exists." << endl;
        }
    }

    void addFileToFolder(const string& folderName, const string& fileName)
    {
        if (folderMap.find(folderName) != folderMap.end())
        {
            folderMap[folderName].push_back(fileName);
            cout << "File '" << fileName << "' added to folder '" << folderName << "'." << endl;
        }
        else
        {
            cout << "Folder '" << folderName << "' does not exist." << endl;
        }
    }

    void displayDirectory()
    {
        if (folderMap.empty())
        {
            cout << "No folders available." << endl;
            return;
        }

        cout << "Directory Structure:" << endl;

        for (const auto& folder : folderMap)
        {
            cout << "Folder: " << folder.first << endl;
            cout << "Files: ";
            for (const auto& file : folder.second)
            {
                cout << file << " ";
            }
            cout << endl;
        }

    }
};

int main()
{
    Directory dir;

    dir.createFolder("Documents");
    dir.createFolder("Images");
    dir.createFolder("Music");

    dir.addFileToFolder("Documents", "Resume.pdf");
    dir.addFileToFolder("Documents", "Project.docx");
    dir.addFileToFolder("Images", "Vacation.jpg");
    dir.addFileToFolder("Music", "Song.mp3");

    dir.displayDirectory();

    return 0;
}
