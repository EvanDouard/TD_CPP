/* //EXO 1.2
#include <iostream>
#include <string>

int main()
{
    std::string hlwrd="Hellow world";
    std::cout<<hlwrd;

    return 0;
}
*/


 //EXO 1.4
#include "main.h"



class my_class{
    public:
        my_class(std::string);
};


void print_my_element(std::string val)
{
    std::cout << val;
};

int main(int argc, char *argv[])
{
    print_my_element("Hello world");

    return 0;
};
