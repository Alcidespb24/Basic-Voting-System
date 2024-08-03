#include <stdio.h>
#include <stdbool.h>

#define MAX_CANDIDATES 3
#define MAX_VOTERS 100

typedef struct {
    int vote_id;
    int count;
} Votes;

typedef struct {
    int voter_id;
    bool has_voted;
} Voter;

void count_votes(Votes votes[], int vote_id);
bool has_voter_voted(Voter voters[], int voter_id, int total_voters);

int main() {
    Votes votes[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int total_votes = 0;
    int total_voters = 0;

    // Initialize votes count for each candidate
    for(int i = 0; i < MAX_CANDIDATES; i++) {
        votes[i].vote_id = i + 1;
        votes[i].count = 0;
    }

    // Initialize voters
    for(int i = 0; i < MAX_VOTERS; i++) {
        voters[i].voter_id = 0;
        voters[i].has_voted = false;
    }

    printf("These are the candidates: \n");
    printf("1. Candidate 1\n");
    printf("2. Candidate 2\n");
    printf("3. Candidate 3\n");

    while (total_votes < MAX_VOTERS) {
        int voter_id, vote_id;
        
        printf("Enter your voter ID: ");
        scanf("%d", &voter_id);

        if (has_voter_voted(voters, voter_id, total_voters)) {
            printf("You have already voted. You cannot vote again.\n");
            continue;
        }

        printf("Enter the number of the candidate you would like to vote for (0 to stop): ");
        scanf("%d", &vote_id);

        if (vote_id == 0) {
            break;
        }

        if (vote_id >= 1 && vote_id <= MAX_CANDIDATES) {
            count_votes(votes, vote_id);
            total_votes++;

            // Register the voter
            voters[total_voters].voter_id = voter_id;
            voters[total_voters].has_voted = true;
            total_voters++;
        } else {
            printf("Invalid candidate number. Please try again.\n");
        }
    }

    printf("Voting results: \n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("Candidate %d: %d votes\n", votes[i].vote_id, votes[i].count);
    }

    return 0;
}

void count_votes(Votes votes[], int vote_id) {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (votes[i].vote_id == vote_id) {
            votes[i].count += 1;
            break;
        }
    }
}

bool has_voter_voted(Voter voters[], int voter_id, int total_voters) {
    for (int i = 0; i < total_voters; i++) {
        if (voters[i].voter_id == voter_id && voters[i].has_voted) {
            return true;
        }
    }
    return false;
}
