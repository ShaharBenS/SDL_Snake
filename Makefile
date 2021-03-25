CXX_FLAGS = -g -pthread

TryingOutSDL: mkdirs main.o snake.o bodylink.o autoupdated.o
	g++ .obj/main.o .obj/snake.o .obj/bodylink.o .obj/autoupdated.o /usr/local/lib/libSDL2.so -o TryingOutSDL $(CXX_FLAGS)

bodylink.o: logic/BodyLink.h logic/BodyLink.cpp
	g++ -c logic/BodyLink.cpp -o .obj/bodylink.o $(CXX_FLAGS)

autoupdated.o: logic/AutoUpdated.cpp logic/AutoUpdated.h
	g++ -c logic/AutoUpdated.cpp -o .obj/autoupdated.o $(CXX_FLAGS)

snake.o: logic/Snake.cpp logic/Snake.h
	g++ -c logic/Snake.cpp -o .obj/snake.o $(CXX_FLAGS)

main.o: main.cpp
	g++ -c main.cpp -o .obj/main.o $(CXX_FLAGS)

.PHONY: clean

mkdirs:
	mkdir -p .obj

clean:
	rm -rf *.o TryingOutSDL