#include "product.h"
#include <algorithm>

Product::Product() {}

Product::~Product() {}

int Product::getNextId() {
    return nextId++;
}

void Product::addProduct(const std::string& name, double price, int quantity) {
    if (price < 0 || quantity < 0) {
        std::cout << "Помилка: ціна та кількість мають бути додатніми.\n";
        return;
    }
    products.push_back({ getNextId(), name, price, quantity });
}

void Product::displayProducts() const {
    for (const auto& product : products) {
        std::cout << "ID: " << product.id 
                  << ", Назва: " << product.name 
                  << ", Ціна: " << product.price 
                  << ", Кількість: " << product.quantity << std::endl;
    }
}

void Product::updateProduct(int id, const std::string& name, double price, int quantity) {
    for (auto& product : products) {
        if (product.id == id) {
            if (!name.empty()) product.name = name;
            if (price >= 0) product.price = price;
            else std::cout << "Ціна має бути додатнім числом.\n";
            if (quantity >= 0) product.quantity = quantity;
            else std::cout << "Кількість має бути додатнім числом.\n";
            return;
        }
    }
    std::cout << "Товар з ID " << id << " не знайдено.\n";
}

void Product::deleteProduct(int id) {
    products.erase(std::remove_if(products.begin(), products.end(),
                 [id](const product_s_t& product) { return product.id == id; }),
                 products.end());
}

void Product::clearProducts() {
    products.clear();
}
