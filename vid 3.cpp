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
//=================================================================

// adding "0" to front of the the number if it is lower than 10;
string getWith2Digits(int Number)
{
    string numText = "";
    if (Number < 10)
        numText = "0" + to_string(Number);
    else
        numText = to_string(Number);

    return numText;
}

vector<string> criteria = {"Presenting", "C++ Knowledge", "Explaining Concepts", "Q & A"};
vector<float> marks = {23, 54, 65, 76};
int FinalMarks;
// calculating final marks;
int getFinalMarks()
{
    float total = 0;
    for (float i : marks)
    {
        total += i;
    }
    FinalMarks = static_cast<int>(total / marks.size());
    return FinalMarks;
}

// to take string with same string length;
string fixedStringLength(string Text, int FixedLength)
{
    if (Text.length() < FixedLength)
    {
        for (int i = Text.length(); i <= FixedLength; i++)
        {
            Text += " ";
        }
    }
    return Text;
}

void DisplayStudentResults(string StudentName, string GroupName, vector<string> criteria, vector<float> marks)
{
    CreateTitle("Student Result Details");
    int i = 1;
    cout << getWith2Digits(i++) << ". " << fixedStringLength("Student Name", 50) << ": " << StudentName << "." << endl;
    cout << getWith2Digits(i++) << ". " << fixedStringLength("Student Group Name", 50) << ": " << GroupName << "." << endl;
    for (int a = 0; a < marks.size(); a++)
    {
        cout << getWith2Digits(i++) << ". " << fixedStringLength(criteria[a], 50) << ": " << marks[a] << endl;
    }
    cout << getWith2Digits(i++) << ". " << fixedStringLength("FINAL MARKS", 50) << ": " << getFinalMarks() << endl;
}

int main()
{
    // f1
    cout << "enter a one digit number : ";
    int num;
    cin >> num;
    cout << getWith2Digits(num) + ". Item Displayed with two digits." << endl
         << endl
         << endl;

    //====================================================================

    // f2
    cout << "vector<float> marks = {23, 54, 65, 76}; " << endl
         << endl;
    cout << "\n\nThis value is created by \"GetFinalMarks()\" function:";
    cout << getFinalMarks() << endl
         << endl
         << endl;

    // f3 ================================================================
    cout << "enter a text :";
    string text = GetStringInput();
    cout << fixedStringLength(text, 70) << ":";

    cout << endl
         << endl
         << endl;

    // f4 =================================================================
    cout << "Enter the Student Name : ";
    string studentName = GetStringInput();
    cout << endl
         << endl
         << endl;
    DisplayStudentResults(studentName, "Librery Management System", criteria, marks);

    GetStringInput();

    return 0;
}