#include <iostream>
#include <string>

class Product {
public:

    Product() : name(""), price(0.0), quantity(0) {}


    Product(const std::string& name, double price, int quantity) {
        setName(name);
        setPrice(price);
        setQuantity(quantity);
    }


    ~Product() {}


    void input() {
        std::cout << "Enter product name: ";
        std::cin >> name;
        std::cout << "Enter price: ";
        double p;
        std::cin >> p;
        setPrice(p);
        std::cout << "Enter quantity: ";
        int q;
        std::cin >> q;
        setQuantity(q);
    }

    void output() const {
        std::cout << "Product Name: " << name
                  << ", Price: " << price
                  << ", Quantity: " << quantity << std::endl;
    }


    void setName(const std::string& name) { this->name = name; }

    void setPrice(double price) {
        if (price >= 0.0) {
            this->price = price;
        } else {
            std::cout << "Invalid price! Must be non-negative." << std::endl;
        }
    }

    void setQuantity(int quantity) {
        if (quantity >= 0) {
            this->quantity = quantity;
        } else {
            std::cout << "Invalid quantity! Must be non-negative." << std::endl;
        }
    }

private:
    std::string name;
    double price;
    int quantity;
};

int main() {

    Product product;


    product.input();


    std::cout << "Product details:" << std::endl;
    product.output();

    return 0;
}
