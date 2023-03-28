#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/////////////////////////////////////////////////
//                    Date                     //
/////////////////////////////////////////////////
class date {
private:
    bool leapYear;
    int16_t day = 0;
    int16_t month = 0;
    int16_t year = 0;

    bool Leap(int y) const;
    bool DateCorrect(const int16_t& day_, const int16_t& month_, const int16_t& year_);

public:
    date();
    date(const int16_t& day_, const int16_t& month_, const int16_t& year_);
    void Set(const int16_t& day_, const int16_t& month_, const int16_t& year_);
    string Get() const;

    int16_t GetDay() const;   //for sort
    int16_t GetMonth() const; //for sort
    int16_t GetYear() const;  //for sort

    bool DateCorrect() const;
    void Show() const;

    bool operator ==(const date& other) const;
};


/////////////////////////////////////////////////
//                  Student                    //
/////////////////////////////////////////////////
class student {
private:
    string surname;
    string firstname;
    string patronymic;
    date dateOfBirth;
    string address;
    int64_t phoneNum;
    int16_t faculty;
    int16_t course;

public:

    student();

    void Set(const string& surname_, const string& firstname_, const string& patronymic_, const date& dateOfBirth_,
        const string& address_, const int64_t& phoneNum_, const int16_t& faculty_, const int16_t& course_);
    void SetSurname(const string& surname_);
    void SetFirstname(const string& firstname_);
    void SetPatronymic(const string& patronymic_);
    void GetDate(const date& dateOfBirth_);
    void SetAddress(const string& address_);
    void SetPhoneNum(const int64_t& phoneNum_);
    void SetFaculty(const int16_t& faculty_);
    void SetCourse(const int16_t& course_);
    
    string Get() const;
    string GetSurname() const;
    string GetFirstname() const;
    string GetPatronymic() const;
    date GetDate() const;      
    string GetAddress() const;
    int64_t GetPhoneNum() const;
    int16_t GetFaculty() const; 
    int16_t GetCourse() const;  

    void Show() const;

    bool operator ==(const student& other ) const;
};

/////////////////////////////////////////////////
//                  Vector                     //
/////////////////////////////////////////////////
template <typename type = int> class myVector {
private:
    type* ptr = nullptr;
    size_t currentSize = 0;
    size_t capacity = 0;

    void Reallocation() {
        type* buffer = new type[currentSize];
        for (size_t i = 0; i < currentSize; ++i) {
            buffer[i] = ptr[i];
        }
        capacity *= 2;

        delete[] ptr;
        ptr = new type[capacity];
        for (size_t i = 0; i < currentSize; ++i) {
            ptr[i] = buffer[i];
        }

        delete[] buffer;
        buffer = nullptr;
    }
public:
    myVector() : currentSize(0), capacity(2), ptr(new type[2]) {}
    myVector(const size_t& size) : currentSize(0), capacity(size > 1 ? size : 2 ), ptr(new type[size > 1 ? size : 2]) {}

    ~myVector() {
        if (ptr != nullptr) {
            delete[] ptr;
            ptr = nullptr;
            capacity = currentSize = 0;
        }
    }
    void Append(type object) {
        if (currentSize == capacity) {
            Reallocation();
        }

        ptr[currentSize++] = object;
    }

    size_t GetSize() const {
        return currentSize;
    }

    void Info() const {
        cout << "ptr: " << ptr << endl
            << "current size: " << currentSize << endl
            << "capacity: " << capacity << endl;
    }

    void ClearVector() {
        delete[] ptr;
        ptr = nullptr;
        capacity = currentSize = 0;
    }

    type& operator [](size_t index) {
        return ptr[index];
    }
    const type& operator [](size_t index) const {
        return ptr[index];
    }

    myVector<type>& operator = (const myVector<type>& other) {
        if (this != &other) {
            ClearVector();
            currentSize = other.currentSize;
            capacity = other.capacity;
            ptr = new type[capacity];
            for (size_t i = 0; i < currentSize; ++i) {
                ptr[i] = other[i];
            }
        }
        return *this;
    }

    bool operator == (const myVector<type>& other) const{
        if (currentSize != other.currentSize) {
            return false;
        }
        for (size_t i = 0; i < currentSize; ++i) {
            if (!(ptr[i] == other.ptr[i])) {
                return false;
            }
        }
                        
        return true;
    }
};