#pragma once

#include <string>

namespace hte {

class NameValue
{
 public:
  static NameValue Build(const std::string& name, const std::string& value)
  {
    NameValue tmp;
    tmp.set_name(name);
    tmp.set_value(value);
  }
 
  inline const std::string& name()
  {
    return name_;
  }
 
  inline void set_name(const std::string& name)
  {
    name_ = name;
  }
 
  inline const std::string& value()
  {
    return value_;
  }
 
  inline void set_value(const std::string& value)
  {
    value_ = value;
  }
 
 private:
  string name_;
  string value_;
};

class Section
{
 public:
  
 private:
  std::string pattern_;
  std::regex pattern_regex_;
  std::vector<NameValue> name_values_;
};

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
