#include <stdio.h>
#include <string.h>

extern int eventCount;
extern struct Event {
    int id;
    char title[100];
    char category[50];
    char date[12];
    int rsvp_count;
} events[];

void displayEvents() {
    if(eventCount==0){printf("No events.\n"); return;}
    printf("\nID  Title                    Category            Date        RSVP\n");
    printf("---------------------------------------------------------------\n");
    for(int i=0;i<eventCount;i++)
        printf("%-3d %-25s %-18s %-12s %-5d\n",
               events[i].id,events[i].title,events[i].category,events[i].date,events[i].rsvp_count);
}

void searchByCategory() {
    char cat[50]; 
    printf("Enter category: "); 
    fgets(cat,50,stdin);
    cat[strcspn(cat,"\n")]=0;

    int found=0;
    for(int i=0;i<eventCount;i++) {
        if(strcmp(events[i].category,cat)==0) {
            printf("%d | %s | %s | %s\n",
                   events[i].id,events[i].title,events[i].category,events[i].date);
            found=1;
        }
    }
    if(!found) printf("No events in this category.\n");
}
