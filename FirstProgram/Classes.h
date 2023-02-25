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
    int currentSize = 0;
    int capacity = 0;

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
    myVector(const int& size) : currentSize(size), capacity(size > 1 ? size : 2 ), ptr(new type[size > 1 ? size : 2]) {}

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

    int GetSize() const {
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

    type& operator [](int index) {
        return ptr[index];
    }
    const type& operator [](int index) const {
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
};
