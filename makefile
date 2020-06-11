prog:main.o bg.o coin.o collision1.o enemie.o enigme.o perso.o scrolling.o vie.o score.o
	gcc main.o bg.o coin.o collision1.o enemie.o enigme.o perso.o scrolling.o vie.o score.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer  -o prog -g

main.o:main.c
	gcc -c main.c -g

bg.o:bg.c 
	gcc -c bg.c -g 

coin.o:coin.c
	gcc -c coin.c -g

collision1.o:collision1.c
	gcc -c collision1.c -g

enemie.o:enemie.c
	gcc -c enemie.c -g

vie.o:vie.c
	gcc -c vie.c -g

scrolling.o:scrolling.c
	gcc -c scrolling.c -g

enigme.o:enigme.c
	gcc -c enigme.c -g

score.o:score.c
	gcc -c score.c -g

perso.o:perso.c
	gcc -c perso.c -g

