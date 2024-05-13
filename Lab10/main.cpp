#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class employee
{
    /* data */
public:
    employee(string name, double years) : name{name}, years{years} {};
    // ~employee();
    string name;
    double years;
    int BSE = 20000;
};

class parttimer : public employee
{
    /* data */
public:
    parttimer(string name, double years) : employee{name, years} {};
    double psalary = BSE + 1000 * years;
};

class manager : public employee
{
    /* data */
public:
    manager(string name, double years) : employee{name, years} {};
    double msalary = BSE + 15000 + 5000 * years;
};

class chairman : public manager
{
    /* data */
public:
    chairman(string name, double years) : manager{name, years} {};
    double csalary = msalary + 50000;
};

int main()
{
    ifstream ifs("input.txt");

    if (ifs.fail())
    {
        cout << "Fail to open file" << endl;
        exit(1);
    }

    map<double, vector<string>> people_map;

    int num_people;
    ifs >> num_people;

    ofstream ofs("output.txt");

    while (num_people > 0)
    {
        string name, kind;
        double years, money;
        ifs >> name >> kind >> years;

        if (kind == "C")
        {
            chairman c(name, years);
            money = c.csalary;
            people_map[money] = vector<string>{name, to_string(years)};
        }
        if (kind == "M")
        {
            manager m(name, years);
            money = m.msalary;
            people_map[money] = vector<string>{name, to_string(years)};
        }
        if (kind == "P")
        {
            parttimer p(name, years);
            money = p.psalary;
            people_map[money] = vector<string>{name, to_string(years)};
        }

        num_people -= 1;
    }

    // for (const auto &n : people_map){
    //     ofs << n.second[0] << " " << stod(n.second[1]) << " " << n.first << endl;
    // }

    for (auto it = people_map.rbegin(); it != people_map.rend(); ++it)
    {
        ofs << it->second[0] << " " << stod(it->second[1]) << " " << it->first << endl;
    }

    // or we can store the address of employee and then sort with the address points to value
    return 0;
}