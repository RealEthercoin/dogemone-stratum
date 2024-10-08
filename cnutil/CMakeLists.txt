set(CXXLIB "cnutil")

find_package(Boost COMPONENTS thread system program_options date_time filesystem REQUIRED)

# Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D_GNU_SOURCE")

include_directories(${Boost_INCLUDE_DIRS})
include_directories("${MONERO_DIR}/contrib/epee/include")
include_directories("${MONERO_DIR}/src")
include_directories("${MONERO_DIR}/include")
include_directories(${CMAKE_SOURCE_DIR}/System)
include_directories("${MONERO_DIR}/external")
include_directories("${MONERO_DIR}/external/easylogging++")

link_directories(
    ${MONERO_DIR}/src/CryptoNoteCore
    ${MONERO_DIR}/src/crypto
    ${MONERO_DIR}/src/Common
    ${MONERO_DIR}/src/Platform
    ${MONERO_DIR}/include
    ${MONERO_DIR}/external
    ${CMAKE_SOURCE_DIR}/System
)

# Build library
add_library(${CXXLIB} SHARED src/cnutil.cpp)

target_link_libraries(${CXXLIB}
    CryptoNoteCore
    cncrypto
    Common
    Platform
    include
    external
    System
)

target_link_libraries(${CXXLIB}
    ${Boost_THREAD_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_PROGRAM_OPTIONS_LIBRARY}
    ${Boost_DATE_TIME_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
)
