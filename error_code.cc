#include "error_code.h"

bool ErrorCode::ok() {
  return msg_ == NULL;
}
