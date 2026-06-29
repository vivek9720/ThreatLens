cmake_minimum_required(VERSION 3.12)

project(ThreatLens LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(threatlens src/core/types.cpp src/core/exposure_catalog.cpp src/packet/packet.cpp src/ioc/ioc.cpp src/rules/rules.cpp src/policy/policy.cpp)

target_include_directories(threatlens PUBLIC include)

foreach(t packetscan iocmatch rulecheck policyaudit)

 add_executable(${t} tools/${t}.cpp)

 target_link_libraries(${t} PRIVATE threatlens)

endforeach()

include(CTest)

if(BUILD_TESTING)

 add_executable(threatlens_tests tests/test_all.cpp)

 target_link_libraries(threatlens_tests PRIVATE threatlens)

 add_test(NAME threatlens_tests COMMAND threatlens_tests)

endif()

