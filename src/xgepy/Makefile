# get main configuration from inc file
include ../../Makefile.inc

# cpp configuration
CXXFLAGS+=-I../ -I../xge $(PYTHON_INCLUDE)

# all source code in this directory
SRC_CPP=$(shell ls *.cpp)
OBJS=$(SRC_CPP:.cpp=.o)

ifeq ($(PLATFORM_NAME),PLATFORM_Linux)
all: libxgepy.so
	@echo "all done"

libxgepy.so: $(OBJS) 
	g++ $(LDFLAGS) -fPIC -shared -o $@ ${OBJS} ${LIBS} -L../xge -lxge -lpthread -lGL -lGLU -lXinerama -lasound -lfreetype -lrt -lX11 -lfreeimage
endif


ifeq ($(PLATFORM_NAME),PLATFORM_Darwin)

#64 bit architecture not supported
LDFLAGS=-arch i386  -arch x86_64

all: libxgepy.dylib
	@echo "all done"

libxgepy.dylib: $(OBJS) 
	g++ $(LDFLAGS) -dynamiclib -framework Python -o $@ ${OBJS} ${LIBS} -L../xge -lxge 
endif

swig:
	swig -outcurrentdir -o xgepy.cpp -I../ -c++ -python ../xge/xge.i


depend:
	makedepend -Y. *.cpp *.c *.h

clean:
	rm -Rf *.o Debug/ Release/ temp* *.o *.dylib *.a *.so


