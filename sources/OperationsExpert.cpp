#include "OperationsExpert.hpp"

pandemic::Player& pandemic::OperationsExpert::build() {
    b.buildStation(currCity, true);
    return *this;
}

string pandemic::OperationsExpert::role() {
    return "OperationsExpert";
}
