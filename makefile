all:
	g++ *.cpp -o main.out

run:
	./main.out	
	
clean:
	rm main.out