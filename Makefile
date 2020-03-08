OBJS= obj/Image.o obj/Pixel.o

FLAGS= -g -Wall 
CC = g++
SDL= -lSDL2 -lSDL2_ttf -lSDL2_image


all: bin/test bin/exemple bin/affichage

bin/test: obj/mainTest.o $(OBJS)
	$(CC) -g obj/mainTest.o $(OBJS) -o bin/test $(SDL)

bin/exemple: obj/mainExemple.o $(OBJS)
	$(CC) -g obj/mainExemple.o $(OBJS) -o bin/exemple $(SDL)

bin/affichage: obj/mainAffichage.o $(OBJS)
	$(CC) -g obj/mainAffichage.o $(OBJS) -o bin/affichage $(SDL)

obj/mainExemple.o: src/mainExemple.cpp src/Image.h src/Pixel.h
	$(CC) $(FLAGS) -c src/mainExemple.cpp -o obj/mainExemple.o

obj/mainTest.o: src/mainTest.cpp src/Image.h src/Pixel.h
	$(CC) $(FLAGS) -c src/mainTest.cpp -o obj/mainTest.o

obj/mainAffichage.o: src/mainAffichage.cpp src/Image.h src/Pixel.h
	$(CC) $(FLAGS) -c src/mainAffichage.cpp -o obj/mainAffichage.o

obj/Image.o: src/Image.h src/Image.cpp src/Pixel.h
	$(CC) $(FLAGS) -c src/Image.cpp -o obj/Image.o

obj/Pixel.o: src/Pixel.cpp src/Pixel.h
	$(CC) $(FLAGS) -c src/Pixel.cpp -o obj/Pixel.o


clean:
	rm obj/*.o
	rm bin/*
				
veryclean: clean
