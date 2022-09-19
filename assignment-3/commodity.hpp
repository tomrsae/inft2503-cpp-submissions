#include <string>

const double TAX = 0.25;

class Commodity {
public:
    Commodity(std::string, int, double);

    std::string get_name() const;
    int get_id() const;
    double get_price(double = 1) const;
    double get_price_with_sales_tax(double = 1) const;

    void set_price(double price);
private:
    std::string m_name;
    int m_id;
    double m_price;
};