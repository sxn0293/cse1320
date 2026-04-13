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

void displayEvents() {
    if (eventCount == 0) {
        printf("No events available.\n");
        return;
    }
    printf("ID  Title                     Category           Date         RSVP\n");
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < eventCount; i++)
        printf(
            "%-3d %-25s %-18s %-12s %-5d\n",
            events[i].id,
            events[i].title,
            events[i].category,
            events[i].date,
            events[i].rsvp_count
        );
}

void searchByTitle() {
    if (eventCount == 0) {
        printf("No events available.\n");
        return;
    }
    char title[100];
    printf("Enter title: ");
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = 0;
    for (int i = 0; i < eventCount; i++) {
        if (strcmp(events[i].title, title) == 0) {
            printf("Event found:\n");
            printf("ID: %d\n", events[i].id);
            printf("Title: %s\n", events[i].title);
            printf("Category: %s\n", events[i].category);
            printf("Date: %s\n", events[i].date);
            printf("RSVP: %d\n", events[i].rsvp_count);
            return;
        }
    }
    printf("No event found with this title.\n");
}

void searchByCategory() {
    if (eventCount == 0) {
        printf("No events available.\n");
        return;
    }
    char category[50];
    printf("Enter category: ");
    fgets(category, 50, stdin);
    category[strcspn(category, "\n")] = 0;
    for (int i = 0; i < eventCount; i++) {
        if (strcmp(events[i].category, category) == 0) {
            printf("Event found:\n");
            printf("ID: %d\n", events[i].id);
            printf("Title: %s\n", events[i].title);
            printf("Category: %s\n", events[i].category);
            printf("Date: %s\n", events[i].date);
            printf("RSVP: %d\n", events[i].rsvp_count);
            return;
        }
    }
    printf("No events found in this category.\n");
}
