cc=gcc-8

CFLAGS= -Wall -Wextra


SRC= ./core/src/*c ./core/include/*.h

output= ./bin/release.exe



compile: $(SRC)
	@$(cc) $(CFLAGS) $(SRC) -o $(output) \
	&& echo "Compilation ended successfully"


build:
	@echo "*********** Compilation execution *********** "
	@/usr/bin/time --format="Build Duration: %E" make -s compile

launch:
	@echo "\n\n"
	@./bin/release.exe

all: build launch