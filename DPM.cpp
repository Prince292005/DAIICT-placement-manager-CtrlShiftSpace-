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

void parseCSVLine(const string &line, Student students[], Company companies[], ProgramStats programStats[], int &numStudents, int &numCompanies, int &numPrograms)
{
    stringstream ss(line);
    string cell;

    getline(ss, students[numStudents].fullName, ',');
    getline(ss, students[numStudents].lastName, ','); // Read the program name
    getline(ss, cell, ',');
    students[numStudents].selected = (cell == "p");
    getline(ss, cell, ',');
    try
    {
        students[numStudents].roundsPassed = stoi(cell);
    }
    catch (const std::invalid_argument &e)
    {
        cerr << "Invalid value for roundsPassed. Setting to default (0)." << endl;
        students[numStudents].roundsPassed = 0; // Default value
    }
    getline(ss, cell, ','); // Reading company name
  // Update program statistics
    bool foundProgram = false;
    for (int i = 0; i < numPrograms; i++)
    {
        if (programStats[i].program == students[numStudents].lastName)
        {
            foundProgram = true;
            if (students[numStudents].selected)
                programStats[i].selectedCount++;
                
            else
                programStats[i].unselectedCount++;
            break;
        }
    }



int main()
{
    // Writing to the CSV file
    char first_name[30];
    char last_name[30];
    char programme_enrolled[30];
    char interview_date[20];
    char company[20];
    char result[2];
    char email[50];
    long long contact_number;

    ofstream savedFile;
    savedFile.open("placement_data.csv", ios::app);

    cout << "Please input Student Details : ---" << endl;

    cout << "Enter your first name : " << endl;
    cin.getline(first_name, 30);

    cout << "Enter your Last name : " << endl;
    cin.getline(last_name, 30);

    cout << "Enter your Programme : " << endl;
    cin.getline(programme_enrolled, 30);

    cout << "Enter your Interview_date : " << endl;
    cin.getline(interview_date, 20);

    cout << "Enter visited Company Name : " << endl;
    cin.getline(company, 20);

    cout << "Enter Result (P/F) : " << endl;
    cin.getline(result, 2);

    cout << "Enter Email ID : " << endl;
    cin.getline(email, 50);

    cout << "Enter contact number : " << endl;
    cin >> contact_number;
    cin.ignore();
    cout << endl;

    savedFile << first_name << "," << last_name << "," << programme_enrolled << "," << interview_date << "," << company << "," << result << "," << email << "," << contact_number << endl;

    savedFile.close();

    // Reading from the CSV file and processing data
    ifstream file("placement_data.csv");
    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string header;
    getline(file, header);

    Student students[MAX_STUDENTS];
    Company companies[MAX_COMPANIES];
    ProgramStats programStats[MAX_PROGRAMS];
    int numStudents = 0, numCompanies = 0, numPrograms = 0;

    string line;
    while (getline(file, line))
    {
        parseCSVLine(line, students, companies, programStats, numStudents, numCompanies, numPrograms);
    }

    file.close();

    exportToCSV(programStats, companies, numPrograms, numCompanies);

    cout << "Values saved in placement_data.csv" << endl;
    cout << "Placement summary exported to placement_summary.csv" << endl;

    return 0;
}



