#include <iostream>
#include <limits>
using namespace std;

// F1 take answer for [Y/N] questions;
bool yesOrNo()
{
    string yn;
    do
    {
        cin >> yn;
        if (yn == "y" || yn == "Y")
            return true;
        else if (yn == "n" || yn == "N")
            return false;
        else
        {
            cout << "you entered a wrong value ---- Try Again [Y/N]: ";
            continue;
        }

    } while (true);
}

// F2 Draw line function
void DrawLine(int Width)
{
    string line;
    for (int i = 0; i < Width; i++)
    {
        line += "-";
    }

    cout << endl
         << line << endl
         << endl;
}

// F3 taking string inputs with avoiding the space problem
string GetStringInput()
{
    string in;

    // Clear any previous errors , inputs and newline characters from the buffer
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Get input using getline
    getline(cin, in);
    return in;
}

// F4 clearing console easily.
void clearConsole()
{
    system("cls");
}

int main()
{

    // function 1.
    cout << "Do you want to test Yes or No Function [Y/N]: ";
    bool yes = yesOrNo();
    if (yes)
    {
        cout << "you prefer yes";
    }
    else
    {
        cout << "you prefer No.";
    }

    cout << endl
         << endl;

    //================================================================================================

    // function 2.
    cout << "enter the line width you want :";
    int lineWidth;
    cin >> lineWidth;
    DrawLine(lineWidth);

    cout << "You draw a line with " << lineWidth << " of width." << endl
         << endl;

    //================================================================================================

    // function 3.
    string fullname;
    cout << "Enter the full name : ";
    cin >> fullname;
    cout << "full name taken only until is finds space :  " + fullname << endl
         << endl;
    cout << "to avoid this problem we can use our custom \"GetString()\" input Function";
    cout << endl
         << endl
         << "Enter the  Full Name Again : ";

    string fullNameWithSpaces;
    fullNameWithSpaces = GetStringInput();
    cout << endl
         << "Now Full Name Taken Correctly : " << fullNameWithSpaces;

    cout << endl
         << endl;
    //================================================================================================

    // function 4.
    cout << "Do you Want to Clear Console [Y/N]: ";
    if (yesOrNo())
    {
        clearConsole();
    }
    else
    {
        cout << "you prefer not to clear console";
    }
    cout << "\n\n console cleared";

    GetStringInput();
    return 0;
}