CONFIG:=default.conf
include ${CONFIG}

SUBPROJECTS=sandbox ribbon
export BASEDIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
export SRC:=$(BASEDIR)/src
export OBJ:=$(BASEDIR)/obj
export BIN:=$(BASEDIR)/bin
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

.PHONY: pure $(SUBPROJECTS) clean clean-vendor clean-pch clean-all create-obj-infrastructure

sandbox: $(LIB)
$(SUBPROJECTS): create-obj-infrastructure
	$(MAKE) -C $(SRC)/$@

pure:
	$(MAKE) -C $(SRC)/sandbox

$(LIB): ribbon

clean:
	-rm -f obj/*.o obj/events/*.o obj/layers/*.o $(PLATFORMOBJ)/*.o $(BINARIES)

clean-vendor:
	-rm -f obj/vendor/*.o

ifeq ($(CC),g++)
clean-pch:
	-rm -f $(SRCR)/pch/*.gch
endif

clean-all: clean clean-vendor clean-pch
clean-non-vendor: clean clean-pch

create-obj-infrastructure:
	if [ ! -d "$(OBJ)" ]; then mkdir "$(OBJ)"; fi
	if [ ! -d "$(OBJ)/vendor" ]; then mkdir "$(OBJ)/vendor"; fi
	if [ ! -d "$(OBJ)/events" ]; then mkdir "$(OBJ)/events"; fi
	if [ ! -d "$(OBJ)/layers" ]; then mkdir "$(OBJ)/layers"; fi
	if [ ! -d "$(OBJ)/platform" ]; then mkdir "$(OBJ)/platform"; fi
	if [ ! -d "$(PLATFORMOBJ)" ]; then mkdir "$(PLATFORMOBJ)"; fi
