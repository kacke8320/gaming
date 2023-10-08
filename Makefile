SRC_DIR := ./src
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

build:
	@echo "------------------- Building -------------------"
	g++ $(SRCS) -o main -lsfml-graphics -lsfml-window -lsfml-system -lglfw

run: build
	./main

clean:
	rm main main.o
