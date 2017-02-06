#pragma once

#include <string>

namespace hte {

class Combine
{
 public:
  static Combine Build(const std::string& pattern, std::string* err);
  std::string out(const std::string& src);
  
 private:
};
 
class NameValue
{
 public:
  static NameValue Build(const std::string& name, const std::string& value)
  {
    NameValue tmp;
    tmp.set_name(name);
    tmp.set_value(value);
    return tmp;
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

class Field
{
 public:
 private:
  std::string name_;
  std::string xpath_;
  std::string type_;
  std::string prop_;
  std::string value_;
  std::string filter_;
  std::regex filter_regex_;
  Combine combine_;
  std::string method_;
 
  FieldType field_type_;
};
 
class Item
{
 public:
 private:
  std::string name_;
  std::string xpath_;
  std::vector<Field> fields_;
  bool repeated_
};
 
class Section
{
 public:
  
 private:
  std::string pattern_;
  std::regex pattern_regex_;
  std::vector<NameValue> name_values_;
 
  std::vector<Field> links_;
  std::vector<Item> items_;
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
