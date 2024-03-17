include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    lr1_tests
    lr1_test.cpp
        lr1_test.cpp
)

target_link_libraries(
    lr1_tests
    lr1_lib
    GTest::gtest_main
)

configure_file(test1.txt ${CMAKE_CURRENT_BINARY_DIR}/test1.txt COPYONLY)
configure_file(test2.txt ${CMAKE_CURRENT_BINARY_DIR}/test2.txt COPYONLY)
configure_file(test3.txt ${CMAKE_CURRENT_BINARY_DIR}/test3.txt COPYONLY)
configure_file(test4.txt ${CMAKE_CURRENT_BINARY_DIR}/test4.txt COPYONLY)
configure_file(test5.txt ${CMAKE_CURRENT_BINARY_DIR}/test5.txt COPYONLY)
configure_file(test6.txt ${CMAKE_CURRENT_BINARY_DIR}/test6.txt COPYONLY)
configure_file(test7.txt ${CMAKE_CURRENT_BINARY_DIR}/test7.txt COPYONLY)
configure_file(test8.txt ${CMAKE_CURRENT_BINARY_DIR}/test8.txt COPYONLY)
configure_file(test9.txt ${CMAKE_CURRENT_BINARY_DIR}/test9.txt COPYONLY)
configure_file(test10.txt ${CMAKE_CURRENT_BINARY_DIR}/test10.txt COPYONLY)
configure_file(test11.txt ${CMAKE_CURRENT_BINARY_DIR}/test11.txt COPYONLY)
configure_file(test12.txt ${CMAKE_CURRENT_BINARY_DIR}/test12.txt COPYONLY)
configure_file(test13.txt ${CMAKE_CURRENT_BINARY_DIR}/test13.txt COPYONLY)
configure_file(test14.txt ${CMAKE_CURRENT_BINARY_DIR}/test14.txt COPYONLY)
configure_file(test15.txt ${CMAKE_CURRENT_BINARY_DIR}/test15.txt COPYONLY)
configure_file(test16.txt ${CMAKE_CURRENT_BINARY_DIR}/test16.txt COPYONLY)
configure_file(test17.txt ${CMAKE_CURRENT_BINARY_DIR}/test17.txt COPYONLY)
configure_file(test18.txt ${CMAKE_CURRENT_BINARY_DIR}/test18.txt COPYONLY)
configure_file(test19.txt ${CMAKE_CURRENT_BINARY_DIR}/test19.txt COPYONLY)
configure_file(test20.txt ${CMAKE_CURRENT_BINARY_DIR}/test20.txt COPYONLY)
configure_file(test21.txt ${CMAKE_CURRENT_BINARY_DIR}/test21.txt COPYONLY)
configure_file(test22.txt ${CMAKE_CURRENT_BINARY_DIR}/test22.txt COPYONLY)
configure_file(test23.txt ${CMAKE_CURRENT_BINARY_DIR}/test23.txt COPYONLY)

target_include_directories(lr1_tests PUBLIC ${PROJECT_SOURCE_DIR})

include(GoogleTest)

gtest_discover_tests(lr1_tests)

