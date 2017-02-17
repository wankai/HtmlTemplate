#pragma once

class Error
{
 public:
  Error()
   : msg_(NULL)
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
