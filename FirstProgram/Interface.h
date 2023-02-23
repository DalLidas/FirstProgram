#pragma once
#include <regex>
#include "classes.h"
#include "Algorithms.h"

#define numberOfFaculty 7 + 1
#define numberOfCourse 5 + 1 
#define smallestPhoneNumber   9999999999
#define bigestPhoneNumber   100000000000
#define maximumOfStudents 10000  //2147483647 максимальное значение, так как это максимум int

enum inputFields {
    surnameField, firstnameField, patronymicField, dateOfBirthField,
    addressField, phoneNumField, facultyField, courseField
};

using namespace std;

int16_t EnterSettings();

date GetDayMonthYear(const string& str);

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
        cout << "Enter file path: ";
        string filePath = " ";
        cin >> filePath;
        ifstream inputStream(filePath);
        if (!inputStream.is_open()) {
            cout << "Invalide file path. Try again" << endl;
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
                    dateOfBirth = GetDayMonthYear(dateOfBirth_);
                    if(!dateOfBirth.DateCorrect()) {
                        dateOfBirth = CorrectDateOfBirth(surname, firstname, patronymic);
                    }
                    break;
                case(addressField):
                    inputStream >> address;
                    break;
                case(phoneNumField):
                    inputStream >> phoneNum;
                    if (!IsInBetween<int64_t>(phoneNum, smallestPhoneNumber, bigestPhoneNumber)) {
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

    cout << "#1.1" << endl;
    s.Info();
    for (int i = 0; i < s.GetSize(); ++i) {
        s[i].Show();
    }

    return s;
}

template <typename type = student> myVector<type>InputFromConsole() {
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
        cin >> numberOfStudents;
        if (IsInBetween<int>(numberOfStudents, 0, maximumOfStudents)) {
            break;
        }
        cout << "Invalide value. Try again" << endl;
    }
    
    for (int i = 0; i < numberOfStudents; ++i) {
        cout << endl << "Surname: ";
        cin >> surname;

        cout << "Firstname: ";
        cin >> firstname;

        cout << "Patronymic: ";
        cin >> patronymic;
        
        cout << "Date of birth: ";
        cin >> dateOfBirth_;
        dateOfBirth = GetDayMonthYear(dateOfBirth_);
        if (!dateOfBirth.DateCorrect()) {
            dateOfBirth = CorrectDateOfBirth(surname, firstname, patronymic);
        }

        cout << "Address: ";
        cin >> address;

        cout << "Phone number: ";
        cin >> phoneNum;
        if (!IsInBetween<int64_t>(phoneNum, smallestPhoneNumber, bigestPhoneNumber)) {
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

    cout << "#1.2" << endl;
    s.Info();
    for (int i = 0; i < s.GetSize(); ++i) {
        s[i].Show();
    }

    return s;
}
