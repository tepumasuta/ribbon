include ${CONFIGFILE}

DEFINES=-D RIB_BUILD_DLL
BINARY=$(LIB)
LIBFLAGS=-shared -Wl,-soname,$(notdir $@)
RIBOBJS=app.o log.o events/event_printer.o
VENDOROBJS:=vendor/easylogging++.o
HEADERED:=app.o log.o
SOURCED:=app.o log.o events/event_printer.o
VENDOR:=$(SRCR)/vendor
EVENTS:=$(SRCR)/events
UTILS:=$(SRCR)/utils
EASYLOGGING:=$(VENDOR)/easyloggingpp/src
INCLUDE:=-I$(VENDOR)/glfw/include/
PCHSRC:=$(SRCR)/pch
WINDOWHEADERS=$(SRCR)/window.hpp
EVENTHEADERS=$(EVENTS)/event.hpp $(EVENTS)/app_event.hpp $(EVENTS)/key_event.hpp $(EVENTS)/mouse_event.hpp
ifeq ($(CC),g++)
PCHOBJ:=$(PCHSRC)/ribpch.hpp.gch
endif
ifeq ($(OS),LINUX)
PLATFORMPREFIX:=platform/linux
PLATFORMSRC=$(SRCR)/$(PLATFORMPREFIX)
WINDOWHEADERS+=$(PLATFORMSRC)/linux_window.hpp
RIBOBJS+=$(PLATFORMPREFIX)/linux_window.o
HEADERED+=$(PLATFORMPREFIX)/linux_window.o
SOURCED+=$(PLATFORMPREFIX)/linux_window.o
endif
OBJECTS:=$(RIBOBJS) $(VENDOROBJS)

.PHONY: all

all: $(PCHOBJ) $(BINARY)

$(OBJ)/app_REQS:=$(SRCR)/common.hpp $(UTILS)/category.hpp $(UTILS)/enum.hpp $(WINDOWHEADERS) $(EVENTHEADERS)
$(OBJ)/log_REQS:=$(SRCR)/common.hpp $(EASYLOGGING)/easylogging++.cc $(EASYLOGGING)/easylogging++.h
$(OBJ)/vendor/easylogging++_REQS:=$(EASYLOGGING)/easylogging++.cc $(EASYLOGGING)/easylogging++.h
$(OBJ)/platform/linux/linux_window_REQS:=$(SRCR)/window.hpp $(EVENTHEADERS)
$(OBJ)/events/event_printer_REQS:=$(EVENTHEADERS)
.SECONDEXPANSION:


$(addprefix $(OBJ)/,$(SOURCED)): $$(subst $$(OBJ),$$(SRCR),$$(basename $$@)).cpp
$(addprefix $(OBJ)/,$(HEADERED)): $$(subst $$(OBJ),$$(SRCR),$$(basename $$@)).hpp
$(addprefix $(OBJ)/,$(OBJECTS)): $$($$(basename $$@)_REQS)

$(RIBOBJS): $(PCHOBJ)

$(BINARY): $$(addprefix $(OBJ)/,$(OBJECTS))
	$(CC) $(DDEFINES) $(DEFINES) $(DCFLAGS) $(DINCLUDE) $(INCLUDE) $(LIBFLAGS) -o $(BINARY) $^ -lc $(DLINK)

$(OBJ)/%.o:
	$(CC) $(DDEFINES) $(DEFINES) $(DCFLAGS) -fPIC -c $(DINCLUDE) $(INCLUDE) $< -o $@ $(DLINK)

ifeq ($(CC),g++)
$(PCHOBJ): $(PCHSRC)/ribpch.hpp
	$(CC) $(DDEFINES) $(DEFINES) $(DCFLAGS) -fPIC -c $(DINCLUDE) $(INCLUDE) $< -o $@
endif
