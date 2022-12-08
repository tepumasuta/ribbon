DEFINES=-D RIB_BUILD_DLL
INCLUDE=
BINARY=$(LIB)
LIBFLAGS=-shared -Wl,-soname,$(notdir $@)
OBJECTS:=app.o log.o vendor/easylogging++.o
HEADERED:=app.o log.o
SOURCED:=app.o log.o
VENDOR:=$(SRCR)/vendor
EASYLOGGING:=$(VENDOR)/easyloggingpp/src

.PHONY: all

all: $(BINARY) $(HEADER)


$(OBJ)/app_REQS:=$(SRCR)/common.hpp
$(OBJ)/log_REQS:=$(SRCR)/common.hpp $(EASYLOGGING)/easylogging++.cc $(EASYLOGGING)/easylogging++.h
$(OBJ)/vendor/easylogging++_REQS:=$(EASYLOGGING)/easylogging++.cc $(EASYLOGGING)/easylogging++.h
.SECONDEXPANSION:

$(addprefix $(OBJ)/,$(SOURCED)): $$(SRCR)/$$(notdir $$(basename $$@)).cpp
$(addprefix $(OBJ)/,$(HEADERED)): $$(SRCR)/$$(notdir $$(basename $$@)).hpp
$(addprefix $(OBJ)/,$(OBJECTS)): $$($$(basename $$@)_REQS)

$(BINARY): $$(addprefix $(OBJ)/,$(OBJECTS))
	$(CC) $(DDEFINES) $(DEFINES) $(DCFLAGS) $(DINCLUDE) $(INCLUDE) $(LIBFLAGS) -o $(BINARY) $^ -lc $(DLINK)

$(OBJ)/%.o:
	$(CC) $(DDEFINES) $(DEFINES) $(DCFLAGS) -fPIC -c $(DINCLUDE) $(INCLUDE) $< -o $@ $(DLINK)
