CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)


ADD_EXECUTABLE(test
	base.h
	oldcontainer.h
	print.h
	test.cpp)


TARGET_LINK_LIBRARIES(test gtest)
