build:
	gcc example.c -o example -lpthread
	gcc example4.c -o example4 -lpthread
	gcc add_serial.c -o add_serial -lpthread
	gcc add_serial1.c -o add_serial1 -lpthread
clean:
	rm example add_serial