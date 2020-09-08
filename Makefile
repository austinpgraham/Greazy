CC=gcc
CFLAGS=-I
BIN=./bin

$(BIN)/greazy: ./cli/main.c
	mkdir -p $(BIN)
	$(CC) -o $@ ./cli/main.c $(CFLAGS)

clean:
	rm -rf ./bin
