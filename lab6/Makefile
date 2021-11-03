all: pi_private.c pi_shared.c
	gcc -pthread -o pi_private pi_private.c -lm
	gcc -pthread -o pi_shared pi_shared.c -lm
pi_private: pi_private.c
	gcc -pthread -o pi_private pi_private.c -lm

pi_shared: pi_shared.c
	gcc -pthread -o pi_shared pi_shared.c -lm

clean: 
	rm pi_private pi_shared
	
