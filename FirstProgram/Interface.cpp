#include "Interface.h"

//#define numberOfFaculty 7 + 1
//#define numberOfCourse 5 + 1 
//#define smallestPhoneNumber   9999999999
//#define bigestPhoneNumber   100000000000

int16_t EnterSettings() {
    int16_t setting = 0;

    while (true) {
        cin >> setting;
        if (setting == 1 || setting == 2) {
            break;
        }
        cout << "Invalide input. Try again" << endl;
    }

    return setting;
}

date GetDayMonthYear(const string& str) {
    cmatch result;
    static const regex regular( "([0-9]{1,2})" //day
                                "([\\s-_\./])"
                                "([0-9]{2})"   //month
                                "([\\s-_\./])"
                                "([0-9]{4})"); //year
    if (regex_match(str.c_str(),result, regular)) {
        return date(stoi(result[1]), stoi(result[3]), stoi(result[5]));
    }
    return date();
}

int64_t CorrectPhoneNum(const string& surname, const string& firstname, const string& patronymic) {
    int64_t phoneNum = 0;
    while (!IsInBetween<int64_t>(phoneNum, smallestPhoneNumber, bigestPhoneNumber)) {
        cout << "Field \"phoneNum\" by " << surname << " " << firstname << " " << patronymic << " is uncorrect." << endl
            << "You can enter now correct (press 1) or do not initialize it (press 2)";
        if (EnterSettings() == 1) {
            cout << "Phone number: ";
            cin >> phoneNum;
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
        cout << "Field \"faculty\" by " << surname << " " << firstname << " " << patronymic << " is uncorrect." << endl
            << "You can enter now correct (press 1) or do not initialize it (press 2)";
        if (EnterSettings() == 1) {
            cout << "Faculty: ";
            cin >> faculty;
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
        cout << "Field \"course\" by " << surname << " " << firstname << " " << patronymic << " is uncorrect." << endl
            << "You can enter now correct (press 1) or do not initialize it (press 2)";
        if (EnterSettings() == 1) {
            cout << "Faculty: ";
            cin >> course;
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
        cout << "Field \"dateOfBirth\" by " << surname << " " << firstname << " " << patronymic << " is uncorrect." << endl
            << "You can enter now correct (press 1) or do not initialize it (press 2)";
        if (EnterSettings() == 1) {
            cout << "Date of birth: ";
            cin >> dateOfBirth_;
            dateOfBirth = GetDayMonthYear(dateOfBirth_);
        }
        else {
            return dateOfBirth;
        }
    }
    return dateOfBirth;
}
