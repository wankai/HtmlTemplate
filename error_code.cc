#include "error_code.h"

bool ErrorCode::ok() {
  return msg_ == NULL;
}

bool ErrorCode::code() {
  int* p = reinterpret_cast<int*>(msg_);
  return *p;
}

const char* ErrorCode::reason() {
  return msg_ + 4;
}
