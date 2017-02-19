#pragma once

#define ERROR(msg) \
  Error(__FILE__, __FUNCTION__, __LINE__, msg)

#define WRAPPED_ERROR(msg, last_error) \
  Error(__FILE__, __FUNCTION__, __LINE__, msg, last_error)

class Error
{
 public:
  Error(const char* file,
        const char* func,
        int line,
        const char* msg);
  
  Error(const char* file,
        const char* func,
        int line,
        const char* msg,
        Error* last_error);
  
  virtual std::string what() const;
 private:
  char* msg_;
  Error* next_;
};

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
 
  Error(const char* file,
        const char* func,
        int line,
        const char* msg);
  
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
  // FILE FUNCTION LINE \n
  char* msg_;
};
