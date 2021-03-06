#include "StdAfx.h"
#include "Logger.h"


Logger::Logger(Game *_game) {
	this->game = _game;
}


Logger::~Logger(void)
{
	delete this->path;
}



void Logger::setup(string * _path) {
	this->path = path;
	//this->path = new string("D:\\civstat.log") ;
}


void Logger::write() {

	GameStatus *stat = game->getStatus();

	cout << *path;

	fstream file(*path, ios_base::out | ios_base::trunc); //output and overwrite the file
	file << stat->toString();
	file.close();

}