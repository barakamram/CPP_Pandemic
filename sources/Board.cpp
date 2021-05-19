

#include "Board.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;
using namespace pandemic;
const unsigned int SIX = 6;
const unsigned int FORTYEIGHT = 48;
map <City, string> Board::cities;

vector <string> split(const string &s, char c) {
    vector <string> v;
    stringstream ss(s);
    string u;
    while (getline(ss, u, c)) {
        v.push_back(u);
    }
    return v;
}

namespace pandemic {

    ostream &operator<<(ostream &os, Board &b) {
        cout << "| City\t\t | Cubes\t | Cure\t\t | Station |" << endl;
        for (int i = 0; i < FORTYEIGHT; i++) {
            City c = (City) i;
            cout << "| " << Board::cities[c] << "\t";
            if (Board::cities[c].size() < SIX) { cout << "\t"; }
            cout << " | " << b.cubes[c] << "\t\t | ";
            if (b.cures[b.getColor(c)]) { cout << "yes"; }
            else { cout << "no"; }
            cout << "\t\t | " << b.stations[c] << "\t | " << endl;
        }
        return os;
    }
}
Board::Board() {
    //Blue
    cities[City::Atlanta] = "Atlanta";
    cities[City::Chicago] = "Chicago";
    cities[City::Essen] = "Essen";
    cities[City::London] = "London";
    cities[City::Madrid] = "Madrid";
    cities[City::Milan] = "Milan";
    cities[City::Montreal] = "Montreal";
    cities[City::NewYork] = "NewYork";
    cities[City::Paris] = "Paris";
    cities[City::SanFrancisco] = "SanFrancisco";
    cities[City::StPetersburg] = "StPetersburg";
    cities[City::Washington] = "Washington";
    //Yellow
    cities[City::Bogota] = "Bogota";
    cities[City::BuenosAires] = "BuenosAires";
    cities[City::Johannesburg] = "Johannesburg";
    cities[City::Khartoum] = "Khartoum";
    cities[City::Kinshasa] = "Kinshasa";
    cities[City::Lagos] = "Lagos";
    cities[City::Lima] = "Lima";
    cities[City::LosAngeles] = "LosAngeles";
    cities[City::MexicoCity] = "MexicoCity";
    cities[City::Miami] = "Miami";
    cities[City::Santiago] = "Santiago";
    cities[City::SaoPaulo] = "SaoPaulo";
    //Black
    cities[City::Algiers] = "Algiers";
    cities[City::Baghdad] = "Baghdad";
    cities[City::Cairo] = "Cairo";
    cities[City::Chennai] = "Chennai";
    cities[City::Delhi] = "Delhi";
    cities[City::Istanbul] = "Istanbul";
    cities[City::Karachi] = "Karachi";
    cities[City::Kolkata] = "Kolkata";
    cities[City::Moscow] = "Moscow";
    cities[City::Mumbai] = "Mumbai";
    cities[City::Riyadh] = "Riyadh";
    cities[City::Tehran] = "Tehran";
    //Red
    cities[City::Bangkok] = "Bangkok";
    cities[City::Beijing] = "Beijing";
    cities[City::HoChiMinhCity] = "HoChiMinhCity";
    cities[City::HongKong] = "HongKong";
    cities[City::Jakarta] = "Jakarta";
    cities[City::Manila] = "Manila";
    cities[City::Osaka] = "Osaka";
    cities[City::Seoul] = "Seoul";
    cities[City::Shanghai] = "Shanghai";
    cities[City::Sydney] = "Sydney";
    cities[City::Taipei] = "Taipei";
    cities[City::Tokyo] = "Tokyo";

    map <string, Color> colorMap;
    colorMap["Blue"] = Color::Blue;
    colorMap["Yellow"] = Color::Yellow;
    colorMap["Black"] = Color::Black;
    colorMap["Red"] = Color::Red;

    map <string, City> reversed;
    for (auto const &c : cities) {
        reversed[c.second] = c.first;
    }

    string line;
    ifstream path{"cities_map.txt"};
    while (getline(path, line)) {
        vector <string> neighbor = split(line, ' ');
        City c = reversed[neighbor[0]];

        colors[c] = colorMap[neighbor[1]];

        list <City> cities;
        for (unsigned int i = 2; i < neighbor.size(); ++i) {
            cities.push_back(reversed[neighbor[i]]);
        }
        nei[c] = cities;
        cubes[c] = 0;
        stations[c] = false;
    }
    remove_cures();
}

int &Board::operator[](pandemic::City c) {
    return cubes[c];
}

bool Board::neighbors(pandemic::City c1, pandemic::City c2) {
    return find(nei[c1].begin(), nei[c1].end(), c2) != nei[c1].end() ||
           c1 == c2;
}
void Board::buildStation(pandemic::City c, bool s) {
    stations[c] = s;
}
bool Board::getStation(pandemic::City c) {
    return stations[c];
}
void Board::setCure(pandemic::Color c) {
    cures[c] = true;
}
bool Board::getCure(pandemic::Color c) {
    return cures[c];
}
bool Board::getCure(pandemic::City c) {
    return cures[colors[c]];
}
pandemic::Color Board::getColor(pandemic::City c) {
    return colors[c];
}
bool Board::is_clean() {
    for (auto c : cubes) {
        if (c.second != 0) {
            return false;
        }
    }
    return true;
}
void Board::remove_cures() {
    for (auto c : cures) {
        cures[c.first] = false;
    }
}
void Board::remove_stations() {
    for (auto s : stations) {
        stations[s.first] = false;
    }
}
