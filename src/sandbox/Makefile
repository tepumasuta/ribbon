BINARY=$(BIN)/sandbox
INCLUDE:=-I$(VENDOR)
LINK:=-L../../bin/ -lribbon
OBJECTS:=sandbox.o
SOURCED:=sandbox.o
HEADERED:=

.PHONY: all

all: $(BINARY)

SRCS:=$(SRC)/sandbox


.SECONDEXPANSION:

$(OBJ)/sandbox_REQS:=

$(addprefix $(OBJ)/,$(SOURCED)): $$(SRCS)/$$(notdir $$(basename $$@)).cpp
$(addprefix $(OBJ)/,$(HEADERED)): $$(SRCS)/$$(notdir $$(basename $$@)).hpp
$(addprefix $(OBJ)/,$(OBJECTS)): $$($$@_REQS)


$(BINARY): $$(addprefix $(OBJ)/,$(OBJECTS)) $(LIBHEADER)
	$(CC) $(DCFLAGS) $(INCLUDE) $^ -o $@ $(LINK)

$(OBJ)/%.o:
	$(CC) $(DCFLAGS) $(INCLUDE) -c $< -o $@ $(LINK)
