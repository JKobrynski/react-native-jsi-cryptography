cmake_minimum_required(VERSION 3.4.1)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 11)

include_directories(
            ../cpp
            ../node_modules/react-native/React
            ../node_modules/react-native/React/Base
            ../node_modules/react-native/ReactCommon/jsi
)

add_library(jsi-cryptography
            SHARED
            ../node_modules/react-native/ReactCommon/jsi/jsi/jsi.cpp
            ../cpp/react-native-jsi-cryptography.cpp
            ../cpp/react-native-jsi-cryptography.h
            ../cpp/sha1.cpp
            ../cpp/sha1.h
            ../cpp/md5.cpp
            ../cpp/md5.h
            ../cpp/sha224.cpp
            ../cpp/sha224.h
            ../cpp/sha256.cpp
            ../cpp/sha256.h
            ../cpp/sha384.cpp
            ../cpp/sha384.h
            ../cpp/sha512.cpp
            ../cpp/sha512.h
            cpp-adapter.cpp
)

target_link_libraries(jsi-cryptography)