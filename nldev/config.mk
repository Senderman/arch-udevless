# nldev metadata
NAME = nldev
VERSION = 0.4

# Customize below to fit your system

# paths
PREFIX = /usr
MANPREFIX = ${PREFIX}/share/man

# includes and libs
INCS = -I. -I/usr/include
LIBS = -L/usr/lib -lc

# flags
CPPFLAGS = -DVERSION=\"${VERSION}\" -D_DEFAULT_SOURCE -D_GNU_SOURCE
CFLAGS = -pedantic -Wall -O2 ${INCS} ${CPPFLAGS}
LDFLAGS = ${LIBS}
#LDFLAGS = -s ${LIBS}

# compiler and linker
CC = cc

