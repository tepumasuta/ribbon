include ${CONFIGFILE}

DEFINES=-DRIB_BUILD_DLL -DGLFW_INCLUDE_NONE
BINARY=$(LIB)
LIBFLAGS=-shared -Wl,-soname,$(notdir $@)
RIBOBJS=app.o log.o events/event_printer.o layers/layer.o layers/layer_stack.o layers/layer_printer.o
VENDOROBJS:=vendor/easylogging++.o vendor/glad.o
HEADERED:=app.o log.o layers/layer.o layers/layer_stack.o
SOURCED:=app.o log.o events/event_printer.o layers/layer.o layers/layer_stack.o layers/layer_printer.o
VENDOR:=$(SRCR)/vendor
EVENTS:=$(SRCR)/events
LAYERS:=$(SRCR)/layers
UTILS:=$(SRCR)/utils
EASYLOGGING:=$(VENDOR)/easyloggingpp/src
GLAD:=$(VENDOR)/glad
INCLUDE:=-I$(VENDOR)/glfw/include/ -I$(VENDOR)/glad/include
PCHSRC:=$(SRCR)/pch
WINDOWHEADERS=$(SRCR)/window.hpp
EVENTHEADERS=$(EVENTS)/event.hpp $(EVENTS)/app_event.hpp $(EVENTS)/key_event.hpp $(EVENTS)/mouse_event.hpp
LAYERHEADERS=$(LAYERS)/layer.hpp $(LAYERS)/layer_stack.hpp
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

$(OBJ)/app_REQS:=$(SRCR)/common.hpp $(UTILS)/category.hpp $(UTILS)/enum.hpp $(WINDOWHEADERS) $(EVENTHEADERS) $(LAYERHEADERS)
$(OBJ)/log_REQS:=$(SRCR)/common.hpp $(EASYLOGGING)/easylogging++.cc $(EASYLOGGING)/easylogging++.h
$(OBJ)/vendor/easylogging++_REQS:=$(EASYLOGGING)/easylogging++.cc $(EASYLOGGING)/easylogging++.h
$(OBJ)/vendor/glad_REQS:=$(GLAD)/src/glad.c $(GLAD)/include/glad/glad.h
$(OBJ)/platform/linux/linux_window_REQS:=$(SRCR)/window.hpp $(EVENTHEADERS)
$(OBJ)/events/event_printer_REQS:=$(EVENTHEADERS)
$(OBJ)/layers/layer_stack_REQS:=$(LAYERS)/layer.hpp
$(OBJ)/layers/layer_printer_REQS:=$(LAYERHEADERS)
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
