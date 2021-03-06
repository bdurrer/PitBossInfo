#include "StdAfx.h"
#include "GameStatus.h"
#include "time.h"

#include <sstream>


GameStatus::GameStatus(void)
{
}

GameStatus::GameStatus(string _name, int _year, time_t _nextRound, int _nPlayer)
{
	name = _name;
	year = _year;
	nextRound = _nextRound;
	nPlayer = _nPlayer;

	player = new Player[nPlayer];
}

GameStatus::~GameStatus(void)
{
	delete [] player;
}



void GameStatus::setPlayer(int id, Player &p){
	player[id] = p;
}

void GameStatus::setPlayer(int id, string name, bool finishedTurn, Status status, int score){
	Player *p = new Player(name, finishedTurn, status, score);
	player[id] = *p;
}


string GameStatus::toString(){
	
	stringstream buf = stringstream();
	struct tm * timeinfo;
	
	time_t rawCurrenttime;
  	time ( &rawCurrenttime );

	buf << "Gamestatus:\n";
	buf << "  name: "+name << "\n";
	//buf << "  year: "+year << "\n";
	char bufff[MAX_CHAR_LEN];
	sprintf(bufff,"%d",year);
	buf << "  year: " + string(bufff) << "\n";
	//buf << "  nextRound: " + nextRound << "\n";
	buf << "  nextRound: "; buf << asctime(localtime(&nextRound)) << "\n"; 
	buf << "  updated: "; buf << asctime(localtime(&rawCurrenttime)) << "\n";

	for (int i =0; i<nPlayer;++i){
		buf << "    P"<<i<<": "<<player[i].toString()<<"\n"; 
	}
		
	return buf.str();
}