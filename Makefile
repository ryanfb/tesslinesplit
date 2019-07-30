all: tesslinesplit

tesslinesplit: tesslinesplit.cpp
	clang++ -std=c++11 -Wall -o $@ `pkg-config --cflags --libs tesseract lept` $^

clean:
	rm -fv tesslinesplit
