#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
    int id;
    std::string name;
    int age;
    std::string birthday;
    std::string profession;
    char gender;
};

std::vector<Person> people;

void registerPerson() {
    Person p;
    std::cout << "Enter ID (number): ";
    std::cin >> p.id;
    std::cout << "Enter Name(20 characters): ";
    std::cin >> p.name;
    std::cout << "Enter Age(Number): ";
    std::cin >> p.age;
    std::cout << "Enter Birthday(dd-mm-yy): ";
    std::cin >> p.birthday;
    std::cout << "Enter Profession: ";
    std::cin >> p.profession;
    std::cout << "Enter Gender (M/F): ";
    std::cin >> p.gender;

    people.push_back(p);
}

void showAllData() {
    std::cout << "All People Data:\n";
    for(const auto& person : people) {
        std::cout << "ID: " << person.id << ", Name: " << person.name << ", Age: " << person.age << ", Birthday: " << person.birthday << ", Profession: " << person.profession << ", Gender: " << person.gender << std::endl;
    }
}

void showDataByAge() {
   

    int count_above_50 = 0, count_above_40 = 0, count_below_40 = 0;

    for(const auto& person : people) {
        if(person.age > 50)
            count_above_50++;
        else if(person.age > 40)
            count_above_40++;
        else
            count_below_40++;
    }
    std::cout << "Count of people above 50: " << count_above_50 << std::endl;
    std::cout << "Count of people between 40 and 50: " << count_above_40 << std::endl;
    std::cout << "Count of people below 40: " << count_below_40 << std::endl;
}

void showDataByGender() {
    int count_male = 0, count_female = 0;
    std::cout << "Count of people by gender:\n";
    for(const auto& person : people) {
        if(person.gender == 'M')
            count_male++;
        else if(person.gender == 'F')
            count_female++;
    }
    std::cout << "Count of male: " << count_male << std::endl;
    std::cout << "Count of female: " << count_female << std::endl;
}


int main() {
    char choice;
    do {
        std::cout << "\n========= Menu ==========\n";
        std::cout << "1. Register\n";
        std::cout << "2. Show All Data\n";
        std::cout << "3. Show Data by Age\n";
        std::cout << "4. Show Data by Gender\n";
        std::cout << "0. Logout\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case '1':
                registerPerson();
                break;
            case '2':
                showAllData();
                break;
            case '3':
                showDataByAge();
                break;
            case '4':
                showDataByGender();
                break;
            case '0':
                std::cout << "Thank you for using our app. Logging out.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != '0');

    return 0;
}
