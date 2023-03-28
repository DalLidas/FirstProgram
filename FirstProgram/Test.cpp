#include "Test.h"


bool ErrorHandler() {
	try {
		Test1();
		Test2();
		Test3();
		Test4();
		Test5();
	}
	catch(const int& numOfFailedTest){
        switch (numOfFailedTest){
        case(1):
            cout << "Test 1 Failed. Sort by Faculty work incorrect" << endl;
            break;
        case(2):
            cout << "Test 2 Failed. Sort by Faculty work incorrect" << endl;
            break;
        case(3):
            cout << "Test 3 Failed. Sort by Course work incorrect" << endl;
            break;
        case(4):
            cout << "Test 4 Failed. Sort by Date work incorrect" << endl;
            break;
        case(5):
            cout << "Test 5 Failed. Sort by Date work incorrect" << endl;
            break;
        default:
            cout << "Undefined error" << endl;
            break;
        }

		return true;
	}
    return false;
}

bool Test1() {
    myVector<student> sIn;
    myVector<student> sOut;
    student bob;
    date dt;

    dt.Set(12, 12, 1212);
    bob.Set("Bob1", "Bob", "Boba", dt, "Brazil", 88005553535, 4, 1);
    sIn.Append(bob);
    sOut.Append(bob);

    dt.Set(12, 12, 1200);
    bob.Set("Bob2", "Bob", "Booba", dt, "Brazil", 88005553535, 3, 1);
    sIn.Append(bob);
    //sOut.Append(bob);

    bob.Set("Bob3", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 1);
    sIn.Append(bob);
    //sOut.Append(bob);

    dt.Set(12, 12, 1270);
    bob.Set("Bob4", "Bob", "Boba", dt, "Brazil", 88005553535, 4, 1);
    sIn.Append(bob);
    sOut.Append(bob);

    bob.Set("Bob5", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 1);
    sIn.Append(bob);
    //sOut.Append(bob);
    dt.Set(12, 12, 1240);

    bob.Set("Bob6", "Bob", "Boba", dt, "Brazil", 88005553535, 1, 1);
    sIn.Append(bob);
    //sOut.Append(bob);

    bob.Set("Bob7", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 1);
    sIn.Append(bob);
    //sOut.Append(bob);

    if (SortByFacultyInner(sIn, 4) == sOut) {
        return true;
    }
    else {
        throw (1);
    }
}
bool Test2() {
    myVector<student> sIn;
    myVector<student> sOut;
    student bob;
    date dt;

    dt.Set(12, 12, 1212);
    bob.Set("Bob1", "Bob", "Boba", dt, "Brazil", 88005553535, 4, 1);
    sIn.Append(bob);
    //sOut.Append(bob);

    dt.Set(12, 12, 1200);
    bob.Set("Bob2", "Bob", "Booba", dt, "Brazil", 88005553535, 3, 1);
    sIn.Append(bob);
    //sOut.Append(bob);

    bob.Set("Bob3", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 1);
    sIn.Append(bob);
    sOut.Append(bob);

    dt.Set(12, 12, 1270);
    bob.Set("Bob4", "Bob", "Boba", dt, "Brazil", 88005553535, 4, 1);
    sIn.Append(bob);
    //sOut.Append(bob);

    bob.Set("Bob5", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 1);
    sIn.Append(bob);
    sOut.Append(bob);

    dt.Set(12, 12, 1240);
    bob.Set("Bob6", "Bob", "Boba", dt, "Brazil", 88005553535, 1, 1);
    sIn.Append(bob);
    //sOut.Append(bob);

    bob.Set("Bob7", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 1);
    sIn.Append(bob);
    sOut.Append(bob);

    if (SortByFacultyInner(sIn, 2) == sOut) {
        return true;
    }
    else {
        throw (2);
    }
}
bool Test3() {
    myVector<student> sIn;
    myVector<student> sOut;
    student bob;
    date dt;

    dt.Set(12, 12, 1212);
    bob.Set("Bob1", "Bob", "Boba", dt, "Brazil", 88005553535, 4, 1);
    sIn.Append(bob);

    dt.Set(12, 12, 1200);
    bob.Set("Bob2", "Bob", "Booba", dt, "Brazil", 88005553535, 3, 1);
    sIn.Append(bob);

    bob.Set("Bob3", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 4);
    sIn.Append(bob);

    bob.Set("Bob4", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 2);
    sIn.Append(bob);
    sOut.Append(bob);

    bob.Set("Bob3", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 4);
    sOut.Append(bob);

    dt.Set(12, 12, 1200);
    bob.Set("Bob2", "Bob", "Booba", dt, "Brazil", 88005553535, 3, 1);
    sOut.Append(bob);

    dt.Set(12, 12, 1212);
    bob.Set("Bob1", "Bob", "Boba", dt, "Brazil", 88005553535, 4, 1);
    sOut.Append(bob);

    if (SortByFacultyCourse(sIn) == sOut) {
        return true;
    }
    else {
        throw (3);
    }
}
bool Test4() {
    myVector<student> sIn;
    myVector<student> sOut;
    student bob;
    date dt;

    dt.Set(12, 12, 1212);
    bob.Set("Bob1", "Bob", "Boba", dt, "Brazil", 88005553535, 4, 1);
    sIn.Append(bob);
    //sOut.Append(bob);

    dt.Set(12, 12, 1200);
    bob.Set("Bob2", "Bob", "Booba", dt, "Brazil", 88005553535, 3, 1);
    sIn.Append(bob);
    //sOut.Append(bob);

    bob.Set("Bob3", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 1);
    sIn.Append(bob);
    //sOut.Append(bob);

    dt.Set(12, 12, 1270);
    bob.Set("Bob4", "Bob", "Boba", dt, "Brazil", 88005553535, 4, 1);
    sIn.Append(bob);
    sOut.Append(bob);

    bob.Set("Bob5", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 1);
    sIn.Append(bob);
    sOut.Append(bob);

    dt.Set(12, 12, 1240);
    bob.Set("Bob6", "Bob", "Boba", dt, "Brazil", 88005553535, 1, 1);
    sIn.Append(bob);
    sOut.Append(bob);

    bob.Set("Bob7", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 1);
    sIn.Append(bob);
    sOut.Append(bob);

    if (SortByYearOfBirthInner(sIn, 1220) == sOut) {
        return true;
    }
    else {
        throw (4);
    }
}
bool Test5() {
    myVector<student> sIn;
    myVector<student> sOut;
    student bob;
    date dt;

    dt.Set(12, 12, 1212);
    bob.Set("Bob1", "Bob", "Boba", dt, "Brazil", 88005553535, 4, 1);
    sIn.Append(bob);
    //sOut.Append(bob);

    dt.Set(12, 12, 1200);
    bob.Set("Bob2", "Bob", "Booba", dt, "Brazil", 88005553535, 3, 1);
    sIn.Append(bob);
    //sOut.Append(bob);

    bob.Set("Bob3", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 1);
    sIn.Append(bob);
    //sOut.Append(bob);

    dt.Set(12, 12, 1270);
    bob.Set("Bob4", "Bob", "Boba", dt, "Brazil", 88005553535, 4, 1);
    sIn.Append(bob);
    sOut.Append(bob);

    bob.Set("Bob5", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 1);
    sIn.Append(bob);
    sOut.Append(bob);

    dt.Set(12, 12, 1240);
    bob.Set("Bob6", "Bob", "Boba", dt, "Brazil", 88005553535, 1, 1);
    sIn.Append(bob);
    //sOut.Append(bob);

    bob.Set("Bob7", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 1);
    sIn.Append(bob);
    //sOut.Append(bob);

    if (SortByYearOfBirthInner(sIn, 1260) == sOut) {
        return true;
    }
    else {
        throw (5);
    }
}
