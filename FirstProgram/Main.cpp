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
    //settings
    int inputSetting = 0;
    int actionSetting = 0;
    int outputSetting = 0;
    int exitSetting = 0;

    //flag
    bool flagOldStudents = false;

    //containers with students
    myVector<student> studentsInput;
    myVector<student> studentsOutput;

    cout << "3.1 Task by Mukhametov D.I. 423 group option 1" << endl << endl
         << "Create class student included fields ( surname, first name, patronymic," << endl
         << "date of birth, address, phone, faculty, course.Create an array of objects." << endl << endl
         << "To realize the possibility of obtaining :" << endl
         << "- a list of students of a given faculty," << endl
         << "- lists of students for each faculty and course," << endl
         << "- a list of students born after a given year." << endl << endl ;

    while (true) {
        //input
        if (!flagOldStudents) {
            cout << "How do you want to input information about student (file \"1\" or console \"2\"): ";
            inputSetting = EnterSettingsTwo();

            switch (inputSetting) {
            case(inputFromFile): studentsInput = InputFromFile(); break;        //for file input
            case(inputFromConsole): studentsInput = InputFromConsole(); break;  //for console input                                
            default: cout << "Unexpected behavior" << endl; continue;
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

        cout << endl;
        cout << "Do you want to write result of sorting (Yes \"1\" or No \"2\"): ";
        outputSetting = EnterSettingsTwo();

        //save result (studentOutput)
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
        case(oldStudent): flagOldStudents = true; break;                                //Sort by faculty
        case(newStudent): flagOldStudents = false; studentsInput.ClearVector();; break; //Sort by faculty & course
        case(closeProgram): return 0;                                                   //closeProgram
        default: cout << "Unexpected behavior" << endl; continue;
        }
    } 
}