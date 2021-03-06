// stl
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unordered_set>

//project
#include "Bot.h"
#include "Move.h"

//tools
#include "tools/StringManipulation.h"

Bot::Bot() :
	armies(0), timebank(0), timePerMove(0), maxRounds(0), parser(this), general(this)
{
}

Bot::~Bot()
{
	//git test
	//conflict hopefuly
	//milos is making me do things
}

void Bot::playGame()
{
	std::cerr << "ECE 368 Bot v0.1" << std::endl;

	game_running = true;
	while (game_running) {
		// Wait for input
		parser.parseInput();
	}
}

void Bot::pickStartingRegion(int time, std::unordered_set<Region*> regions)
{
	Region* start = general.pickStartingRegions(time, startingPickAmount, regions);
	std::cout << start->id << std::endl;
}

void Bot::placeArmies()
{
	std::vector<Move> deploys = general.getDeployment();
	for (Move m : deploys) {
		std::cout << botName << " place_armies " << m.from->id << " " << m.armies << ", ";
	}
	std::cout << std::endl;
	//how does the map class get updated info on our army movements?
	//do we need an updateArmies() function in Map?

	//addArmies(ownedRegions[region], armiesLeft);
}

void Bot::makeMoves()
{
	// START HERE!
	/// Output No moves when you have no time left or do not want to commit any moves.
	// std::cout << "No moves "  << std::endl;
	/// Anatomy of a single move
	//  std::cout << botName << " attack/transfer " << from << " " << to << " "<< armiesMoved;
	/// When outputting multiple moves they must be seperated by a comma
	for (Move m : general.getAttack()) {
		std::cout << botName << " attack/transfer " << m.from->id << " " << m.to->id <<
			" " << m.armies << ", ";
	}
	std::cout << std::endl;
}

/*void Bot::addWasteland(const unsigned &noRegion)
{
	wastelands.push_back(noRegion);
}*/

void Bot::setBotName(const std::string& name)
{
	botName = name;
}
void Bot::setOpponentBotName(const std::string& name)
{
	opponentBotName = name;
}
void Bot::setArmiesLeft(const int& nbArmies)
{
	armies = nbArmies;
}
void Bot::setTimebank(const int &newTimebank)
{
	timebank = newTimebank;
}
void Bot::setTimePerMove(const int &newTimePerMove)
{
	timePerMove = newTimePerMove;
}
void Bot::setMaxRounds(const int &newMaxRounds)
{
	maxRounds = newMaxRounds;
}

void Bot::clearStartingRegions()
{
	startingRegionsreceived.clear();
}

void Bot::addStartingRegion(const unsigned& noRegion)
{
	Region* r = general.map.getRegion(noRegion);
	startingRegionsreceived.push_back(r);
}

void Bot::addOpponentStartingRegion(const unsigned& noRegion)
{
	opponentStartingRegions.push_back(noRegion);
}
void Bot::opponentPlacement(const unsigned & noRegion, const int & nbArmies)
{
	// suppress unused variable warnings
	(void)noRegion;
	(void)nbArmies;

	// TODO: STUB
}
void Bot::opponentMovement(const unsigned &noRegion, const unsigned &toRegion, const int &nbArmies)
{
	// suppress unused variable warnings
	(void)noRegion;
	(void)toRegion;
	(void)nbArmies;
}