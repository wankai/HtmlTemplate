#pragma once

class XPath
{
 public:
  class Node
  {
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
  std::vector<XPath::Node> nodes_;
};
