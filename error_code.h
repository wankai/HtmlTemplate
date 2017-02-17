#pragma once

class ErrorCode
{
 public:
  bool ok() const;
 
  int code() const;
 
  const char* reason() const;
 private:
  char* msg_;
};
