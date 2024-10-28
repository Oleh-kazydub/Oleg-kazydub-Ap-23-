#include <iostream>
#include <vector>
#include <string>

class Product {
public:
    // Конструктор за замовчуванням
    Product() : name(""), price(0.0), quantity(0) {}

    // Конструктор з параметрами
    Product(const std::string& name, double price, int quantity) {
        setName(name);
        setPrice(price);
        setQuantity(quantity);
    }

    // Деструктор
    ~Product() {}

    // Методи для введення і виведення даних
    void input() {
        std::cout << "Enter product name: ";
        std::getline(std::cin >> std::ws, name); // Use std::getline to read the name
        std::cout << "Enter product price: ";
        std::cin >> price;
        std::cout << "Enter product quantity: ";
        std::cin >> quantity;
    }

    void output() const {
        std::cout << "Product Name: " << name 
                  << ", Price: " << price 
                  << ", Quantity: " << quantity << std::endl;
    }

    // Методи для валідації
    void setName(const std::string& name) { this->name = name; }
    
    void setPrice(double price) {
        if (price >= 0.0) {
            this->price = price;
        } else {
            std::cout << "Invalid price!" << std::endl;
        }
    }

    void setQuantity(int quantity) {
        if (quantity >= 0) {
            this->quantity = quantity;
        } else {
            std::cout << "Invalid quantity!" << std::endl;
        }
    }

    // Метод для виведення інформації за критерієм (фільтрація за ціною)
    static void filterProducts(const std::vector<Product>& products, double priceFilter) {
        bool found = false;
        for (const auto& product : products) {
            if (product.price >= priceFilter) {
                product.output();
                found = true;
            }
        }
        if (!found) {
            std::cout << "No products found with price >= " << priceFilter << "." << std::endl;
        }
    }

private:
    std::string name;
    double price;
    int quantity;
};

int main() {
    std::vector<Product> products;
    
    // Створення кількох товарів
    products.emplace_back("Laptop", 1500.99, 10);
    products.emplace_back("Smartphone", 999.50, 15);
    products.emplace_back("Headphones", 199.99, 25);

    // Введення даних нового товару
    Product newProduct;
    newProduct.input();
    products.push_back(newProduct);

    // Виведення інформації про товари, ціна яких більше або дорівнює 500
    std::cout << "Products with price >= 500:" << std::endl;
    Product::filterProducts(products, 500);

    return 0;
}

