#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream ifs(argv[1]);
    // ifstream ifs("./input_1.txt");
    if (ifs.fail())
    {
        cout << "File open failed.\n";
        exit(1);
    }

    int num_students, num_class;
    ifs >> num_students >> num_class;

    map<string, vector<string>> studentmap;

    for (int i = 0; i < num_class; ++i)
    {
        string temp;
        ifs >> temp;
        studentmap[temp] = vector<string>();
    }

    for (int i = 0; i < num_students; ++i)
    {
        int num;
        string name;
        ifs >> name >> num;
        for (int i = 0; i < num; ++i)
        {
            string temp;
            ifs >> temp;
            studentmap[temp].push_back(name);
        }
    }

    ofstream ofs(argv[2]);
    // ofstream ofs("./test.txt");

    for (const auto &n : studentmap)
    {

        ofs << "Class : " << n.first << endl;
        ofs << "\t";
        for (int i = 0; i < n.second.size(); ++i)
        {
            ofs << n.second[i] << " ";
        }
        ofs << endl;
    }
}
