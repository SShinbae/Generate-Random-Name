// GenerateName.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <xlsxwriter.h>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

std::vector<std::string> ukFirstNames = { "Oliver", "Amelia", "Jack", "Olivia", "Harry", 
"Isla", "George", "Ava", "Noah", "Emily", "Charlie", "Poppy", "Jacob", "Mia", "Alfie", 
"Isabella", "Freddie", "Sophia", "Oscar", "Grace" , "Muhammad", "Ali", "Ahmed", "Omar", "Hassan", "Abdullah",
"Ibrahim", "Aadam", "Yusuf", "Zayd", "Mustafa", "Hamza", "Bilal", "Sulaiman", "Nasir", "Tariq",
"Rashid", "Jibril", "Ismail", "Khalid", "James", "Olivia", "Amelia", "Jack", "Isla", "George", 
"Sophie", "Harry", "Emily", "Wan", "Muhamad", "Abdul","Amsyar", "Nik", "Tengku"};

std::vector<std::string> ukLastNames = { "Smith", "Jones", "Williams", 
"Taylor", "Brown", "Davies", "Evans", "Patel", "Wilson", "Johnson", "Singh", "Wright",
"Robinson", "Thompson", "White", "Walker", "Edwards", "Green", "Hall", "Lewis" , "Fatima", "Aisha",
"Khadijah", "Mariam", "Layla","Zainab", "Safiya", "Sumayyah", "Amina", "Hana", "Fatimah", "Naima",
"Nour", "Sara", "Zahra", "Farida","Yasmin", "Huda", "Lubna", "Munira", "Davies", "Murphy", "Cooper", 
"Haziq", "Ahnaf", "Haikal", "Zuhairy","Azlan","Liyana", "Syarif", "Syerina", "Asraf", "Khairul", 
"Zuraidah", "Zuraini", "Masyitah", "Sabrina", "Najiah", "Mastura"};


// Function to generate a random string of specified length
std::string generateRandomString() {
    std::string firstName = ukFirstNames[rand() % ukFirstNames.size()];
    std::string lastName = ukLastNames[rand() % ukLastNames.size()];
    return firstName + " " + lastName;
    
}

int main() {

    srand(static_cast<unsigned>(time(0)));

    // Create a new Excel workbook and add a worksheet
    lxw_workbook* workbook = workbook_new("output.xlsx");
    lxw_worksheet* worksheet = workbook_add_worksheet(workbook, NULL);

    // Generate and write 10,000 records to the Excel file
    for (int i = 0; i < 10000; ++i) {
        int id = i + 1;
        std::string name = generateRandomString();
        int age = rand() % 30 + 19;
        std::string states[] = { "Selangor", "Malacca", "Johor", "Kedah", "Terengganu" };
        std::string state = states[rand() % 5];
        std::string departments[] = { "FTMK", "FTKEK", "FPTT" };
        std::string department = departments[rand() % 3];
        std::string roomFloors[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
        std::string roomFloor = roomFloors[rand() % 9];
        std::string paymentFees[] = {"RM1500" , "RM1000" , "RM500"};
        std::string paymentFee = paymentFees[rand() %3];

        // Write the record to the Excel file
        worksheet_write_number(worksheet, i, 0, id, NULL);
        worksheet_write_string(worksheet, i, 1, name.c_str(), NULL);
        worksheet_write_number(worksheet, i, 2, age, NULL);
        worksheet_write_string(worksheet, i, 3, state.c_str(), NULL);
        worksheet_write_string(worksheet, i, 4, department.c_str(), NULL);
        worksheet_write_string(worksheet, i, 5, roomFloor.c_str(), NULL);
        worksheet_write_string(worksheet, i, 6, paymentFee.c_str(), NULL);
    }

    // Close the workbook
    workbook_close(workbook);

    std::cout << "Data generation complete. Check 'output.xlsx' for the results." << std::endl;

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
