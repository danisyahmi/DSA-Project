CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main

TEXTFILES := PATIENT.txt PATIENTDATA.txt

all: $(TEXTFILES) $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

# Create binary
$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	@mkdir -p $(BIN)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

# Create text files if not exist
$(TEXTFILES):
	@for file in $(TEXTFILES); do \
		if [ ! -f $$file ]; then \
			echo "Creating $$file..."; \
			touch $$file; \
		fi \
	done

clean:
	-rm -f $(BIN)/*
