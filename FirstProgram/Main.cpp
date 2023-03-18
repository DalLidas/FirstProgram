#include "Classes.h"
#include "Algorithms.h"
#include "Interface.h"

enum inputSettings { inputFromFile = 1, inputFromConsole = 2 };
enum actionSettings { sortByFaculty = 1, sortByFacultyCourse = 2, sortByYearOfBirth = 3};
enum exitSettings { oldStudent = 1, newStudent = 2, closeProgram = 3};

//using namespace std;
using std::string;
using std::ifstream;
using std::ofstream;
using std::to_string;
using std::endl;
using std::cout;
using std::cin;

int main() {

    //{
    //    myVector<student> sIn;
    //    myVector<student> sOut;
    //    student bob;
    //    date dt;
    //    dt.Set(12, 12, 1212);
    //    bob.Set("Bob1", "Bob", "Boba", dt, "Brazil", 88005553535, 4, 1);
    //    sIn.Append(bob);
    //    sOut.Append(bob);
    //    dt.Set(12, 12, 1200);
    //    bob.Set("Bob2", "Bob", "Booba", dt, "Brazil", 88005553535, 3, 1);
    //    sIn.Append(bob);
    //    //sOut.Append(bob);
    //    bob.Set("Bob3", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 1);
    //    sIn.Append(bob);
    //    //sOut.Append(bob);
    //    dt.Set(12, 12, 1270);
    //    bob.Set("Bob4", "Bob", "Boba", dt, "Brazil", 88005553535, 4, 1);
    //    sIn.Append(bob);
    //    sOut.Append(bob);
    //    bob.Set("Bob5", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 1);
    //    sIn.Append(bob);
    //    //sOut.Append(bob);
    //    dt.Set(12, 12, 1240);
    //    bob.Set("Bob6", "Bob", "Boba", dt, "Brazil", 88005553535, 1, 1);
    //    sIn.Append(bob);
    //    //sOut.Append(bob);
    //    bob.Set("Bob7", "Bob", "Boba", dt, "Brazil", 88005553535, 2, 1);
    //    sIn.Append(bob);
    //    //sOut.Append(bob);
    //    SortByFacultyInner(sIn, 4) == sOut ? cout << "true" << endl : cout << "false" << endl;
    //}

    //settings
    int inputSetting = 0;
    int actionSetting = 0;
    int outputSetting = 0;
    int exitSetting = 0;

    //flag
    bool flagInputNewStudents = true;
    bool flagWriteStudents = false;

    //containers with students
    myVector<student> studentsInput;
    myVector<student> studentsOutput;

    cout << "3.1 Task by Mukhametov D.I. 423 group option 1" << endl << endl
         << "Create class student included fields ( surname, first name, patronymic," << endl
         << "date of birth, address, phone, faculty, course.Create an array of objects." << endl << endl
         << "To realize the possibility of obtaining :" << endl
         << "- a list of students of a given faculty," << endl
         << "- lists of students for each faculty and course," << endl
         << "- a list of students born after a given year." << endl << endl;

    while (true) {
        //input
        if (flagInputNewStudents) {
            cout << "How do you want to input information about student (file \"1\" or console \"2\"): ";
            inputSetting = EnterSettingsTwo();

            switch (inputSetting) {
            case(inputFromFile): studentsInput = InputFromFile(); break;                                  //for file input
            case(inputFromConsole): studentsInput = InputFromConsole(); flagWriteStudents = true; break;  //for console input
            default: cout << "Unexpected behavior" << endl; continue;
            }

            if (flagWriteStudents) {
                cout << "Do you want to write entered students to file (Yes \"1\" or No \"2\"): ";
                outputSetting = EnterSettingsTwo();

                //save (studentsInput)
                switch (outputSetting) {
                case(oldStudent): WriteOutput(studentsInput); break;       //write to file
                case(newStudent): break;                                   //nothing :)
                default: cout << "Unexpected behavior" << endl; continue;
                }
                flagWriteStudents = false;
            }
        }

        cout << endl;
        cout << "What do you want to do:" << endl
            << "1.Sort student by faculty" << endl
            << "2.Sort by faculty & course" << endl
            << "3.Sort student by year of birth" << endl;
        actionSetting = EnterSettingThree();

        //action
        switch (actionSetting){
        case(sortByFaculty): studentsOutput = SortByFaculty(studentsInput); break;              //sorting by faculty
        case(sortByFacultyCourse): studentsOutput = SortByFacultyCourse(studentsInput); break;  //sorting by faculty & course
        case(sortByYearOfBirth): studentsOutput = SortByYearOfBirth(studentsInput); break;      //sorting student by year of birth
        default: cout << "Unexpected behavior" << endl; continue;
        }

        //output
        for (size_t i = 0; i < studentsOutput.GetSize(); ++i) {
            studentsOutput[i].Show();
        }

        cout << "Do you want to write result of sorting (Yes \"1\" or No \"2\"): ";
        outputSetting = EnterSettingsTwo();

        //save (studentOutput)
        switch (outputSetting) {
        case(oldStudent): WriteOutput(studentsOutput); break;      //write to file
        case(newStudent): break;                                   //nothing :)
        default: cout << "Unexpected behavior" << endl; continue;
        }
        
        cout << endl;
        cout << "What do you prefer to do next:" << endl
            << "1.Sort again current students" << endl
            << "2.Enter new student" << endl
            << "3.Close program " << endl;
        exitSetting = EnterSettingThree();

        //ending
        switch (exitSetting) {
        case(oldStudent): flagInputNewStudents = false; break;                             //use old students on next cycle
        case(newStudent): flagInputNewStudents = true; studentsInput.ClearVector(); break; //enter new students on next cycle
        case(closeProgram): return 0;                                                      //closeProgram
        default: cout << "Unexpected behavior" << endl; continue;
        }

    } 
}