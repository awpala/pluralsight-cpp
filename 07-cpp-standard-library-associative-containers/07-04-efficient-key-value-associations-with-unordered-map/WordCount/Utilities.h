#pragma once

#include <algorithm>
using std::remove;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <vector> 
using std::vector;
#include <boost/algorithm/string.hpp>
using boost::split;


// Given a filename as input, return a string vector containing the words
// read from the input file.
vector<string> ReadWordsFromFile(string const& filename) {
  vector<string> words{};
  
  // Read file line by line
  ifstream inFile{filename};
  string line{};
  while (getline(inFile, line)) {
    // Parse the current line, splitting it into words
    vector<string> wordsInLine{};
    boost::split(
      wordsInLine, line,
      [](char ch) { return !isalnum(ch); }, 
      boost::algorithm::token_compress_on
    );

    // Add current parsing results to the words array
    words.insert(end(words), begin(wordsInLine), end(wordsInLine));
  }

  // Erase spurious empty strings returned by boost::split,
  // using the erase-remove idiom.
  words.erase(remove(begin(words), end(words), ""), end(words));

  return words;
}
