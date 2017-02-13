#pragma once

namespace hte {

enum TokenType
{
  kOpenedTag = 1,
  kClosedTag = 2,
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
