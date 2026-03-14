#include <stdio.h>

extern void displayEvents();
extern void searchByCategory();
extern void addEvent();
extern void deleteEvent();
extern int eventCount;
extern struct Event {
    int id;
    char title[100];
    char category[50];
    char date[12];
    int rsvp_count;
} events[];

void rsvpEvent() {
    int id; 
    printf("Enter event ID to RSVP: "); 
    scanf("%d",&id); getchar();

    for(int i=0;i<eventCount;i++) {
        if(events[i].id==id){
            events[i].rsvp_count++;
            printf("RSVP successful! Total: %d\n",events[i].rsvp_count);
            return;
        }
    }
    printf("Event not found.\n");
}

void mainMenu() {
    int choice;
    do {
        printf("\n=== CommuniKnot ===\n1.View Events\n2.Add Event\n3.Delete Event\n4.Search Category\n5.RSVP Event\n6.Exit\nChoose: ");
        scanf("%d",&choice); getchar();

        switch(choice){
            case 1: displayEvents(); break;
            case 2: addEvent(); break;
            case 3: deleteEvent(); break;
            case 4: searchByCategory(); break;
            case 5: rsvpEvent(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice!=6);
}
