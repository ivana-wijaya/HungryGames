enum move {UP,DOWN,LEFT,RIGHT,STOP}direction;
enum people_move {UP1,DOWN1,LEFT1,RIGHT1,STOP1}people1_dir, people2_dir;

//enum move people1_dir,people2_dir;

void move_player(enum move dir);
void people1_direction();
void people2_direction();


void people1_move(enum people_move p1_dir);
void people2_move(enum people_move p2_dir);


int player_r, player_c;
int people1_r, people1_c;
int people2_r, people2_c, people11, people22;
int finish_r, finish_c;

char people = 'i';
char food = '*';
int score = 0;
char finish = 'F';



char frame[X][Y]= {
	"____________________________________________________________________________________________________",
	"|          |          |00000     |          |00000|0000|          |0000000000|          |00000     |",
	"|                                                 |                                                |",
	"|                                                 |                                                |",
	"|00000     |          |00000|0000|          |00000000000|         |       000|0000000000|          |",
	"|          |      ____|     |    |____      |     |           ____|                     |      ____|",
	"|     |    |          |     |               |     |_____          |000               ___|          |",
	"|     |____|____      |     |_________      |           |         |          |          |____      |",
	"|                     |                                 |         |       ___|___       |    |     |",
	"|      _______________|      ___________________        |                               |    |     |",
	"|     |        |            |                   |       |________________          _____|          |",
	"|     |        |            |                   |       |                               |      ____|",
	"|              |            |        |                  |               ________________|          |",
	"|______        |      |     |        |__________________|                               |_____     |",
	"|                     |     |                    |      |____________________           |     |    |",
	"|       ______________|     |________            |                           |          |          |",
	"|      |                                         |                 __________|          |      ____|",
	"|      |                                                |                               |          |",
	"|      |________________________________________________|_______________________________|_________ |"};
void print_frame(int score);


int read_score(void);
void save_score(int score);

int main(){
	int choice;
	FILE *fscore;
	
	do{
		printf("\033[0;36m");
		printf("\n======================================\n");
		printf("======================================\n");
		printf("============  HUNGRY GAME ============\n");
		printf("============    1. Play   ============\n");
		printf("============ 2. Best score ===========\n");
		printf("============    0. Exit   ============\n");
		printf("======================================\n");
		printf("======================================\n");
		
		scanf("%d", &choice);
		
		if(choice == 1){
			save_score(score);
			system("cls");
			int i, count = 20;
			char ch;
			
			player_r = 19;
			player_c = 3;
		
			people1_r=2;
			people1_c=47;
			
			people2_r=2;
			people2_c=52;
		
			finish_r=19;
			finish_c=99;
			
			print_frame(score);
			people1_direction();
			people2_direction();
			
			 while(count){
			
				    ch =_getch();
				       
				     switch(ch){
				        case 'd':
				
				                direction=RIGHT;
				                break;
				
				
				        case 'a':
				
				                direction=LEFT;
				                break;
				        
				
				
				        case 'w':
				
				                direction = UP;
				                break;
				              
				
				
				        case 's':
				
				                direction = DOWN;
				                break;
				             
				
				
				        default:;
				    }
				    //lose condition
				    if(frame[people1_r][people1_c]==frame[player_r][player_c] || frame[people2_r][people2_c]==frame[player_r][player_c]){
				    	system("cls");
				    	printf("+==========================================================================================+");
				        printf("\n                                GAME OVER T_T                                            \n");
				        printf("                                Final Score: %d                                           \n", score);
				        printf("+==========================================================================================+");
				        break;
				    }
				    
				    //Win condition
				    if(score >= 50 && frame[player_r][player_c] == finish)
					{
						system("cls");
						printf("+==========================================================================================+");
						printf("\n                                YOU WIN!!!                                              \n");
						printf("                                Final Score: %d                                           \n", score);
						printf("+==========================================================================================+");
						break;
					}

			   	printf("\033[0;34m");
			    move_player(direction);
				
			    people1_move(people1_dir);
			    people2_move(people2_dir);
			    
			    Beep(400, 150);
			    //Beep(frequencies, duration)
			    //Duration, more low more fast
			    //Frequencies (the sound), more high more low
			    
			    system("cls");
			    print_frame(score);
			}
			
		}
		else if(choice == 2)
		{
			system("cls");
			read_score();
			printf("\nThe best score is: %d\n", score);
		}
		else if(choice == 0)
		{
			system("cls");
			printf("Please come back again :)\n");
			break;	
		}
	}
	while(choice != 2);
	
	return 0;
}

int read_score(void){
    FILE *fscore = fopen("score.txt", "r");
    int score=1;
    fscanf(fscore, "%d", &score);
    fclose(fscore);
    return score;
}

void save_score(int score){
		FILE *fscore = fopen("score.txt", "a+");
        fprintf(fscore, "%d", score);
        fclose(fscore);
}

void print_frame(int score){
    int i;
	printf("===========================================HUNGRY GAME=============================================\n\n");
	printf("Score: %d\n", score);
    for(i = 0; i < X; i++){
		printf("\033[0;32m");
    	printf("%s\n", frame[i]);
	}
	frame[1][1] = food;
	frame[1][2] = food;
	frame[1][3] = food;
	frame[1][4] = food;
	frame[1][5] = food;
	frame[1][6] = food;
	frame[1][7] = food;
	frame[1][8] = food;
	frame[1][9] = food;
	frame[1][10] = food;
	
	frame[1][12] = food;
	frame[1][13] = food;
	frame[1][14] = food;
	frame[1][15] = food;
	frame[1][16] = food;
	frame[1][17] = food;
	frame[1][18] = food;
	frame[1][19] = food;
	frame[1][20] = food;
	frame[1][21] = food;
	
	frame[1][34] = food;
	frame[1][35] = food;
	frame[1][36] = food;
	frame[1][37] = food;
	frame[1][38] = food;
	frame[1][39] = food;
	frame[1][40] = food;
	frame[1][41] = food;
	frame[1][42] = food;
	frame[1][43] = food;
	
	frame[1][56] = food;
	frame[1][57] = food;
	frame[1][58] = food;
	frame[1][59] = food;
	frame[1][60] = food;
	frame[1][61] = food;
	frame[1][62] = food;
	frame[1][63] = food;
	frame[1][64] = food;
	frame[1][65] = food;
	
	frame[1][78] = food;
	frame[1][79] = food;
	frame[1][80] = food;
	frame[1][81] = food;
	frame[1][82] = food;
	frame[1][83] = food;
	frame[1][84] = food;
	frame[1][85] = food;
	frame[1][86] = food;
	frame[1][87] = food;
	
	frame[18][98] = finish;
	

	
    printf("Press w = UP\n");
    printf("Press s = DOWN\n");
    printf("Press a = LEFT\n");
    printf("Press d = RIGHT\n");
    

}
void move_player(enum move dir){
	
    if(dir==UP){
        if(frame[player_r-1][player_c]!= '|' && frame[player_r-1][player_c]!= '_' && frame[player_r-1][player_c]!= '0'){
           frame[player_r][player_c]=' ';
           frame[player_r-1][player_c]='@';
           player_r--;
        } 
    }
    else if(frame[player_r-1][player_c] == food){
    	
			score++;
	}
		
    if(dir==DOWN){
        if(frame[player_r+1][player_c]!= '|' && frame[player_r+1][player_c]!= '_' && frame[player_r+1][player_c]!= '0'){
      	
        	frame[player_r][player_c]=' ';
        	frame[player_r+1][player_c]='@';
			player_r++;
      }
      
    }
    else if(frame[player_r+1][player_c]== food){
		score++;
	}
	  
    if(dir==LEFT){
       if(frame[player_r][player_c-1]!= '|' && frame[player_r][player_c-1]!= '_' && frame[player_r][player_c-1]!= '0'){
           frame[player_r][player_c]=' ';
           frame[player_r][player_c-1]='@';
           player_c--;
		}
    }
    else if(frame[player_r][player_c-1] == food){
		score++;
	}
		
    if(dir==RIGHT){
       if(frame[player_r][player_c+1]!= '|' && frame[player_r][player_c+1]!= '_' && frame[player_r][player_c+1]!= '0'){
           frame[player_r][player_c]=' ';
           frame[player_r][player_c+1]='@';
           player_c++;
       } 

    }
    else if(frame[player_r][player_c+1] == food){	
		score++;
	}
}
void people1_direction(){
    int people1;
    srand((unsigned) time(NULL));

    people1=(rand()%5)+1;
            
    if(people1 == 1)
       people1_dir = LEFT1;
       else
        people1_dir = RIGHT1;
}

void people2_direction(){
        int people2;
        //srand((unsigned) time(NULL));
        people2=(rand()%5)+1;

        switch(people2)
        {
        case 1:
        case 3:


                people2_dir=LEFT1;
                break;

        case 2:
        case 4:

                people2_dir=RIGHT1;
                break;

        }

    }


void people1_move(enum people_move p1_dir){
 // Beep(200,200);
	  int x,y;
		
	  if(p1_dir==LEFT1){
	
	      if(frame[people1_r][people1_c-1]!= '|' && frame[people1_r][people1_c-1]!= '_' && frame[people1_r][people1_c-1]!= '0'){
	          frame[people1_r][people1_c]=' ';
	          frame[people1_r][people1_c-1]= people;
	          people1_c--;
	          if(frame[people1_r][people1_c]==frame[4][48]||frame[people1_r][people1_c]==frame[4][96]||frame[people1_r][people1_c] == frame[4][172]){
	            x=rand()%2;
	            switch (x){
	                
	                case 1:
					{
	                        people1_dir = LEFT1;
	                    
	                    }
	
	            }
	          }
	          else if(frame[people1_r][people1_c]==frame[32][48]||frame[people1_r][people1_c]==frame[32][192]||frame[people1_r][people1_c] == frame[32][172]){
	             x=rand()%2;
	            switch (x){
	                
	                case 1:
	                {
	                        people1_dir = RIGHT1;
	                    	
	                }
	
	            }
	          }
	         else if(frame[people1_r][people1_c]==frame[32][132]){
	             x=rand()%2;
	            switch (x){
	               
	                case 1:
	                    {
	                        people1_dir = LEFT1;
	                    	
	                    }
	
	            }
	         }
	         else if(frame[people1_r][people1_c]==frame[8][24]){
	             x=rand()%2;
	            switch (x){
	                case 0:{
	                        people1_dir = LEFT1;
	               
	                    }
	
	                case 1:
	                    {
	                        people1_dir = RIGHT1;
	                    
	                    }
	
	            }
	         }
	         else if(frame[people1_r][people1_c]==frame[32][12]){
	             x=rand()%2;
	            switch (x){
	                case 0:
	                    {
	                        people1_dir = RIGHT1;
	                    
	                    }
	
	                case 1:
	                    {
	                        people1_dir = LEFT1;
	                    
	                    }
	
	            }
	         }
	         else if(frame[people1_r][people1_c]==frame[76][12]){
	             x=rand()%2;
	            switch (x){
	                case 0:
	                    {
	                        people1_dir = RIGHT1;
	                    
	                    }
	
	                case 1:
	                    {
	                        people1_dir = LEFT1;
	                    
	                    }
	
	            }
	         }
	
	      }
	
	
	  }
	  else if (p1_dir==RIGHT1){
	      if(frame[people1_r][people1_c+1]!= '|' && frame[people1_r][people1_c+1]!= '_' && frame[people1_r][people1_c+1]!= '0'){
	          frame[people1_r][people1_c]=' ';
	          frame[people1_r][people1_c+1]= people;
	          people1_c++;
	
	          if(frame[people1_r][people1_c]==frame[4][48]||frame[people1_r][people1_c]==frame[4][96]||frame[people1_r][people1_c] == frame[4][172]){
	
	            x=rand()%2;
	            switch (x){
	                
	                case 1:
	                    {
	                        people1_dir = RIGHT1;
	                   
	                    }
	
	            }
	          }
	          else if(frame[people1_r][people1_c]==frame[16][24]||frame[people1_r][people1_c]==frame[16][48]||frame[people1_r][people1_c] == frame[16][86]{
	             x=rand()%2;
	            switch (x){
	                
	                case 1:
	                    {
	                        people1_dir = LEFT1;
	                    
	                    }
	
	            }
	          }
	          else if(frame[people1_r][people1_c]==frame[16][66]){
	            x=rand()%2;
	            switch (x){
	                
	                case 1:
	                    {
	                        people1_dir = RIGHT1;
	                    
	                    }
	
	            }
	         }
	         else if(frame[people1_r][people1_c]==frame[2][136]){
	            x=rand()%2;
	            switch (x){
	                case 0:
	                    {
	                        people1_dir = LEFT1;
	                
	                    }
	
	                case 1:
	                    {
	                        people1_dir = RIGHT1;
	                    break;
	                    }
	
	            }
	         }
	         else if(frame[people1_r][people1_c]==frame[16][136]){
	             x=rand()%2;
	            switch (x){
	                case 0:
	                    {
	                        people1_dir = LEFT1;
	                    
	                    }
	
	                case 1:
	                    {
	                        people1_dir = RIGHT1;
	                   
	                    }
	
	            }
	         }
	         else if(frame[people1_r][people1_c]==frame[38][136]){
	             x=rand()%2;
	            switch (x){
	                case 0:
	                    {
	                        people1_dir = LEFT1;
	                    
	                    }
	
	                case 1:
	                    {
	                        people1_dir = RIGHT1;
	                    
	                    }
	
	            }
	         }
	      }
	  }
}


void people2_move(enum people_move p2_dir){
 //Beep(200,250);
    	  int x,y;
		
	  if(p2_dir==LEFT1){
	
	      if(frame[people2_r][people2_c-1]!= '|' && frame[people2_r][people2_c-1]!= '_' && frame[people2_r][people2_c-1]!= '0'){
	          frame[people2_r][people2_c]=' ';
	          frame[people2_r][people2_c-1]= people;
	          people2_c--;
	          if(frame[people2_r][people2_c]==frame[4][48]||frame[people2_r][people2_c]==frame[4][96]||frame[people2_r][people2_c] == frame[4][172]){
	            x=rand()%2;
	            switch (x){
	                
	                case 1:
	                    {
	                        people2_dir = LEFT1;
	                    
	                    }
	
	            }
	          }
	          else if(frame[people2_r][people2_c]==frame[32][48]||frame[people2_r][people2_c]==frame[32][192]||frame[people2_r][people2_c] == frame[32][172]){
	             x=rand()%2;
	            switch (x){
	                
	                case 1:
	                {
	                        people2_dir = RIGHT1;
	                    	
	                }
	
	            }
	          }
	         else if(frame[people2_r][people2_c]==frame[32][132]){
	             x=rand()%2;
	            switch (x){
	               
	                case 1:
	                    {
	                        people2_dir = LEFT1;
	                    	
	                    }
	
	            }
	         }
	         else if(frame[people2_r][people2_c]==frame[8][24]){
	             x=rand()%2;
	            switch (x){
	                case 0:
	                    {
	                        people2_dir = RIGHT1;
	               
	                    }
	
	                case 1:
	                    {
	                        people2_dir = LEFT1;
	                    
	                    }
	
	            }
	         }
	         else if(frame[people2_r][people2_c]==frame[32][12]){
	             x=rand()%2;
	            switch (x){
	                case 0:
	                    {
	                        people2_dir = LEFT1;
	                    
	                    }
	
	                case 1:
	                    {
	                        people2_dir = RIGHT1;
	                    
	                    }
	
	            }
	         }
	         else if(frame[people2_r][people2_c]==frame[76][12]){
	             x=rand()%2;
	            switch (x){
	                case 0:
	                    {
	                        people2_dir = LEFT1;
	                    
	                    }
	
	                case 1:
	                    {
	                        people2_dir = RIGHT1;
	                    
	                    }
	
	            }
	         }
	
	      }
	
	
	  }
	  else if (p2_dir==RIGHT1){
	      if(frame[people2_r][people2_c+1]!= '|' && frame[people2_r][people2_c+1]!= '_' && frame[people2_r][people2_c+1]!= '0'){
	          frame[people2_r][people2_c]=' ';
	          frame[people2_r][people2_c+1]= people;
	          people2_c++;
	
	          if(frame[people2_r][people2_c]==frame[4][48]||frame[people2_r][people2_c]==frame[4][96]||frame[people2_r][people2_c] == frame[4][172]){
	
	            x=rand()%2;
	            switch (x){
	                
	                case 1:
	                    {
	                        people2_dir = RIGHT1;
	                   
	                    }
	
	            }
	          }
	          else if(frame[people2_r][people2_c]==frame[16][24]||frame[people2_r][people2_c]==frame[16][48]||frame[people2_r][people2_c] == frame[16][86]){
	             x=rand()%2;
	            switch (x){
	                
	                case 1:
	                    {
	                        people2_dir = LEFT1;
	                    
	                    }
	
	            }
	          }
	          else if(frame[people2_r][people2_c]==frame[16][66]){
	            x=rand()%2;
	            switch (x){
	                
	                case 1:
	                    {
	                        people2_dir = RIGHT1;
	                    
	                    }
	
	            }
	         }
	         else if(frame[people2_r][people2_c]==frame[2][136]){
	            x=rand()%2;
	            switch (x){
	                case 0:
	                    {
	                        people2_dir = LEFT1;
	                
	                    }
	
	                case 1:
	                    {
	                        people2_dir = RIGHT1;
	                    break;
	                    }
	
	            }
	         }
	         else if(frame[people2_r][people2_c]==frame[16][136]){
	             x=rand()%2;
	            switch (x){
	                case 0:
	                    {
	                        people2_dir = RIGHT1;
	                    
	                    }
	
	                case 1:
	                    {
	                        people2_dir = LEFT1;
	                   
	                    }
	
	            }
	         }
	         else if(frame[people2_r][people2_c]==frame[38][136]){
	             x=rand()%2;
	            switch (x){
	                case 0:
	                    {
	                        people2_dir = RIGHT1;
	                    
	                    }
	
	                case 1:
	                    {
	                        people2_dir = LEFT1;
	                    
	                    }
	
	            }
	         }
	      }
	  }
     
}
