cmake_minimum_required(VERSION 3.4.0)
project(design_pattern_tests)

#enable_testing()

set(FACTORY_METHOD_TEST factory_method_test)
set(FACTORY_METHOD_TEST_SRC factory_method_test.cpp)

add_executable(${FACTORY_METHOD_TEST} ${FACTORY_METHOD_TEST_SRC})
#target_link_libraries(${PROJECT_NAME} PUBLIC gtest)
