#include<iostream>
using namespace std;

class Item
{
public:
    bool updateQuantity(int quantity) {}
private:
    string mProductId;
    int mQuantity;
    double mPrice;
};


class ShoppingCart
{
public:
    ShoppingCart() {}
    bool addItem(Item* item) {}
    bool removeItem(Item* item) {}
    bool updateItemQuantity(Item* item, int quantity) {}
    bool checkout() {}
    list<Item*> getItems() {}

private:
    list<Item> mItems;
};
