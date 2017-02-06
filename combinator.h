#pragma once

namespace hte {

class Combinator
{
 public:
  static Combinator Build(const std::string& pattern, std::string* error);
  
  std::string Out(const std::string& src, std::string* error);
  
 private:
};

} // namespace hte
