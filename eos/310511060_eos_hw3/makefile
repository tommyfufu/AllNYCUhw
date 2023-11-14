ODIR=./obj
LDIR =./lib
IDIR = ./inc
OUT_DIR = ./

GPP = g++
CC = gcc
CFLAGS=-w -lpthread -I${IDIR}

main_file = hw3
DEP_FILE = $(main_file) sem_u socket_u calc_func

_DEPS = $(patsubst %,%.h,$(filter-out $(main_file), $(DEP_FILE)))
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ = $(patsubst %,$(ODIR)/%.o,$(DEP_FILE))

n_OBJ = $(patsubst %,$(ODIR)/%.o,$(filter-out $(main_file), $(DEP_FILE)))

EXE = $(patsubst %,$(OUT_DIR)/%,$(main_file))

all : $(EXE)
	echo $(OBJ);

$(ODIR)/%.o: %.cpp $(IDIR)/*.h
	mkdir -p $(dir $@)
	$(GPP) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ) 
	mkdir -p $(dir $@)
	$(GPP) -o $@ $^ $(CFLAGS)


.PHONY: clean
clean:
	rm -f $(ODIR)/*.o