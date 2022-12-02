SUBPROJECTS=sandbox ribbon
export DEBUG?=
export BASEDIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
export SRC:=$(BASEDIR)/src
export OBJ:=$(BASEDIR)/obj
export BIN:=$(BASEDIR)/bin
export SRCR:=$(SRC)/ribbon
export SRCS:=$(SRC)/sandbox
export DINCLUDE:=-I$(SRCR) -I$(SRCS) -I$(SRC) -I$(SRCR)/vendor/include/plog
export CC=g++
export DCFLAGS=-std=c++20 -Wall -Wextra
export DDEFINES=-D RIB_PLATFORM_LINUX
export LIB:=$(BIN)/libribbon.so
BINARIES=$(BIN)/sandbox $(LIB)

.PHONY: pure $(SUBPROJECTS) clean

sandbox: $(LIB)
$(SUBPROJECTS):
	$(MAKE) -C $(SRC)/$@

pure:
	$(MAKE) -C $(SRC)/sandbox

$(LIB): ribbon

clean:
	-rm -f obj/*.o $(BINARIES)

