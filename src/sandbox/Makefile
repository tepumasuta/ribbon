BINARY=$(BIN)/sandbox
LINK:=-L../../bin/ -lribbon
OBJECTS:=sandbox.o
SOURCED:=sandbox.o
HEADERED:=

.PHONY: all

all: $(BINARY)


.SECONDEXPANSION:

$(OBJ)/sandbox_REQS:=common.hpp $(RIBBON_HEADERS)

$(addprefix $(OBJ)/,$(SOURCED)): $$(SRCS)/$$(notdir $$(basename $$@)).cpp
$(addprefix $(OBJ)/,$(HEADERED)): $$(SRCS)/$$(notdir $$(basename $$@)).hpp
$(addprefix $(OBJ)/,$(OBJECTS)): $$($$(basename $$@)_REQS)


$(BINARY): $$(addprefix $$(OBJ)/,$$(OBJECTS)) $$(LIBHEADER)
	$(CC) $(DDEFINES) $(DCFLAGS) $(DINCLUDE) $^ -o $@ $(DLINK) $(LINK)

$(OBJ)/%.o:
	$(CC) $(DDEFINES) $(DCFLAGS) $(DINCLUDE) -c $< -o $@ $(DLINK) $(LINK)
