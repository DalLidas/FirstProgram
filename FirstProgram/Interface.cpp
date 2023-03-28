#include "Interface.h"

//#define numberOfFaculty 7 + 1
//#define numberOfCourse 5 + 1 
//#define smallestPhoneNumber   9999999999
//#define biggestPhoneNumber   100000000000

int EnterSettingsTwo() {
    int  setting = 0;
    cin >> setting;

    while (true) {
        if (setting == 1 || setting == 2) {
            break;
        }

        while (!(cin >> setting))
        {
            cin.clear();
            cin.ignore(INT32_MAX, '\n');
            cout << "Invalid input. Try again" << endl
                << "Enter \"1\" or \"2\": ";
        }
    }
    return setting;
}

int EnterSettingThree() {
    int setting = 0;
    cin >> setting;

    while (true) {
        if (setting == 1 || setting == 2 || setting == 3) {
            break;
        }

        while (!(cin >> setting))
        {
            cin.clear();
            cin.ignore(INT32_MAX, '\n');
            cout << "Invalid input. Try again" << endl
                << "Enter \"1\" or \"2\" or \"3\": ";
        }
    }
    return setting;
}

date EnterDayMonthYear(const string& str) {
    cmatch result;
    static const regex reg( "([0-9]{1,2})" //day
                     "([\\s-_./])"
                     "([0-9]{1,2})"   //month
                     "([\\s-_./])"
                     "([0-9]{1,4})"); //year
    if (regex_match(str.c_str(),result, reg)) {
        return date(static_cast<int16_t>(stoi(result[1])), 
                    static_cast<int16_t>(stoi(result[3])),
                    static_cast<int16_t>(stoi(result[5])));
    }
    return date();
}
 
string EnterFilePath() {
    string filePath = " ";
    static const regex reg("((/./)?(con))|((/./)?(con\\.))|((/./)?(con\\.)(.*))");

    while (true) {
        cout << "Enter file path: ";
        cin >> filePath;

        if (!regex_match(filePath.c_str(), reg)) {
            break;
        }
        cout << "You enter reserved by system file name. Try again" << endl;
    }

    return filePath.c_str();
}

int64_t CorrectPhoneNum(const string& surname, const string& firstname, const string& patronymic) {
    int64_t phoneNum = 0;
    while (!IsInBetween<int64_t>(phoneNum, smallestPhoneNumber, biggestPhoneNumber)) {
        cout << endl << "Field \"phoneNum\" by " << surname << " " << firstname << " " << patronymic << " is incorrect." << endl
            << "You can enter now correct (press 1) or do not initialize it (press 2): ";
        if (EnterSettingsTwo() == 1) {
            cout << "Phone number: ";
            phoneNum = EnterNum<int64_t>();;
        }
        else {
            return 0;
        }
    }
    return phoneNum;
}

int16_t CorrectFaculty(const string& surname, const string& firstname, const string& patronymic){
    int16_t faculty = 0;
    while (!IsInBetween<int16_t>(faculty, 0, numberOfFaculty)) {
        cout << endl << "Field \"faculty\" by " << surname << " " << firstname << " " << patronymic << " is incorrect." << endl
            << "You can enter now correct (press 1) or do not initialize it (press 2): ";
        if (EnterSettingsTwo() == 1) {
            cout << "Faculty: ";
            faculty = EnterNum<int16_t>();
        }
        else {
            return 0;
        }
    }
    return faculty;
}

int16_t CorrectCourse(const string& surname, const string& firstname, const string& patronymic) {
    int16_t course = 0;
    while (!IsInBetween<int16_t>(course, 0, numberOfCourse)) {
        cout << endl << "Field \"course\" by " << surname << " " << firstname << " " << patronymic << " is incorrect." << endl
            << "You can enter now correct (press 1) or do not initialize it (press 2): ";
        if (EnterSettingsTwo() == 1) {
            cout << "Faculty: ";
            course = EnterNum<int16_t>();
        }
        else {
            return 0;
        }
    }
    return course;
}

date CorrectDateOfBirth(const string& surname, const string& firstname, const string& patronymic) {
    date dateOfBirth;
    string dateOfBirth_;
    while (!dateOfBirth.DateCorrect()) {
        cout << endl << "Field \"dateOfBirth\" by " << surname << " " << firstname << " " << patronymic << " is incorrect." << endl
            << "You can enter now correct (press 1) or do not initialize it (press 2): ";
        if (EnterSettingsTwo() == 1) {
            cout << "Date of birth: ";
            cin >> dateOfBirth_;
            dateOfBirth = EnterDayMonthYear(dateOfBirth_);
        }
        else {
            return dateOfBirth;
        }
    }
    return dateOfBirth;
}
