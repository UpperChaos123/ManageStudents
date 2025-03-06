# Tìm tất cả file .cpp trong thư mục hiện tại và thư mục con
file(GLOB_RECURSE INTEGRATION_TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Tạo một executable cho integration tests
add_executable(integrationTests 
    ${UNIT_TEST_SOURCES} 
    ${CMAKE_SOURCE_DIR}/src/class1/Student.cpp
    ${CMAKE_SOURCE_DIR}/tests/test_main.cpp)

# Link với Google Test
target_link_libraries(integrationTests PRIVATE GTest::gtest GTest::gtest_main pthread)

target_include_directories(integrationTests PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)

# Liên kết với thư viện
target_link_libraries(integrationTests PRIVATE MyLibraryStatic)

# Đăng ký integration tests với CTest
add_test(NAME IntegrationTests COMMAND integrationTests)

