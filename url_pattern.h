#pragma once

#include <regex>

class MatchResult;

class UrlPattern
{
 public:
  struct MatchOptions
  {
    bool append = true;
    bool overwrite = false;
  };
 
  UrlPattern(const std::string& path_pattern)
    : path_regex_(path_pattern)
  {
  }
 
  AddQuery(const std::string& query_name, const std::string& value_pattern)
  {
    query_regexs_.insert(std::make_pair(query_name, std::regex(value_pattern)));
  }
 
  void Reset();
 
  void ResetQuery();
 
  bool Match(const std::string& target,
             MatchResult* match_result,
             MatchOption = MatchOption());
 private:
  std::regex path_regex_;
  std::unordered_map<std::string, std::regex> query_regexs_;
};
