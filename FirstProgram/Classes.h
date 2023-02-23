#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
    bool DateCorrect() const;
    void Show() const;
};

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
    string Get() const;
    void Show() const;
};

template <typename type = int> class myVector {
private:
    type* ptr = nullptr;
    int curentSize = 0;
    int capacity = 0;

    void Reallocation() {
        type* buffer = new type[curentSize];
        for (size_t i = 0; i < curentSize; ++i) {
            buffer[i] = ptr[i];
        }
        capacity *= 2;

        ptr = new type[capacity];
        for (int i = 0; i < curentSize; ++i) {
            ptr[i] = buffer[i];
        }

        delete[] buffer;
        buffer = nullptr;
    }
public:
    myVector() : curentSize(0), capacity(1), ptr(new type) {}
    myVector(const int& size) : curentSize(size), capacity(size), ptr(new type[size]) {}

    ~myVector() {
        curentSize = capacity = 0;
        if (!(ptr == nullptr)) {
            delete[] ptr;
        }
    }
    void Append(type object) {
        if (curentSize == capacity) {
            Reallocation();
        }

        ptr[curentSize++] = object;
    }

    int GetSize() const {
        return curentSize;
    }

    void Info() const {
        cout << "ptr: " << ptr << endl
            << "curent size: " << curentSize << endl
            << "capacity: " << capacity << endl;
    }

    type& operator [](int index) {
        return ptr[index];
    }

    type& operator = ( type const& other) {
        if (this != &other) {
            curentSize = other.curentSize;
            capacity = other.capacity;

            ptr = new type[capacity];
            for (int i = 0; i < other.curentSize; ++i) {
                ptr[i] = other.ptr[i];
            }
        }

        return this;
    }
};
