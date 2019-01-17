/* Programming Exercise 4-5 */
#include <stdio.h>
int main(void)
{
	float download_bandwidth;
	float file_size;
	float download_time;
	printf("Enter the download width:");
	scanf("%f", &download_bandwidth);
	printf("Enter the file size:");
	scanf("%f", &file_size);
	download_time = file_size / (download_bandwidth / 8);
	printf("At %.2f megabits per second, a file of %.2f megabytes\n", download_bandwidth, file_size);
	printf("downloads in %.2f seconds.\n", download_time); 

	return 0;
}