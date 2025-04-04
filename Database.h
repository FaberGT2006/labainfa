#ifndef DATABASE_HEADER
#define DATABASE_HEADER

#include <iostream>
#include <string> 
#include <fstream>

using namespace std;

class Product
{
private:
    int id;
    string name;
    double price;
    int count;

public:
    Product(int id, string name, double price, int count)
    {
        this->id = id;
        this->name = name;
        this->price = price;
        this->count = count;
    }

    Product() : id(0), name(""), price(0), count(0) {};

    int getId()
    {
        return id;
    }
    void setId(int id)
    {
        this->id = id;
    }

    string getName()
    {
        return name;
    }
    void setName(string n)
    {
        name = n;
    }

    double getPrice()
    {
        return price;
    }
    void setPrice(double p)
    {
        price = p;
    }

    int getCount()
    {
        return count;
    }
    void setCount(int c)
    {
        count = c;
    }


    friend ofstream& operator<<(ofstream& os, const Product& product);
    friend ifstream& operator>>(ifstream& is, Product& product);

};


class Database
{
private:
    Product* products;
    int size; // текущее кол-во товаров
    int capacity; // максимальное вместить массива
    string filename;

public:
    Database(string filename)
    {
        capacity = 1;
        size = 0;
        products = new Product[capacity];
        this->filename = filename;
    }

    void resize(int newCapacity);

    void load();

    void save();

    void display();

    void addProduct();

    void editProduct();

    void deleteProduct();

    void search(double minPrice, double maxPrice);
};

#endif


