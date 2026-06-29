#include "policy/policy.hpp"
extern "C" int LLVMFuzzerTestOneInput(const uint8_t*d,size_t s){std::string x((const char*)d,s);auto p=threatlens::policy::parse_policy(x);for(auto&r:p.value.rules)(void)threatlens::policy::normalize_rule(r);(void)threatlens::policy::analyze_ordering(p.value);return 0;}
