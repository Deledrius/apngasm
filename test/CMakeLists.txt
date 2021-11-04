cmake_minimum_required(VERSION 3.13)

if(BUILD_TESTING)

project(APNGASM_TEST)

# Generate C++ test
add_executable(apngasm-cpp-test
  ${PROJECT_SOURCE_DIR}/cpp/apngasm-test.cpp
)

set_target_properties(apngasm-cpp-test
  PROPERTIES
  OUTPUT_NAME apngasm-cpp-test
  CXX_STANDARD 20
)
link_directories(${CMAKE_BINARY_DIR}/lib)
include_directories(
  ${PROJECT_SOURCE_DIR}/../lib/src
  ${CMAKE_BINARY_DIR}/lib/src
)
target_link_libraries(apngasm-cpp-test apngasm-static)

add_test(NAME apngasm-cpp-test
  COMMAND $<TARGET_FILE:apngasm-cpp-test> ${PROJECT_SOURCE_DIR}/samples
)

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/cli-out)
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/cpp-out)

add_test(NAME cli-logo-test
  COMMAND ${PROJECT_SOURCE_DIR}/cli/logo-test.sh
)

add_test(NAME cli-delay-test
  COMMAND ${PROJECT_SOURCE_DIR}/cli/delay-test.sh
)

add_test(NAME cli-json-test
  COMMAND ${PROJECT_SOURCE_DIR}/cli/json-test.sh
)

add_test(NAME cli-xml-test
  COMMAND ${PROJECT_SOURCE_DIR}/cli/xml-test.sh
)

add_test(NAME cli-disassemble-test
  COMMAND ${PROJECT_SOURCE_DIR}/cli/disassemble-test.sh
)

endif(BUILD_TESTING)
