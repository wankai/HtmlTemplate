#pragma once

class ErrorCode
{
 public:
  bool ok() const;
  const std::string& reason() const;
 private:
  char* msg_;
};
