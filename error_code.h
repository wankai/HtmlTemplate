#pragma once

class ErrorCode
{
 public:
  ErrorCode()
   : msg_(NULL)
  {
  }
 
  inline ErrorCode Ok()
  bool ok() const;
 
  int code() const;
 
  const char* reason() const;
 private:
  char* msg_;
};
