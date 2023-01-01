include ${CONFIGFILE}

DEFINES=-D RIB_BUILD_DLL
INCLUDE=
BINARY=$(LIB)
LIBFLAGS=-shared -Wl,-soname,$(notdir $@)
RIBOBJS:=app.o log.o
VENDOROBJS:=vendor/easylogging++.o
OBJECTS:=$(RIBOBJS) $(VENDOROBJS)
HEADERED:=app.o log.o
SOURCED:=app.o log.o
VENDOR:=$(SRCR)/vendor
EVENTS:=$(SRCR)/events
UTILS:=$(SRCR)/utils
EASYLOGGING:=$(VENDOR)/easyloggingpp/src
PCHSRC:=$(SRCR)/pch
ifeq ($(OS),LINUX)
PCHOBJ:=$(PCHSRC)/ribpch.hpp.gch
endif

.PHONY: all

all: $(PCHOBJ) $(BINARY)

$(OBJ)/app_REQS:=$(SRCR)/common.hpp $(EVENTS)/event.hpp $(UTILS)/category.hpp $(UTILS)/enum.hpp 
$(OBJ)/log_REQS:=$(SRCR)/common.hpp $(EASYLOGGING)/easylogging++.cc $(EASYLOGGING)/easylogging++.h
$(OBJ)/vendor/easylogging++_REQS:=$(EASYLOGGING)/easylogging++.cc $(EASYLOGGING)/easylogging++.h
.SECONDEXPANSION:

$(addprefix $(OBJ)/,$(SOURCED)): $$(SRCR)/$$(notdir $$(basename $$@)).cpp
$(addprefix $(OBJ)/,$(HEADERED)): $$(SRCR)/$$(notdir $$(basename $$@)).hpp
$(addprefix $(OBJ)/,$(OBJECTS)): $$($$(basename $$@)_REQS)

$(RIBOBJS): $(PCHOBJ)

$(BINARY): $$(addprefix $(OBJ)/,$(OBJECTS))
	$(CC) $(DDEFINES) $(DEFINES) $(DCFLAGS) $(DINCLUDE) $(INCLUDE) $(LIBFLAGS) -o $(BINARY) $^ -lc $(DLINK)

$(OBJ)/%.o:
	$(CC) $(DDEFINES) $(DEFINES) $(DCFLAGS) -fPIC -c $(DINCLUDE) $(INCLUDE) $< -o $@ $(DLINK)

ifeq ($(OS),LINUX)
$(PCHOBJ): $(PCHSRC)/ribpch.hpp
	$(CC) $(DDEFINES) $(DEFINES) $(DCFLAGS) -fPIC -c $(DINCLUDE) $(INCLUDE) $< -o $@
endif
