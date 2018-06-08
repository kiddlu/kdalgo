all: main.exe

main.exe: main.c array.c sequential_search.c binary_search.c jump_search.c -lm
	gcc -std=c99 -o $@ $^

clean:
	rm main.exe*
