#include <stdio.h>
#include <time.h>

int main() {
    // Get the current date and time
    time_t now;
    struct tm newyear;
    double seconds;

    // Set the date for the end of the year (December 31, 23:59:59)
    time(&now); // Get the current time
    newyear = *localtime(&now); // Convert the current time to a struct tm
    newyear.tm_hour = 23;
    newyear.tm_min = 59;
    newyear.tm_sec = 59;
    newyear.tm_mon = 11; // December (0-based month)
    newyear.tm_mday = 31;

    // Calculate the number of seconds remaining until the end of the year
    seconds = difftime(mktime(&newyear), now);

    // Convert seconds to days
    int days_left = (int)(seconds / 86400); // 86400 seconds in a day

    printf("Number of days left before the year-end: %d days\n", days_left);

    return 0;
}

