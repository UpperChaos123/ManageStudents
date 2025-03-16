# Phiên bản của CMake
cmake_minimum_required(VERSION 3.31)

# Định nghĩa project
project(MyProject LANGUAGES CXX)

# Dùng chuẩn C++23
set(CMAKE_CXX_STANDARD 23)  

# Bắt buộc dùng chuẩn C++23             
set(CMAKE_CXX_STANDARD_REQUIRED YES)   

# Không dùng các extension của compiler  
set(CMAKE_CXX_EXTENSIONS OFF)           

# Tìm tất cả các file .cpp trong thư mục src
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Tạo file thực thi của dự án
add_executable(Project1 ${SOURCES})

# Thêm thư mục chứa file header của dự án chính
target_include_directories(Project1 PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)

# Tạo thư mục build/libs
add_subdirectory(libs)

# Liên kết với thư viện tĩnh hoặc động
target_link_libraries(Project1 PRIVATE MyLibraryStatic)
#target_link_libraries(Project1 PRIVATE MyLibraryShared)

# Copy file .dll về cùng thư mục với Project1.exe sau khi build
#add_custom_command(
#    TARGET Project1 
#    POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different
#    ${CMAKE_BINARY_DIR}/libs/dynamic/libMyLibraryShared.dll
#    $<TARGET_FILE_DIR:Project1>)

# Bật chế độ testing
enable_testing()

# Tìm Google Test
find_package(GTest CONFIG REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Thêm thư mục tests vào build
add_subdirectory(tests)

