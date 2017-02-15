#pragma once

#include <regex>

class UrlPattern
{
 public:
  static Build(const std::string& s);
  bool Match(std::unordered_map<string, string>* match_result);
 private:
  std::regex path_regex_;
  std::unordered_map<std::string, std::regex> query_regexs_;
};
