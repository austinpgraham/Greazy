CC=gcc
CFLAGS=-I
BIN=./bin
ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

$(BIN)/greazy: ./cli/main.c
	mkdir -p $(BIN)
	$(CC) -o $@ ./cli/main.c $(CFLAGS)

clean:
	rm -rf ./bin

install: $(BIN)/greazy
	install -d $(PREFIX)/bin
	install $(BIN)/greazy $(PREFIX)/bin

uninstall: $(PREFIX)/bin/greazy
	rm $(PREFIX)/bin/greazy
