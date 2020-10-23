cc=gcc-8

CFLAGS= -Wall -Wextra `pkg-config --cflags gtk+-3.0`

CLIBS= `pkg-config --libs gtk+-3.0`

SRC= ./core/src/Partie1.c ./core/include/Partie1.h

output= ./bin/release.exe



compile: $(SRC)
	@$(cc) $(CFLAGS) $(SRC) -o $(output) $(CLIBS)\
	&& echo "Compilation ended successfully"


build:
	@echo "*********** Compilation execution *********** "
	@/usr/bin/time --format="Build Duration: %E" make -s compile

launch:
	@echo "\n\n"
	@./bin/release.exe

all: build launch