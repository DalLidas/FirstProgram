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