SUBPROJECTS=sandbox ribbon
export DEBUG?=
export BASEDIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
export SRC:=$(BASEDIR)/src
export OBJ:=$(BASEDIR)/obj
export BIN:=$(BASEDIR)/bin
export SRCR:=$(SRC)/ribbon
export SRCS:=$(SRC)/sandbox
export DINCLUDE:=-I$(SRCR) -I$(SRCS) -I$(SRC) -I$(SRCR)/vendor/easyloggingpp/src/
export CC=g++
export DCFLAGS=-std=c++20 -Wall -Wextra
export DDEFINES=-D RIB_PLATFORM_LINUX
export DLINK=
export LIB:=$(BIN)/libribbon.so
export RIBBON_HEADERS:=$(addsuffix .hpp,$(addprefix $(SRCR)/,app log entry_point))
BINARIES=$(BIN)/sandbox $(LIB)

.PHONY: pure $(SUBPROJECTS) clean clean-vendor

sandbox: $(LIB)
$(SUBPROJECTS):
	$(MAKE) -C $(SRC)/$@

pure:
	$(MAKE) -C $(SRC)/sandbox

$(LIB): ribbon

clean:
	-rm -f obj/*.o $(BINARIES)

clean-vendor:
	-rm -f obj/vendor/*.o

