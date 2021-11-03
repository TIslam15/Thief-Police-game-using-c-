#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int round_number;
int player[4];
int chor,dakat,babu,police;
int players_score[4];
int chor_score,dakat_score,babu_score,police_score;
bool Unique_array[4];

class game
{
public:
    bool Check_unique(int i)
    {
        if(Unique_array[i])return true;
        else return false;
    }
    void shuffle()
    {
        srand(time(0));
        for(int i=0;i<4;i++){
            while(true){
                int j=rand()%4;
                if(Check_unique(j)==true)continue;
                else {
                    player[i]=j;
                    Unique_array[j]=true;
                    break;
                }
            }
        }
    }
    void assign_players()
    {
        chor=player[0];
        dakat=player[1];
        babu=player[2];
        police=player[3];
    }
    void declare_babu()
    {
        cout<<"Player "<<babu+1<<" ~~> You are babu in this round "<<endl;
        players_score[babu]+=100;
    }
    void declare_police()
    {
        cout<<"Player "<<police+1<<" ~~> You are police in this round "<<endl;
    }
    int ask_police_for_thief()
    {
        cout<<"Player "<<police+1<<" ~~> Enter which player you think is the chor now : "<<endl;
        int guess;
        cin>>guess;
        return guess;
    }
    int ask_police_for_dakat()
    {
        cout<<"Player "<<police+1<<" ~~> Enter which player you think is the dakat now : "<<endl;
        int guess;
        cin>>guess;
        return guess;
    }
    void show_score()
    {
        cout<<"After round "<<round_number<<endl<<"Score of players: ";
        for(int i=0;i<4;i++){
        cout<< "\tPLAYER "<<i+1<< "=  "<<players_score[i];
        }
        int i=0;
        int p;

int win=players_score[0];

       for(i=0; i<4; i++)
      {
       if(players_score[i]>win)
       win=players_score[i];

          p=i;
      }

cout<<endl;
    cout<<"winer is "<<"player"<<p<<"\n"<<"score"<<win<<endl;
    }




void refresh()
    {
        for(int i=0;i<4;i++)Unique_array[i]=false;
        for(int i=0;i<4;i++)player[i]=-1;
    }
};

int main()
{
    game c;
    system("COLOR 75");
    for(int i=0;i<4;i++)players_score[i]=0;
    while(true){
        cout<<endl<< "Want to play a round? Enter 1 if YES "<<endl;
        int agree;
        cin>>agree;
        if(agree==1){
            round_number++;
            c.shuffle();
            c.assign_players();
            c.declare_babu();
            c.declare_police();

            if(round_number%2==1){
                int guessed_chor=c.ask_police_for_thief();

                if(guessed_chor==chor+1){
                    cout<<"CONGRATS!!   PLAYER  "<<police+1<<" ~~> You guessed it right"<<endl;
                    cout<<"Player "<<chor+1<<" ~~> is chor in this round "<<endl;
                    cout<<"Player "<<dakat+1<<" ~~> is dakat in this round "<<endl;
                    players_score[police]+=80;
                    players_score[chor]+=0;
                    players_score[dakat]+=60;

                }
                else{
                    cout<<"OOPS!!   PLAYER  "<<police+1<<" ~~> You guessed it wrong"<<endl;
                    cout<<"Player "<<chor+1<<" ~~> is chor in this round "<<endl;
                    cout<<"Player "<<dakat+1<<" ~~> is dakat in this round "<<endl;
                    players_score[police]+=0;
                    players_score[chor]+=40;
                    players_score[dakat]+=60;
                }

            }
            else
            {
                int guessed_dakat=c.ask_police_for_dakat();

                if(guessed_dakat==dakat+1){
                    cout<<"CONGRATS!!   PLAYER  "<<police+1<<" ~~> You guessed it right"<<endl;
                    cout<<"Player "<<dakat+1<<" ~~> is dakat in this round "<<endl;
                    cout<<"Player "<<chor+1<<" ~~> is chor in this round "<<endl;
                    players_score[police]+=80;
                    players_score[chor]+=40;
                    players_score[dakat]+=0;

                }
                else{
                    cout<<"OOPS!!   PLAYER  "<<police+1<<" ~~> You guessed it wrong"<<endl;
                    cout<<"Player "<<dakat+1<<" ~~> is dakat in this round "<<endl;
                    cout<<"Player "<<chor+1<<" ~~> is chor in this round "<<endl;
                    players_score[police]+=0;
                    players_score[chor]+=40;
                    players_score[dakat]+=60;
                }
            }

            c.show_score();

            c.refresh();
                }
        else break;
    }
}
