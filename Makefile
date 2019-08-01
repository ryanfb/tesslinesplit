PREFIX ?= /usr/local

all: tesslinesplit-ocular tesslinesplit-kraken

tesslinesplit-ocular: tesslinesplit-ocular.cpp
	g++ -std=c++11 -Wall -o $@ `pkg-config --cflags --libs tesseract lept` $^

tesslinesplit-kraken: tesslinesplit-kraken.cpp
	g++ -std=c++11 -Wall -o $@ `pkg-config --cflags --libs tesseract lept` $^

clean:
	rm -fv tesslinesplit-ocular tesslinesplit-kraken

install: tesslinesplit-ocular tesslinesplit-kraken
	install -m 557 tesslinesplit-ocular tesslinesplit-kraken $(PREFIX)/bin

uninstall:
	rm -v $(PREFIX)/bin/tesslinesplit-ocular $(PREFIX)/bin/tesslinesplit-kraken

.PHONY: all install clean uninstall
