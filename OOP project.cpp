#include <iostream>
#include <vector>
using namespace std;
class Dish
{
private:
    string name;
    int price;

public:
    Dish(string n, double p) : name(n), price(p)
    {
    }
    string getName()
    {
        return name;
    }
    double getPrice()
    {
        return price;
    }
};
class Menu
{
private:
    vector<Dish> dishes;

public:
    void addDish(Dish d)
    {
        dishes.push_back(d);
    }
    void display()
    {
        cout << "The Dishes That Avalibale in Our Resturant are \n";
        for (int i = 0; i < dishes.size(); i++)
        {
            cout << "- " << dishes[i].getName() << " | price: " << dishes[i].getPrice() << "$\n";
        }
    }
    vector<Dish> getDishes()
    {
        return dishes;
    }
};
class Customer

{
private:
    string name;
    int tableNumber;

public:
    Customer()
    {
        cout << "Enter your name" << endl;
        cin >> name;
        cout << "Enter your table number" << endl;
        cin >> tableNumber;
    }
    string getName1()
    {
        return name;
    }
    int getTable()
    {
        return tableNumber;
    }
    void print()
    {
        cout << "- " << name << "| TableNumber " << tableNumber << endl;
    }
};
class Order
{
private:
    Customer coustmer;
    vector<Dish> orderDishes;

public:
    Order(const Customer &c) : coustmer(c)
    {
    }
    void addDishToOrder(Dish dish)
    {
        orderDishes.push_back(dish);
    }
    void displayOrder()
    {
        cout << "\nOrder For " << coustmer.getName1() << " (Table " << coustmer.getTable() << ") \n";
        for (int i = 0; i < orderDishes.size(); i++)
        {
            cout << "- " << orderDishes[i].getName() << "|Price " << orderDishes[i].getPrice() << "$ \n";
        }
        double total = 0;
        for (int i = 0; i < orderDishes.size(); i++)
        {
            total += orderDishes[i].getPrice();
        }
        cout << "Total price is " << total << "$\n";
    }
};
class ResturantSystem
{
private:
    Menu menu;

public:
    // add menu
    ResturantSystem()
    {
        menu.addDish(Dish("pizza", 20));
        menu.addDish(Dish("Juice", 5));
        menu.addDish(Dish("Burger", 25));
        menu.addDish(Dish("Rice", 10));
    }
    // رسالة ترحيبة وعرض الاكلات
    void Run()
    {
        cout << "========== Welcome to Our Restaurant ==========\n";
        menu.display();
        // ادخال بيانات الزبون
        Customer customer;
        // انشاء الطلب
        Order Order(customer);
        // اختيار الطلب
        char choice;
        do
        {
            string dishname;
            cout << "Enter your dishName" << endl;
            cin >> dishname;

            bool found = false;
            for (Dish d : menu.getDishes())
            {
                if (d.getName() == dishname)
                {
                    Order.addDishToOrder(d);
                }
                found = true;
                break;
            }
            if (!found)
            {
                cout << "Sorry, we don't have this dish.\n";
            }
            cout << "Do you want to order another dish? (y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
        Order.displayOrder();
    }
};
int main()
{
    ResturantSystem ob1;
    ob1.Run();
    return 0;
}
