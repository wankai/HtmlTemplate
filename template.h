#pragma once

#include <string>

namespace hte {

class Template
{
 public:
  inline const std::string& site()
  {
    return site_;
  }
 
  inline const std::vector<Section>& sections()
  {
    return sections_;
  }
 private:
  std::string site_;
  std::vector<Section> sections_;
};

} // namespace hte
