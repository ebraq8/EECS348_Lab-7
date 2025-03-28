#include <stdio.h>

#define TD 6
#define FG 3
#define SAFETY 2
#define TD_2PT 8
#define TD_1PT 7

void find_combinations(int score) {
    int td, td_fg, td_2pt, fg, safety;
    printf("Possible combinations of scoring plays if the score is %d:\n", score);
    
    for(td_2pt = 0; td_2pt <= score/TD_2PT; td_2pt++)
        for(td_fg = 0; td_fg <= score/TD_1PT; td_fg++)
            for(td = 0; td <= score/TD; td++)
                for(fg = 0; fg <= score/FG; fg++)
                    for(safety = 0; safety <= score/SAFETY; safety++)
                        if(td_2pt*TD_2PT + td_fg*TD_1PT + td*TD + fg*FG + safety*SAFETY == score)
                            printf("%d TD+2pt, %d TD+FG, %d TD, %d FG, %d Safety\n",
                                td_2pt, td_fg, td, fg, safety);
}

int main() {
    int score;
    while(1) {
        printf("\nEnter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
        
        if(score <= 1) {
            printf("Exiting...\n");
            break;
        } else if(score < 2) {
            printf("Invalid input! Please enter a score of 2 or higher.\n");
            continue;
        }

        find_combinations(score);
    }
    return 0;
}
