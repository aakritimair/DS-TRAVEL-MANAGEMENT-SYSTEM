#include <iostream>
#include <cstdlib>
#include <cstring>

// Defining Structure
struct Node {
    char name[20];
    char gen[6];
    int age;
    Node* link;
};

Node* start = nullptr;

// Declaring Functions Used In This Program
void heading();
void details();
void inter();
void india();
void receipt();

// Global variables
int k, amount;
char type[60], place[30], date[20];

// Function to add details in node for each passenger
void add_node(const char* lol, const char* der, int b) {
    Node* newptr = new Node;
    strcpy(newptr->name, lol);
    strcpy(newptr->gen, der);
    newptr->age = b;
    newptr->link = nullptr;

    if (start == nullptr)
        start = newptr;
    else {
        Node* ptr = start;
        while (ptr->link != nullptr)
            ptr = ptr->link;
        ptr->link = newptr;
    }
}

// Function For Printing Heading Of Portal
void heading() {
    std::cout << "\t\t\t\t***Tourism Package Management System***\n";
    std::cout << "\t\t\t***Vaccination Certificate Is Necessary For Travel Purpose***\n\n";
}

// Function To Take Package Choice From India
void india() {
    int a;

    // Clearing Screen
    system("cls");

    // Calling heading() function
    heading();
    strcpy(type, "India Tour Package");
    std::cout << "\t\t\t\t1. Shimla Tour Packages    6 Days 7 Nights (18880/-)\n";
    std::cout << "\t\t\t\t2. Kashmir Tour Packages 5 Days 4 Nights (35500/-)\n";
    std::cout << "\t\t\t\t3. Kolkata Tour Packages 11 Days 10 Nights (10000/-)\n";
    std::cout << "\t\t\t\tEnter Choice: ";
    std::cin >> a;

    if (a == 1) {
        strcpy(place, "Shimla Tour");
        amount = 18880;
    }
    else if (a == 2) {
        strcpy(place, "Kashmir Tour");
        amount = 35500;
    }
    else if (a == 3) {
        strcpy(place, "Kolkata Tour");
        amount = 10000;
    }
    else
        std::cout << "Enter Correct Choice...\n";
}

// Function To Take Package Choice From International
void inter() {
    int a;

    // Clearing Screen
    system("cls");

    // Calling heading() function
    heading();
    strcpy(type, "International Tour Package");
    std::cout << "\t\t\t\t1. England Tour Packages 6 Days 7 Nights (28880/-)\n";
    std::cout << "\t\t\t\t2. Thailand Tour Packages 5 Days 4 Nights (15500/-)\n";
    std::cout << "\t\t\t\t3. New York Tour Packages 11 Days 10 Nights (567800/-)\n";
    std::cout << "\t\t\t\tEnter Choice: ";
    std::cin >> a;

    if (a == 1) {
        strcpy(place, "England Tour");
        amount = 28880;
    }
    else if (a == 2) {
        strcpy(place, "Thailand Tour");
        amount = 15500;
    }
    else if (a == 3) {
        strcpy(place, "New York Tour");
        amount = 567800;
    }
    else
        std::cout << "Enter Correct Choice...\n";
}

// Function To Take Passenger Details
void details() {
    int i, a;
    char val[20], gen[6];

    // Clearing Screen
    system("cls");

    // Calling heading() function
    heading();
    std::cout << "\t\t\t\tEnter Number Of Passengers: ";
    std::cin >> k;
    std::cout << "\t\t\t\tEnter Date (DD/MM/YY): ";
    std::cin >> date;

    for (i = 1; i <= k; i++) {
        system("cls");
        heading();
        std::cout << "\t\t\t\tEnter The " << i << "th Passenger Name: ";
        std::cin.ignore();
        std::cin.getline(val, 20);
        std::cout << "\t\t\t\tEnter The " << i << "th Passenger Gender: ";
        std::cin.getline(gen, 6);
        std::cout << "\t\t\t\tEnter The " << i << "th Passenger Age: ";
        std::cin >> a;

        // Calling add_node() function
        add_node(val, gen, a);
    }
}

// Function For Printing Receipt
void receipt() {
    int i, b;
    Node* ptr = start;
    system("cls");
    heading();
    std::cout << "\n\t\t\t\t**Take Screenshot For Further Use**\n";

    for (i = 1; i <= k; i++) {
        std::cout << "\t\t\t\t" << i << "st Passenger Name: " << ptr->name << "\n";
        std::cout << "\t\t\t\t" << i << "st Passenger Gender: " << ptr->gen << "\n";
        std::cout << "\t\t\t\t" << i << "st Passenger Age: " << ptr->age << "\n\n";
        ptr = ptr->link;
    }

    std::cout << "\t\t\t\tSelected Type: " << type << "\n";
    std::cout << "\t\t\t\tPackage: " << place << "\n";
    std::cout << "\t\t\t\tDate: " << date << "\n";
    b = amount * k;
    std::cout << "\t\t\t\tTotal Amount: " << b << "\n";
    std::cout << "\n\t\t\t\t**Thank You For Registration**\n";
}

// Driver Code
int main() {
    int a;

    // Calling heading() function
    heading();

    // Taking Choice From User
    std::cout << "\t\t\t\t1. International Tour Packages\n";
    std::cout << "\t\t\t\t2. India Tour Packages\n";
    std::cout << "\t\t\t\tEnter Choice: ";
    std::cin >> a;

    switch (a) {
        // Calling inter() function
        case 1:
            inter();
            break;

        // Calling india() function
        case 2:
            india();
            break;

        default:
            std::cout << "Enter Right Choice...\n";
            break;
    }

    // Calling details() function
    details();

    // Calling receipt() function
    receipt();

    return 0;
}
