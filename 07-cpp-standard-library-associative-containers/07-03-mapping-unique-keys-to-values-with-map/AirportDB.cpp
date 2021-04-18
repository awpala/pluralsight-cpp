// Demo: std::map from string keys to a custom class:
// implementing a simple airport database.

#include <iostream>
using std::cin;
using std::cout;
#include <map>
using std::map;
#include <string>
using std::string;

// Airport database:
// https://openflights.org/data.html

struct Airport {
  string Name{};
  string City{};
  string Country{};
  double Latitude{};
  double Longitude{};
  int AltitudeFeet{};

  // constructors
  Airport() = default;

  Airport(
    string const& name, string const& city, string const& country,
    double latitude, double longitude, int altitudeFeet
  )
  : Name(name), City(city), Country(country)
    , Latitude(latitude), Longitude(longitude), AltitudeFeet(altitudeFeet)
  {}
};

int main() {
  map<string, Airport> airportDatabase{ // value association via custom user-defined object `Airport`
    { "SEA", 
      {"Seattle Tacoma International Airport", "Seattle", "United States",
      47.449001, -122.308998, 433}
    },
    { "LAX",
      {"Los Angeles International Airport", "Los Angeles", "United States",
      33.94250107, -118.4079971, 125 }
    },
    { "FCO",
      { "Leonardo da Vinci - Fiumicino Airport", "Rome", "Italy",
      41.8002778, 12.2388889, 13}
    },
    { "LHR",
      {"London Heathrow Airport", "London", "United Kingdom",
      51.4706, -0.461941, 83}
    }
  };

  cout << " Airport Database Demo \n";
  cout << " --------------------- \n\n";

  cout << " Airport unique code? ";
  string code{};
  cin >> code;
  cout << '\n';

  // Look up airport information in the std::map database
  auto it = airportDatabase.find(code);
  if (it != airportDatabase.end()) {
    Airport const& airport = it->second; // read by `const&`
    cout << " Airport name:   " << airport.Name         << '\n';
    cout << " City:           " << airport.City         << '\n';
    cout << " Country:        " << airport.Country      << '\n';
    cout << " Latitude:       " << airport.Latitude     << '\n';
    cout << " Longitude:      " << airport.Longitude    << '\n';
    cout << " Elevation (ft): " << airport.AltitudeFeet << '\n';
  } else { 
    cout << " Sorry, airport code not found. \n";
  }

  return 0;
}
