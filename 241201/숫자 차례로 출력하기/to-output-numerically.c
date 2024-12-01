#include <stdio.h>
#include <time.h>
int main(void)
{
time_t tepoch=0, tnow = time(NULL);
struct tm * ptm_now;
ptm_now = gmtime(&tnow);
if (ptm_now)
printf("Now in UTC: %s", asctime(ptm_now));
ptm_now = localtime(&tnow);
if (ptm_now)
printf("Now in Local: %s", asctime(ptm_now));
printf("Epoch in UTC: %s", asctime(gmtime(&tepoch)));
printf("Epoch in Local: %s", 
asctime(localtime(&tepoch)));
return 0;
}