#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char* argv[]) {
	int i, ran;
	pid_t pid, cpid;

	// perf record -F 99 -p 13204 -g -- sleep 30
	char *args[]={"/usr/bin/perf", "record", "-F", "99", "-g", "--", "sleep", "30", NULL}; 

	pid = fork();

	if (pid == 0) {
		printf("Child here!\n");
		execvp(args[0], args);
	} else {
		printf("Parent here! Child PID is %d\n", pid);
		cpid = wait(NULL);
		printf("Finished waiting! %d\n", cpid);
	}

	return 0;
}
