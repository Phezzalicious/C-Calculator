#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Calculator.h"
using namespace std;

vector<string> myanswers;

void UserInfo()
{
    string name;
    cout << "Enter your Name: " << endl;
    cin >> name;
    myanswers.push_back(name);
}
void Run()
{
    UserInfo();
    Calculator Calc;
    bool doMore = true;

    while (doMore)
    {
        float x, y;
        float answer;
        char operation, cont;

        cout << "Type a number: ";
        cin >> x;
        cout << "Type an operation (+,-,*,/) ";
        cin >> operation;
        cout << "Type another number: ";
        cin >> y;

        switch (operation)
        {
        case '+':
            // code block
            answer = Calc.Add(x, y);
            break;
        case '-':
            // code block
            answer = Calc.Subtract(x, y);
            break;
        case '*':
            // code block
            answer = Calc.Multiply(x, y);
            break;
        case '/':
            // code block
            answer = Calc.Divide(x, y);
            break;
        default:
            // code block
            break;
        }

        cout << x << " " << operation << " " << y << " is " << answer << endl;
        cout << "Would you like to do more math? y/n" << endl;
        cin >> cont;

        string fullanswer = to_string(x).substr(0, to_string(x).find(".") + 3) + " " + operation + " " + to_string(y).substr(0, to_string(y).find(".") + 3) + " = " + to_string(answer).substr(0, to_string(answer).find(".") + 3);

        myanswers.push_back(fullanswer);

        if (cont != 'y')
        {
            doMore = false;
        }
    }
    cout << "Calculations completed: " << endl;
    for (int i = 0; i < myanswers.size(); i++)
    {
        cout << myanswers[i] << endl;
    }
}
void Save()
{
    // Create and open a text file
    ofstream MyHistory("calculations.txt", ios_base::app);

    // Write to the file
    for (int i = 0; i < myanswers.size(); i++)
    {
        MyHistory << myanswers[i] << endl;
    }
    MyHistory << endl;
    // Close the file
    MyHistory.close();
    myanswers.clear();
}

void Show()
{
    string myLine;

    // Read from the text file
    ifstream MyHistory("calculations.txt");

    if (MyHistory)
    {
        while (getline(MyHistory, myLine))
        {
            // Output the text from the file
            cout << myLine << endl;
            // Close the file
            
        }
        MyHistory.close();

    }
    cout << endl;
}
void Menu()
{
    int choice = 0;
    while (choice < 3)
    {
        cout << "Enter a number: " << endl
             << "1. View saved Calculations" << endl
             << "2. Make new Calculations" << endl
             << "3. Exit" << endl;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            Show();
            break;
        case 2:
            Run();
            Save();
            break;
        }
    }
}

int main()
{
    // IN TERMINAL
    //   g++ -o Calc  MyFirstCalc.cpp Calculator.cpp
    //   ./Calc
    Menu();

    return 0;
}
