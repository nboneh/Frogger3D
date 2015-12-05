#include "Frogger3D.h"



void *PlaySoundThread(void *soundname){
	
	char * command = "";

	#ifdef __APPLE__
		command = "afplay";
	#else
		command = "aplay";
	#endif
		
	char* folder = "sounds/";
	char str[90];
	strcpy(str, command);
	strcat(str, " ");
	strcat(str, folder);
	strcat(str, soundname);
	
    int i = system(str);
    if(i == 0);
	pthread_exit(NULL);
}

void PlaySound(const char *soundname)
{
	pthread_t thread[0];
	
	pthread_create(&thread[0], NULL, PlaySoundThread, (void *)soundname);
	
}

