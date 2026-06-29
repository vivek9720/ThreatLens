#!/bin/bash -eu
ROOT="${SRC:-$(pwd)}"
cd "$ROOT"
: "${OUT:?OUT must be set}"
COMMON_SRC="src/core/types.cpp src/core/exposure_catalog.cpp src/packet/packet.cpp src/ioc/ioc.cpp src/rules/rules.cpp src/policy/policy.cpp"
for target in packet_fuzzer ioc_fuzzer rules_fuzzer policy_fuzzer; do
  $CXX $CXXFLAGS -std=c++17 -Iinclude fuzz/${target}.cc $COMMON_SRC $LIB_FUZZING_ENGINE -o "$OUT/${target}"
done
