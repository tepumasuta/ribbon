DEFINES=-D RIB_BUILD_DLL
BINARY=$(LIB)
LIBFLAGS=-shared -Wl,-soname,$(notdir $@)
OBJECTS:=app.o
HEADERED:=app.o
SOURCED:=app.o

.PHONY: all

all: $(BINARY) $(HEADER)


.SECONDEXPANSION:
$(OBJ)/app_REQS:=$(SRCR)/common.hpp

$(addprefix $(OBJ)/,$(SOURCED)): $$(SRCR)/$$(notdir $$(basename $$@)).cpp
$(addprefix $(OBJ)/,$(HEADERED)): $$(SRCR)/$$(notdir $$(basename $$@)).hpp
$(addprefix $(OBJ)/,$(OBJECTS)): $$($$@_REQS)

$(BINARY): $$(addprefix $(OBJ)/,$(OBJECTS))
	$(CC) $(DDEFINES) $(DEFINES) $(DCFLAGS) $(INCLUDE) $(LIBFLAGS) -o $(BINARY) $^ -lc

$(OBJ)/%.o:
	$(CC) $(DDEFINES) $(DEFINES) $(DCFLAGS) -fPIC -c $(INCLUDE) $< -o $@
