#pragma once

#include <map>
using std::map;
#include <string>
using std::string;
#include <vector>
using std::vector;


// Given a string vector as input, return for each word the associated count.
map<string, int> CountWordsMap(vector<string> const& words) {
  map<string, int> wordCount{};
  for (auto const& word : words) {
    ++wordCount[word];
  }

  return wordCount;
}
