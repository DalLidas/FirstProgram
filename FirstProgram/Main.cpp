#include "Classes.h"
#include "Algorithms.h"
#include "Interface.h"

enum inputSettings { inputFromFile = 1, inputFromConsole = 2 };

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
    int16_t inputSetting = 0;
    int16_t actionSetting = 0;

    //container with students
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
        cout << "How do you want to input information about student (file \"1\" or console \"2\"): ";
        inputSetting = EnterSettings();

        //input
        if (inputSetting == inputFromFile) { //for file input
            studentsInput = InputFromFile();
        }
        else if (inputSetting == inputFromConsole) { //for console input
            studentsInput = InputFromConsole();
        }
        else {
            cout << "Unexpected behavior" << endl;
            continue;
        } 

        cout << "\nWhat do you want to do:" << endl
            << "1.Sort student by faculty" << endl
            << "2.Sort by faculty & course" << endl
            << "3.Sort student by year of birth" << endl;

        cin >> actionSetting;

        //action
        if (actionSetting == 1) { //Sort by faculty
            studentsOutput = SortByFaculty(studentsInput);
        }
        else if (actionSetting == 2) { //Sort by faculty & course
            studentsOutput = SortByFacultyCourse(studentsInput);
        }
        else if (actionSetting == 3) { //Sort by year of birth
            studentsOutput = SortByYearOfBirth(studentsInput);
        }
        else {
            cout << "Unexpected behavior" << endl;
            continue;
        }

        //output
        for (size_t i = 0; i < studentsOutput.GetSize(); ++i) {
            studentsOutput[i].Show();
        }


    }
    return 0;
}