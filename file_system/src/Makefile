# 定義編譯器
CC = gcc

# 定義編譯選項
CFLAGS = -Wall -Wextra -O2

# 定義目標可執行檔案
TARGET = file_system_test

# 定義源文件

SRCS = file_system_test.c

# 定義物件文件
OBJS = $(SRCS:.c=.o)

# 目標規則
all: $(TARGET)

# 可執行文件規則
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 物件文件規則
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理規則
clean:
	rm -f $(TARGET) $(OBJS)

# 設定標準規則
.PHONY: all clean

