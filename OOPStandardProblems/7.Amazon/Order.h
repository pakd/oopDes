#include <iosteram>

using namespace std;


enum OrderStatus
{
    UNSHIPPED,
    PENDING,
    SHIPPED,
    COMPLETED,
    CANCELED,
    REFUND_APPLIED
};

struct Date
{
    int date;
    int month;
    int year;
};
class OrderLog
{
public:
private:

    String mOrderNumber;
    Date mCreationDate;
    OrderStatus mstatus;
}

class Order
{
public:
private:
    string mOrderNumber;
    OrderStatus mOrderStatus;
    Date mDate;
    list<OrderLog> mOrderLogs;

};
