#pragma once

#define OK Error(__FILE__, __FUNCTION__, __LINE__)

#define WRAPPED_ERROR(msg) \
  Error(__FILE__, __FUNCTION__, __LINE__, msg, last_error)

class Error
{
 public:
  Error()
   : msg_(NULL)
  {
  }
 
  ~Error()
  {
    if (msg_ != NULL && !__builtin_constant_p(msg_)) {
      free(msg_);
    }
  }
 
  // msg should be a string literal
  Error(const char* msg)
    : msg_(msg)
  {
    static_assert(__builtin_constant_p(msg),
                  "msg parameter should be a string literal");
  }
 
  Error(const std::string& msg)
  {
    
  }
 
  inline static Error OK()
  {
    return Error();
  }
 
  inline static Error WrapError(const char* msg, Error* last_error); 
 
  inline bool ok() const
  {
    return msg_ == NULL;
  }
 
  inline const char* reason() const
  {
    return msg_;
  }
 
 private:
  // FILE FUNCTION LINE \n
  char* msg_;
};
