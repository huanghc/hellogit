//file name guess_game.cpp
//Game for guess three numbers
#include <iostream>
#include <ctime>
#include <cstdlib> 
using namespace std;
int main()
{
	int num[3],input[3],i;
	int count_win=0,count_all=0;
	char flag='Y';
		
	while (flag='Y') {
		cout<<"Do you want to play a game?(Y/N)";
	    cin>>flag;
	    
	    if (flag=='N'){
	    	cout<<"You have played "<<count_all<<" times,win "<<count_win<<" times,lose "<<(count_all-count_win)<<" times";break;
		}
		else{
		    int count_one_game=0;
			srand(time(NULL));
			for (i=0; i<3; ++i){
				num[i]=rand()%10;
			}                          //create randon numbers
			i=0;
	        while (i<3){
	        	if (num[i]==num[(i+1)%3] || num[i]==num[(i+2)%3]){
				num[i]=rand()%10;
				}
	            else ++i;
	        }                          //in case there are same numbers 
	        
		    while (count_one_game<7){				
		        int A=0,B=0;                
	            cout<<"Please input the number you guess:"<<endl;
		        for (i=0; i<3; ++i) cin>>input[i];
		        
		        for (i=0; i<3; ++i){
			        if (num[i]==input[i]) ++A;
			        else{
			        	if (num[i]==input[(i+1)%3] || num[i]==input[(i+2)%3]) ++B;
					}
		        }                      //calculate A & B
			        
		        if (A==3) {
		        	++count_win;
		        	cout <<"Congratulations,you win!"<<endl;
					break;	        	
				}                      //win the game
	            cout<<A<<'A'<<B<<'B'<<endl;
				++count_one_game;
				
				if (count_one_game==7){
				cout<<"Sorry,you didn't get the right answer in ruled times.The answer is ";
			    for (i=0; i<3; ++i)  cout << num[i];
				cout<<endl;}           //lose the game
			}					
			++count_all;	        
	        }
	}
	return 0;	
}
