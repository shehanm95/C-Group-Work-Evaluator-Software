#include <iostream>
#include <limits>
#include <windows.h>
#include <vector>
#include <fstream>

using namespace std;

//=================================================================

string GetStringInput()
{
    string in;

    // Check if there are errors in the input buffer
    if (cin.fail() || cin.peek() == '\n')
    {
        // Clear any previous errors and newline characters from the buffer
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Get input using getline
    getline(cin, in);

    // Replace commas with "and"

    return in;
}

//=================================================================

// this create the title of the requested page.
void CreateTitle(string TitleText)
{
    string spaces;
    int howmanySpacesWant;
    TitleText = "- - - - -   " + TitleText + "   - - - - -";

    string equals = "===============================================================================================";
    howmanySpacesWant = equals.length() - TitleText.length();
    for (int i = 0; i < howmanySpacesWant / 2; i++)
    {
        spaces += " ";
    }
    string finalString = equals + "\n" + spaces + TitleText + "\n" + equals + "\n\n";

    cout << finalString;
}

// taking only if it is a numeric input
int getNumericInput()
{

    int userInput;
    do
    {
        cin >> userInput;
        if (cin.fail())
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "\nInvalid input. Please enter a numeric value :";
        }
        else
        {
            // Input is valid, break out of the loop
            return userInput;
            break;
        }
    } while (true);
}

// This creates a red green color Text;
void GetGreenText(const string &text)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

    cout << text;

    // Reset to default color
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

// read a file and returns it values as vector;
vector<string> readFileValues(const string &filename)
{
    vector<string> values;

    // Open the file
    ifstream inputFile(filename);

    // Check if the file is open
    if (!inputFile.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return values; // Return an empty vector in case of an error
    }

    string value;

    // Read values from the file and store them in the vector
    while (getline(inputFile, value))
    {
        values.push_back(value);
    }

    // Close the file
    inputFile.close();

    return values;
}

int main()
{

    // f1
    CreateTitle("Runamga Nirmal");
    cout << "Enter the Title you Want to create : ";
    string title = GetStringInput();
    cout << endl;
    CreateTitle(title);
    cout << endl;
    //=============================================================

    // f2
    cout << "Enter A numertc Input : ";
    int num = getNumericInput();
    cout << "you entered the Numeric input : " << num << endl
         << endl;

    //=============================================================

    // f3

    cout << "Enter the text you want in green :";
    string text = GetStringInput();
    GetGreenText(text);

    cout << endl
         << endl;

    //=============================================================

    // f4
    cout << "we are going to read a file ";
    vector<string> fileValues = readFileValues("nirmal.txt");
    cout << endl;
    for (string word : fileValues)
    {
        cout << word << endl;
    }

    //==============================================================
    GetStringInput();
    return 0;
}