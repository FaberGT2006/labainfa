#include "Database.h"
#include <algorithm>


ofstream& operator<<(ofstream& os, const Product& product)
{
    os << product.id << " " << product.name << " " << product.price << " " << product.count;
    return os;
}

ifstream& operator>>(ifstream& is, Product& product)
{
    is >> product.id >> product.name >> product.price >> product.count;
    return is;
}

void Database::resize(int newCapacity)
{
    Product* newArray = new Product[newCapacity];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = products[i];
    }

    delete[] products;

    products = newArray;
    capacity = newCapacity;
}


void Database::load()
{
    size = 0;

    ifstream infile(filename);
    if (!infile) return;

    Product temp;

    while (infile >> temp)
    {
        if (size >= capacity)
        {
            resize(capacity * 2);
        }
        products[size++] = temp;
    }

    infile.close();
}

void Database::save()
{
    ofstream outfile(filename);

    for (int i = 0; i < size; i++)
    {
        outfile << products[i] << "\n";
    }

    outfile.close();
}

void Database::display()
{
    if (size == 0)
    {
        cout << "Databass is empty" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        cout << "ID: " << products[i].getId() << endl
            << "Name: " << products[i].getName() << endl
            << "Price: " << products[i].getPrice() << endl
            << "Count: " << products[i].getCount() << endl
            << "----------------------------------------" << endl;
    }
}

void Database::addProduct()
{
    int id, count;
    string name;
    double price;

    cout << "Input ID: ";
    cin >> id;

    cout << "Input count: ";
    cin >> count;

    cout << "Input name: ";
    cin >> name;

    cout << "Input price ";
    cin >> price;

    Product p(id, name, price, count);

    if (size >= capacity)
    {
        resize(capacity * 2);
    }

    products[size++] = p;

    save();
}

void Database::editProduct()
{
    int id;
    cout << "Input I product: " << endl;
    cin >> id;

    for (int i = 0; i < size; i++)
    {
        if (products[i].getId() == id)
        {
            string name;
            int count;
            double price;

            cout << "Edit product with ID " << id << ":" << endl;
            cout << "Input new name: ";
            cin >> name;
            cout << "Input new price: ";
            cin >> price;
            cout << "Input new count: ";
            cin >> count;

            products[i].setName(name);
            products[i].setPrice(price);
            products[i].setCount(count);
            save();

            cout << "Proucts is updated" << endl;
            return;
        }
    }
    cout << "This element is not find " << endl;
}

void Database::deleteProduct()
{
    int id;
    cout << "Input ID if product to delete: " << endl;
    cin >> id;

    for (int i = 0; i < size; i++)
    {
        if (products[i].getId() == id)
        {
            for (int j = i; j < size-1; j++)
            {
                products[j] = products[j + 1];
            }
            size--;
            save();
            cout << "Delete product";
            return;
        }
    }

    cout << "This element is not find " << endl;
}

void Database::search(double minPrice, double maxPrice)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (products[i].getPrice() >= minPrice &&
            products[i].getPrice() <= maxPrice)
        {
            cout << "----------------------" << endl;
            cout << "ID: " << products[i].getId() << endl;
            cout << "Name: " << products[i].getName() << endl;
            cout << "Price: " << products[i].getPrice() << endl;
            cout << "Count: " << products[i].getCount() << endl;
            found = true;
        }
    }

    if (found == false)
    {
        cout << "This element is not find " << endl;
    }
}