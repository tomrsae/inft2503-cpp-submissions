#include "commodity.hpp"

Commodity::Commodity(std::string name, int id, double price)
    : m_name(name), m_id(id), m_price(price)
{ }

std::string Commodity::get_name() const {
    return m_name;
}

int Commodity::get_id() const {
    return m_id;
}

double Commodity::get_price(double quantity) const {
    return m_price * quantity;
}

double Commodity::get_price_with_sales_tax(double quantity) const {
    double price_with_tax = m_price * (1 + TAX);
    return price_with_tax * quantity;
}

void Commodity::set_price(double price) {
    m_price = price;
}