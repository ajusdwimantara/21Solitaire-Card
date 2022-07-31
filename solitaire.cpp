#include<iostream>
#include<string>
using namespace std;

class player{
    public:
        int card=10;
        int deck1[8]={0,4,1,6,-6,-4,6,-2};
		int size1=8;
		int deck2[8]={0,5,8,-2,-3,7,8,-4};
		int size2=8;
		int deck3[8]={0,6,-3,4,-5,6,-10,3};
		int size3=8;
		string deck4[4]={"-","max","min","reset"};
		int size4=4;
        
    	bool gameOver(){
            if((card<1)||(card>20)){
                return true;
            } else{
                return false;
            }
        }
        bool win(){
        	if((card>=1)&&(card<=20)){
        		if((size1==1)&&(size2==1)&&(size3==1)&&(size4==1)){
        			return true;
				}
				else{
					return false;
				}
			}
			else{
				return false;
			}
		}
};

int main(){
	int pick;	
	cout<<"\t===WELCOME TO SOLITAIRE===\t\n\n";
	bool play=true;
	player solitaire;
	while(play==true){
		cout<<"deck 1 ["<<solitaire.size1-1<<"]\t:"<<solitaire.deck1[solitaire.size1-1]<<endl;
		cout<<"deck 2 ["<<solitaire.size2-1<<"]\t:"<<solitaire.deck2[solitaire.size2-1]<<endl;
		cout<<"deck 3 ["<<solitaire.size3-1<<"]\t:"<<solitaire.deck3[solitaire.size3-1]<<endl;
		cout<<"deck 4 ["<<solitaire.size4-1<<"]\t:"<<solitaire.deck4[solitaire.size4-1]<<endl;
		cout<<endl<<"My card\t\t\t: "<<solitaire.card;
		cout<<endl<<"Choose deck (1-4)\t: ";cin>>pick;
		cout<<"======================================================================================="<<endl;
		switch(pick){
			case 1:{
				if(solitaire.deck1[solitaire.size1-1]==0){
					cout<<"This deck is empty ! Choose another deck !\n";
				}
				else {
					solitaire.card=solitaire.card+solitaire.deck1[solitaire.size1-1];
					solitaire.size1=solitaire.size1-1;
				}
				break;
			}
			case 2:{
				if(solitaire.deck2[solitaire.size2-1]==0){
					cout<<"This deck is empty ! Choose another deck !\n";
				}
				else{
					solitaire.card=solitaire.card+solitaire.deck2[solitaire.size2-1];
					solitaire.size2=solitaire.size2-1;
				}		
				break;
			}
			case 3:{
				if(solitaire.deck3[solitaire.size3-1]==0){
					cout<<"This deck is empty ! Choose another deck !\n";
				}
				else{
					solitaire.card=solitaire.card+solitaire.deck3[solitaire.size3-1];
					solitaire.size3=solitaire.size3-1;
				}
				break;
			}
			case 4:{
				if(solitaire.deck4[solitaire.size4-1]=="-"){
					cout<<"This deck is empty ! Choose another deck !\n";
				}
				else{
					if(solitaire.deck4[solitaire.size4-1]=="reset"){
					solitaire.card=10;
					}
					else if(solitaire.deck4[solitaire.size4-1]=="min"){
						solitaire.card=1;
					}
					else if(solitaire.deck4[solitaire.size4-1]=="max"){
						solitaire.card=20;
					}
				solitaire.size4=solitaire.size4-1;
				}
				break;
			}
			default:{
				cout<<"Invalid input !\n";
				break;
			}
		}
		if(solitaire.gameOver()){
            cout<<"You Lose !"<<endl;
            cout<<"My Card\t\t\t: "<<solitaire.card<<endl;
            play=false;
        }
        if(solitaire.win()){
            cout<<"You Win !"<<endl;
            cout<<"My card\t\t\t: "<<solitaire.card<<endl;
            play=false;
        }
	}
	return 0;
}
