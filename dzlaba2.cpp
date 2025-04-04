#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "Database.h"

using namespace std;

int main() {
    Database db("C:/test/database.txt");
    int choice = 0;

    while (true) {
        cout << "1. Add a product" << endl;
        cout << "2. Delete a product" << endl;
        cout << "3. Display a list of products" << endl;
        cout << "4. Search for a product" << endl;
        cout << "5. Change the information about the product" << endl;
        cout << "6. Exit" << endl;
        cout << "Your choice: ";

        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wrong choice. Try again." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            db.addProduct();
            break;
        case 2:
            db.deleteProduct();
            break;
        case 3:
            db.display();
            break;
        case 4:
            db.search(10, 20);
            break;
        case 5:
            db.editProduct();
            break;
        case 6:
            cout << "Exiting program." << endl;
            return 0;
        }
    }
}
