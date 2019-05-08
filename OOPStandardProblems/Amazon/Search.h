#include <iostream>
using namespace std;



class Search
{
public:
    list<Product> searchProductByName(string name);
    list<Product> searchProductByCategory(string name);

private:
    map<string, list<Product>> mProductNames;
    map<string, list<Product>> mProductCategories;
};
