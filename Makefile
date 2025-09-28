build:
	g++ test.cpp main.cpp -o test.exe

.PHONY: clean
clean:
	rm test.exe