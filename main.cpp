#include <iostream>
#include "calc.hpp"
#include "Wifi.hpp"

int main()
{
    Clac obj;
    std::cout << obj.add(6,3) << std::endl;
    std::cout << obj.sub(6,3) << std::endl;
    std::cout << obj.mult(6,3) << std::endl;
    std::cout << obj.divv(6,3) << std::endl;

    Wifi_Init();

    return 0;
}