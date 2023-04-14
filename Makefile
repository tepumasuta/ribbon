CONFIG:=default.conf
include ${CONFIG}

SUBPROJECTS=sandbox ribbon
export BASEDIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
ifeq ($(TARGET),DEBUG)
export BUILDDIR:=$(BASEDIR)/build/debug
endif
ifeq ($(TARGET),RELEASE)
export BUILDDIR:=$(BASEDIR)/build/release
endif
export SRC:=$(BASEDIR)/src
export OBJ:=$(BUILDDIR)/obj
export BIN:=$(BUILDDIR)/bin
export SRCR:=$(SRC)/ribbon
export SRCS:=$(SRC)/sandbox
export DINCLUDE:=-I$(SRCR) -I$(SRCS) -I$(SRC) -I$(SRCR)/vendor/easyloggingpp/src/
ifeq ($(OS),LINUX)
export CC:=g++
export PLATFORMOBJ=$(OBJ)/platform/linux
endif
export CONFIGFILE:=$(BASEDIR)/$(CONFIG)
DCFLAGS=-std=c++20 -Wall -Wextra -fconcepts-diagnostics-depth=2
DCFLAGS+=$(LOG_FLAGS)
export DDEFINES=-D RIB_PLATFORM_LINUX
export DLINK=-lglfw3 -lX11
export LIB:=$(BIN)/libribbon.so
export RIBBON_HEADERS:=$(addsuffix .hpp,$(addprefix $(SRCR)/,app log entry_point))
BINARIES=$(BIN)/sandbox $(LIB)

ifeq ($(TARGET),DEBUG)
DCFLAGS+=-O0 -ggdb -g3
endif
ifeq ($(TARGET),RELEASE)
DCFLAGS+=-O2 -g0
endif
export DCFLAGS
ifeq ($(ENABLE_ASSERTS),YES)
DDEFINES+=-D RIB_ENABLE_ASSERTS
endif


.PHONY: pure $(SUBPROJECTS) clean clean-vendor clean-pch clean-all create-infrastructure

sandbox: $(LIB)
$(SUBPROJECTS): create-infrastructure
	$(MAKE) -C $(SRC)/$@

pure:
	$(MAKE) -C $(SRC)/sandbox

$(LIB): ribbon

clean:
	-rm -f $(OBJ)/*.o $(OBJ)/events/*.o $(OBJ)/layers/*.o $(PLATFORMOBJ)/*.o $(BINARIES)

clean-vendor:
	-rm -f $(OBJ)/vendor/*.o

ifeq ($(CC),g++)
clean-pch:
	-rm -f $(SRCR)/pch/*.gch
endif

clean-all: clean clean-vendor clean-pch
clean-non-vendor: clean clean-pch

create-infrastructure:
	mkdir -p "$(OBJ)/vendor" "$(OBJ)/events" "$(OBJ)/layers" "$(PLATFORMOBJ)"\
			 "$(BIN)"
