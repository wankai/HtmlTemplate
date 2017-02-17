#pragma once

class Error
{
 public:
  Error()
   : msg_(NULL)
  {
  }
 
  ~Error()
  {
    if (msg_ != NULL) {
      free(msg_);
    }
  }
 
  // msg should be a string literal
  Error(const char* msg)
  {
    return 
  }
 
  Error(const std::string& msg)
  {
    
  }
 
  inline static Error OK()
  {
    return Error();
  }
 
  inline bool ok() const
  {
    return msg_ == NULL;
  }
 
  inline const char* reason() const
  {
    return msg_;
  }
 
 private:
  char* msg_;
};