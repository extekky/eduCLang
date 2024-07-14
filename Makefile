TARGET = eduCLang

SRC_DIR = src
BUILD_DIR = build

CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -I/usr/local/include  

LDFLAGS = -L/usr/local/lib -ljansson  

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: run
run: $(BUILD_DIR)/$(TARGET)
	./$(BUILD_DIR)/$(TARGET)


# Объяснение флагов:
#     -I/usr/local/include:
#         Этот флаг добавляет путь /usr/local/include к списку директорий, 
# 		  в которых компилятор ищет заголовочные файлы. Это необходимо для 
# 		  включения заголовков Jansson, таких как jansson.h.
#     -L/usr/local/lib:
#         Этот флаг добавляет путь /usr/local/lib к списку директорий, в 
# 		  которых компилятор ищет библиотечные файлы. Это необходимо для 
# 		  нахождения библиотечного файла Jansson (libjansson.so или libjansson.a).
#     -ljansson:
#         Этот флаг указывает компилятору на необходимость линковки с библиотекой 
# 		  Jansson. Префикс -l говорит компилятору искать файл библиотеки с именем 
# 		  libjansson.so или libjansson.a.