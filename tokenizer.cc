#include "tokenizer.h"

Tokenizer::Tokenizer(const std::string& content)
  : content_(content)
{
}

Token Tokenizer::Next()
{
  if (offset_ >= content_.length()) {
    return kEOFToken;
  }
  
  int c = content_[offset_];
  
  if (c == '\n') {
    line_++;
    column_ = 1;
    
    if (!isCompleted(last_token()) {
      installError();
      return kInvalidToken;
    }
  }
        
  if (c == '<') {
    if (status_ = kStatus) {
    }
  }
}
