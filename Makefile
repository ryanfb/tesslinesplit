all: tesslinesplit

tesslinesplit: tesslinesplit.cpp
	g++ -Wall -o $@ `pkg-config --cflags --libs tesseract lept` $^

clean:
	rm -fv tesslinesplit
