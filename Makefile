cc=gcc-8

CFLAGS= -Wall -Wextra  `pkg-config --cflags gtk+-3.0`

EXTRA_CFLAGS= -Wshadow -Wformat-overflow -Wformat-truncation -g3 

CLIBS= `pkg-config --libs gtk+-3.0`

SRC= ./core/src/*.c ./core/include/*.h   ./core/src/objects/*.c ./core/include/objects/*.h 

output= ./bin/release.exe

compile: $(SRC)
	@$(cc) $(CFLAGS) $(EXTRA_CFLAGS) $(SRC) -o $(output) $(CLIBS)\
	&& echo "Compilation ended successfully"


build:
	@echo "*********** Compilation execution *********** "
	@/usr/bin/time --format="Build Duration: %E" make -s compile

launch:
	@echo "\n\n"
	@$(output)

all: build launch
	@echo "\n*********** fin du programme ***********"

debug: build
	gdb $(output)