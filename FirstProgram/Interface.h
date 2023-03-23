#pragma once
#include <regex>
#include "classes.h"
#include "Algorithms.h"

#define numberOfFaculty 7 + 1
#define numberOfCourse 5 + 1 
#define smallestPhoneNumber   9999999999
#define biggestPhoneNumber   100000000000
#define maximumOfStudents 10000  //2147483647 максимальное значение, так как это максимум int

enum inputFields {
    surnameField, firstnameField, patronymicField, dateOfBirthField,
    addressField, phoneNumField, facultyField, courseField
};

using namespace std;

int EnterSettingsTwo();
int EnterSettingThree();
date EnterDayMonthYear(const string& str);
string EnterFilePath();
template <typename type> type EnterNum() {
    type num = 0;

    while (!(cin >> num)) {
        cin.clear();
        cin.ignore(INT32_MAX, '\n');
        cout << "Invalid input. Try again" << endl << "> ";
    }

    return num;
}

date CorrectDateOfBirth(const string& surname, const string& firstname, const string& patronymic);
int64_t CorrectPhoneNum(const string& surname, const string& firstname, const string& patronymic);
int16_t CorrectFaculty(const string& surname, const string& firstname, const string& patronymic);
int16_t CorrectCourse(const string& surname, const string& firstname, const string& patronymic);

template <typename type = student> myVector<type> InputFromFile() {
    string surname;
    string firstname;
    string patronymic;
    string dateOfBirth_;
    date dateOfBirth;
    string address;
    int64_t phoneNum;
    int16_t faculty;
    int16_t course;

    myVector <student> s;

    while (true) {
        string filePath = " ";
        filePath = EnterFilePath();
        ifstream inputStream(filePath.c_str());
        if (!inputStream.is_open()) {
            cout << "File with this name don't exist. Try again" << endl;
            continue;
        }
        else {
            int fieldOrder = 0;

            while (inputStream) {
                switch (fieldOrder) {
                case(surnameField):
                    inputStream >> surname;
                    break;
                case(firstnameField):
                    inputStream >> firstname;
                    break;
                case(patronymicField):
                    inputStream >> patronymic;
                    break;
                case(dateOfBirthField):
                    inputStream >> dateOfBirth_;
                    dateOfBirth = EnterDayMonthYear(dateOfBirth_);
                    if(!dateOfBirth.DateCorrect()) {
                        dateOfBirth = CorrectDateOfBirth(surname, firstname, patronymic);
                    }
                    break;
                case(addressField):
                    inputStream >> address;
                    break;
                case(phoneNumField):
                    inputStream >> phoneNum;
                    if (!IsInBetween<int64_t>(phoneNum, smallestPhoneNumber, biggestPhoneNumber)) {
                        phoneNum = CorrectPhoneNum(surname, firstname, patronymic);
                    }
                    break;
                case(facultyField):
                    inputStream >> faculty;
                    if (!IsInBetween<int64_t>(faculty, 0, numberOfFaculty)) {
                        faculty = CorrectFaculty(surname, firstname, patronymic);
                    }
                    break;
                case(courseField):
                    inputStream >> course;
                    if (!IsInBetween<int16_t>(course, 0, numberOfCourse)) {
                        course = CorrectCourse(surname, firstname, patronymic);
                    }
                    break;
                }

                if (fieldOrder == 7) {
                    fieldOrder = 0;
                    student s_;
                    s_.Set(surname, firstname, patronymic, dateOfBirth, address, phoneNum, faculty, course);
                    s.Append(s_);
                }
                else {
                    ++fieldOrder;
                }
            }

            inputStream.close();
            break;
        }
    }

    return s;
}

template <typename type = student> myVector<type> InputFromConsole() {
    string surname;
    string firstname;
    string patronymic;
    string dateOfBirth_;
    date dateOfBirth;
    string address;
    int64_t phoneNum;
    int16_t faculty;
    int16_t course;

    int numberOfStudents = 0;
    myVector <student> s;
   
    while (true) {
        cout << "Enter number of students: ";
        numberOfStudents = EnterNum<int>();
        if (IsInBetween<int>(numberOfStudents, 0, maximumOfStudents)) {
            break;
        }
        cout << "Invalid value. Try again" << endl;
    }
    
    for (size_t i = 0; i < numberOfStudents; ++i) {
        cout << endl << "Surname: ";
        cin >> surname;

        cout << "Firstname: ";
        cin >> firstname;

        cout << "Patronymic: ";
        cin >> patronymic;
        
        cout << "Date of birth: ";
        cin >> dateOfBirth_;
        dateOfBirth = EnterDayMonthYear(dateOfBirth_);
        if (!dateOfBirth.DateCorrect()) {
            dateOfBirth = CorrectDateOfBirth(surname, firstname, patronymic);
        }

        cout << "Address: ";
        cin >> address;

        cout << "Phone number: ";
        cin >> phoneNum;
        if (!IsInBetween<int64_t>(phoneNum, smallestPhoneNumber, biggestPhoneNumber)) {
            phoneNum = CorrectPhoneNum(surname, firstname, patronymic);
        }

        cout << "Faculty: ";
        cin >> faculty;
        if (!IsInBetween<int64_t>(faculty, 0, numberOfFaculty)) {
            faculty = CorrectFaculty(surname, firstname, patronymic);
        }

        cout << "Course: ";
        cin >> course;
        if (!IsInBetween<int16_t>(course, 0, numberOfCourse)) {
            course = CorrectCourse(surname, firstname, patronymic);
        }

        student s_;
        s_.Set(surname, firstname, patronymic, dateOfBirth, address, phoneNum, faculty, course);
        s.Append(s_);
    }

    return s;
}

template <typename type = student> myVector<type> SortByFacultyInner(const myVector<type>& input, int16_t faculty) {
    myVector<type> output;

    for (size_t i = 0; i < input.GetSize(); ++i) {
        if (input[i].GetFaculty() == faculty) {
            output.Append(input[i]);
        }
    }

    return output;
}
template <typename type = student> myVector<type> SortByFaculty(const myVector<type>& input) {
    myVector<type> output;
    int16_t faculty = 0;

    while (true) {
        cout << "Enter faculty for sorting: ";
        faculty = EnterNum<int16_t>();
        if (IsInBetween<int16_t>(faculty, 0, numberOfFaculty)) {
            break;
        }
        cout << "Invalid value. Try again" << endl;
    }

    for (size_t i = 0; i < input.GetSize(); ++i) {
        if (input[i].GetFaculty() == faculty) {
            output.Append(input[i]);
        }
    }

    return SortByFacultyInner(input, faculty);
}

template <typename type = student> myVector<type> SortByFacultyCourse(const myVector<type>& input) {
    myVector<type> output;

    for (size_t fIterator = 1; fIterator < numberOfFaculty; ++fIterator){
        for (size_t cIterator = 1; cIterator < numberOfCourse; ++cIterator) {
            for (size_t i = 0; i < input.GetSize(); ++i) {
                if (input[i].GetFaculty() == fIterator && input[i].GetCourse() == cIterator) {
                    output.Append(input[i]);
                }
            }
        }
    }

    return output;
}

template <typename type = student> myVector<type> SortByYearOfBirthInner(const myVector<type>& input, int16_t year) {
    myVector<type> output;

    for (size_t i = 0; i < input.GetSize(); ++i) {
        if (input[i].GetDate().GetYear() > year) {
            output.Append(input[i]);
        }
    }

    return output;
}
template <typename type = student> myVector<type> SortByYearOfBirth(const myVector<type>& input) {
    int16_t year = 0;

    while (true) {
        cout << endl << "Enter year of birth for sorting: ";
        year = EnterNum<int16_t>();
        if (year > 0) {
            break;
        }
        cout << "Invalid value. Try again" << endl;
    }

    return SortByYearOfBirthInner(input, year);
}

template <typename type = student> void WriteOutput(const myVector<type>& input) {
    while (true) {
        string filePath = " ";
        filePath = EnterFilePath();

        ifstream test(filePath.c_str());
        if (test.is_open()) {
            cout << "File already exist. You still want a write on it? (Yes \"1\" or No \"2\"): ";
            if (EnterSettingsTwo() == 2) {
                continue;
            }
        }

        ofstream outputStream(filePath.c_str());
        if (!outputStream.is_open()) { 
            cout << "File with this name don't exist. Try again" << endl;
            continue;
        }
        else{
            for (size_t i = 0; i < input.GetSize(); ++i) {
                outputStream << input[i].Get() << endl;
            }
            break;
        }
    }
}