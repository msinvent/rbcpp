add_library(csv_reader src/csv_reader.cxx)
target_include_directories(csv_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})
target_compile_options(csv_reader PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(csv_reader ${Boost_LIBRARIES})

add_executable(full_test src/full_test.cxx)
target_include_directories(full_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(full_test PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(full_test PRIVATE librbc config_parser)

add_executable(messages_test src/messages_test.cxx)
target_include_directories(messages_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(messages_test PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(messages_test PRIVATE librbc csv_reader)

add_executable(response_test src/response_test.cxx)
target_include_directories(response_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(response_test PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(response_test PRIVATE librbc csv_reader)

add_executable(foo src/foo.cxx)
target_include_directories(foo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(foo PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(foo PRIVATE librbc cpprestsdk::cpprest
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_THREAD_LIBRARY}
        ${Boost_CHRONO_LIBRARY})