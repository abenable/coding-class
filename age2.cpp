#include <iostream>
#include <ctime>

using namespace std;

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

void calculateAge(int day, int month, int year)
{
    time_t t = time(0);
    tm *now = localtime(&t);
    int ageYears = now->tm_year + 1900 - year - (now->tm_mon + 1 < month || (now->tm_mon + 1 == month && now->tm_mday < day));
    tm lastBirthday = {0, 0, 0, day, month - 1, (now->tm_mon + 1 > month || (now->tm_mon + 1 == month && now->tm_mday >= day)) ? now->tm_year : now->tm_year - 1};
    double ageDays = difftime(mktime(now), mktime(&lastBirthday)) / (60 * 60 * 24);
    cout << "You are " << ageYears << " years and " << static_cast<int>(ageDays) << " days old." << endl;
}

int main()
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
    calculateAge(day, month, year);
    return 0;
}