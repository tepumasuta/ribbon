SUBPROJECTS=sandbox ribbon
export DEBUG?=
export BASEDIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
export SRC:=$(BASEDIR)/src
export OBJ:=$(BASEDIR)/obj
export BIN:=$(BASEDIR)/bin
export VENDOR:=$(BASEDIR)/vendor
export CC=g++
export DCFLAGS=-std=c++20 -Wall -Wextra
export LIB:=$(BIN)/libribbon.so
export LIBHEADER:=$(VENDOR)/ribbon.hxx
BINARIES=$(BIN)/sandbox $(LIB) $(BIN)/ribbon.hxx

.PHONY: $(SUBPROJECTS) clean

sandbox: $(LIB)
$(SUBPROJECTS):
	$(MAKE) -C $(SRC)/$@

$(LIB): ribbon

clean:
	-rm -f obj/*.o $(BINARIES)

