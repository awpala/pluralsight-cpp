#pragma once

#include <unordered_map>
using std::unordered_map;
#include <string>
using std::string;
#include <vector>
using std::vector;


// Given a string vector as input, return for each word the associated count.
unordered_map<string, int> CountWordsUnorderedMap(vector<string> const& words) {
  unordered_map<string, int> wordCount{};
  for (auto const& word : words) {
    ++wordCount[word];
  }

  return wordCount;
}
