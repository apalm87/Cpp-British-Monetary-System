#include <iostream>
using namespace std;
#include "sterling.h"

int main()
{
    //part I
    cout << "Part I\n";
    Sterling s1;
    cout << "Constructor with no arguments gives you: \n";
    cout << "Pounds: " << s1.get_pounds() << " Shilling: " << s1.get_shills()
         << " pence: " << s1.get_pence() << endl << endl;

    Sterling s2 (12, 18, 9);
    cout << "Constructor with three arguments (" << s2.get_pounds() << ", "
         << s2.get_shills() << ", " << s2.get_pence() << ") gives you: \n";
    cout << "Pounds: " << s2.get_pounds() << " Shilling: " << s2.get_shills()
         << " pence: " << s2.get_pence() << endl << endl;

    long pounds = 12;
    int shills = 48, pence = 29;
    Sterling s3 (pounds,shills,pence);
    cout << "Constructor with three arguments (" << pounds << ", "
         << shills << ", " << pence << ") gives you: \n";
    cout << "Pounds: " << s3.get_pounds() << " Shilling: " << s3.get_shills()
         << " pence: " << s3.get_pence() << endl << endl;

    //part II
    cout << "Part II\n";
    Sterling s4("12.8.9");
    cout << "Constructor with one arguments (" << s4.get_old_system() << ") gives you:\n"
         << "Pounds: " << s4.get_pounds() << " Shilling: "
         << s4.get_shills()<< " pence: " << s4.get_pence() << endl
         << "or using get_old_system() method: " << s4.get_old_system() << endl << endl;

    //part III
    cout << "Part III\n";
    Sterling s5(45.67);
    cout << "Constructor with one arguments (45.67) gives you:\n"
         << "Pounds: " << s5.get_pounds() << " Shilling: " << s5.get_shills()
         << " pence: " << s5.get_pence() << endl << endl;

    //part IV
    cout << "Part IV\n";
    cout << "Constructor with one arguments (45.67) and using << operator " << endl;
    Sterling s6 (45.67);
    cout << s6 << endl << endl;

    //part V
    cout << "Part V";
    Sterling s7(42.27);
    cout << endl;
    cout << "Constructor with one arguments (42.27)\n";
    cout << s7 << endl;;
    cout << "Update pounds to 23" << endl;
    s7.set_pounds(23);
    cout << s7 << endl;;
    cout << endl;

    //resetter
    s7.set_pounds(42);

    cout << "Constructor with one arguments (42.27)\n";
    cout << s7 << endl;;
    cout << "Update shills to 67, and adjust numbers" << endl;
    s7.set_shills(67);
    cout << s7 << endl;;
    cout << endl;

    //resetters
    s7.set_pounds(42);
    s7.set_shills(5);

    cout << "Constructor with one arguments (42.27)\n";
    cout << s7 << endl;;
    cout << "Update pence to 31, and adjust numbers" << endl;
    s7.set_pence(31);
    cout << s7 << endl;;
    cout << endl;

    //part VI
    cout << "Part VI\n";
    cout << "Testing == operator\n";
    cout << "Create two objects: \n";
    Sterling s8(9,4,7);
    Sterling s9(9,4,7);
    cout << s8 << endl;;
    cout << s9 << endl;;
    if (s8 == s9)
    {
        cout << "Object 1 and object 2 are equal\n";
    }
    else
    {
        cout << "Object 1 and object 2 are not equal\n";
    }
    cout << endl;

    cout << "Create two objects: \n";
    Sterling s10(9,4,7);
    Sterling s11(12,4,2);
    cout << s10 << endl;;
    cout << s11 << endl;;
    if (s10 == s11)
    {
        cout << "Object 1 and object 2 are equal\n";
    }
    else
    {
        cout << "Object 1 and object 2 are not equal\n";
    }
    cout << endl;

    cout << "Testing != operator\n";
    cout << "Create two objects: \n";
    Sterling s12(67,17,7);
    Sterling s13(33,2,2);
    cout << s12 << endl;;
    cout << s13 << endl;;
    if (s12 != s13)
    {
        cout << "Object 1 and object 2 are not equal\n";
    }
    else
    {
        cout << "Object 1 and object 2 are equal\n";
    }
    cout << endl;

    cout << "Create two objects: \n";
    Sterling s14(33,2,2);
    Sterling s15(33,2,2);
    cout << s14 << endl;;
    cout << s15 << endl;;
    if (s14 != s15)
    {
        cout << "Object 1 and object 2 are not equal\n";
    }
    else
    {
        cout << "Object 1 and object 2 are equal\n";
    }
    cout << endl;

    //part VII
    cout << "Part VII\n";
    cout << "Constructor with one argument (12.27)\n";
    Sterling s16(12.27);
    cout << s16 << endl;;
    cout << "Using decimal_pound() operator " << s16.decimal_pound();
    cout << endl << endl;

    //part VIII
    cout << "Part VIII\n";
    // Testing + operator
    cout << "\nCreate two objects:" << endl;
    Sterling s17(33.15);
    Sterling s18(6.21);
    cout << s17 << endl;
    cout << s18 << endl;
    Sterling s19 = s17 + s18;
    cout << "The sum of obj1 + obj2 = " << s19.decimal_pound();

// Testing - operator
    cout << endl << endl;
    cout << s17 << endl;
    cout << s18 << endl;
    Sterling s20 = s17 - s18;
    cout << "The difference of obj1 - obj2 = " << s20.decimal_pound() << endl;

    return 0;
}
