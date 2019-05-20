#include <iostream>
using namespace std;

class ProductCategory
{
public:
    ProductCategory() {}
    // all getter and setters
private:
    string mCategoryName;
    string mCategoryDiscription;
};

class ProductReview
{
private:
    ProductReview() {}
    // all getters and setters
public:
    int mRating;
    string mReview;
    Account mReviewer;
};

class Product
{
public:
    Product() {}
    // all getters and setters
    getAvailableCount() {}
    bool updatePrice(double price) {}
private:
    string mProductId;
    string mProductName;
    string mProductDescription;
    double mPrice;
    ProductCategory mProductCategory;
    int availableItemCount;
    Account mSeller;
};

class Item
{
public:
    bool updateQuantity(int quantity) {}
private:
    string mProductId;
    int mQuantity;
    double mPrice;
};
