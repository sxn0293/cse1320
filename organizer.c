#include <stdio.h>
#include <string.h>

extern int eventCount;
extern struct Event {
    char title[100];
    char category[50];
    char date[12];
    int rsvp_count;
    int id;
} events[];

void addEvent() {
    if (eventCount >= 100) {
        printf("Event list full, remove event to add more!\n");
        return;
    }
    events[eventCount].id = eventCount + 1;

    printf("Enter title: ");
    fgets(events[eventCount].title, 100, stdin);
    events[eventCount].title[strcspn(events[eventCount].title, "\n")] = 0;

    printf("Enter category: ");
    fgets(events[eventCount].category, 50, stdin);
    events[eventCount].category[strcspn(events[eventCount].category, "\n")] = 0;

    printf("Enter date (DD/MM/YYYY): ");
    scanf("%11s", events[eventCount].date);
    getchar();

    events[eventCount].rsvp_count = 0;
    printf("Event %s added as ID %d.\n", events[eventCount].title, events[eventCount].id);
    eventCount++;
}

void deleteEvent() {
    if (eventCount == 0) {
        printf("No events available.\n");
        return;
    }
    int id;
    printf("Enter ID to delete: ");
    while(scanf("%d", &id) != 1 || id < 1){
        printf("Invalid ID! Please enter a valid ID: ");
        while (getchar() != '\n');
    }
    getchar();
    for (int i = 0; i < eventCount; i++) {
        if (events[i].id == id) {
            for (int j = i; j < eventCount - 1; j++) events[j] = events[j + 1];
            eventCount--;
            printf("Event %s deleted.\n", events[i].title);
            return;
        }
    }
    printf("Event with ID %d not found.\n", id);
}
