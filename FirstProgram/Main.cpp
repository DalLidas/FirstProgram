#include <iostream>
#include <fstream>
#include <string>

//using namespace std;
using std::string;

class student {
public:
    student(){
        surname     = "Undefined";
        firstname   = "Undefined";
        patronymic  = "Undefined";
        dateOfBirth = 0;
        address     = "Undefined";
        phoneNum    = 0;
        faculty     = 0;
        course      = 0;
    }

    void Set(const string& surname_, const string& firstname_, const string& patronymic_, const int& dateOfBirth_,
        const string& address_, const int64_t& phoneNum_, const int& faculty_, const int& course_) {
        surname     = surname_;
        firstname   = firstname_;
        patronymic  = patronymic_;
        dateOfBirth = dateOfBirth_;
        address     = address_;
        phoneNum    = phoneNum_;
        faculty     = faculty_;
        course      = course_;
    }

    void Set() {
        std::cout << "Surname: ";     std::cin >> surname;
        std::cout << "firstname: ";   std::cin >> firstname;
        std::cout << "patronymic: ";  std::cin >> patronymic;
        std::cout << "dateOfBirth: "; std::cin >> dateOfBirth;
        std::cout << "address: ";     std::cin >> address;
        std::cout << "phoneNum: ";    std::cin >> phoneNum;
        std::cout << "faculty: ";     std::cin >> faculty;
        std::cout << "course: ";      std::cin >> course;
    }

    string Get() {
        return "Surname: "        + surname                     + "\n" 
                + "Firstname: "   + firstname                   + "\n"
                + "patronymic: "  + patronymic                  + "\n"
                + "dateOfBirth: " + std::to_string(dateOfBirth) + "\n"
                + "address: "     + address                     + "\n"
                + "phoneNum: "    + std::to_string(phoneNum)    + "\n"
                + "faculty: "     + std::to_string(faculty)     + "\n"
                + "course: "      + std::to_string(course)      + "\n\n";
    }

    void Show() const {
        std::cout << "Surname: "     << surname     << std::endl
                  << "Firstname: "   << firstname   << std::endl
                  << "patronymic: "  << patronymic  << std::endl
                  << "dateOfBirth: " << dateOfBirth << std::endl
                  << "address: "     << address     << std::endl
                  << "phoneNum: "    << phoneNum    << std::endl
                  << "faculty: "     << faculty     << std::endl
                  << "course: "      << course      << std::endl << std::endl;
    }

    bool SuitableFaculty(const int& numOfFaculty) const{
        return faculty == numOfFaculty;
    }

    bool SuitableDateOfBirth(const int& numOfFaculty) const {
        return dateOfBirth > numOfFaculty;
    }


private:
    string surname;
    string firstname;
    string patronymic;
    int dateOfBirth;
    string address;
    int64_t phoneNum;
    int faculty;
    int course;
};





int main() {
    //settings
    int numOfStudents = 0;
    char inputSetting;
    char outputSetting;
    char exitSetting;
    int actionSetting;
         
    
    //for input information about students from file
    string surname;  
    string firstname;
    string patronymic;
    int dateOfBirth;
    string address;
    int64_t phoneNum;
    int faculty;
    int course;


    //for suitable
    int suitableFaculty;
    int suitableDateOfBirth;

    std::cout << "3.1 Task by Mukhametov D.I. 423 group option 1" << std::endl << std::endl;

    while (true) {
        std::cout << "How many object \"Student\" you want create: ";
        std::cin >> numOfStudents;
        std::cout << "How do you want to input information about student (file \"F\" or console\"C\"): ";
        std::cin >> inputSetting;
        std::cout << "How do you want to output information aboutstudent (file \"F\" or console\"C\"): ";
        std::cin >> outputSetting;

        student* sOrig = new student[numOfStudents];
        
        //input
        if (inputSetting == 'F') { //for file input
            std::ifstream in("Input.txt");
            for (int i = 0; i < numOfStudents; ++i) {
                in >> surname >> firstname >> patronymic >> dateOfBirth >> address >> phoneNum >> faculty >> course;
               sOrig[i].Set(surname, firstname, patronymic, dateOfBirth, address, phoneNum, faculty, course);
            } 
            in.close();
        }
        else if (inputSetting == 'C') { //for console input
            for (int i = 0; i < numOfStudents; ++i) {
                sOrig[i].Set();
                std::cout << std::endl;
            }
        }
        else {
            continue;
        }

        
        std::cout << "\nWhat do you want to do:" << std::endl
            << "1.Sort student by faculty" << std::endl
            << "2.Show " << std::endl
            << "3.Sort student by dateOfBirth" << std::endl;

        std::cin >> actionSetting;

        //output
        if (actionSetting == 1) { //Sort by faculty
            std::cout << "\nEnter the faculty: ";
            std::cin >> suitableFaculty;
            if (outputSetting == 'F') {
                std::ofstream out("Output.txt");
                for (int i = 0; i < numOfStudents; ++i) {
                    if (sOrig[i].SuitableFaculty(suitableFaculty)) {
                        out << sOrig[i].Get();
                    }
                }
                out.close();
            }
            else if (outputSetting == 'C') {
                for (int i = 0; i < numOfStudents; ++i) {
                    sOrig[i].Show();
                }
            }
        }
        else if (actionSetting == 2) { //Show
            if (outputSetting == 'F') {
                std::ofstream out("Output.txt");
                for (int i = 0; i < numOfStudents; ++i) {
                    out << sOrig[i].Get();
                }
                out.close();
            }
            else if (outputSetting == 'C') {
                for (int i = 0; i < numOfStudents; ++i) {
                    sOrig[i].Show();
                }
            }
            
        }
        else if (actionSetting == 3) { //Sort by date of birth
            std::cout << "\nEnter the date of birth: ";
            std::cin >> suitableDateOfBirth;
            if (outputSetting == 'F') {
                std::ofstream out("Output.txt");
                for (int i = 0; i < numOfStudents; ++i) {
                    if (sOrig[i].SuitableDateOfBirth(suitableDateOfBirth)) {
                        out << sOrig[i].Get();
                    }
                }
                out.close();
            }
            else if (outputSetting == 'C') {
                for (int i = 0; i < numOfStudents; ++i) {
                    sOrig[i].Show();
                }
            }
        }
        else {
            continue;
        }

        std::cout << "Do you want to exit (yes \"Y\" or no\"N\"): ";
        std::cin >> exitSetting;

        if (exitSetting == 'Y') {
            return 0;
        }

        delete[] sOrig;
    }
}