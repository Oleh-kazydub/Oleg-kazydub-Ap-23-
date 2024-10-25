#include <string>
#include <array>
#include <iostream>

const int SIZE = 5;  // Кількість товарів

// Оголошення структури product_s_t
struct product_s_t {
    int id;
    std::string name;
    double price;
    int quantity;
};
// Оголошення класу Product
class Product {
public:
    // Конструктор та деструктор
    Product();
    ~Product();
    // Методи для введення та виведення даних
    void input();
    void output() const;
    // Метод для перевірки і зміни даних
    void setPrice(double price);
    void setName(const std::string& name);
    void setId(int id);
    void setQuantity(int quantity);
private:
    std::array<product_s_t, SIZE> products;  // Масив товарів
};
