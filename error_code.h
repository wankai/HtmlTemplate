#pragma once

class ErrorCode
{
 public:
  ErrorCode()
   : msg_(NULL)
  {
  }
 
  inline static ErrorCode Ok();
 
  bool ok() const;
 
  int code() const;
 
  const char* reason() const;
 
 private:
  InternalError(int code, const char* msg);
 
  char* msg_;
};
