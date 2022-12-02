DEFINES=-D RIB_BUILD_DLL
BINARY=$(LIB)
LIBFLAGS=-shared -Wl,-soname,$(notdir $@)
OBJECTS:=
HEADERED:=
SOURCED:=

.PHONY: all

all: $(BINARY) $(HEADER)

SRCR:=$(SRC)/ribbon

.SECONDEXPANSION:
$(OBJ)/ribbon_REQS:=$(SRCR)/common.hpp

$(addprefix $(OBJ)/,$(SOURCED)): $$(SRCR)/$$(notdir $$(basename $$@)).cpp
$(addprefix $(OBJ)/,$(HEADERED)): $$(SRCR)/$$(notdir $$(basename $$@)).hpp
$(addprefix $(OBJ)/,$(OBJECTS)): $$($$@_REQS)

$(BINARY): $$(addprefix $(OBJ)/,$(OBJECTS))
	$(CC) $(DDEFINES) $(DEFINES) $(DCFLAGS) -fvisibility=hidden $(LIBFLAGS) -o $(BINARY) $^ -lc

$(OBJ)/%.o:
	$(CC) $(DDEFINES) $(DEFINES) $(DCFLAGS) -fvisibility=hidden -fPIC -c $< -o $@
