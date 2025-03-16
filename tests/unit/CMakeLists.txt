# Tìm tất cả file .cpp trong thư mục hiện tại và thư mục con
file(GLOB_RECURSE UNIT_TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Tạo một executable cho unit tests
add_executable(unitTests 
    ${UNIT_TEST_SOURCES} 
    ${CMAKE_SOURCE_DIR}/src/class1/Student.cpp
    ${CMAKE_SOURCE_DIR}/tests/test_main.cpp)

# Link với Google Test
target_link_libraries(unitTests PRIVATE GTest::gtest GTest::gtest_main pthread)

target_include_directories(unitTests PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)

# Liên kết với thư viện
target_link_libraries(unitTests PRIVATE MyLibraryStatic)

# Đăng ký unit tests với CTest
add_test(NAME UnitTests COMMAND unitTests)

