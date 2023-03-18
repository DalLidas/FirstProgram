#include "Classes.h"

/////////////////////////////////////////////////
//                    Date                     //
/////////////////////////////////////////////////
bool date::Leap(int y) const {
    return ((y % 4 == 0 && y % 100 != 0) || y % 400);
}

bool date::DateCorrect(const int16_t& day_, const int16_t& month_, const int16_t& year_) {
    int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    leapYear = Leap(year_);
    if (leapYear) {
        days[1] = 29;
    }

    if (month_ > 0 && month_ <= 12 && day_ > 0 && day_ <= days[month_ - 1]) {
        return true;
    }
    else {
        return false;
    }
}

date::date() : leapYear(Leap(0)), day(0), month(0), year(0) {}

date::date(const int16_t& day_, const int16_t& month_, const int16_t& year_) : leapYear(Leap(0)), day(0), month(0), year(0) {
    if (DateCorrect(day_, month_, year_)) {
        day = day_;
        month = month_;
        year = year_;
    }
}

void date::Set(const int16_t& day_, const int16_t& month_, const int16_t& year_) {
    if (DateCorrect(day_, month_, year_)) {
        day = day_;
        month = month_;
        year = year_;
    }
}

string date::Get() const {
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

int16_t date::GetDay() const {
    return day;
}

int16_t date::GetMonth() const {
    return month;
}

int16_t date::GetYear() const {
    return year;
}

bool date::DateCorrect() const {
    return !(day == 0 || month == 0);
}

void date::Show() const {
    cout << day << "/" << month << "/" << year << "/";
}

bool date::operator ==(const date& other) const{
    return day == other.day &&
        month == other.month &&
        year == other.year;
}

/////////////////////////////////////////////////
//                  Student                    //
/////////////////////////////////////////////////
student::student() {
    surname = "Undefined";
    firstname = "Undefined";
    patronymic = "Undefined";
    dateOfBirth.Set(0, 0, 0);
    address = "Undefined";
    phoneNum = 0;
    faculty = 0;
    course = 0;
}

void student::Set(const string& surname_, const string& firstname_, const string& patronymic_, const date& dateOfBirth_,
    const string& address_, const int64_t& phoneNum_, const int16_t& faculty_, const int16_t& course_) {
    surname = surname_;
    firstname = firstname_;
    patronymic = patronymic_;
    dateOfBirth = dateOfBirth_;
    address = address_;
    phoneNum = phoneNum_;
    faculty = faculty_;
    course = course_;
}
void student::SetSurname(const string& surname_) {
    surname = surname_;
}
void student::SetFirstname(const string& firstname_) {
    firstname = firstname_;
}
void student::SetPatronymic(const string& patronymic_) {
    patronymic = patronymic_;
}
void student::GetDate(const date& dateOfBirth_) {
    dateOfBirth = dateOfBirth_;
}
void student::SetAddress(const string& address_) {
    address = address_;
}
void student::SetPhoneNum(const int64_t& phoneNum_) {
    phoneNum = phoneNum_;
}
void student::SetFaculty(const int16_t& faculty_) {
    faculty = faculty_;
}
void student::SetCourse(const int16_t& course_) {
    course = course_;
}

string student::Get() const {
    return surname + "\n"
        + firstname + "\n"
        + patronymic + "\n"
        + dateOfBirth.Get() + "\n"
        + address + "\n"
        + to_string(phoneNum) + "\n"
        + to_string(faculty) + "\n"
        + to_string(course) + "\n\n";
}

string student::GetSurname() const {
    return surname;
}
string student::GetFirstname() const {
    return firstname;
}
string student::GetPatronymic() const {
    return patronymic;
}
date student::GetDate() const {
    return dateOfBirth;
}
string student::GetAddress() const {
    return address;
}
int64_t student::GetPhoneNum() const {
    return phoneNum;
}
int16_t student::GetFaculty() const {
    return faculty;
}
int16_t student::GetCourse() const {
    return course;
}


void student::Show() const {
    cout << "Surname: " << surname << endl
        << "Firstname: " << firstname << endl
        << "Patronymic: " << patronymic << endl
        << "DateOfBirth: " << dateOfBirth.Get() << endl
        << "Address: " << address << endl
        << "PhoneNum: " << phoneNum << endl
        << "Faculty: " << faculty << endl
        << "Course: " << course << endl << endl;
}

bool student::operator ==(const student& other) const{
    return surname == other.surname &&
        firstname == other.firstname &&
        patronymic == other.patronymic &&
        dateOfBirth == other.dateOfBirth &&
        address == other.address &&
        phoneNum == other.phoneNum &&
        faculty == other.faculty &&
        course == other.course;
}

