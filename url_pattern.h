#pragma once

#include <regex>

class UrlPattern
{
 public:
  UrlPattern(const std::string& path_pattern)
    : path_regex_(path_pattern)
  {
  }
 
  Add(const std::string& query_name, const std::string& value_pattern)
  {
    query_regexs_.insert(std::make_pair(query_name, value_pattern));
  }
 
  bool Match(const std::string& target,
             std::unordered_map<string, string>* match_result);
 private:
  std::regex path_regex_;
  std::unordered_map<std::string, std::regex> query_regexs_;
};
