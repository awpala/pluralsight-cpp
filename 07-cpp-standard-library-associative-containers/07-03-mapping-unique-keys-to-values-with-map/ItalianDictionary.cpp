// Basic std::map demo: implementing a simple English-Italian dictionary

#include <iostream>
using std::cout;
#include <map>
using std::map;
#include <string>
using std::string;


// Show some basic operations with std::map
int main() {
  // initialize `std::map` object instance
  map<string, string> dictionary{
    // English  --->  Italian
    {"hello",         "ciao"},
    {"goodbye",       "arrivederci"},
    {"good morning",  "buon giorno"},
    {"good evening",  "buona sera"},
    {"thank you",     "grazie"},
    {"beautiful",     "bello (m.), bella (f.)"},
    {"church",        "chiesa"},
    {"pizza",         "pizza"},
    {"pasta",         "pasta"},
    {"ice cream",     "gelato"}
  };

  // use `std::map::insert()` to insert elements/associations
  dictionary.insert({ "museum",    "museo" });
  dictionary.insert({ "how much?", "quanto?" });

  cout << " English to Italian Dictionary \n";
  cout << " ----------------------------- \n";

  // use ranged `for` loop to access elements sequentially (in sorted order)
  for (auto const& [english, italian] : dictionary) {
    cout << '\t' << english << ": " << italian << '\n';
  }

  cout << "\n The Italian for 'thank you' is: '" 
    << dictionary["thank you"] << "' \n";

  return 0;
}
