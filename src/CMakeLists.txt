set(SOURCES
        client/Client.cpp business/Business.cpp insurance/Plan.cpp insurance/EyePlan.cpp insurance/Insurance.cpp AmountExceedException.cpp AmountExceedException.cpp)

set (HEADERS
        client/Client.h business/Business.h insurance/Plan.h insurance/EyePlan.h insurance/Insurance.h AmountExceedException.h)

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES} ${HEADERS})