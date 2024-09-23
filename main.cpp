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
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    return false;
}

// Function to validate the day based on the month and year
bool isValidDate(int day, int month, int year)
{
    // Days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust for leap years in February
    if (isLeapYear(year))
        daysInMonth[1] = 29;

    if (month < 1 || month > 12)
        return false; // Invalid month
    if (day < 1 || day > daysInMonth[month - 1])
        return false; // Invalid day
    return true;
}

// Function to calculate age
void calculateAge()
{
    string dob;
    cout << "Enter your date of birth (DD/MM/YYYY): ";
    cin >> dob;

    // Parse the date
    int day, month, year;
    sscanf(dob.c_str(), "%d/%d/%d", &day, &month, &year);

    // Validate the date
    if (!isValidDate(day, month, year))
    {
        cout << "Invalid date. Please enter a valid date (DD/MM/YYYY)." << endl;
        return;
    }

    // Get current date
    time_t now = time(0);
    tm *currentTime = localtime(&now);
    int currentYear = currentTime->tm_year + 1900;
    int currentMonth = currentTime->tm_mon + 1;
    int currentDay = currentTime->tm_mday;

    // Calculate the age
    int ageYears = currentYear - year;
    int ageMonths = currentMonth - month;
    int ageDays = currentDay - day;

    // Adjust age based on days
    if (ageDays < 0)
    {
        ageMonths--;
        // Correct for negative days based on the previous month
        int daysInPreviousMonth = (month == 1) ? 31 : (isLeapYear(year) && month == 3) ? 29
                                                                                       : 28; // Handle February
        ageDays += daysInPreviousMonth;                                                      // Adjust day difference
    }

    // Adjust age based on months
    if (ageMonths < 0)
    {
        ageYears--;
        ageMonths += 12;
    }

    // Output final age in years and remaining days
    cout << "You are " << ageYears << " years and " << ageDays << " days old." << endl;
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
