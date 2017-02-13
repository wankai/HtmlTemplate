#include "tokenizer.h"

Tokenizer::Tokenizer(const std::string& content)
  : content_(content)
{
}

Token Tokenizer::Next()
{
  int c = content_[offset_];
  
  if (c == '<') {
  }
}
