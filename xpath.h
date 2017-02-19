#pragma once

class XPath
{
 public:
  static void RegisterTag(const std::string& tag);
 
  enum OpType
  {
    EQUAL = 1,
    MATCH = 2,
  };
 
  class Node
  {
   public:
    std::string tag;
    std::string prop;
    OpType op;
    union {
     std::string value;
     std::regex value_regex;
    };
    std::string index;
  };
  
  static bool Build(const std::string& format,
                    XPath* xpath,
                    std::string* error);
  
  typedef std::vector<XPath::Node>::iterator iterator;
  typedef std::vector<XPath::Node>::const_iterator const_iterator;
  
  iterator begin();
  const_iterator begin();
  
  iterator end();
  const_iterator end();
  
 private:
  static std::set<std::string> valid_tags;
  std::vector<XPath::Node> nodes_;
};
