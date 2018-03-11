#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.hpp"
#include "board.hpp"
#include <vector>
using namespace std;

class Player {

public:
    Player(Side side);
    ~Player();

    Move *doMove(Move *opponentsMove, int msLeft);
    int max_depth = 4;
    /*Move *MiniMax(Move *opponentsMove, int msLeft); */
    Move *RandomHeuristic(Move *opponentsMove, int msLeft);
    Move *SimplePlayer(Move *opponentsMove, int msLeft);

    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
    Side mine;
    Side yours;
    bool my_side;
    Board *othello;
    //Side opponent;
};

#endif
