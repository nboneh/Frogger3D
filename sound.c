#include "Frogger3D.h"

int PlaySoundHelper(const char * soundname){
	char * command

	#ifdef __APPLE__
		= "afplay";
	#else
		 = "aplay";
	#endif
		
	char* folder = "sounds/";
	char str[90];
	strcpy(str, command);
	strcat(str, " ");
	strcat(str, folder);
	strcat(str, soundname);
	
    return system(str);
}

void *PlaySoundThread(void *soundname){
	int ret = PlaySoundHelper(soundname);
	pthread_exit((void *) &ret);
}


void PlaySound(const char *soundname)
{
	//For some reason on mac forking works and on linux threading works
	#ifdef __APPLE__
		if(!fork()){
			PlaySoundHelper(soundname);
			exit(0);
		}
	#else
		pthread_t thread[0];
		pthread_create(&thread[0], NULL, PlaySoundThread, (void *)soundname);
	#endif
	
}

