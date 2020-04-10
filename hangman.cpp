#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<process.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
 class playa
  {
    int plno;
    char plname[20];
    int hscore;

    public:
    playa()
     {
      plno=0;
      hscore=1;             //constructor to initialize data members with Null or 0
      strcpy(plname,"NULL");
     }


    void enpaod()
       {
	 clrscr();
	 cout<<"Enter your name playa ::\n";
	 gets(plname);                          //function to accept details of player
	 cout<<"Enter playa number ::\n";
	 cin>>plno;
       }
    void hsetter(int a);

    void display()
      {

	   cout<<"NAME::\n";
	   puts(plname);
	   cout<<"Hi-Score= ";          //function to display name and highscore
	   cout<<hscore;
	   cout<<endl<<"----------------------------------------------------------------------------"<<endl;
	   getch();

      }

  }p1;

      void playa::hsetter(int a)
       {
	 switch(a)
	    {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5: hscore=1999;
			break;
		case 6:
		case 7:
		case 8:
		case 9:
		case 10: hscore=3999;
			 break;               //function that sets high score
		case 11:
		case 12:
		case 13:
		case 14:
		case 15: hscore=5999;
			 break;
		case 16:
		case 17:
		case 18:
		case 19:
		case 20: hscore=9999;
			 break;
		default: hscore=19999;
			 break;
	    }
       }


 char word[25][25]={"AUSTRALIA","AMERICA","AFRICA","INDIA","PAKISTAN","BRAZIL","ARGENTINA","PORTUGAL","MANCHESTER","BABYLON","LEBANON","UGANDA","UKRAINE","FRANCE","GERMANY","POLAND","NETHERLAND","CHINA","JAPAN","BELGIUM","SWEDEN","SWITZERLAND"};
 char wrd[20];
 float x[1000];

 void crash()
  {
    getch();
    for(int i=0;i<867;++i)
      {
	 cout<<&x[i]<<" "<<&word[i]<<" "<<*x<<" "<<&wrd[i]<<" "; //in case user provides a option not provided
	 delay(20);
      }
    getch();
  }
 void winitializer()
      {
	int a;
	randomize();              //initializes word to  be predicted
	a=random(22);
	strcpy(wrd,word[a]);
      }
 void quicgame()             //function to run option Quick Game
      {
	int e=5;
	char tword[20];
	winitializer();
	cout<<"You have 5 chances to predict the word (name of a country)::\n\n ";
	for(int i=0;i<strlen(wrd);++i)
	   {
	     if(i==0||i==(strlen(wrd)/2)||i==strlen(wrd))
		cout<<wrd[i]<<" ";
	     else cout<<"_ ";
	   }
	for(i=0;i<strlen(wrd);++i)
	   {
	     cin>>tword[i];
	     if(toupper(tword[i])==wrd[i])
		continue;
	     else
	       {
		 cout<<"wrong letter "<<e--<<" chances left";
		 if(e==0)
		    {
			 cout<<"Its over....";
			 return;
		    }
		 i-=1;
	       }
	   }
	cout<<"Correct!!!!!!";
	getch();
      }

 void cmode()                      //runs option Career mode
  {
    char ch;
    cout<<"\n\tYou have chosen career mode.\n You have 3 lives.\n Choose your letters wisely."<<endl;
    cout<<"\tContinue?? ::Y or N?"<<endl;
    cin>>ch;
    switch(toupper(ch))
      {
	 case 'Y':cout<<"\nGREAT!!!!!\n";
		  getch();
		  clrscr();
		  break;
	 case 'N':cout<<"okay!!!\n";       //checking...
		  getch();
		  clrscr();
		  return;
	 default: crash();
      }

    p1.enpaod();
    int b=3,l=0;
    while(b) //loop for 3 cycles
       {
	int e=5;
	clrscr();
	char tword[20];
	winitializer();
	cout<<"You have 5 chances to predict the word (name of a place on Earth)::\n\n ";
	for(int i=0;i<strlen(wrd);++i)
	   {
	     if(i==0||i==(strlen(wrd)/2)||i==strlen(wrd))
		cout<<wrd[i]<<" ";
	     else cout<<"_ ";
	   }
	for(i=0;i<strlen(wrd);++i)
	   {
	     cin>>tword[i];
	     cout<<endl;
	     if(toupper(tword[i])==wrd[i])
	       {
		 continue;
	       }
	     else
	       {
		 e-=1;
		 cout<<"wrong letter "<<e<<" chances left"<<endl;
		 if(e==0)                               //in case 5 chances are exhausted
		    {
			 cout<<"Its over....";
			 b=b-1;
			 break;
		    }
		 i-=1;
	       }
	   }
	if(e!=0)     //typed word being correct
	   cout<<"correct!!!!!!!";
	l+=1;
	getch();
     }
   p1.hsetter(l);           //calls function set the highscore
   ofstream f;
   f.open("HNGMN.dat",ios::app|ios::ate);
       f.write((char*)&p1,sizeof(p1));
   f.close();                                  //writing details to a file
  }
 void hscore()
  {
    clrscr();
    cout<<"\tHH  H  II  GGGGG  HH  H     SSSS   CCCC  OOOO  RRRR    EEEE\n";
    cout<<"\tHH  H  II  GG     HH  H    SS      CC    O  O  RR  RR  EE   \n";
    cout<<"\tHHHHH  II  GG GG  HHHHH ==  SSSS   CC    O  O  RRRR    EEEE\n";
    cout<<"\tHH  H  II  GG  G  HH  H        SS  CC    O  O  RR RR   EE   \n";
    cout<<"\tHH  H  II  GGGGG  HH  H     SSSS   CCCC  OOOO  RR  RR  EEEE\n";
    cout<<"\t===========================================================\n";
    ifstream d;
    d.open("HNGMN.dat");
    while (d.read((char*)&p1,sizeof(p1)))
       {
	 p1.display();
       }
    getch();
    d.close();
  }
 void howtoplay()
  {
   cout<<"\t\tHOW TO PLAY"<<endl
       <<"\t\t-----------"<<endl;
   cout<<"\t* This is a version of the classic word game HANGMAN \n"
       <<"\t* Guess the name of a place on Earth\n"
       <<"\t* You have three lives to guess the word in career mode and 5"
       <<" \n\t  chances to guess each word correctly\n"                                      //instructions for gameplay
       <<"\t* You have 5 chances at guessing in Quick Game mode\n"
       <<"\t* It is recommended that you type the word letter by letter\n"
       <<"\t* Begin from the first letter\n"
       <<"\t* You have to guess in the same order the letter appears in the word\n"
       <<"\t\t\t HAVE FUN!!!!\n";
   }
 void abouthegame()
   {
     cout<<"\n\n HANGMAN---The different version\n"
	 <<" Made by R.NO 21735\n"                  //Info about the game
	 <<" All rights reserved\n"
	 <<"MADE TO LOOK LIKE THE ARCADE VERSION";
     cout<<" Happy Hanging!!!!!!!!";
   }

 void main()     //main block
{
 int ch;
 char opt;
 int d=1;
 while(d)
   {

	 clrscr();
	 cout<<"       HH    H   AAAAAAA   NN    N   GGGGG   MM     M   AAAAAA   NN    N"<<endl
	     <<"       HH    H   AA    A   NN N  N   GG      MM MMM M   AA   A   NN N  N"<<endl
	     <<"       HHHHHHH   AAAAAAA   NN  N N   GG GG   MM  M  M   AAAAAA   NN  N N"<<endl
	     <<"       HH    H   AA    A   NN   NN   GG  G   MM     M   AA   A   NN   NN"<<endl
	     <<"       HH    H   AA    A   NN    N   GGGGG   MM     M   AA   A   NN    N"<<endl;        //to print HANGMAN
	 cout<<"       ================================================================="<<endl
	     <<"       -----------------------------------------------------------------"<<endl;
	 cout<<"\t\t1.Quick Game\n"
	     <<"\t\t2.Career Mode\n"
	     <<"\t\t3.High Score\n"
	     <<"\t\t4.How To Play\n"
	     <<"\t\t5.About\n"       //prints options from which the user may choose
	     <<"\t\t6.Quit Game"
	     <<endl
	     <<"\tEnter your choice (sr.no of the option) :: ";
	 cin>>ch;
	 switch(ch)
	  {
	    case 1: clrscr();
		    quicgame();   //calls function to play quickgame
		    getch();
		    clrscr();
		    break;
	    case 2: clrscr();
		    cmode();       //calls function for entering career mode
		    getch();
		    clrscr();
		    break;
	    case 3: clrscr();
		    hscore(); //Calls function to display the high score of all te players , just like the arcade version
		    getch();
		    clrscr();
		    break;
	    case 4: clrscr();
		    howtoplay();  //calls function to instruct the user about how the game is to be played
		    getch();
		    clrscr();
		    break;
	    case 5: clrscr();
		    abouthegame(); //calls function to display Details of the game
		    getch();
		    clrscr();
		    break;
	    case 6: clrscr();
		    cout<<"\n\n\n\tAre you sure you want to quit?"<<endl<<"\t\tY or N\n\t";
		    cin>>opt;
		    switch(toupper(opt))
			 {
			   case 'Y': d=d-1;       //makes d=0, making loop to fail
				     break;
			   case 'N': continue;                       //continues if person had a chane of mind
			   default : cout<<"INVALID!!!!!!";
				     crash();                   //displays many characters if person chooses an invalid option
				     break;
			 }
		    break;
	   default: cout<<"Invalid option!!!!!!!";
		    getch();
		    break;			  //In case a number not included is pressed
	  }
   }
 getch();
}
