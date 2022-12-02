BINARY=$(LIB)
HEADER=$(BIN)/ribbon.hxx
LIBFLAGS=-shared -Wl,-soname,$(notdir $@)
OBJECTS:=ribbon.o
HEADERED:=ribbon.o
SOURCED:=ribbon.o
HEADERNAMES=ribbon

.PHONY: all sync_vendor

all: $(BINARY) $(HEADER)

SRCR:=$(SRC)/ribbon
HEADERES:=$(addsuffix .hpp,$(HEADERNAMES))

$(HEADER): $(SRCR)/ribbon.hxx
	cp $< $(BIN)/ribbon.hxx
	$(MAKE) sync_vendor

sync_vendor: $(SRCR)/ribbon.hxx
	-rm -f $(VENDOR)/$(notdir $(HEADER))
	cp $(HEADER) $(VENDOR)/$(notdir $(HEADER))

.SECONDEXPANSION:
$(OBJ)/ribbon_REQS:=$(SRCR)/common.hpp

$(addprefix $(OBJ)/,$(SOURCED)): $$(SRCR)/$$(notdir $$(basename $$@)).cpp
$(addprefix $(OBJ)/,$(HEADERED)): $$(SRCR)/$$(notdir $$(basename $$@)).hpp
$(addprefix $(OBJ)/,$(OBJECTS)): $$($$@_REQS)

$(BINARY): $$(addprefix $(OBJ)/,$(OBJECTS))
	$(CC) $(DCFLAGS) -fvisibility=hidden $(LIBFLAGS) -o $(BINARY) $^ -lc

$(OBJ)/%.o:
	$(CC) $(DCFLAGS) -fvisibility=hidden -fPIC -c $< -o $@
