cmake_minimum_required(VERSION 3.4.0)
project(design_pattern_tests)

set(FACTORY_METHOD_TEST factory_method_test)
set(FACTORY_METHOD_TEST_SRC factory_method_test.cpp)
add_executable(${FACTORY_METHOD_TEST} ${FACTORY_METHOD_TEST_SRC})

set(ABSTRACT_FACTORY_TEST abstract_factory_test)
set(ABSTRACT_FACTORY_TEST_SRC abstract_factory_test.cpp)
add_executable(${ABSTRACT_FACTORY_TEST} ${ABSTRACT_FACTORY_TEST_SRC})
