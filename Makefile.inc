# platform name
PLATFORM_NAME=PLATFORM_$(shell uname)

# current gcc optimization
OPTIMIZATION=-O3

# C compilation flags
CFLAGS=-w -fPIC -fno-common

# C++ compilation flags
CXXFLAGS=-w -fPIC ${OPTIMIZATION} -D${PLATFORM_NAME} 

# default link flags
LDFLAGS=-fPIC


# --- windows ---
ifeq ($(PLATFORM_NAME),PLATFORM_CYGWIN_NT-6.1-WOW64)
PYTHON_SITE_PACKAGES=/cygdrive/c/Python32/Lib/site-packages
endif


# --- LINUX ---
ifeq ($(PLATFORM_NAME),PLATFORM_Linux)
    PYTHON_INCLUDE=$$(pkg-config --cflags python3)
    PYTHON_SITE_PACKAGES=$$(python3 -c "import site; print(site.getsitepackages()[0])")
endif

# ---- DARWIN ----
ifeq ($(PLATFORM_NAME),PLATFORM_Darwin)
PYTHON_INCLUDE_DIRECTORY=/Library/Frameworks/Python.framework/Versions/3.2/include/python3.2
PYTHON_SITE_PACKAGES=/Library/Frameworks/Python.framework/Versions/3.2/lib/python3.2/site-packages
CFLAGS+= -arch i386 -arch x86_64
CXXFLAGS+= -arch i386 -arch x86_64
LDFLAGS+= -arch i386 -arch x86_64
endif
















