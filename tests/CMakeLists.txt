find_package(GTest)
include(GoogleTest)

# add_executable(
#     proto_to_fix_test
#     proto_to_fix_test.cpp
# )
# target_link_libraries(
#     proto_to_fix_test
#     PRIVATE eflow::protobuf-entry_point
#     PRIVATE GTest::gtest_main
#             fmt::fmt
#             gRPC::grpc
#             gRPC::grpc++
#             gRPC::grpc++_reflection
#             protobuf::libprotobuf
#             quickfix::quickfix
# )

# include(${_project_options_SOURCE_DIR}/src/StaticAnalyzers.cmake)
# target_disable_static_analysis(proto_to_fix_test)

# gtest_discover_tests(proto_to_fix_test)