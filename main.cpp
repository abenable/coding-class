#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Function to validate password
bool validatePassword(const string &inputPassword, const string &courseCode)
{
    return inputPassword == courseCode;
}

// Function to calculate GPA
double calculateGPA(const vector<int> &marks)
{
    double totalGradePoints = 0.0;
    double grade;

    // Loop through all the marks
    for (int mark : marks)
    {
        // Assign grade points based on the mark
        if (mark >= 80)
        {
            grade = 5.0;
        }
        else if (mark >= 75)
        {
            grade = 4.5;
        }
        else if (mark >= 70)
        {
            grade = 4.0;
        }
        else if (mark >= 65)
        {
            grade = 3.5;
        }
        else if (mark >= 60)
        {
            grade = 3.0;
        }
        else if (mark >= 55)
        {
            grade = 2.5;
        }
        else if (mark >= 50)
        {
            grade = 2.0;
        }
        else if (mark >= 45)
        {
            grade = 1.5;
        }
        else if (mark >= 40)
        {
            grade = 1.0;
        }
        else if (mark >= 35)
        {
            grade = 0.5;
        }
        else
        {
            grade = 0.0;
        }

        // Add the grade points to the total
        totalGradePoints += grade;
    }

    // Calculate the GPA by dividing the total grade points by the number of subjects
    return totalGradePoints / marks.size();
}
// Function to check if a year is a leap year
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int day, int month, int year)
{
    if (month < 1 || month > 12)
        return false;
    int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return day > 0 && day <= daysInMonth[month - 1];
}

// Function to calculate age
void calculateAge()
{
    string dob;
    cout << "Enter your date of birth (dd/mm/yyyy): ";
    cin >> dob;
    if (dob.length() != 10 || dob[2] != '/' || dob[5] != '/')
    {
        cout << "Invalid format. Please use dd/mm/yyyy." << endl;
        return 1;
    }
    int day = stoi(dob.substr(0, 2)), month = stoi(dob.substr(3, 2)), year = stoi(dob.substr(6, 4));
    if (!isValidDate(day, month, year))
    {
        cout << "Invalid date. Please try again." << endl;
        return 1;
    }

    time_t t = time(0);
    tm *now = localtime(&t);
    int ageYears = now->tm_year + 1900 - year - (now->tm_mon + 1 < month || (now->tm_mon + 1 == month && now->tm_mday < day));
    tm lastBirthday = {0, 0, 0, day, month - 1, (now->tm_mon + 1 > month || (now->tm_mon + 1 == month && now->tm_mday >= day)) ? now->tm_year : now->tm_year - 1};
    double ageDays = difftime(mktime(now), mktime(&lastBirthday)) / (60 * 60 * 24);
    cout << "You are " << ageYears << " years and " << static_cast<int>(ageDays) << " days old." << endl;
}
// Main function
int main()
{
    string fullName, inputPassword;
    string courseCode = "BELE";
    int numberOfSubjects;
    char continueProgram;

    cout << "Enter your full name: ";
    getline(cin, fullName);

    // Password Check
    int attempts = 0;
    while (attempts < 3)
    {
        cout << "Enter your password: ";
        cin >> inputPassword;

        if (validatePassword(inputPassword, courseCode))
        {
            cout << "Password accepted!" << endl;
            break;
        }
        else
        {
            attempts++;
            cout << "Incorrect password. Attempts left: " << (3 - attempts) << endl;
        }
    }

    if (attempts == 3)
    {
        cout << "Too many failed attempts. Exiting program." << endl;
        return 1;
    }

    // Capturing Marks and GPA Calculation
    do
    {
        cout << "Enter the number of subjects: ";
        cin >> numberOfSubjects;

        vector<int> marks(numberOfSubjects);
        for (int i = 0; i < numberOfSubjects; ++i)
        {
            do
            {
                cout << "Enter marks for subject " << (i + 1) << ": ";
                cin >> marks[i];
                if (marks[i] < 0 || marks[i] > 100)
                {
                    cout << "Invalid marks. Please enter a value between 0 and 100." << endl;
                }
            } while (marks[i] < 0 || marks[i] > 100);
        }

        double gpa = calculateGPA(marks);
        cout << "Your GPA is: " << gpa << endl;

        // Age Calculation

        calculateAge();

        // Continue or terminate the program
        cout << "Do you want to continue? (y/n): ";
        cin >> continueProgram;

    } while (continueProgram == 'y' || continueProgram == 'Y');

    cout << "Thank you for using the program!" << endl;
    return 0;
}
