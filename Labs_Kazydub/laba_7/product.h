#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>
#include <iostream>

struct product_s_t {
    int id;
    std::string name;
    double price;
    int quantity;
};

class Product {
private:
    std::vector<product_s_t> products;
    int nextId = 1;

    int getNextId();  // Генерація унікального ID

public:
    Product();
    ~Product();
    
    void addProduct(const std::string& name, double price, int quantity);
    void displayProducts() const;
    void updateProduct(int id, const std::string& name, double price, int quantity);
    void deleteProduct(int id);
    void clearProducts();
};

#endif