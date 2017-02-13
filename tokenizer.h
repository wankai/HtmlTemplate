#pragma once

namespace hte {

enum TokenType
{
  kOpenedTagBegin = 1,
  kClosedTag = 2,
  kPropName = 3,
  kPropValue = 4,
  kEqual = 5,
};

enum Status
{
  kStart = 1,
  kInOpenedTagBegin = 2,
  kInClosedTag = 3,
  kInPropName = 4,
  kInPropValue = 5
};

class Token {
 public:
  TokenType type() const
  {
    return type_;
  }
 
  const std::string& value() const
  {
    return value_;
  }
 private:
  std::string value_;
  TokenType type_;
};

class Tokenizer
{
 public:
  Tokenizer(const std::string& content);
  
  Token Next();
  bool Valid();
  std::string Error();
 private:
  const std::string& content_;
  size_t line_;
  size_t column_;
};

} // namespace hte
