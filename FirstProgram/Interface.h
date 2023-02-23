#pragma once
#include <regex>
#include "classes.h"
#include "Algorithms.h"

#define numberOfFaculty 7 + 1
#define numberOfCourse 5 + 1 
#define smallestPhoneNumber   9999999999
#define bigestPhoneNumber   100000000000

enum inputFields {
    surnameField, firstnameField, patronymicField, dateOfBirthField,
    addressField, phoneNumField, facultyField, courseField
};

using namespace std;

int16_t EnterSettings();

date GetDayMonthYear(const string& str);

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
                    while(!dateOfBirth.DateCorrect()) {
                        cout << "Field \"dateOfBirth\" by " << surname << " " << firstname << " " << patronymic << " is uncorrect." << endl
                            << "You can enter now correct (press 1) or do not initialize it (press 2)";
                        if (EnterSettings() == 1) {
                            cout << "Date of birth: ";
                            cin >> dateOfBirth_;
                            dateOfBirth = GetDayMonthYear(dateOfBirth_);
                        }
                        else {
                            break;
                        }
                    }
                    break;
                case(addressField):
                    inputStream >> address;
                    break;
                case(phoneNumField):
                    inputStream >> phoneNum;
                    while (true) {
                        if (IsInBetween<int64_t>(phoneNum, smallestPhoneNumber, bigestPhoneNumber)) {
                            break;
                        }
                        else {
                            cout << "Field \"phoneNum\" by " << surname << " " << firstname << " " << patronymic << " is uncorrect." << endl
                                << "You can enter now correct (press 1) or do not initialize it (press 2)";
                            if (EnterSettings() == 1) {
                                cout << "Phone number: ";
                                cin >> phoneNum;
                            }
                            else {
                                phoneNum = 0;
                                break;
                            }
                        }
                    }
                    break;
                case(facultyField):
                    inputStream >> faculty;
                    while (true) {
                        if (IsInBetween<int16_t>(faculty, 0, numberOfFaculty)) {
                            break;
                        }
                        else {
                            cout << "Field \"faculty\" by " << surname << " " << firstname << " " << patronymic << " is uncorrect." << endl
                                << "You can enter now correct (press 1) or do not initialize it (press 2)";
                            if (EnterSettings() == 1) {
                                cout << "Faculty: ";
                                cin >> faculty;
                            }
                            else {
                                faculty = 0;
                                break;
                            }
                        }
                    }
                    break;
                case(courseField):
                    inputStream >> course;
                    while (true) {
                        if (IsInBetween<int16_t>(course, 0, numberOfCourse)) {
                            break;
                        }
                        else {
                            cout << "Field \"course\" by " << surname << " " << firstname << " " << patronymic << " is uncorrect." << endl
                                << "You can enter now correct (press 1) or do not initialize it (press 2)";
                            if (EnterSettings() == 1) {
                                cout << "Course: ";
                                cin >> course;
                            }
                            else {
                                course = 0;
                                break;
                            }
                        }
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

 