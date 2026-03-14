#include <stdio.h>
#include <string.h>

// dùng extern để dùng chung biến từ data.c
extern int eventCount;
extern struct Event {
    int id;
    char title[100];
    char category[50];
    char date[12];
    int rsvp_count;
} events[];

void addEvent() {
    if(eventCount >= 100) { printf("Event list full!\n"); return; }

    events[eventCount].id = eventCount+1;

    printf("Enter title: "); 
    fgets(events[eventCount].title,100,stdin);
    events[eventCount].title[strcspn(events[eventCount].title,"\n")]=0;

    printf("Enter category: "); 
    fgets(events[eventCount].category,50,stdin);
    events[eventCount].category[strcspn(events[eventCount].category,"\n")]=0;

    printf("Enter date (DD/MM/YYYY): "); 
    scanf("%11s",events[eventCount].date);
    getchar();

    events[eventCount].rsvp_count = 0;
    eventCount++;

    printf("Event added!\n");
}

void deleteEvent() {
    int id; 
    printf("Enter ID to delete: "); 
    scanf("%d",&id); 
    getchar();

    for(int i=0;i<eventCount;i++) {
        if(events[i].id==id) {
            for(int j=i;j<eventCount-1;j++) events[j]=events[j+1];
            eventCount--;
            printf("Event deleted.\n"); return;
        }
    }
    printf("Event not found.\n");
}
