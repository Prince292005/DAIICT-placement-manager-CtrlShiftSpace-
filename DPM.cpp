#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_COMPANIES = 100;
const int MAX_PROGRAMS = 100;

struct Student
{
    string fullName;
    string lastName;
    bool selected;
    int roundsPassed;
};

struct Company
{
    string name;
    int placements[1]; // Assuming only one year for simplicity
};

struct ProgramStats
{
    string program;
    int selectedCount;
    int unselectedCount;
};



