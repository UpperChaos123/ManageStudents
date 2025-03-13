# Tìm tất cả các file .cpp trong thư mục src của thư viện
file(GLOB LIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Tạo thư viện tĩnh và động từ mã nguồn thư viện
add_library(MyLibraryStatic STATIC ${LIB_SOURCES})
#add_library(MyLibraryShared SHARED ${LIB_SOURCES})

# Định nghĩa đường dẫn
target_include_directories(MyLibraryStatic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)
#target_include_directories(MyLibraryShared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)

# Đặt đầu ra của thư viện vào thư mục build/libs
set_target_properties(MyLibraryStatic PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs/static)

#set_target_properties(MyLibraryShared PROPERTIES
#    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs/dynamic   # .dll
#    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs/dynamic   # .dll.a (import library)
#    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs/dynamic)  # .dll trên Linux hoặc .so
