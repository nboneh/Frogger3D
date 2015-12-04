#include "Frogger3D.h"

void PlaySound(const char *soundname)
{
	char * command = "";
	#ifdef __APPLE__
		command = "afplay";
	#else
		command = "aplay";
	#endif
		
	char *folder = "sounds/";
	char str[90];
	strcpy(str, command);
	strcat(str, " ");
	strcat(str, folder);
	strcat(str, soundname);
	
	int pid;
	if((pid = fork()) == 0){
		system(str);
		exit(0);
	}
}