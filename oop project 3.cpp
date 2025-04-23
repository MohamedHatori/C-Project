#include <iostream>
#include <vector>
using namespace std;
class Product
{
private:
    string name;
    double price;
    int quantity;
    int id;

public:
    Product(string n, double p, int q, int i) : name(n), price(p), quantity(q), id(i)
    {
    }
    void updateQuantity(int amount)
    {
        quantity += amount;
    }
    double totalPrice()
    {
        double total = price * quantity;
        return total;
    }
    int getQuantity() const
    {
        return quantity;
    }
    int getId() const
    {
        return id;
    }
    int getPrice() const
    {
        return price;
    }
    string getName() const
    {
        return name;
    }
    void displayInfo()
    {
        cout << "- name = " << name << "\n"
             << "- price = " << price << "$\n"
             << "- id = " << id << "\n"
             << "- Quantity = " << quantity << endl
             << "-Total price = " << totalPrice() << "$\n";
    }
};
class Inventory
{
private:
    vector<Product> products;

public:
    void addProduct(Product p)
    {
        products.push_back(p);
    }
    // void deletaProduct(Product p)
    // {
    //     products.erase(p);
    // }
    void getQuantity(int id)
    {
        for (const auto &product : products)
        {
            if (product.getId() == id)
            {
                cout << "The Product that has id " << id << " Avalible with " << product.getQuantity() << " Quanties\n";
            }
        }
    }
    bool searchProduct()
    {
        string choice;
        cout << "Enter The product Name you want to search" << endl;
        cin >> choice;
        for (const auto &product : products)
        {
            if (product.getName() == choice)
            {
                cout << choice << " is available\n";
                return true;
            }
        }
        cout << choice << " is not available\n";
        return false;
    }
    void getReport()
    {
        cout << "Available Products:\n";
        for (int i = 0; i < products.size(); i++)
        {
            cout << "| -name = " << products[i].getName();
            cout << "| -quantity = " << products[i].getQuantity();
            cout << "| -id = " << products[i].getId();
            cout << "| -price = " << products[i].getPrice() << "$\n";
            cout << "===================================\n";
        }
    }

    Product *findProductById(int id)
    {
        for (auto &product : products)
        {
            if (product.getId() == id)
            {
                return &product; // رجعنا pointer للمنتج اللي لقيناه
            }
        }
        return nullptr; // لو مفيش منتج بالـ id ده
    }
};
class Order
{
private:
    string name;
    string date;
    int id;
    vector<Product> products;
    string order_Type;
    double totalCost;

public:
    Order(string d, int i, string ot) : date(d), id(i), order_Type(ot)
    {
    }
    void addProduct(Product product)
    {
        products.push_back(product);
    }
    double calculateTotalCost()
    {
        double totalCost = 0;
        for (auto &p : products)
        {
            totalCost += p.getPrice() * p.getQuantity();
            return totalCost;
        }
    }
    void executeOrder(Inventory &inv)
    {
        for (auto &p : products)
        {
            Product *instock = inv.findProductById(p.getId());
            if (instock)
            {
                int change = (order_Type == "sale") ? p.getQuantity() : p.getQuantity();
                instock->updateQuantity(change);
            }
        }
    }
    void displayOrder()
    {
        cout << "Order ID: " << id << "\nDate: " << date << "\nOrder Type: " << order_Type << endl;
        cout << "Products:\n";
        cout << "=======================\n";
        for (auto d : products)
        {
            cout << "Order name: " << d.getName() << endl;
            cout << "Order id: " << d.getId() << endl;
            cout << "Order Quantity: " << d.getQuantity() << endl;
            cout << "Order price: " << d.getPrice() * d.getQuantity() << endl;
            cout << "=========================\n";
        }
    }
};
int main()
{
    Inventory inv;
    Product p1("Laptop", 1000.0, 3, 1);
    Product p2("Mouse", 50.0, 5, 2);
    inv.addProduct(p1);
    inv.addProduct(p2);
    cout << "\nInventory before order:\n";
    inv.getReport();
    Order order1("20/4/2024", 1, "sale");
    order1.addProduct(Product("Labtob", 1000.0, 2, 1));
    order1.addProduct(Product("Mouse", 1000.0, 3, 1));
    cout << "\nOrder details:\n";
    order1.displayOrder();
    order1.executeOrder(inv);
    cout << "\nInventory after order:\n";
    inv.getReport();

    return 0;
}
