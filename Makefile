EXENAME = Main

CXX = g++
# CXXFLAGS = -I./include -std=c++14 -stdlib=libc++ -ssl -lcrypto -Wall -lboost_system
CXXFLAGS = -I./include -std=c++14 -Wall -lboost_system

TPSRCS = ./
LIBSRCS = src/Main.cpp \

SRCS = src/Main.cpp

build:
	$(CXX) -o $(EXENAME) $(SRCS) $(CXXFLAGS)

clean: 
	-rm -f *.o $(EXENAME)

