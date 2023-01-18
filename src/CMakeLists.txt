set(PACKAGES fmt spdlog CLI11 rabbitmq-c Threads)
foreach(package ${PACKAGES})
    find_package(${package})
endforeach()

file(GLOB srcs_utils utils/*.cpp)

add_executable(
    main
        main.c
        ${srcs_utils}
)
target_link_libraries(
    main
    PRIVATE project_options
            project_warnings
    PRIVATE fmt::fmt 
            spdlog::spdlog
            rabbitmq::rabbitmq
            CLI11::CLI11
            Threads::Threads
)