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

void Product::insertProduct(int position, const std::string& name, double price, int quantity) {
    if (position < 0 || position > products.size()) {
        std::cout << "Некоректна позиція для вставки.\n";
        return;
    }
    if (price < 0 || quantity < 0) {
        std::cout << "Ціна та кількість мають бути додатніми.\n";
        return;
    }
    products.insert(products.begin() + position, { getNextId(), name, price, quantity });
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

void Product::swapProducts(int id1, int id2) {
    auto it1 = std::find_if(products.begin(), products.end(), [id1](const product_s_t& p) { return p.id == id1; });
    auto it2 = std::find_if(products.begin(), products.end(), [id2](const product_s_t& p) { return p.id == id2; });

    if (it1 != products.end() && it2 != products.end()) {
        std::swap(*it1, *it2);
    } else {
        std::cout << "Товар з одним із вказаних ID не знайдено.\n";
    }
}

