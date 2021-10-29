all:	main.c pi_serial.c pi_multi-thread.c
	gcc -pthread -o main main.c
	make pi_serial
	make pi_multi-thread

pi_serial:	pi_serial.c
	gcc -o pi_serial pi_serial.c -lm

pi_multi-thread: pi_multi-thread.c
	gcc -pthread -o pi_multi-thread pi_multi-thread.c -lm
	
clean:	
	rm main pi_serial
