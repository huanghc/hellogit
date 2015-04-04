//file name:Blackjack.cpp
//Game for Blackjack
#include <iostream>
#include <ctime>
#include <cstdlib> 
using namespace std;

double cardvalue(int i);
char check_input();
int send_card();
void show_card_1(int);
void show_card_2(int);
double player();
int coputer(double player_sum);
void game_result(int computer,int player);
bool replay();
	
int main()
{	do{
		int player_card_number,computer_card_number;
	    double player_sum,computer_sum,sum;
	    
		player_sum=player();
		player_card_number=int(player_sum)/100;
		sum=player_sum-100*player_card_number;    //calculate card number and sum 
				
		if (player_sum!=-1){
			computer_card_number=coputer(sum);    //computer's part
			game_result(computer_card_number,player_card_number);    //cout game resuit
		}                                         
	  }	while(replay());                         //whether replay the game
	return 0;
}

//Function: game_result
//Description: cout whether player wins or loses
void game_result(int computer,int player){
	if (computer!=-1){
		if (computer>player) cout<<endl<<"You lose the game!";
		else cout<<endl<<"You win the game!";
	}	
}

//Function: cardvalue
//Description: return the value a card weighs
double cardvalue(int i){
    if (i%13==0) return 1;
    if (0<(i%13) && (i%13)<10) return (i%13)+1;
    if (i%13>9) return 0.5;
}

//Function: check_input
//Description: make sure the input is y,n,Y,or N,and return it
char check_input(){
	char choice[20];
	while(1){
		try {
			cin.getline(choice,20);
		    if (choice[0]=='y' || choice[0]=='n' || choice[0]=='Y' || choice[0]=='N'){
		    	throw 0;		    
			}
			else cout<<"illegal input, please input again: ";		
	    }
		catch (int) {break;}
	} 
	return choice[0];
}

//Function: send_card
//Description: give a random card	
int send_card(){
	srand(time(NULL));
	int p;
	p=rand()%52;
	return p;	
	}

//Function: show_card_1
//Description: cout the four suits of cards
void show_card_1(int number){
	switch (number%4){
		case 0: cout<<"spade";break;
		case 1: cout<<"heart";break;
		case 2: cout<<"diamond";break;
		case 3: cout<<"club";break;
	}
}

//Function: show_card_2
//Description: cout the value of a card
void show_card_2(int number){
	if (number%13==0) cout<<"A";
	if (0<(number%13) && (number%13)<10) cout<<(number%13)+1;
	if (number%13==10) cout<<"J";
	if (number%13==11) cout<<"Q";
	if (number%13==12) cout<<"K";	
}

//Function: replay
//Description: replay the game or not
bool replay(){
	cout<<endl<<"Go on playing?";char choice;
	choice=check_input();
	if (choice=='y' || choice=='Y') return true;
	else return false;	
}

//Function: player
//Description: player's turn
//including sending cards and get the sum
double player(){
	bool flag=true;
	double sum=0;int card_total=2,first,second,i=0;
	int card_get[25]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	
	cout<<"Player's turn"<<endl;
	
	first=send_card();
	card_get[0]=first;
	
	while (flag){
		second=send_card();flag=false;
		for (int k=0;k<card_total;++k){
		    if (card_get[k]==second) flag=true;
		} 			
	}

	card_get[1]=second;
	sum=cardvalue(first)+cardvalue(second);
	cout<<endl<<"The card you get: ";
	while (i<2){
		show_card_1(card_get[i]);show_card_2(card_get[i]);cout<<"\t";++i;
	}
	cout<<endl;                        //get two cards at the beginning

	while (sum<=21){
		char choice;int new_card;
		cout<<endl<<"Do you want more cards?(y/n)";
		choice=check_input();
		if (choice=='n' || choice=='N') {return sum+card_total*100;}
		flag=true;
		while (flag){
			new_card=send_card();flag=false;
			for (int k=0;k<card_total;++k){
		        if (card_get[k]==new_card) flag=true;
		    } 			
		}                                  //get a new different card
		card_get[card_total]=new_card;++card_total;
		sum=sum+cardvalue(new_card);
		cout<<endl<<"You get another card:";
		i=0;
		while (i<25 && card_get[i]!=-1){
			show_card_1(card_get[i]);show_card_2(card_get[i]);cout<<"\t";++i;
		}                                  //cout all cards player get
		cout<<endl;
	}	
	cout<<endl<<"You lose the game!";return -1;
}

//Function: computer
//Description: computer's turn
int coputer(double player_sum){
	bool flag=true;int computer_card_number=2;
	double sum=0;int card_total=2,first,second,i=0;
	int card_get[25]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	
	cout<<endl<<"Computer's turn"<<endl;
	
	first=send_card();
	card_get[0]=first;
	
	while (flag){
		second=send_card();flag=false;
		for (int k=0;k<card_total;++k){
		    if (card_get[k]==second) flag=true;
		} 	
	}

	card_get[1]=second;
	sum=cardvalue(first)+cardvalue(second);
	cout<<endl<<"The card computer gets: ";
	while (i<2){
		show_card_1(card_get[i]);cout<<"\t";show_card_2(card_get[i]);cout<<"\t";++i;
	}
	cout<<endl;                                   //get and cout first two cards

	while (sum<player_sum){
		flag=true;int new_card;
		while (flag){
			new_card=send_card();flag=false;
			for (int k=0;k<card_total;++k){
		        if (card_get[k]==new_card) flag=true;
		    } 	
		}                                              //get a new different card
		++computer_card_number;
		card_get[card_total]=new_card;++card_total;
		sum=sum+cardvalue(new_card);
		cout<<endl<<"Computer gets another card:";
		i=0;
		while (i<25 && card_get[i]!=-1){
			show_card_1(card_get[i]);show_card_2(card_get[i]);cout<<"\t";++i;
		}                                  //cout all cards computer get
		cout<<endl;
		if (sum>21){
			cout<<endl<<"You win the game!"<<endl;return -1;
		}
	}

	if (sum>player_sum) {
		cout<<endl<<"You lose the game!"<<endl;
		return -1;
	}
	else return	computer_card_number;	
}


