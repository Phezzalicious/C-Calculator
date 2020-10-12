#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Calculator.h"
using namespace std;

//global so it can be used in multiple functions
vector<string> myanswers;

//simply get the users name for the text file
void UserInfo()
{
    string name;
    cout << "Enter your Name: " << endl;
    cin >> name;
    myanswers.push_back(name);
}

//where I get the inputs for the global vector myanswers
void Run()
{
    //Grab the name
    UserInfo();
    Calculator Calc;

    //Short for do more calculations
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

        //Call the calculator methods based on user input
        switch (operation)
        {
        case '+':
            answer = Calc.Add(x, y);
            break;
        case '-':
            answer = Calc.Subtract(x, y);
            break;
        case '*':
            answer = Calc.Multiply(x, y);
            break;
        case '/':
            answer = Calc.Divide(x, y);
            break;
        default:
            break;
        }

        cout << x << " " << operation << " " << y << " is " << answer << endl;
        cout << "Would you like to do more math? y/n" << endl;
        cin >> cont;

        //build string for global vector myanswers
        string fullanswer = to_string(x).substr(0, to_string(x).find(".") + 3) + " " + operation + " " + to_string(y).substr(0, to_string(y).find(".") + 3) + " = " + to_string(answer).substr(0, to_string(answer).find(".") + 3);

        //add it to vector
        myanswers.push_back(fullanswer);

        if (cont != 'y')
        {
            doMore = false;
        }
    }
    // ****************Testing purposes*******************8
    // cout << "Calculations completed: " << endl;
    // for (int i = 0; i < myanswers.size(); i++)
    // {
    //     cout << myanswers[i] << endl;
    // }
}


void Save()
{
    // Create and open a text file -- append mode
    ofstream MyHistory("calculations.txt", ios_base::app);

    // Write to the file
    for (int i = 0; i < myanswers.size(); i++)
    {
        MyHistory << myanswers[i] << endl;
    }
    MyHistory << endl;

    // Close the file
    MyHistory.close();

    //clear the answers, it is a global variable
    myanswers.clear();
}

void Show()
{
    string myLine;

    // Read from the text file
    ifstream MyHistory("calculations.txt");

    //does it exist?
    if (MyHistory)
    {
        //iterate over whole file
        while (getline(MyHistory, myLine))
        {
            // Output the line from the file
            cout << myLine << endl;  
            
        } 
        // Close the file
        MyHistory.close();

    }else{//this is if the file doesnt exist
        cout << "No Data";
    }
    //formatting the console
    cout << endl;
}


void Menu()
{
    int choice = 0;
    while (choice < 3)
    {
        //"Home screen" of the application
        cout << "Enter a number: " << endl
             << "1. View saved Calculations" << endl
             << "2. Make new Calculations" << endl
             << "3. Exit" << endl;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        //Display text file
            Show();
            break;
        case 2:
        //Run calculator 
            Run();
        //Append text file
            Save();
            break;
        }
    }
}

int main()
{
    // COMMANDS TO RUN THE APP
    //   g++ -o Calc  MyFirstCalc.cpp Calculator.cpp
    //   ./Calc

    //This contains the main while loop, basically the whole app
    Menu();

    return 0;
}
