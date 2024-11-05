#ifndef BUS_H
#define BUS_H
#include <iostream>
#include <string>

struct Bus {
    std::string _licensePlate;
    int _maximumCapacity;
    int _currentCapacity;

    Bus(std::string, int);

    bool boardPassengers(int);
    bool disembarkPassengers(int);
    bool transferPassengers(Bus*, int);
    void printStatus() const;
};

#endif