#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Student {
private:

    int numStudents, numClasses;
    string input_file, output_file;
    map<string, vector<string>> studentMap;

public:

    Student(const string& _input_file, const string& _output_file) : 
        input_file(_input_file), output_file(_output_file) {}
    void readStudentsInfo(); 
    void writeStudentsInfo();

};


void Student::readStudentsInfo() {

    ifstream file(input_file);

    if (!file.is_open()) {
        cerr << "Error opening file " << input_file << endl;
        return ;
    }

    file >> numStudents >> numClasses;

    for (int i = 0; i < numClasses; ++i) {
        string subject ;
        file >> subject ;
        studentMap[subject] = vector<string>();
    }

    file.ignore(); 

    for (int i = 0; i < numStudents; ++i) {
        string name;
        int numEnrolled;
        file >> name >> numEnrolled;
        
        for (int j = 0; j < numEnrolled; ++j) {
            string course;
            file >> course;
            studentMap[course].push_back(name);
        }
        
    }
    file.close();
}

void Student::writeStudentsInfo() {

    ofstream file(output_file);
    if (!file.is_open()) {
        cerr << "Error opening file " << output_file << endl;
        return;
    }

    for (const auto& entry : studentMap) {
        const string& subject = entry.first;
        const vector<string>& students = entry.second;
        file << "Class : " << subject << endl;
        file << "   ";
        for (const auto& student : students) {
            file << student << " ";
        }
        file << endl;
    }

    file.close();
}

int main(int argc, char *argv[]) {

    string input_file = argv[1];
    string output_file = argv[2];

    Student Student_List(input_file, output_file);
    Student_List.readStudentsInfo();
    Student_List.writeStudentsInfo();

    return 0;

}