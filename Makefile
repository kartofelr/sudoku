SRC_PATH=src
BUILD_PATH=build
BIN_PATH=${BUILD_PATH}/bin
OBJ_PATH=${BUILD_PATH}/obj

CC=clang
CFLAGS=-Iinclude -O0 -Werror -Wall -g
COBJFLAGS := $(CFLAGS) -c


TARGET_NAME=sudoku

TARGET=${BIN_PATH}/${TARGET_NAME}

SRC=$(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ=$(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

CLEAN_LIST=$(TARGET) \
		   $(OBJ)

default: makedir all

# non-phony targets
$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c*
	$(CC) $(COBJFLAGS) -o $@ $<

.PHONY: makedir
makedir:
	@mkdir -p $(BIN_PATH) $(OBJ_PATH) $(DBG_PATH)

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(CLEAN_LIST)

.PHONY: run
run: $(TARGET)
	$(TARGET)

