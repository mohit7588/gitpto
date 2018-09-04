#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
int fdr, fdw, er;
char rfile[20],wfile[20];
char buff[20];
printf("Enter file name to be copied:");
scanf("%s",rfile);
fdr=open(rfile,O_RDONLY);
if(fdr==-1)
{
printf("File does not exist");
return 1;
}
er=read(fdr,buff,20);
if(er==-1)
{
printf("Cannot Read File!!!");
return 1;
}
close(fdr);
printf("Enter destination file name:");
scanf("%s",wfile);
fdw=open(wfile,O_WRONLY | O_CREAT,0777);
if(fdw==-1)
{
printf("Cannot open File !!!");
return 1;
}
write(fdw,buff,5);
close(fdw);
printf("File Copied Successfully");
}
