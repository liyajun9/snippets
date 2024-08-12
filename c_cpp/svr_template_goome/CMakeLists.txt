cmake_minimum_required(VERSION 3.15)
project(svr_template)

add_executable(${PROJECT_NAME} src/main.cpp
        src/BoApp.cpp src/BoApp.h
        src/typedef.h
        src/globals.h src/globals.cpp
        ../Goome/platform/public/common/src/src/TraceThread.cpp
        ../Goome/platform/common_srv/COMMON_TRACE/common/trace.pb.cc
        src/gmqdirectI.cpp src/gmqdirectI.h src/ThreadGmqProcessor.cpp src/ThreadGmqProcessor.h)

target_compile_options(${PROJECT_NAME} PRIVATE -g -Wall -fPIC -std=c++0x -Wno-deprecated)
target_compile_definitions(${PROJECT_NAME} PRIVATE _LINUX_OS_ RAPIDJSON_HAS_STDSTRING __STDC_FORMAT_MACROS USE_GMLOGAPI)

target_include_directories(${PROJECT_NAME} PRIVATE
        ../Goome/platform/public/gmlogapi/src/include
        ../Goome/platform/public/netframe2/include
        ../Goome/platform/public/common/src/include
        ../Goome/platform/common_srv/COMMON_TRACE/common
        ../Goome/platform/public
        ../Goome/platform/lite/common/libgoocar/include
        ../Goome/platform/GUD/src
        )

target_link_directories(${PROJECT_NAME} PRIVATE ../Goome/platform/public/common/src/src
        /usr/lib/nptl
        /usr/lib
        /usr/local/lib
        /usr/Ice_3.4.2/lib64
        ../Goome/platform/public/libexe)

target_link_libraries(${PROJECT_NAME} PRIVATE -llite -lcommon -llog4cxx -lIce -lIceUtil -pthread -lrt -lssl -lprotobuf -lnframe2 -lcrypto -lboost_system -lboost_thread-mt -l_redis_cpp_client)
