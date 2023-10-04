build:
				g++ ./src/*.cpp -lSDL2 -lSDL2_image -o game

run:
				./game

clean:
				rm game
