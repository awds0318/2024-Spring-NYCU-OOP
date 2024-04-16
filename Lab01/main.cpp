#include <iostream>
using namespace std;

int main()
{
    int num_people{0}, num_adult{0};
    int age;
    double total_age{0};

    string insert;

    while (true)
    {
        cout << "Key in Y to insert more personal information or N to exit : ";
        cin >> insert;
        if (insert == "Y")
        {
            cout << "Key in the age of the person: ";
            cin >> age;
            if (age < 0)
                cout << "You keyed in a negative number. please key in again." << endl;
            else
            {
                total_age += age;
                num_people += 1;
                if (age > 18)
                    num_adult += 1;
            }
            continue;
        }
        else if (insert == "N")
        {
            cout << "Exit from inserting personal information." << endl;
            cout << "The number of people is " << num_people << endl;
            if (num_people == 0)
                cout << "The mean value of their age is 0" << endl;
            else
                cout << "The mean value of their age is " << total_age / (num_people * 1.0) << endl;
            cout << "The number of adult is " << num_adult << endl;
            break;
        }
    };

    return 0;
}