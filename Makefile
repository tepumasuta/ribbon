SUBPROJECTS=sandbox ribbon
export DEBUG?=
export BASEDIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
export SRC:=$(BASEDIR)/src
export OBJ:=$(BASEDIR)/obj
export BIN:=$(BASEDIR)/bin
export CC=g++
export DCFLAGS=-std=c++20 -Wall -Wextra
export DDEFINES=-D RIB_PLATFORM_LINUX
export LIB:=$(BIN)/libribbon.so
BINARIES=$(BIN)/sandbox $(LIB)

.PHONY: $(SUBPROJECTS) clean

sandbox: $(LIB)
$(SUBPROJECTS):
	$(MAKE) -C $(SRC)/$@

$(LIB): ribbon

clean:
	-rm -f obj/*.o $(BINARIES)

