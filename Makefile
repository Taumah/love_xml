cc=gcc-8

CFLAGS= -Wall -Wextra  `pkg-config --cflags gtk+-3.0`

EXTRA_CFLAGS= -Werror -Wshadow -Wformat-overflow -Wformat-truncation -g3

CLIBS= `pkg-config --libs gtk+-3.0`

SRC= ./core/src/*.c ./core/include/*.h

output= ./bin/release.exe


compile: $(SRC)
	@$(cc) $(CFLAGS) $(EXTRA_CFLAGS) $(SRC) -o $(output) $(CLIBS)\
	&& echo "Compilation ended successfully"


build:
	@echo "*********** Compilation execution *********** "
	@/usr/bin/time --format="Build Duration: %E" make -s compile

launch:
	@echo "\n\n"
	@./bin/release.exe

all: build launch

debug: all
	