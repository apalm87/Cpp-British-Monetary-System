#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "sterling.h"
using namespace std;

/**
 * @brief function to set pounds
 * @param pounds
 */
void Sterling::set_pounds(long pounds)
{
    pounds_ = pounds;
}

/**
 * @brief function to set shills
 * @param shillings
 * @brief while loop if shillings >= 20, while loop is active it will add 1 to
 * pounds and subtract 20 from shillings
 */
void Sterling::set_shills(int shillings)
{
    shills_ = shillings;
    while (shills_ >=20)
    {
        pounds_++;
        shills_ -= 20;
    }
}

/**
 * @brief function to set pence
 * @param pence
 * @brief while loop if pence >=20, nested if statement if shills >=20
 */
void Sterling::set_pence(int pence)
{
    pence_ = pence;
    while (pence_ >=12)
    {
        shills_++;
        if(shills_ >=20)
        {
            pounds_++;
            shills_ -= 20;
        }
        pence_ -= 12;
    }
}

/**
 * @brief function to set old system
 * @param sterling
 */
void Sterling::set_old_system(const std::string &sterling)
{
    old_system_ = sterling;
}

/**
 * @brief 3-arg constructor to set pounds, shills, pence
 * @param pounds
 * @param shills
 * @param pence
 */
Sterling::Sterling(long pounds, int shills, int pence)
{
    set_pounds(pounds);
    set_shills(shills);
    set_pence(pence);
}

/**
 * @brief setting old_system_ string and pounds_, shills-, and pence_ as int
 * @param old_system
 */
Sterling::Sterling(const std::string &old_system)
{
    int period = old_system.find('.'); //first period
    int last_period = old_system.find_last_of('.'); //second period
    int length = old_system.size();
    old_system_ = old_system;
    pounds_ = stoi(old_system.substr(0, period));
    shills_ = stoi(old_system.substr(period +1, period));
    pence_ = stoi(old_system.substr(last_period +1,length));

}

/**
 * @brief converting decimal pounds to old system
 * @param decimal_pounds
 */
Sterling::Sterling(double decimal_pounds)
{
    cout << fixed << setprecision(2);
    int pounds = floor(decimal_pounds);
    double fractional_part = decimal_pounds - pounds;
    double decimal_shillings = fractional_part * 20;
    int shillings = floor(decimal_shillings);
    int pence = floor((decimal_shillings - shillings) * 12);
    set_pounds(pounds);
    set_shills(shillings);
    set_pence(pence);
}

/**
 * @brief decimal pound formula
 * @return
 */
float Sterling::decimal_pound()
{
    float decimal_pound = pounds_ + shills_/20.0 +pence_/240;

    return decimal_pound;
}

/**
 * @brief function to print in a specifiec format
 * @param os
 * @param sterling
 * @return
 */
std::ostream& operator << (std::ostream &os, const Sterling &sterling)
{
    os << "pounds: " << sterling.pounds_ << " shills: " << sterling.shills_
    << " pence: " << sterling.pence_;
    return os;
}

/**
 * @brief overload function for !=
 * @param rhs
 * @return
 */
bool Sterling::operator!=(const Sterling &rhs) const
{
    return ((pounds_ != rhs.pounds_)||(shills_!=rhs.shills_)||
            (pence_!=rhs.pence_)) ? true : false;
}

/**
 * @brief overload function for ==
 * @param rhs
 * @return
 */
bool Sterling::operator==(const Sterling &rhs) const
{
    return ((pounds_ == rhs.pounds_)&&(shills_==rhs.shills_)&&
            (pence_==rhs.pence_)) ? true : false;
}

/**
 * @brief Overload operator for +
 * @param s2
 * @return
 */
Sterling Sterling::operator+(Sterling s2) const
{
    double pounds_value = pounds_ + s2.pounds_;
    double shills_value = shills_ + s2.shills_;
    double pence_value = pence_ + s2.pence_;
    return Sterling(pounds_value, shills_value, pence_value);
}

/**
 * @brief Overload operator for -
 * @param s2
 * @return
 */
Sterling Sterling::operator-(Sterling s2) const
{
    double pounds_value = pounds_ - s2.pounds_;
    double shills_value = shills_ - s2.shills_;
    double pence_value = pence_ - s2.pence_;
    return Sterling(pounds_value, shills_value, pence_value);
}



