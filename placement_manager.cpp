#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct student{
    string company_name;

    string name;
    string interview_date;
    string interview_status;
    string time_start;
    string time_end;
    int student_id;
    string email;
    string program;
    long long contact_no;
    long long whatsapp_no;
    long long alt_no;
    string skype_id;
};

void add_record (){
    fstream fout;

    student s;

    cout << "Interviewing Company Name : ";
    getline(cin, s.company_name);

    cout << "\n---:Enter student details:--- " << endl;

    cout << "Student Name: ";
    getline(cin, s.name);
    cout << "Interview Date: ";
    getline(cin, s.interview_date);
    cout << "Interview status (completed/not completed) :";
    getline(cin, s.interview_status);
    cout << "Interview start time : ";
    getline(cin, s.time_start);
    cout << "Interview end time : ";
    getline(cin, s.time_end);
    cout << "Student ID: ";
    cin >> s.student_id; cin.ignore();
    cout << "Email : ";
    getline(cin, s.email);
    cout << "Program enrolled : ";
    getline (cin, s.program);
    cout << "Contact Number: ";
    cin >> s.contact_no; cin.ignore();
    cout << "Whatsapp Number: ";
    cin >> s.whatsapp_no; cin.ignore();
    cout << "Alternate Number: ";
    cin >> s.alt_no; cin.ignore();
    cout << "Student Skype Id : ";
    getline(cin, s.skype_id);


    string file_name = "placement_data_" + s.company_name +".csv";
    
    ifstream file;
    file.open(file_name);
    fout.open(file_name, ios::out | ios::app);
    if (!fout.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }
    fout << s.name << ","
        << s.interview_date << ","
        << s.interview_status << ","
        << s.time_start << ","
        << s.time_end << ","
        << s.student_id << ","
        << s.email << ","
        << s.program << ","
        << s.contact_no << ","
        << s.whatsapp_no << ","
        << s.alt_no << ","
        << s.skype_id << "\n";

    cout << "Record added successfully!" << endl;
    fout.close();
    file.close();


}

void delete_record() {
    string comp_name;
    cout << "Enter company name: ";
    getline(cin, comp_name);


    string file_name = "placement_data_" + comp_name + ".csv";
    ifstream fin(file_name);
    if (!fin) {
        cout << "Error! File not found!" << endl;
        return;
    }

    string stud_id_to_delete;
    cout << "Enter student ID to delete: ";
    cin >> stud_id_to_delete;

    ofstream fout("temp.csv");

    string line;
    bool found = false;
    while (getline(fin, line)) {
        stringstream ss(line);
        vector<string> columns;
        string column;
        while (getline(ss, column, ',')) {
            columns.push_back(column);
        }
        if (columns.size() > 0 && columns[5] == stud_id_to_delete) {
            found = true;
            continue;
        }
        fout << line << "\n";
    }

    fin.close();
    fout.close();

    if (!found) {
        cout << "Student ID not found!" << endl;
        remove("temp.csv");
        return;
    }

    if (remove(file_name.c_str()) != 0) {
        cout << "Error: Unable to delete file." << endl;
        return;
    }
    if (rename("temp.csv", file_name.c_str()) != 0) {
        cout << "Error: Unable to rename file." << endl;
        return;
    }

    cout << "Record deleted successfully." << endl;

}

void display_record(){

    string comp_name;
    cout << "Enter company name: ";
    getline(cin, comp_name);
    string file_name = "placement_data_" + comp_name + ".csv";

    string stud_to_display;
    cout << "Enter student ID to display: ";
    cin >> stud_to_display;

    ifstream fin(file_name);
    if (!fin) {
        cout << "Error! File not found!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(fin, line)) {
        stringstream ss(line);
        vector<string> columns;
        string column;
        while (getline(ss, column, ',')) {
            columns.push_back(column);
        }
        if (columns.size() > 0 && columns[5] == stud_to_display) {
            found = true;
            cout << "Student Name : " << columns[0] << endl;
            cout << "Interview Date : " << columns[1] << endl;
            cout << "Interview Status : "  << columns[2] << endl;
            cout << "Interview Start Time : " << columns[3] << endl;
            cout << "Interview End Time : " << columns[4] << endl;
            cout << "Student ID : " << columns[5] << endl;
            cout << "Email : " << columns[6] << endl;
            cout << "Program enrolled : " << columns[7] << endl;
            cout << "Contact Number : " << columns[8] << endl;
            cout << "Whatsapp Number : " << columns[9] << endl;
            cout << "Alternate Number : " << columns[10] << endl;
            cout << "Skype ID : " << columns[11] << endl;
            break;
        }
    }

    fin.close();
    if (!found) {
        cout << "Student ID not found!" << endl;
    }
}

void update_record() {
    string comp_name;
    cout << "Enter company name: ";
    getline(cin, comp_name);

    string file_name = "placement_data_" + comp_name + ".csv";
    ifstream fin(file_name);
    if (!fin) {
        cout << "Error! File not Found!" << endl;
        return;
    }

    string stud_id_to_update;
    cout << "Enter student ID to update: ";
    cin >> stud_id_to_update;

    ofstream fout("temp.csv");

    string line;
    bool found = false;
    while (getline(fin, line)) {
        stringstream ss(line);
        vector<string> columns;
        string column;
        while (getline(ss, column, ',')) {
            columns.push_back(column);
        }
        if (columns.size() > 0 && columns[5] == stud_id_to_update) {
            found = true;

            student updated_student;
            updated_student.company_name = comp_name;
            cout << "Enter student details:\n";
            cout << "Student Name: ";
            cin.ignore();
            getline(cin, updated_student.name);
            cout << "Interview Date: ";
            getline(cin, updated_student.interview_date);
            cout << "Interview status (completed/not completed): ";
            getline(cin, updated_student.interview_status);
            cout << "Interview start time: ";
            getline(cin, updated_student.time_start);
            cout << "Interview end time: ";
            getline(cin, updated_student.time_end);
            cout << "Student ID: " << stud_id_to_update << endl;
            updated_student.student_id = stoi(stud_id_to_update);
            cout << "Email: ";
            getline(cin, updated_student.email);
            cout << "Program enrolled: ";
            getline(cin, updated_student.program);
            cout << "Contact Number: ";
            cin >> updated_student.contact_no;
            cout << "Whatsapp Number: ";
            cin >> updated_student.whatsapp_no;
            cout << "Alternate Number: ";
            cin >> updated_student.alt_no;
            cout << "Student Skype Id: ";
            cin.ignore();
            getline(cin, updated_student.skype_id);

            fout << updated_student.name << ","
                 << updated_student.interview_date << ","
                 << updated_student.interview_status << ","
                 << updated_student.time_start << ","
                 << updated_student.time_end << ","
                 << updated_student.student_id << ","
                 << updated_student.email << ","
                 << updated_student.program << ","
                 << updated_student.contact_no << ","
                 << updated_student.whatsapp_no << ","
                 << updated_student.alt_no << ","
                 << updated_student.skype_id << "\n";
        } else {
            fout << line << "\n";
        }
    }

    fin.close();
    fout.close();

    if (!found) {
        cout << "Student ID not found!" << endl;
        remove("temp.csv");
        return;
    }

    remove(file_name.c_str());
    rename("temp.csv", file_name.c_str());


    cout << "Record updated successfully." << endl;

}


int main(){

    int choice = 0;
    while (choice!= 5){
        cout << "===========================================\n";
        cout << "Welcome to the Placement Management System!\n";
        cout << "===========================================\n";
        cout << "1. Add record\n2. Update record\n3. Delete record\n4. Display record\n5. Exit\n";
        cout << "===========================================\n";
        cout << "Enter your choice : ";
        cin >> choice; cin.ignore();

        switch(choice){
            case(1):
                add_record(); break;
            case(2):
                update_record(); break;
            case(3):
                delete_record(); break;
            case(4):
                display_record(); break;
            case(5):
                cout << "Thanks for using!"; break;
            default:
                cout << "Invalid Input! Try Again!\n";
        }
    }

    return 0;
}
