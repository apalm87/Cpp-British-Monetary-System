#ifndef STERLING_H_
#define STERLING_H_

#include <iostream>

// Global variable for poundsign
const unsigned char kPoundSign = static_cast<unsigned char>(156); // £

class Sterling
{
private:
    //data items
    long pounds_;   //pounds
    int shills_;    //shillings: 20 per pound
    int pence_;     //pence: 12 per shilling
    std::string old_system_;  //13.18.1


public:
    //constructors
    Sterling(){pounds_ = 0; shills_ = 0; pence_ = 0;} //default
    Sterling(long pounds, int shills, int pence); //3-arg
    Sterling(const std::string &old_system); // 1-arg constructor old system
    Sterling(double decimal_pounds); //1-arg constructor dec pounds

    //getters
    long get_pounds() const {return pounds_;}
    int get_shills() const {return shills_;}
    int get_pence() const {return pence_;}
    const std::string& get_old_system() const {return old_system_;}

    //setters
    void set_pounds(long pounds);
    void set_shills(int shillings);
    void set_pence(int pence);
    void set_old_system(const std::string &sterling); //user types "7.10.6"

    //methods
    friend std::ostream& operator << (std::ostream &os, const Sterling &sterling);
    float decimal_pound();

    //overload operators
    bool operator == (const Sterling &rhs) const;
    bool operator != (const Sterling &rhs) const;
    Sterling operator + (Sterling s2) const;
    Sterling operator - (Sterling s2) const;
};

#endif /* !STERLING_H_ */
