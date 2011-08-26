# dwm version
VERSION = `git rev-parse HEAD`
COMMIT  = `git log --format=%B -n 1 HEAD | head -n1`

# Customize below to fit your system

# paths
PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib

# Xinerama
XINERAMALIBS = -L${X11LIB} `pkg-config --libs xinerama`
XINERAMAFLAGS = -DXINERAMA

# Xft, comment if you don't want it
XFTINC = `pkg-config --cflags xft pango pangoxft`
XFTLIBS = -L${X11LIB} `pkg-config --libs xft pango pangoxft`
XFTFLAGS = -DXFT

# includes and libs
INCS = -I. -I/usr/include -I${X11INC} ${XFTINC}
LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 ${XINERAMALIBS} ${XFTLIBS}

# flags
#CFLAGS = -std=c99 -pedantic -Wall -march=core2 -mtune=core2 -O2 ${INCS} ${DEFINES}
CFLAGS = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${DEFINES} ${XINERAMAFLAGS} ${XFTFLAGS}
#LDFLAGS = -s ${LIBS}
LDFLAGS = -g ${LIBS}

# compiler and linker
CC = cc

