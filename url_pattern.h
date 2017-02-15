#pragma once

class UrlPattern
{
 public:
   
 private:
  std::regex path_regex_;
  std::unordered_map<std::string, std::regex> query_regex_;
};
