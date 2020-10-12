#include <iostream>
#include <vector>
#include <string>
#include "Calculator.h"
using namespace std;

vector<string> myanswers;

void Run()
{
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
            answer = Calc.Add(x,y);
            break;
        case '-':
            // code block
            answer = Calc.Subtract(x,y);
            break;
        case '*':
            // code block
            answer = Calc.Multiply(x,y);
            break;
        case '/':
            // code block
            answer = Calc.Divide(x,y);
            break;
        default:
            // code block
            break;
        }

        cout << x << " " << operation << " " << y << " is " << answer << endl;
        cout << "Would you like to do more math? y/n" << endl;
        cin >> cont;

        string fullanswer = to_string(x).substr(0, to_string(x).find(".")+3) + " " + operation + " " + to_string(y).substr(0, to_string(y).find(".")+3) + " = " + to_string(answer).substr(0, to_string(answer).find(".")+3);

        myanswers.push_back(fullanswer);

        if (cont != 'y')
        {
            doMore = false;
        }
    }
}
void Show()
{
    cout << "Calculations completed: " << endl;
    for (int i = 0; i < myanswers.size(); i++)
    {
        cout << myanswers[i] << endl;
    }
}
int main()
{
    // IN TERMINAL
    //   g++ -o Calc  MyFirstCalc.cpp Calculator.cpp
    //   ./Calc

    Run();
    Show();
    return 0;
}
