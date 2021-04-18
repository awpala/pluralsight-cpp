//=============================================================================
// Count words using `std::map` vs `std::unordered_map`
//=============================================================================

// #define PRINT_WORD_COUNTS true // include to print word counts

#include <chrono>
#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <boost/algorithm/string.hpp>   // for boost::split

#include "Utilities.h"
#include "Map.h"
#include "UnorderedMap.h"


int main() {
  const vector<string> words = ReadWordsFromFile("test.txt");
  
  /* `std::map` */
  cout << "`std::map`:\n";
  auto startMap = std::chrono::system_clock::now();
    map<string, int> wordCountMap = CountWordsMap(words);
  auto endMap = std::chrono::system_clock::now();
  auto elapsed_ms_map = std::chrono::duration_cast<std::chrono::milliseconds>(endMap - startMap);

  cout << " Word counting took " << elapsed_ms_map.count() << " ms. \n";
  cout << " Processed " << wordCountMap.size() << " words. \n\n";   

#ifdef PRINT_WORD_COUNTS
  cout << " \n Word counts: \n";
  for (auto const& [word, count] : wordCountMap) {
    cout << ' ' << word << ": " << count << '\n';
  }
#endif

  /* `std::unordered_map` */
  cout << "`std::unordered_map`:\n";
  auto startUnorderedMap = std::chrono::system_clock::now();
    unordered_map<string, int> wordCountUnorderedMap = CountWordsUnorderedMap(words);
  auto endUnorderedMap = std::chrono::system_clock::now();
  auto elapsed_ms_unordered_map = std::chrono::duration_cast<std::chrono::milliseconds>(endUnorderedMap - startUnorderedMap);

  cout << " Word counting took " << elapsed_ms_unordered_map.count() << " ms. \n";
  cout << " Processed " << wordCountUnorderedMap.size() << " words. \n\n";   

#ifdef PRINT_WORD_COUNTS
  cout << " \n Word counts: \n";
  for (auto const& [word, count] : wordCountUnorderedMap) {
    cout << ' ' << word << ": " << count << '\n';
  }
#endif

  return 0;
}
