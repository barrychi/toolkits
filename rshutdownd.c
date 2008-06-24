/*
 *	rshutdownd.c
 *
 *	remote shutdown Linux daemon
 * */

#include <fcntl.h>
#include <sys/resource.h>
#include <signal.h>
#include <stdlib.h>
#include <shadow.h>

#define _XOPEN_SOURCE
#include <unistd.h>


int check_passwd(const char * username,const char * password)
{
	struct spwd * s=getspnam(username);
	char * cp;
	if(s==NULL) return 0;
	cp=(char*)crypt(password,s->sp_pwdp);

	if(strcmp(cp,s->sp_pwdp)==0)
		return 1;
	else
		return 0;
}

void daemonize()
{
	int i,fd0,fd1,fd2;
	pid_t pid;
	struct rlimit r1;
	struct sigaction sa;
	umask(0);

	if(getrlimit(RLIMIT_NOFILE,&r1)<0) {
	}
	if((pid=fork())<0) {
	}
	else if(pid!=0) {
	        exit(0);
	}

	setsid();

	sa.sa_handler=SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;
	if(sigaction(SIGHUP,&sa,NULL)<0) {
	}
        if((pid=fork())<0) {
        }
        else if(pid>0) {
		exit(0);
	}
       if(chdir("/")<0) {
       }
       if(r1.rlim_max==RLIM_INFINITY) {
	       r1.rlim_max=1024;
       }
       for(i=0;i<r1.rlim_max;i++) {
	       close(i);
       }
       fd0=open("/dev/null",O_RDWR);
       fd1=dup(0);
       fd2=dup(0);
}

int main()
{
	return 0;
}
