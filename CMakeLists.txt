cmake_minimum_required(VERSION 3.6)
project(KOYO)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_BUILD_TYPE "Release")


if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -std=c++14 -g -Wall -O2 ")
#    set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -std=c++14 -g -Wall ")
    add_definitions(-DRUN_PC)
    add_definitions(-DDEBUG_PRINT)
    add_definitions(-D_DEBUG_LEVEL_HIGH_)
#        add_definitions(-DNDEBUG)
else( CMAKE_BUILD_TYPE STREQUAL "Release" )
#    set(CMAKE_BUILD_TYPE "Release")
    set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -std=c++14 -O3 -Wall")
#    add_definitions(-DRUN_PC)
#    add_definitions(-DNDEBUG)
#    add_definitions(-DDEBUG_PRINT)
endif( CMAKE_BUILD_TYPE STREQUAL "Debug" )
message("Build Type:" ${CMAKE_BUILD_TYPE}    ${CMAKE_CXX_FLAGS})



set(OpenCV_DIR E://ClionProjects//opencv_install)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include)


set(SOURCE_FILES src/KOYOMain.cpp)

add_executable(TestOpenCV ${SOURCE_FILES})
target_link_libraries(TestOpenCV ${OpenCV_LIBS})


add_executable(KOYOMain ${SOURCE_FILES} utils/utils.cpp src/GetUnions.cpp)
target_link_libraries(KOYOMain ${OpenCV_LIBS})

add_executable(UnionTest src/GetUnions.cpp utils/utils.cpp )
target_link_libraries(UnionTest ${OpenCV_LIBS})

add_executable(HuMatch1 src/Hu.cpp include/HuMatch.h)
target_link_libraries(HuMatch1 ${OpenCV_LIBS})

add_executable(GeoMatch src/GeoMatchTest.cpp src/GeoMatch.cpp src/CommandParser.cpp src/RotateImage.cpp utils/utils.cpp)
target_link_libraries(GeoMatch ${OpenCV_LIBS})

add_executable(FeaturesMatch src/FeaturesMatch.cpp)
target_link_libraries(FeaturesMatch ${OpenCV_LIBS})

add_executable(RotateImage1 src/RotateImage.cpp src/IMatImpl.cpp src/sobel.cpp)
target_link_libraries(RotateImage1 ${OpenCV_LIBS})



add_executable(TemplateMatch src/RotateImage.cpp src/TemplateMatchTest.cpp src/TemplateMatch.cpp src/TemplateMatchTest.cpp src/IMatImpl.cpp src/sobel.cpp)
target_link_libraries(TemplateMatch ${OpenCV_LIBS})

add_executable(test1 test/test.cpp)
target_link_libraries(test1 ${OpenCV_LIBS})

add_executable(testpyr test/testPyDown.cpp)
target_link_libraries(testpyr ${OpenCV_LIBS})

add_executable(integral Integral/IntegralMain.cpp)
target_link_libraries(integral ${OpenCV_LIBS})

add_executable(fastLocalization src/fastLocalization.cpp)
target_link_libraries(fastLocalization ${OpenCV_LIBS})

add_executable(testTemplateMatch test/testTemplateMatch.cpp)
target_link_libraries(testTemplateMatch ${OpenCV_LIBS})

add_executable(colorDetection src/color_detection/color_detection.cpp)
target_link_libraries(colorDetection ${OpenCV_LIBS})

add_executable(circle_detection src/circle_detection/circle_detection_original.cpp)
target_link_libraries(circle_detection ${OpenCV_LIBS})

add_executable(getPoint test/getPoint.cpp)
target_link_libraries(getPoint ${OpenCV_LIBS})


add_executable(HuMatch2 src/hu2.cpp)
target_link_libraries(HuMatch2 ${OpenCV_LIBS})


add_executable(create_template src/create_template_pc/contour_detection.h src/create_template_pc/main.cpp src/create_template_pc/contour_detection.cpp)
target_link_libraries(create_template ${OpenCV_LIBS})
add_executable(hfmr src/HuFastMatchRegion.cpp)
target_link_libraries(hfmr ${OpenCV_LIBS})


add_executable(readyuv test/read_y_from_yuv.cpp)
target_link_libraries(readyuv ${OpenCV_LIBS})

add_executable(testRotate test/rotateBitMap.cpp)
target_link_libraries(testRotate ${OpenCV_LIBS})

add_library(create_template_lib STATIC src/create_template_pc/contour_detection.h src/create_template_pc/contour_detection.cpp Integral/integral_test.cpp)

add_executable(myFilter test/myFilter.cpp)
target_link_libraries(myFilter ${OpenCV_LIBS})

add_executable(cydpc test/cydpc/contour_detection.h test/cydpc/contour_detection.cpp test/cydpc/TimeTracker.h test/cydpc/main.cpp)
target_link_libraries(cydpc ${OpenCV_LIBS})

add_executable(testinrect test/color_test/test_inrect.cpp)
target_link_libraries(testinrect ${OpenCV_LIBS})

add_executable(testsobel test/SobelTest.cpp)
target_link_libraries(testsobel ${OpenCV_LIBS})

add_executable(circle_detection_config src/circle_detection/circle_detection.cpp src/circle_detection/main.cpp)
target_link_libraries(circle_detection_config ${OpenCV_LIBS})

add_executable(testNewWidth test/testNewWidth.cpp)
target_link_libraries(testNewWidth ${OpenCV_LIBS})

add_executable(getRgb src/color_detection/getRGB.cpp)
target_link_libraries(getRgb ${OpenCV_LIBS})

add_executable(colorconfig src/color_detection/colorconfig.cpp)
target_link_libraries(colorconfig ${OpenCV_LIBS})


add_executable(integral_test  Integral/integral_test.cpp)
target_link_libraries(integral_test ${OpenCV_LIBS})
