#pragma once

#include <regex>

class MatchResult;

class UrlPattern
{
 public:
  UrlPattern(const std::string& path_pattern)
    : path_regex_(path_pattern)
  {
  }
 
  AddQuery(const std::string& query_name, const std::string& value_pattern)
  {
    query_regexs_.insert(std::make_pair(query_name, std::regex(value_pattern)));
  }
 
  bool Match(const std::string& target, MatchResult* match_result);
 private:
  std::regex path_regex_;
  std::unordered_map<std::string, std::regex> query_regexs_;
};
