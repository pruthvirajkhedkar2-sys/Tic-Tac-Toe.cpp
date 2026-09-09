#include<iostream>
#include<ctime>
void userChoice(char &player,char &computer);
void drawBoard(char *spaces,char player,char computer);
void playermove(char *spaces,char player);
void computermove(char *spaces,char computer);
bool checkwinner(char *spaces,char player ,char computer);
bool checktie(char *spaces);
int main ()
{
    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player;;
    char computer;
    userChoice(player,computer);
    bool running = true;
    drawBoard(spaces,player,computer);
    while(running)
{
 playermove(spaces,player);
 drawBoard(spaces,player,computer);
 if(checkwinner(spaces,player,computer))
 {
    running = false;
 }
 else if(checktie(spaces))
 {
    running = false;
 }

 if(running)
{ computermove(spaces,computer);
 drawBoard(spaces,player,computer);
 if(checkwinner(spaces,player,computer))
 {
    running = false;
 }
 else if(checktie(spaces))
 {
    running = false;
 }
}
}
std::cout<<"thanks for playing";
return 0;
}
void userChoice(char& player,char& computer)
{
    std::cout<<"welcome to tic tac toe game\n";
    std::cout<<"what you like to choose X or O\n";
   
    std::cin>>player;
    player = toupper(player);
    while(player != 'O' && player !='X' )
    {
        std::cout<<"enter a valid choice";
          std::cin>>player;
    player = toupper(player);
    }
     computer = (player=='O')?'X':'O';
}
void drawBoard(char *spaces,char player,char computer)
{
    std::cout<<"\n";
    std::cout<<"     |     |     \n";
    std::cout<<"  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"   \n";
    std::cout<<"_____|_____|_____\n";
    std::cout<<"     |     |     \n";
    std::cout<<"  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"   \n";
    std::cout<<"_____|_____|_____\n";
    std::cout<<"  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"   \n";
    std::cout<<"     |     |     \n";
    std::cout<<"\n";
}
void playermove(char *spaces,char player)
{
    int i;
    do
    {std::cout<<"Enter a position to places your sign (1-9)";
    std::cin>>i;
     if(i<1||i>9)
     {std::cout<<"invalid position";
        continue;
     }
     else if(spaces[i-1]!=' ')
        {
          std::cout<<"Already occupied";
            continue;
        }
        spaces[i-1]=player;
        break;     
        }while(true);
   
    
}
void computermove(char *spaces,char computer)
{
    srand(time(0));
    int t ;
    while (true)
    {
        t = rand()%9 ;
        if(spaces[t]==' ')
        {
            spaces[t]= computer;
            break;
        }
    }
  
}
bool checkwinner(char *spaces,char player ,char computer)
{
     if( spaces[0]!= ' '&&spaces[0]==spaces[1]&&spaces[1]==spaces[2]){
    spaces[0]==player?std::cout<<"You win !!":std::cout<<"you lose";
    }

     else if( spaces[3]!= ' '&&spaces[3]==spaces[4]&&spaces[4]==spaces[5]){
    spaces[3]==player?std::cout<<"You win !!":std::cout<<"you lose";
    }
     else if( spaces[6]!= ' '&&spaces[6]==spaces[7]&&spaces[7]==spaces[8]){
    spaces[6]==player?std::cout<<"You win !!":std::cout<<"you lose";
    }
     else if( spaces[0]!= ' '&&spaces[0]==spaces[3]&&spaces[3]==spaces[6]){
    spaces[0]==player?std::cout<<"You win !!":std::cout<<"you lose";
    }
     else if( spaces[1]!= ' '&&spaces[1]==spaces[4]&&spaces[4]==spaces[7]){
    spaces[1]==player?std::cout<<"You win !!":std::cout<<"you lose";
    }
     else if( spaces[2]!= ' '&&spaces[2]==spaces[5]&&spaces[5]==spaces[8]){
    spaces[2]==player?std::cout<<"You win !!":std::cout<<"you lose";
    }
     else if( spaces[0]!= ' '&&spaces[0]==spaces[4]&&spaces[4]==spaces[8]){
    spaces[0]==player?std::cout<<"You win !!":std::cout<<"you lose";
    } 
     else if( spaces[2]!= ' '&&spaces[2]==spaces[4]&&spaces[4]==spaces[6]){
    spaces[6]==player?std::cout<<"You win !!":std::cout<<"you lose";
    }
    else{
        return false;
    }
    return true;
}
bool checktie(char *spaces)
{
    for(int i = 0;i<9;i++)
    {
        if(spaces[i]==' ')
        {
            return false;
        }
    }
    std::cout<<"its a tie";
    return true;
}