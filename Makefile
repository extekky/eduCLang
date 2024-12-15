# Имя исполняемого файла
TARGET=main

# Компилятор и флаги
CC=gcc
CFLAGS=-Wall -Wextra -I./src
LDFLAGS=

# Указываем директорию для объектных файлов
BUILD_DIR = .build_x86_64

# Указываем исходные файлы
SRCS = $(wildcard src/*.c)

# Список объектных файлов (заменяем .c на .o и добавляем путь к BUILD_DIR)
OBJS = $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Правило по умолчанию
all: $(BUILD_DIR) $(TARGET)

# Правило для создания директории для объектных файлов
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJS)
	$(CC) -o $@ $^

# Правило для компиляции исходных файлов в объектные файлы
$(BUILD_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Правило для очистки
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean

run: $(BUILD_DIR)/$(TARGET)
	./$(BUILD_DIR)/$(TARGET)