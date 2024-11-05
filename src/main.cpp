#include <iostream>
#include <string>
#include "Company.hpp"
#include "Bus.hpp"

int main() {
    char command;
    std::string licensePlate, licensePlate2;
    int maximumCapacity, numberOfPassengers;
    Company company;
    Bus *bus = nullptr, *bus2 = nullptr;

    while (std::cin >> command) {
        switch (command) {
        case 'C':
            std::cin >> licensePlate >> maximumCapacity;

            if (company.addBus(licensePlate, maximumCapacity)) {
                std::cout << "novo ônibus cadastrado" << std::endl;
            } else {
                std::cout << "ERRO : ônibus repetido" << std::endl;
            }
            break;

        case 'S':
            std::cin >> licensePlate >> numberOfPassengers;
            bus = company.searchBus(licensePlate);

            if (bus == nullptr) {
                std::cout << "Erro : ônibus inexistente" << std::endl;
            } else {
                if (bus->boardPassengers(numberOfPassengers)) {
                    std::cout << "passageiros subiram com sucesso" << std::endl;
                } else {
                    std::cout << "Erro : ônibus lotado" << std::endl;
                }
            }
            break;

        case 'D' :
            std::cin >> licensePlate >> numberOfPassengers;
            bus = company.searchBus(licensePlate);

            if (bus == nullptr) {
                std::cout << "Erro : ônibus inexistente" << std::endl;
            } else {
                if (bus->disembarkPassengers(numberOfPassengers)) {
                    std::cout << "passageiros desceram com sucesso" << std::endl;
                } else {
                    std::cout << "Erro: faltam passageiros" << std::endl;
                }
            }
            break;

        case 'T' :
            std::cin >> licensePlate >> licensePlate2 >> numberOfPassengers;
            bus = company.searchBus(licensePlate);
            bus2 = company.searchBus(licensePlate2);

            if (bus == nullptr || bus2 == nullptr) {
                std::cout << "Erro : ônibus inexistente" << std::endl;
            }
            else {
                if(!bus->disembarkPassengers(numberOfPassengers) || !bus2->boardPassengers(numberOfPassengers)) {
                    std::cout << "Erro : transferência cancelada" << std::endl;
                } else {
                    std::cout << "transferência de passageiros efetuada" << std::endl;
                }
            }  
            break;
        
        case 'I' :
            company.printStatus();
            break;

        case 'F' :
            return 0;

        default:
            std::cout << "Comando inválido" << std::endl;
            break;
        }
    }
}

