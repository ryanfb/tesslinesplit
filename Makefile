all: tesslinesplit

tesslinesplit: tesslinesplit.cpp
	g++ -o $@ `pkg-config --cflags --libs tesseract lept` $^

clean:
	rm -fv tesslinesplit
