#include "url_pattern.h"

#include "match_result.h"

void UrlPattern::Reset() {
  path_regex_.reset();
  query_regexs_.clear();
}

void UrlPattern::ResetQuery() {
  query_regexs_.clear();
}
