#ifndef COMPANY_H
#define COMPANY_H
#include <iostream>
#include <string>
#include "Bus.hpp"

struct Company {
    int _numberOfBuses;
    Bus *_buses[20];
    
    Company();
    ~Company();

    Bus* addBus(std::string, int);
    Bus* searchBus(std::string) const;
    void printStatus() const;
};

#endif