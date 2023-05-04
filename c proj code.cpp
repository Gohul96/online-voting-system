#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

struct Candidate {
    int id;
    char name[50];
    int votes;
};

struct Voter {
    int id;
    char name[50];
    int voted;
};

struct Candidate candidates[MAX_CANDIDATES];
struct Voter voters[MAX_VOTERS];
int num_candidates = 0, num_voters = 0;

void add_candidate() {
    if (num_candidates == MAX_CANDIDATES) {
        printf("Maximum candidates limit reached.\n");
        return;
    }

    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].id = num_candidates + 1;
    candidates[num_candidates].votes = 0;

    num_candidates++;

    printf("Candidate added successfully.\n");
}

void add_voter() {
    if (num_voters == MAX_VOTERS) {
        printf("Maximum voters limit reached.\n");
        return;
    }

    printf("Enter voter name: ");
    scanf("%s", voters[num_voters].name);
    voters[num_voters].id = num_voters + 1;
    voters[num_voters].voted = 0;

    num_voters++;

    printf("Voter added successfully.\n");
}

void cast_vote() {
    int voter_id, candidate_id;
    printf("Enter voter ID: ");
    scanf("%d", &voter_id);

    if (voters[voter_id-1].voted == 1) {
        printf("This voter has already casted their vote.\n");
        return;
    }

    printf("List of Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }

    printf("Enter candidate ID to vote: ");
    scanf("%d", &candidate_id);

    candidates[candidate_id-1].votes++;
    voters[voter_id-1].voted = 1;

    printf("Vote casted successfully.\n");
}

void display_result() {
    printf("Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s: %d votes\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n");
        printf("1. Add candidate\n");
        printf("2. Add voter\n");
        printf("3. Cast vote\n");
        printf("4. Display result\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_candidate();
                break;

            case 2:
                add_voter();
                break;

            case 3:
                cast_vote();
                break;

            case 4:
                display_result();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
