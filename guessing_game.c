 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

 void writeToHTML(int no_of_guess, int random, int guess)
{
    FILE *fp = fopen("output.html", "w");
    fprintf(fp, "<!DOCTYPE html>\n<html>\n<head>\n");
    fprintf(fp, "<link rel='stylesheet' type='text/css' href='style.css'>\n");
    fprintf(fp, "<title>Guessing Game Result</title>\n</head>\n<body>\n");

    if (guess == random)
    {
        fprintf(fp, "<div class='result success'>");
        fprintf(fp, "<h1>🎉 Congratulations!</h1>\n");
        fprintf(fp, "<p>You guessed the number in %d attempts!</p>\n", no_of_guess);
    }
    else
    {
        fprintf(fp, "<div class='result failure'>");
        fprintf(fp, "<h1>❌ Game Over!</h1>\n");
        fprintf(fp, "<p>Oops! Better luck next time.</p>\n");
    }

    fprintf(fp, "</div>\n</body>\n</html>");
    fclose(fp);
}


 
 int main()
 {
    int random, guess;
    int no_of_guess = 0;
    srand(time(NULL));

    printf("Welcome to the guessing number game\n");
    random = rand() % 100 +1;

    do{
        printf("\nPlease enter your guess between (1 to 100):");
        scanf("%d",&guess);
        no_of_guess++;

        if (guess < random)
        {
            printf("Guess a larger number.\n");
        }
        else if(guess > random)
        {
            printf("Guess a smaller number.\n");
        }
        else
        {
            printf("Congratulations !!!You have successfully guessed the number in %d attempt", no_of_guess);
        }       
     }while (guess != random);
    
        printf("\n Thanks for Playing.");
        printf("\n Developed By : Ushma Talreja");
    
        return 0;
}
